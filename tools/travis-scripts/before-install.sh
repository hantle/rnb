cd $HOME
echo "Download cocos2d-x-3.4..."
wget  http://www.cocos2d-x.org/filedown/cocos2d-x-3.4.zip
echo "Unzip cocos2d-x"
unzip -o -q cocos2d-x-3.4.zip

mv cocos2d-x-3.4 cocos
cd $HOME/cocos/build

echo "install deps..."
sudo ./install-deps-linux.sh

mkdir linux-build
cd linux-build
cmake ../..

echo "make cocos2d-x"
make
