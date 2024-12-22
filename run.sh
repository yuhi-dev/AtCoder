#!/bin/bash

# 引数で指定されたディレクトリ名（例: 385, 386, etc）
main_dir="ABC/$1"
# 引数で指定されたサブディレクトリ名（例: A, B, C, etc）
sub_dir="$main_dir/$2"

# 引数が渡されていない場合、エラーメッセージを表示
if [ -z "$1" ] || [ -z "$2" ]; then
    echo "Error: Both main directory and subdirectory name are required."
    echo "Usage: ./run.sh <main_subdirectory_name> <subdirectory_name>"
    exit 1
fi

# 指定されたディレクトリが存在するかチェック
if [ ! -d "$main_dir" ]; then
    echo "Error: Main directory '$main_dir' does not exist."
    exit 1
fi

if [ ! -d "$sub_dir" ]; then
    echo "Error: Subdirectory '$sub_dir' does not exist."
    exit 1
fi

# 指定されたサブディレクトリに移動
cd "$sub_dir" || exit

# 現在のディレクトリを取得
current_dir=$(pwd)

# 現在のディレクトリとそのサブディレクトリ内のC++ソースファイルを検索
cpp_files=$(find . -type f -name "*.cpp")

# 各C++ファイルをコンパイル
for cpp_file in $cpp_files; do
    # .cpp拡張子を削除して実行ファイル名を作成
    exe_file="${cpp_file%.cpp}"

    echo "Compiling: $cpp_file"
    g++ "$cpp_file" -o "$exe_file"

    # コンパイルが成功した場合、実行ファイルを実行
    if [ $? -eq 0 ]; then
        echo "Compilation successful: $exe_file"
        
        # 現在のディレクトリ内の全ての入力ファイルを検索
        for input_file in "$current_dir"/*.txt; do
            # 入力ファイルが存在する場合
            if [ -f "$input_file" ]; then
                echo "--------------------------------------"
                echo "Input file: $input_file"
                cat "$input_file"  # 入力ファイルの内容を表示
                echo "--------------------------------------"
                
                # プログラムを実行し、出力を表示
                echo "Output:"
                "$exe_file" < "$input_file"
                echo "--------------------------------------"
            fi
        done
    else
        echo "Compilation error: $cpp_file"
    fi
done
