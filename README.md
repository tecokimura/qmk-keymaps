# qmk-keymaps



# How to setup
https://beta.docs.qmk.fm/
を基にインストールを行う。

## install
$ brew install qmk/qmk/qmk
$ qmk compile -kb mint60 -km default

## new keymap
$ qmk new-keymap -kb mint60 -km tecokimura
$ qmk compile -kb mint60 -km tecokimura

## copy keymaps
### mint60
~/qmk_firmware/keyboards/mint60/keymaps/tecokimura/
に入れるもの

### ergo42
~/qmk_firmware/keyboards/ergo42/keymaps/tecokimura/
$ qmk flash -kb ergo42 -km tecokimura

### hhkb
~/qmk_firmware/keyboards/hhkb/keymaps/tecokimura/

## write to keyboard
$ qmk flash -kb mint60 -km tecokimura


