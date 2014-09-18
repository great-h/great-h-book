= すごい広島の成果

//lead{
すごい広島では、毎週水曜日の活動とは別に勝手に気ままにすごい広島の成果としていろんなことをしています。また、この活動をすごい広島2.0として活動しています。
//}

== すごい広島2.0

すごい広島はひろしま発人材集積促進プロジェクト(ヒロハタ)に参加しています。
この時に、本来のすごい広島の活動であるミートアップから外れた部分の活動を@<strong>{すごい広島2.0}と命名しました。

すごい広島2.0は「広島をよりすごく見せる」というのが主な活動です。
すごい広島で身に付けた技術を生かして、広島をすごくするのがすごい広島2.0なのです。

これまでの成果を紹介したいと思います。

 * 5374.jp For 広島
 * ヒロハタを勝手に応援するサイト
 * とある我馬の非公式
 * すごいHiroshimaの本

== 5374.jp For 広島

5374.jp は「いつ、どのゴミが収集されているのか？」を簡単に調べることができるウェブサイトです。
このウェブサイトはCode For Kanazawaという団体が作成しています。

//quote{
@<strong>{コードで、世界をHappyに。}

Code for Kanazawa（CfK）は、ITやデザインの力で、私たち市民の生活が今よりも良くなることを目指します。
私たちは地域の問題を見つけ、シンプルで具体的な解決方法を開発します。
//}

この5374.jpはゴミの収集日のデータをボランティアを募り作成されています。
はじめは金沢市向けのものだけでしたが、プログラムのソースコードが公開されているため、各都市のゴミの収集日を自分達で集めれば自分達の使える5374.jpを作成することができるのです。

すごい広島では、広島市バージョンを作成しました。

 * 5374.jp for Hirohsima @<href>{http://hiroshima.5374.jp/}

//image[5374][5374.jp for Hiroshima]{
//}

ゴミの収集日の情報は広島市によってウェブサイトに公開されています。
この情報を解析して5374.jpで利用できる形式に変換するプログラムを作成することで、広島市バージョンを作成しました。

広島市のサイトを解析するプログラムはGitHubに公開されています。

 * great-h/5374-csv-generator-in-hiroshima
 ** @<href>{https://github.com/great-h/5374-csv-generator-in-hiroshima}

また、広島版の5374.jpもGitHubに公開されています。

 * great-h/5374 @<href>{https://github.com/great-h/5374}

金沢市のもよりも情報が多いため多少の変更がされています。
変更されている部分を少しだけ紹介します。

オリジナルの5374.jpでは地域を選択すると、その地域の情報が表示されます。
広島市の場合は区を選択してから、地域を選択するように変更点しています。
広島市は金沢市に比べて区分が非常に多く自分の住んでいる場所が難しくなってしまっていました。
区を先に選択してある程度絞り込みをできるようにすることで、利便性を向上させました。

もうひとつは、ゴミの種類が多いため配色を変更しています。
バランスの良い配色をするためにデザイナに協力を求めて作成しました。

== ヒロハタを勝手に応援するサイト

ヒロハタは広島県が行う事業です。
正式名称は「ひろしま発人材集積促進プロジェクト」です。

//quote{
広島県では、イノベーションの原動力となる多様な人材の集積を図る観点から、人を惹きつける力のある優れた人材を指導者として、県内外の人材が参加し、自らのアイデアの実現できるプロジェクトを実施します。

また、参加者が県内に定着、活躍できる仕組みを構築し、多様な人材の集積を促進します。
//}

ヒロハタでは参加者同士の交流が相乗効果を起きることも狙っているということで、すごい広島ではその手伝いができないか考えてみました。
そこで、各参加者の活動情報を集め要約を勝手に作成することで、見える化をすることにしました。
それが「ヒロハタを勝手に応援するサイト」です。

 * ヒロハタを勝手に応援するサイト @<href>{http://great-h.github.io/hirohata/}

このサイトは毎週月曜日に更新予定です。

参加者の活動が見えるようになることで、誰が何をやっているかがわかるようになります。
活動している人がいることがわかると負けじと行動をする人もいますし、自分が手伝えることを自分で考えて行動することもできます。

このサイトの仕組みは、はじめにヒロハタの参加者が運営するFacebook Pageやブログから一週間分の情報を集めます。
次に集めた情報を閲覧し、人間の手で修正します。
あとは記事として公開します。

一週間分の情報を集めるための部分はプログラムを作成していて、GitHubに公開しています。

 * great-h/hirohata-reporter @<href>{https://github.com/great-h/hirohata-reporter}

情報源の登録には@<tt>{config.yml}にしています。

//emlist{
targets:
  - name: "ヒロハタ"
    url: "http://hiro-hata.com/"
    sources:
    - type: rss
      url: "http://hiro-hata.com/rss"
    - type: facebook
      url: "https://www.facebook.com/feeds/page.php?id=619180321492100&format=rss20"
//}

この例ではヒロハタというチームの情報元はRSSとfacebookがあり、その情報のURLを設定できるようになっています。

またウェブサイト自体のリポジトリもGitHubに公開しています。

 * great-h/hirohata @<href>{https://github.com/great-h/hirohata}

== とある我馬の非公式

すごい広島は「我馬」というラーメン屋を応援しています。

我馬というラーメン屋のウェブサイトは更新情報を配信するフィード配信が行われていません。
そこで、すごい広島では勝手に我馬というラーメン屋のウェブサイトのフィードを配信するサイトを作成しました。

それが「とある我馬の非公式(ファンサイト)」です。

我馬というラーメン屋は季節のラーメンという期間限定のラーメンを食べることができます。
この期間限定のラーメンはおよそ3ヶ月に一度新作のラーメンが登場します。
新たに作成されるにも限らず、その季節のラーメンで新しいラーメン屋が作れる可能性を秘めたものが度々登場しています。

この季節のラーメンの情報をいちはやくキャッチするためにもこのウェブサイトをはじめました。

季節のラーメン以外にも店舗限定のラーメンなどあって我馬の情報は一瞬足りとも見逃せません。

* とある我馬の非公式(ファンサイト) @<href>{http://gaba.eiel.info/}

== すごいHiroshimaの本

この書籍のことです。略称はすごいHの本です。

この本はすごい広島のことをまとめるために作成されました。

この本はRe:VIEW(@<href>{https://github.com/kmuto/review})というツールを利用して作成されています。
Re:VIEWはHTMLのようにマークアップをして、文章に意味付けを行うことで書籍を作成します。
Re:VIEWを使用するとePubやPDF、InDesignで利用される(IDGXML)、gihyo.jp独自のマークアップ言語Inaoなどに変換することができます。

この書籍の作成にはWerckerというサービスを利用して継続的デリバリというものにも挑戦しています。
Werckerは書籍の作成ツールとは関係ないツールであることに注意してください。

Re:VIEWという形式で書かれているため、実際に書籍とした形にするにはePubやPDFのような形式に変換する必要があります。
この変換作業を本の修正案が提案される度に自動生成するようになっています。

この生成作業はWerckerで行なわれます。
作成された書籍はウェブ上にアップロードされます。
アップロードされたファイルは1週間経過すると自動的に削除されます。
これはAmazon S3というサービスを使って実現しています。

もし修正案に問題がない場合はすごい広島の最新版として採用され、次の最新版が生成されるまで残ります。
この最新版はすごいHiroshimaの本置場からリンクが貼られており、誰でもダウンロードが可能な状態になっています。

* すごいHiroshimaの本置場 @<href>{http://great-h-book.eiel.info/}

すごい広島では、新しいことに挑戦し、それを目に見える形に残し続けています。
