cd $HOME
echo "Download cocos2d-x-3.4..."
curl -0 http://www.cocos2d-x.org/filedown/cocos2d-x-3.4.zip
echo "Unzip cocos2d-x"
unzip -q coos2d-x-3.4.zip

mv cocos2d-x-3.4.zip cocos
cd $HOME/cocos/build

echo "install deps..."
sudo ./install-deps-linux.sh

mkdir linux-build
cd linux-build
cmake ../..

echo "make cocos2d-x"
make
