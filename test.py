import os
import sys
import subprocess
import re

def main():
    if len(sys.argv) != 2:
        print("Usage: python test.py <path/to/source.c>")
        sys.exit(1)

    cfile = sys.argv[1]

    if not os.path.isfile(cfile):
        print(f"❌ File not found: {cfile}")
        sys.exit(1)

    cfilename = os.path.splitext(os.path.basename(cfile))[0]
    srcdir = os.path.dirname(cfile)
    testdir = os.path.join(srcdir, "test", cfilename)

    if not os.path.isdir(testdir):
        print(f"❌ Test directory not found: {testdir}")
        sys.exit(1)

    exe = f"{cfilename}.out"
    compile_result = subprocess.run(["gcc", cfile, "-o", exe, "-lm"])

    if compile_result.returncode != 0:
        print("❌ Compilation failed.")
        sys.exit(1)

    pass_count = 0
    fail_count = 0

    for input_file in sorted(os.listdir(testdir)):
        if not input_file.startswith("input") or not input_file.endswith(".txt"):
            continue

        num = input_file[len("input"):-len(".txt")]
        input_path = os.path.join(testdir, input_file)
        expected_path = os.path.join(testdir, f"output{num}.txt")

        if not os.path.isfile(expected_path):
            print(f"⚠️ Missing output file: {expected_path}")
            fail_count += 1
            continue

        with open(input_path, "r") as infile, open("temp_output.txt", "w") as outfile:
            subprocess.run([f"./{exe}"], stdin=infile, stdout=outfile)

        with open("temp_output.txt", "r") as temp_output, open(expected_path, "r") as expected_output:
            temp_content = temp_output.read()
            expected_content = expected_output.read()

            matched = True
            # 一文字づつ比較
            i = 0
            offset = 0
            while i < len(temp_content):
                if expected_content[i+offset:i+6+offset] == "/regex":
                    # /regex()の中身を取得
                    pattern = expected_content[i+7+offset:expected_content.find(")", i+7+offset)]
                    match = re.search(pattern, temp_content[i:])
                    i += match.end()
                    offset += len(pattern) - match.end() + 8
                else:
                    try:
                        if temp_content[i] != expected_content[i+offset]:
                            matched = False
                            break
                    except IndexError:
                        matched = False
                        print(f"⚠️ IndexError: {i} {len(temp_content)} {len(expected_content)}")
                        break
                    i += 1

            if matched:
                print(f"## ✅ Test {num} passed")
                print("### 入力:")
                print("```")
                print(open(input_path).read())
                print("```")

                print("### 出力:")
                print("```")
                print(temp_content)
                print("```")
                pass_count += 1
            else:
                print(f"## ❌ Test {num} failed")
                print("### 入力:")
                print("```")
                print(open(input_path).read())
                print("```")

                print("### 出力:")
                print("```")
                print(temp_content)
                print("```")

                print("### 期待:")
                print("```")
                print(expected_content)
                print("```")
                fail_count += 1

    os.remove(exe)
    if os.path.exists("temp_output.txt"):
        os.remove("temp_output.txt")

    print("\n==========================\n")
    print(f"- ✅ Passed: {pass_count}")
    print(f"- ❌ Failed: {fail_count}")

    sys.exit(fail_count)

if __name__ == "__main__":
    main()
