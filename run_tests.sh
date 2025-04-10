#!/bin/bash

# 使い方チェック
if [ $# -ne 1 ]; then
    echo "Usage: $0 <path/to/source.c>"
    exit 1
fi

cfile="$1"

# ファイルが存在するか確認
if [ ! -f "$cfile" ]; then
    echo "❌ File not found: $cfile"
    exit 1
fi

# 拡張子除去（例: exer1-1）
cfilename=$(basename "$cfile" .c)
srcdir=$(dirname "$cfile")
testdir="${srcdir}/test/${cfilename}"

if [ ! -d "$testdir" ]; then
    echo "❌ Test directory not found: $testdir"
    exit 1
fi

exe="${cfilename}.out"
gcc "$cfile" -o "$exe"

if [ $? -ne 0 ]; then
    echo "❌ Compilation failed."
    exit 1
fi

pass=0
fail=0

# テスト実行ループ
for input in "$testdir"/input*.txt; do
    [ -e "$input" ] || continue  # 入力ファイルがなければスキップ

    num=$(basename "$input" .txt | sed 's/input//')
    expected="$testdir/output${num}.txt"

    if [ ! -f "$expected" ]; then
        echo "⚠️ Missing output file: $expected"
        ((fail++))
        continue
    fi

    ./"$exe" < "$input" > temp_output.txt

    if diff -q temp_output.txt "$expected" > /dev/null; then
        echo "## ✅ Test $num passed"
        echo "### 入力:"
        echo '```'
        echo $(cat "$input")
        echo '```'

        echo "### 出力:"
        echo '```'
        echo "$(cat temp_output.txt)"
        echo '```'
        ((pass++))
    else
        echo "## ❌ Test $num failed"
        echo "### 入力:"
        echo '```'
        echo "$(cat "$input")"
        echo '```'

        echo "### 出力:"
        echo '```'
        echo "$(cat temp_output.txt)"
        echo '```'

        echo "### 期待:"
        echo '```'
        echo "$(cat "$expected")"
        echo '```'
        ((fail++))
    fi
done

rm -f "$exe" temp_output.txt

echo ""
echo "=========================="
echo "- ✅ Passed: $pass"
echo "- ❌ Failed: $fail"

exit $fail