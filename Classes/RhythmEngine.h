#ifndef __RHYTHMENGINE_H__
#define __RHYTHMENGINE_H__

#include "cocos2d.h"
#include "SimpleAudioEngine.h"

using namespace CocosDenshion;
using namespace std;

class RhythmEngine {
    private:
        char *filePath;
        SimpleAudioEngine *instance;

    public:
        // we need to use strategy or state pattern
        // which is defined by ctor. because api to call to play background
        // or effect is different.
        // but now, using background music only for testing
        RhythmEngine(const char *filePath);
        //RhythmEngine(const char *filePath, int pitch);
        //RhythmEngine(const char *filePath, int pitch, bool repeat);

        void preLoad();
        void play(bool repeat);
        void stop();
};

#endif // __RHYTHMENGINE_H__
