#ifndef __Stage_h__
#define __Stage_h__

#include "cocos2d.h"
#include "RhythmEngine.h"
#include "TileMap.h"

class Stage {
    private:
        int bpm;
        RhythmEngine *rhythm;
        TileMap *map;

    public:
        Stage(const char *stageZip, cocos2d::Layer *layer);
        RhythmEngine *getRhythmEngine();
        int getBPM();
};

#endif // __Stage_h__
