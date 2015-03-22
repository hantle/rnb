cd $HOME
echo "Download cocos2d-x-3.4..."
wget  http://www.cocos2d-x.org/filedown/cocos2d-x-3.4.zip
echo "Unzip cocos2d-x"
unzip -o -q cocos2d-x-3.4.zip

mv cocos2d-x-3.4 cocos
cd $HOME/cocos/build

echo "Install deps..."
sudo ./install-deps-linux.sh

mkdir linux-build
cd linux-build
cmake ../..

echo "Make cocos2d-x"
make

echo "Setup path"
cd $HOME/cocos
/usr/bin/env python ./setup.py

cd $HOME
echo "Download android-ndk-r9d-linux-x86_64.tar.bz2..."
wget http://dl.google.com/android/ndk/android-ndk-r9d-linux-x86_64.tar.bz2
echo "Decompress android-ndk-r9d-linux-x86_64.tar.bzx2..."
tar xjf android-ndk-r9d-linux-x86_64.tar.bz2
mv android-ndk-r9d android-ndk

