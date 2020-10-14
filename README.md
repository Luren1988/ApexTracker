# M5Stackを使用した,Apexのtrackerプログラム

APIは下記参照
https://apex.tracker.gg/site-api


GCPのCloud Functions環境変数にApextrackerで取得したAPIkeyを設定する
key:TRN-Api-Key
value : "YOUR API Key"


apextacker.pyで下記項目について追記(環境変数に含めるのもあり)
Platformでの🆔 :
プラットフォーム : pc->origin , ps -> psn


表示機器。M5Stack
プログラムはApexTarker.ino
Wifiに接続する必要があるので、SSID,Passwordを適宜追加する



![tracker](https://user-images.githubusercontent.com/66073980/95964692-09358700-0e44-11eb-8e18-230fe28e612d.gif)
