#!/bin/sh
### HTMLファイルの内容を正規表現で置換する

# 入力チェック（シェルスクリプト基本リファレンスp11）
if [ $# -lt 2 -o $# -gt 3 ]; then
    echo "Usage:$0 regexp string [filename]"
    exit 1
fi

if [ $# = 2 ]
then
    # .htmlファイルのbackupをとる（シェルスクリプト基本リファレンスp96）
    for file in *.html
    do
	cp -p "$file" "$file".bak
    done
    # カレントディレクトリの.htmlファイル内の文字列を置換して上書き保存する
    exec find . -maxdepth 1 -name '*.html' -type f -print0 | xargs -0 perl -p -i -e "s/$1/$2/g"
else
# 指定されたファイルのbackupをとる
    cp -p "$3" "$3".bak
# 指定されたファイル内の文字列を置換して上書き保存する
    exec perl -p -i -e "s/$1/$2/g" $3
fi
