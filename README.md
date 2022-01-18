# qmk-keymaps  
自作キーボードのキーマップ定義  
qmkインストールしてすぐ使えるようにkeymapだけ定義している。  

# How to setup  
https://beta.docs.qmk.fm/  
を基にインストールを行う。  

## Install  
### for Mac  
$ brew install qmk/qmk/qmk  

### for Windows  
You have to use installer  

## New keymap  
$ qmk new-keymap -kb mint60 -km tecokimura  

## Compile keymap  
$ qmk compile -kb mint60 -km tecokimura  
$ qmk compile -kb helix/rev2 -km mykeymap   
  
## Copy keymaps  
### mint60  
~/qmk_firmware/keyboards/mint60/keymaps/tecokimura/  
に入れるもの  

### ergo42  
~/qmk_firmware/keyboards/ergo42/keymaps/tecokimura/  
$ qmk flash -kb ergo42 -km tecokimura  

### hhkb  
~/qmk_firmware/keyboards/hhkb/keymaps/tecokimura/  
  
## Write to keyboard  
keymap をキーボードに転送する。  
$ qmk flash -kb mint60 -km tecokimura  
$ qmk flash -kb helix/rev2 -km tecokimura  


