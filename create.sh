#!/bin/bash

BASE_DIR="ABC"

# 引数が指定されていない場合は使い方を表示
if [ -z "$1" ]; then
    echo "Usage: $0 <problem>"
    exit 1
fi

# 引数で指定された問題名をDIR_NAMEに設定
DIR_NAME="$BASE_DIR/$1"

# 作成する7つのサブディレクトリ名
SUB_DIR=("A" "B" "C" "D" "E" "F" "G")

# 各サブディレクトリに対して処理を実行
for dir in "${SUB_DIR[@]}"; do
    TARGET_DIR="$DIR_NAME/$dir" # TARGET_DIRに問題のディレクトリパスを設定
    mkdir -p "$TARGET_DIR" # ディレクトリを作成
    touch "$TARGET_DIR/$dir.cpp" # C++ファイルを作成
    touch "$TARGET_DIR/input1.txt" # 入力ファイルを作成
    touch "$TARGET_DIR/input2.txt" # 入力ファイルを作成
    touch "$TARGET_DIR/input3.txt" # 入力ファイルを作成
done

echo "Directories and files created successfully."
