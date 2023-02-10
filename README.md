# qmk-keymaps  
自作キーボードのキーマップ定義  
qmkインストールしてすぐ使えるようにkeymapだけ定義している。  

# How to setup for QMK  
https://beta.docs.qmk.fm/  
を基にインストールを行う。  
Mac だとCPUによって準備が異なるので注意

## 準備
for Mac M1
https://blog.looseknot.jp/mac/m1mac_terminal_rosetta.html
https://zenn.dev/bon/scraps/1cd6c49320a0ff

## QMK setup
https://docs.qmk.fm/#/newbs_getting_started

## make link
$ git clone ~/Documents/hoge/{THIS_REPOSITORY}
$ ln -s ~/Documents/hoge/qmk-keymaps/hhkb ~/qmk_firmware/keyboards/hhkb/jp/keymaps/tecokimura

## Keycode
https://github.com/qmk/qmk_firmware/blob/master/docs/keycodes_basic.md

## New keymap  
$ qmk new-keymap -kb mint60 -km tecokimura  
$ qmk new-keymap -kb hhkb/jp -km tecokimura  

## Compile keymap  
$ qmk compile -kb mint60 -km tecokimura  
$ qmk compile -kb helix/rev2 -km mykeymap   
$ qmk compile -kb hhkb/jp -km tecokimura   

## 解説
-kb オプションって何を渡せばいいの？
qmk_firmware/keyboards/**/keymaps/
の**の箇所、keyboardsとkeymapsの間のパス？です。
自分の自作したキーボードか反映させるキーボードがどれに当たるかぐぐって調べましょう

-km は？
keymaps/の下のフォルダ名です。

QMKのversion更新で多少変わることがあるかもなので確認しましょう。

## Copy keymaps  
### mint60  
~/qmk_firmware/keyboards/mint60/keymaps/tecokimura/  

### ergo42  
~/qmk_firmware/keyboards/ergo42/keymaps/tecokimura/  
$ qmk flash -kb ergo42 -km tecokimura  

### hhkb  
~/qmk_firmware/keyboards/hhkb/keymaps/tecokimura/  
  
## Write to keyboard  
keymap をキーボードに転送する。  
$ qmk flash -kb mint60 -km tecokimura  
$ qmk flash -kb helix/rev2 -km tecokimura  


