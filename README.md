# qmk-keymaps  
自作キーボードのキーマップ定義  
qmkをインストールしてすぐ使えるようにkeymapだけ定義しました

# How to setup for QMK  
https://docs.qmk.fm

を参考にインストールを行う。  


## QMK setup
https://docs.qmk.fm/#/newbs_getting_started

## make link

```
$ git clone ~/Documents/hoge/{THIS_REPOSITORY}
$ ln -s ~/Documents/hoge/qmk-keymaps/hhkb ~/qmk_firmware/keyboards/hhkb/jp/keymaps/tecokimura
```

## Keycode

https://github.com/qmk/qmk_firmware/blob/master/docs/keycodes_basic.md

## New keymap  

$ qmk new-keymap -kb hhkb/jp -km tecokimura  

## Compile keymap  

$ qmk compile -kb hhkb/jp -km tecokimura   

## Flash to keyboard  

keymap をキーボードに転送する。  
$ qmk flash -kb hhkb/jp -km tecokimura  

## 補足

-kb オプションって何を渡せばいいの？
qmk_firmware/keyboards/**/keymaps/
の**の箇所、keyboardsとkeymapsの間のパス？です。
自分の自作したキーボードか反映させるキーボードがどれに当たるかぐぐって調べましょう

-km は？
keymaps/の下のフォルダ名です。

QMKのversion更新で多少変わることがあるかもなので確認しましょう。

