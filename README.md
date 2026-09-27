# Linux Socket Programming

Linux環境でC言語によるソケットプログラミングを学習するためのリポジトリです。

## Overview

TCP通信を利用した簡単なクライアント・サーバプログラムを実装しています。

## Environment

- Ubuntu
- C
- GCC

## Build

```bash
gcc server.c -o server
gcc client.c -o client

## Run

Server:

```bash
./server

Client:

```bash
./client

## Features

- TCPによるクライアント・サーバ通信
- C言語によるソケットプログラミング
- Linux Socket APIを利用した通信処理
- クライアントからサーバへのデータ送信
- サーバからクライアントへのデータ送信

## Learning

このプロジェクトを通して、以下について学習しました。

- TCP/IP通信の基本
- ソケットAPIの基本的な使い方
- `socket()`, `bind()`, `listen()`, `accept()`, `connect()` の役割
- Linuxにおけるファイルディスクリプタ
- C言語によるネットワークプログラミング
- Linuxにおけるプロセス間通信とネットワーク通信
