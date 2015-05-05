#ifndef __RHYTHMENGINE_H__
#define __RHYTHMENGINE_H__

#include "cocos2d.h"
#include "SimpleAudioEngine.h"

using namespace CocosDenshion;
using namespace std;

/*
 * 
 */
class RhythmEngine {
    private:
        SimpleAudioEngine *instance;
        char *bgmPath;
        char *effectPath;
        bool pause;

    public:
        RhythmEngine();

        // effection sound for touch
        void setEffect(const char *filePath);
        void playEffect();

        // main bgm functions
        void setBGM(const char *filePath);
        void playBGM(bool repeat);
        void stopBGM();
        bool isPlayingBGM();
        bool isPauseBGM();
};

#endif // __RHYTHMENGINE_H__
