import os
import sys
import subprocess
import glob
import re

TIMEOUT_SEC = 1

def run_exec(exe, input_path=None):
    try:
        if input_path:
            with open(input_path, "r") as infile:
                result = subprocess.run(
                    [f"./{exe}"],
                    stdin=infile,
                    capture_output=True,
                    text=True,
                    timeout=TIMEOUT_SEC,
                )
        else:
            result = subprocess.run(
                [f"./{exe}"],
                capture_output=True,
                text=True,
                timeout=TIMEOUT_SEC,
            )
    except subprocess.TimeoutExpired:
        return None, "TIMEOUT"

    return result.stdout, None

def compare_with_regex(actual, expected):
    i = 0
    j = 0
    while i < len(actual) and j < len(expected):
        if expected.startswith("/regex(", j):
            end = expected.find(")", j + 7)
            if end == -1:
                return False
            pattern = expected[j + 7:end]
            match = re.search(pattern, actual[i:])
            if not match:
                return False
            i += match.end()
            j = end + 1
        else:
            if actual[i] != expected[j]:
                return False
            i += 1
            j += 1
    while expected.startswith("/regex(", j):
        end = expected.find(")", j + 7)
        if end == -1:
            return False
        j = end + 1
    return i == len(actual) and j == len(expected)

def print_md_block(title, content):
    print(f"### {title}:")
    print("```")
    print(content.strip())
    print("```")

def main():
    if len(sys.argv) != 2:
        print("Usage: python test.py <path/to/source.c>", file=sys.stderr)
        sys.exit(1)

    cfile = sys.argv[1]
    if not os.path.isfile(cfile):
        print(f"Error: file not found: {cfile}", file=sys.stderr)
        sys.exit(1)

    cfilename = os.path.splitext(os.path.basename(cfile))[0]
    srcdir = os.path.dirname(os.path.abspath(cfile))
    exe = f"{cfilename}.out"

    # --- compile ---
    compile_result = subprocess.run(["gcc", cfile, "-o", exe, "-lm"])
    if compile_result.returncode != 0:
        sys.exit(compile_result.returncode)

    base_testdir = os.path.join(srcdir, "test")
    target_testdir = os.path.join(base_testdir, cfilename)

    if not os.path.isdir(base_testdir) or not os.path.isdir(target_testdir):
        actual, err = run_exec(exe)
        print("## 実行結果")
        if err == "TIMEOUT":
            print_md_block("エラー", f"実行が {TIMEOUT_SEC} 秒を超えました")
        else:
            print_md_block("出力", actual)
        os.remove(exe)
        sys.exit(0)

    input_files = sorted(glob.glob(os.path.join(target_testdir, "input*.txt")))
    output_files = sorted(glob.glob(os.path.join(target_testdir, "output*.txt")))

    if output_files:
        if input_files and len(input_files) != len(output_files):
            print("Error: number of input*.txt and output*.txt files do not match", file=sys.stderr)
            os.remove(exe)
            sys.exit(1)

        for i, out_file in enumerate(output_files):
            inp = input_files[i] if i < len(input_files) else None
            actual, err = run_exec(exe, inp)
            expected = open(out_file).read()

            if err == "TIMEOUT":
                print(f"## ❌ Test {i} failed (TIMEOUT)")
                if inp:
                    print_md_block("入力", open(inp).read())
                print_md_block("エラー", f"実行が {TIMEOUT_SEC} 秒を超えました")
                continue

            if compare_with_regex(actual, expected):
                print(f"## ✅ Test {i} passed")
            else:
                print(f"## ❌ Test {i} failed")

            if inp:
                print_md_block("入力", open(inp).read())
            print_md_block("出力", actual)
            if not compare_with_regex(actual, expected):
                print_md_block("期待", expected)

    elif input_files:
        for i, inp in enumerate(input_files):
            actual, err = run_exec(exe, inp)
            print(f"## 実行 {i}")
            print_md_block("入力", open(inp).read())
            if err == "TIMEOUT":
                print_md_block("エラー", f"実行が {TIMEOUT_SEC} 秒を超えました")
            else:
                print_md_block("出力", actual)
    else:
        actual, err = run_exec(exe)
        print("## 実行結果")
        if err == "TIMEOUT":
            print_md_block("エラー", f"実行が {TIMEOUT_SEC} 秒を超えました")
        else:
            print_md_block("出力", actual)

    os.remove(exe)

if __name__ == "__main__":
    main()
