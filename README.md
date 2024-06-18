# __WIP:__ Analize nosefart

## About

- このリポジトリはオープンソースの NSF プレイヤ [nosefart](https://nosefart.sourceforge.net/) の解析を目的としています。
- オリジナルのソースコードは [nosefart](./nosefart/) ディレクトリ以下に格納されています。
- [nsfplay.cpp](./nsfplay.cpp) は SDL2 を用いて nosefart で NSF ファイルを再生する実装です

## WIP Status

とりあえず再生できたものの矩形波チャネル2が途中からおかしな感じになる。

音程周波数の更新が不適切な状態になっている。

矩形波チャンネルの音程周波数は reg2 (8bits) と reg3 の下位 3bits の 11bits で設定する仕様だが、

```c
/* RECTANGLE WAVE
** ==============
** reg0: 0-3=volume, 4=envelope, 5=hold, 6-7=duty cycle
** reg1: 0-2=sweep shifts, 3=sweep inc/dec, 4-6=sweep length, 7=sweep on
** reg2: 8 bits of freq
** reg3: 0-2=high freq, 7-4=vbl length counter
*/
```

矩形波レジスタのダンプを出力してみたところ、チャネル2 (rect[1]) の reg3 が演奏開始時点は 0x01 になっているが、高い音程になっても 0x01 のまま（低い音）になっていることが分かった。

```
./nsfplay test.nsf
Press enter to exit...
rect[1] = 3F 08 9F 00 rect[1] = 3F 08 DF 01  
                                         ^^ ココが 0x00 になるべきタイミングでも 0x01 のままになっている
```

恐らく、256以下の周波数を設定した時にクリアされるべき reg3 が何故かクリアされない挙動になることで音痴になっているかもしれない。

----

FamiStudio のエクスポート機能の問題かもしれないので issue で確認中。

https://github.com/BleuBleu/FamiStudio/issues/325

FamiStudio の作者さんからの情報によると、音程の変化にSweepを使う可能性があるらしい。

音程周波数の問題に着眼していてSweepが適切に実装されているかは確認していなかったのでnosefartのsweepが適切に実装されているか解析してみることにする。

あとはもうちょっと動作実績のある Linux の NSF 再生機能があるエミュレータについても確認してみる。

-----

[puNES](https://github.com/punesemu/puNES) で検証したところ正常な音程で再生されることを確認した。

puNES コアを利用した形への検証を進める。


## How to Build

Linux (Ubuntu) でのビルドを前提としています。

```
# install GNU Make, GCC and other
sudo apt install build-essential

# install SDL2
sudo apt-get install libsdl2-dev

# install ALSA
sudo apt-get install libasound2
sudo apt-get install libasound2-dev

# download repository
git clone https://github.com/suzukiplan/nosefart

# move to this dir
cd nosefart

# build
make
```

## License

[GPLv2](./LICENSE.txt)
