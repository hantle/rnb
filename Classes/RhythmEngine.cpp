#include <string.h>
#include "RhythmEngine.h"

RhythmEngine::RhythmEngine(const char *filePath)
{
    instance = SimpleAudioEngine::getInstance();

    this->filePath = new char[strlen(filePath)];
    strcpy(this->filePath, filePath);
}
/*
RhythmEngine(const char *filePath, int pitch)
{
    this(filePath);
}*/

void RhythmEngine::preLoad() 
{
    instance->preloadBackgroundMusic(filePath);
}

void RhythmEngine::play(bool repeat)
{
    instance->playBackgroundMusic(filePath, repeat);
}

void RhythmEngine::stop()
{
    instance->stopBackgroundMusic();
}
