#!/bin/bash

if [ "$#" -ne 1 ]; then
    echo "Usage: $0 <file>"
    exit 1
fi

file=$1
dir=$(dirname "$file")
base=$(basename "$file" .c)
mkdir -p "$dir/build"
gcc "$file" -o "$dir/build/$base"
./"$dir/build/$base"