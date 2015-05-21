#ifndef __Stage_h__
#define __Stage_h__

#include "cocos2d.h"
#include "RhythmEngine.h"
#include "TileMap.h"

class Stage {
private:
    int bpm;
    RhythmEngine *rhythm;
    
    void extractZip(const char *stageZip);
public:
    TileMap *map;
    Stage(const char *stageZip, cocos2d::Layer *layer);
    RhythmEngine *getRhythmEngine();
    int getBPM();
};

#endif // __Stage_h__
