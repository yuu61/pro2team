<!--
VScodeで編集した方が楽
cssとかはコパイで書いてるよ
-->
<head>
<style>
.inner {
  max-width: 50%;
  margin: auto;
  min-width: 780px;
}
</style>
</head>
<div class="inner">
<h1 align="center">右上からリポジトリもぜひ見てね</h1>

## 目的

## 反省点
### 最初の抽象的な方向決めを適切に行えなかった
  - 当事者意識を持っておらず筆者を含めPMに丸投げ状態だった

### 割とデカめの仕様変更を途中で2回挟んだ
  - 言語をC++に変更 [df7ee5a](https://github.com/yuu61/pro2team/commit/df7ee5a32985c1fc38ef0b62c8408677d5b1a422)
    - C++を書いたことがない人が大半を占めた
  - 大幅にプログラムの構造を変更 [5242d35](https://github.com/yuu61/pro2team/commit/5242d35a5021f87dc997cb6a1b10007be2473a65)
    - オブジェクト指向他に慣れておらず触れる者が一人だけになってしまった

### チームメンバーがGitHubにあまり慣れていない状態で導入
- 1/16にdetached HEADが発覚。修復できず大幅な変更消失。
  - 先生が全員の技術レベルを合わせろといった意味を身をもって反省
  - 冷静に考えればコミットしてプッシュするのを諦めてリポジトリをzipに圧縮して私が手動でマージして<br>再クローンすれば良かったものを、「昼休みが終わる。昼飯は食べておきたい」という焦りから考えを放棄してしまった

## 企画概要
最初はどこかで見たことあるようなロシアンルーレットのゲームを作る予定やったけど知らん間にルーレットで点数稼ぐゲームになってた
## システム構成
ここにUML図とか
## 機能概要

## 開発環境、言語
<table>
  <tr>
    <td>使用言語</td>
    <td>C++</td>
  </tr>
  <tr>
    <td>ライブラリ</td>
    <td>DX ライブラリ</td>
  </tr>
  <tr>
    <td>IDE</td>
    <td>Visual studio 2022</td>
  </tr>
  <tr>
    <td>コードエディタ</td>
    <td>VS code</td>
  </tr>
  <tr>
    <td>バージョン管理</td>
    <td>GitHub</td>
  </tr>
  <tr>
    <td>webホスティング</td>
    <td>GitHub Pages</td>
  </tr>
  <tr>
    <td>性的サイトジェネレーター</td>
    <td>jekyll</td>
  </tr>    
</table>

## 開発小話
- 最初、この紹介サイトが担当者一人しか編集できないと聞いて、それはさすがに不便すぎるので全員が編集できるようにしたかった。<br><span style="color: #cccccc;">あとwordpressのビジュアルエディタがサイト自体のレスポンスの悪さも相まって死ぬほど使いづらい</span><br>幸いリダイレクトが許可されていたので、HTMLもCSSもJSも書けないけどMarkdownならそれなりに書けるので<br>何かないかと思ったら、GitHub PagesでJekyllを使ってWebホスティングができると聞いてこれを採用。
- 多分文字コードが原因でVisual Studioの補完機能である[IntelliSenseが動かなくなったり](https://qiita.com/yuu2461/items/7e4f090d63e8a332194f)した。

## 今後の展望

## チームメンバー
カード型表示にしたい
<table>
  <tr>
    <th>役割</th>
    <th>名前</th>
    <th>説明</th>
  </tr>
  <tr>
    <td>プロジェクトマネージャー</td>
    <td>松川</td>
    <td>プログラムの99割を書いたひと<br>頭が上がらない</td>
  </tr>
  <tr>
    <td rowspan="2">プログラマー</td>
    <td>山﨑</td>
    <td>自称縁下チカモチ。何もしていない<br>GitHubのリポジトリ用意したり<br>ホームページ用意したり。細々したこと色々<br>detached HEADを修復できず大幅な変更を消失させてしまった。<br>本当に申し訳ない</td>
  </tr>
  <tr>
    <td>松田</td>
    <td>example text</td>
  </tr>
  <tr>
    <td rowspan="4">デザイナー</td>
    <td>渡辺</td>
    <td>example text</td>
  </tr>
  <tr>
    <td>村側</td>
    <td>example text</td>
  </tr>
  <tr>
    <td>宮崎</td>
    <td>example text</td>
  </tr>
  <tr>
    <td>李</td>
    <td>example text</td>
  </tr>
</table>
<!--
# 謝辞
今回のチーム制作におきまして、多大なるご支援を賜りました。<br>
この場をお借りして、深く御礼申し上げます。<br><br>
-->
</div>