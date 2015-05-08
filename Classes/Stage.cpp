#include "Stage.h"
#include "Define.h"

USING_NS_CC;

Stage::Stage(const char *stageZip, cocos2d::Layer *layer)
{
    // TODO: extract map & bgm info from stage zip

    map = new TileMap(layer);

    rhythm = new RhythmEngine();
    rhythm->setBGM("music/sample.mp3");
    rhythm->setEffect("music/knock.mp3");
}

RhythmEngine *Stage::getRhythmEngine()
{
    return rhythm;
}

int Stage::getBPM() 
{
    return bpm;
}
