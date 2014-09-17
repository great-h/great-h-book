[![wercker status](https://app.wercker.com/status/f52d887427c961584ec21f6cc0a6d921/m "wercker status")](https://app.wercker.com/project/bykey/f52d887427c961584ec21f6cc0a6d921)

# すごい広島の本

すごい広島の情報を集めた電子書籍のリポジトリです。

このリポジトリにプッシュすると

* `http://great-h-book.eiel.info/tmp/great-h-book-{コミットID}.epub`

にファイルが生成されるようになっています。
このファイルは一定期間経過すると削除されます。

また master ブランチにマージされると

`http://great-h-book.eiel.info/great-h-book.epub`

にファイルが生成されます。

# Macでコンパイルする方法

```
$ brew install gnuplot --pdf
$ brew cask install mactex
```

# リンク

* [すごい広島](http://great-h.github.io/)
