# __WIP:__ Analize nosefart

## About

- このリポジトリはオープンソースの NSF プレイヤ [nosefart](https://nosefart.sourceforge.net/) の解析を目的としています。
- オリジナルのソースコードは [nosefart](./nosefart/) ディレクトリ以下に格納されています。
- [nsfplay.cpp](./nsfplay.cpp) は SDL2 を用いて nosefart で NSF ファイルを再生する実装です

## WIP Status

とりあえず再生できたものの矩形波チャネル2が途中からおかしな感じになる

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
