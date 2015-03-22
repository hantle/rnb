echo "Setup path"
/usr/bin/env python $(HOME)/cocos/setup.py

source $(HOME)/.bashrc

cocos new -l cpp ../dummy

cp -rf ../dummy/cocos2d ./

