= すごい広島の統計情報

== コミット

週あたりのコミット数の遷移です。

//graph[commit_activity][gnuplot][週あたりのコミット数の遷移]{
    set xdata time
    set timefmt  "%Y-%m-%d"
    set format x "%m/%d"
    set style fill solid 1
    plot "data/commit_activity.dat" using 1:2 title "Commits" w boxes lc rgb "orange"
//}

//table[commit_report][週あたりコミット]{
#@mapoutput(cat data/commit_activity_report.dat)
#@end
//}

== コードの増減

コードの増減量です。

//graph[code_frequency][gnuplot][コードの増減]{
    set xdata time
    set timefmt  "%Y-%m-%d"
    set format x "%m/%d"
    set style fill solid 1
    plot "data/code_frequency_add.dat" using 1:2 title "Additions" w boxes lc rgb "green" , \
         "data/code_frequency_del.dat" using 1:2 title "Deletions" w boxes lc rgb "red"
//}

2月末にある大きな変動はサイトの構築に Jekyll を使用していたのを Sitespec に変更したためです。

== 主な活動時間

水曜日の開催中の活動が活発です。

//graph[punch_card][gnuplot][主な活動時間]{
    set grid
    set style fill solid 1
    set xdata time
    set timefmt  "%Y-%m-%d %H"
    set format x "%a"
    plot ["2014-08-17":"2014-08-24"] "data/punch_card.dat" using 1:3 title "Activity" w boxes lc rgb "orange"
//}

イベントが終了後に報告作業する人が多いため、木曜日深夜も非常に活発です。

前日や土曜日に追い込まれてから活動される方も少しいます。
その代わり、日曜日はあまり活動がないです。

== 主な貢献者

ここ1年間のコミット数が10以上の方を表示しています。

#@mapoutput(bin/main_contributors)
#@end
