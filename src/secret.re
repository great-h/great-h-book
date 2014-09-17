= すごい広島の秘密

すごい広島に関する雑多なことを紹介します。

== 参加者情報の生成

すごい広島はDoorkeeperというウェブサービスで事前申し込みを受付います。
このウェブサービスで申し込みをしておくと、すごい広島のイベントページに自動的に参加者情報が記述されるようになっています。

この自動の生成は毎週水曜日の17時ごろに行なわれます。

DoorkeeperではTwitter, Facebook, GitHub, Linked inのアカウントで認証することができます。
すごい広島のサイトに参加者の情報を記述する際にはGitHub, Twitter, Facebook, Linked inの優先順位で利用するようになっています。

GitHubで認証していれば、GitHubの表示名を表示し、プロフィールへのリンクになります。
GitHubで認証していなければ、Twitterの情報を…となります。

このルールに沿わずに自分好みの設定をする方法も用意してあります。

すごい広島のリポジトリには@<tt>{users.yml}が用意されていて、このファイルに情報を記述することで好みの設定をすることができます。
現在の設定はこのようになっています。

//emlist{
eiel:
  name: eiel
  url: http://eiel.info/
Torokun:
  name: Toro_kun
  url: https://twitter.com/Toro_kun
Nyoho:
  name: Nyoho
  url: http://nyoho.jp/
//}

== すごい広島のAPI

すごい広島にはWebAPIが提供されています。

 * GET http://great-h.github.io/event.json

このAPIは次回のイベント番号と日時、開催場所を返します。
出力は以下の通りです。うまく利用してアプリケーションを作成してみてください。

//emlist{
{"no":70,"datetime":"2014-09-17T18:00:00+09:00","place":"Movin'on"}
//}

== すごい広島コマンドラインツール

すごい広島のコマンドラインツールも開発されています。
2014年9月現在の時点ではMac OS Xのみのサポートとなっています。

開発中のためバイナリ配布はまだされていません。
ソースコードを取得してコンパイルする必要があります。
すごい広島のコマンドラインツールのコンパイルにはHaskell Platform(@<href>{https://www.haskell.org/platform/})のインストールが必要です。
Haskell Platformをインストールしている状態で、

//emlist{
$ git clone git@github.com:great-h/great-h.git
$ cd great-h
$ cabal install great-h
//}

とすることでコマンドラインツールをインストールすることができます。

現在はすごい広島のサイトをブラウザで表示するopenサブコマンドのみ実装されています。

//emlist{
$ great-h open
//}

@<comment>{あとで書く マージルール }
