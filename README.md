# AtCoder Contests and Practice Solutions

このリポジトリは、AtCoderのコンテストや練習問題の解答をまとめたものです。

## リポジトリ構成

- `ABC`: AtCoder Beginners Contestの問題と解答をまとめたディレクトリ
- `ABS`: AtCoder Beginners Selectionの解答をまとめたディレクトリ
- `ALPC`: AtCoder Library Practice Contestの解答をまとめたディレクトリ
- `APG4b`: C++入門 AtCoder Programming Guide for beginners (APG4b)の解答をまとめたディレクトリ
- `typical90`: 競プロ典型 90 問の解答をまとめたディレクトリ
- `tessoku`: 競技プログラミングの鉄則　演習問題集の解答をまとめたディレクトリ
- 各ファイルは、C++で解いた問題のソースコードです。練習問題にはコンテストのURLが書かれたtxtファイルが付属しています。

## 使用言語

- 主に C++ を使用しています。
- その他、必要に応じて Python や他の言語も使用する場合があります。

## コンテストの解答

- 各コンテストごとにディレクトリが作成され、問題の解答をファイルに保存しています。
- コンテスト名に基づくディレクトリが作成されています。例えば、`XXX/` のような形です。

## 練習用の解答

- ディレクトリ内には、AtCoderでの練習用に解いた問題の解答があります。

## シェルスクリプト

### ディレクトリとファイルの自動作成

このリポジトリには、AtCoderのコンテストや練習問題の解答に必要なディレクトリ構成を自動的に作成するシェルスクリプト `create_dirs.sh` が含まれています。これにより、問題ごとのディレクトリとサブディレクトリを迅速にセットアップできます。

#### 使用方法

1. まず、`create_dirs.sh` に実行権限を付与します：
   ```bash
   chmod +x create_dirs.sh

2. 次に、問題名を指定してシェルスクリプトを実行します。例えば、ABC001 という問題を作成したい場合、以下のコマンドを実行します：
   ```bash
   ./create_dirs.sh ABC001
   これにより、ABC/ABC001 というディレクトリが作成され、その中に7つのサブディレクトリ（A から G）と、各サブディレクトリ内に以下のファイルが作成されます：
   <subdirectory>.cpp（C++ ファイル）
   input1.txt, input2.txt, input3.txt（入力ファイル）



## 実行方法

1. このリポジトリをクローンします:
   ```bash
   git clone https://github.com/<your-username>/<your-repository-name>.git
