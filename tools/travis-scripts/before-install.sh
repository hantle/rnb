
install_deps()
{
#install g++-4.9 & cmake-2.8.12
    sudo add-apt-repository --yes ppa:ubuntu-toolchain-r/test
	sudo add-apt-repository --yes ppa:kalakris/cmake
    sudo apt-get -qq update

#try to remove glfw2
    sudo apt-get -qq remove libglfw2

    DEPENDS='libx11-dev'
    DEPENDS+=' libxmu-dev'
    DEPENDS+=' libglu1-mesa-dev'
    DEPENDS+=' libgl2ps-dev'
    DEPENDS+=' libxi-dev'
    DEPENDS+=' g++-4.9'
    DEPENDS+=' libzip-dev'
    DEPENDS+=' libpng12-dev'
    DEPENDS+=' libcurl4-gnutls-dev'
    DEPENDS+=' libfontconfig1-dev'
    DEPENDS+=' libsqlite3-dev'
    DEPENDS+=' libglew-dev'
    DEPENDS+=' libssl-dev'

    MISSING=
    echo "Checking for missing packages ..."
    for i in $DEPENDS; do
        if ! dpkg-query -W --showformat='${Status}\n' $i | grep "install ok installed" > /dev/null; then
            MISSING+="$i "
        fi
    done

    if [ -f /usr/bin/g++ ];then
    sudo rm /usr/bin/g++
    echo "remove old g++"
    fi
    sudo ln -s /usr/bin/g++-4.9 /usr/bin/g++

    if [ -n "$MISSING" ]; then
        TXTCOLOR_DEFAULT="\033[0;m"
        TXTCOLOR_GREEN="\033[0;32m"
        echo -e $TXTCOLOR_GREEN"Missing packages: $MISSING.\nYou may be asked for your password for package installation."$TXTCOLOR_DEFAULT
        sudo apt-get --force-yes --yes -qq install $MISSING
    fi

# install glfw
    ../tools/travis-scripts/install_glfw.sh
}

cd $HOME
echo "Download cocos2d-x-3.4..."
wget  http://www.cocos2d-x.org/filedown/cocos2d-x-3.4.zip
echo "Unzip cocos2d-x"
unzip -o -q cocos2d-x-3.4.zip
mv cocos2d-x-3.4 cocos

echo "Install deps..."
install_deps

cd $HOME
echo "Download android-ndk-r9d-linux-x86_64.tar.bz2..."
wget http://dl.google.com/android/ndk/android-ndk-r9d-linux-x86_64.tar.bz2
echo "Decompress android-ndk-r9d-linux-x86_64.tar.bz2..."
tar xjf android-ndk-r9d-linux-x86_64.tar.bz2
mv android-ndk-r9d android-ndk

cd $HOME
echo "Download android-sdk..."
wget http://dl.google.com/android/android-sdk_r24.1.2-linux.tgz
echo "Decompress android-sdk..."
tar zxf android-sdk_r24.1.2-linux.tgz

