#include <string.h>
#include "RhythmEngine.h"

RhythmEngine::RhythmEngine()
{
    instance = SimpleAudioEngine::getInstance();
    pause = false;
}

void RhythmEngine::setEffect(const char *filePath)
{
    instance->preloadEffect(filePath);

    this->effectPath = new char[strlen(filePath)];
    strcpy(this->effectPath, filePath);
}

void RhythmEngine::playEffect()
{
    instance->playEffect(effectPath, false, 1.0f, 1.0f, 1.0);
}

void RhythmEngine::setBGM(const char *filePath) 
{
    this->bgmPath = new char[strlen(filePath)];
    strcpy(this->bgmPath, filePath);

    /* 
       currently, preloadBackgourndMusic do nothing...
       time lag still exist when play bgm even if call preload bgm before
       so, temporarily use start / stop method for preload
       */
    //instance->preloadBackgroundMusic(filePath);
    instance->playBackgroundMusic(bgmPath, false);
    instance->pauseBackgroundMusic();
    pause = true;
}

void RhythmEngine::playBGM(bool repeat)
{
    //instance->playBackgroundMusic(bgmPath, false);
    instance->resumeBackgroundMusic();
    pause = false;
}

void RhythmEngine::stopBGM()
{
    instance->stopBackgroundMusic();
}

bool RhythmEngine::isPlayingBGM() 
{
    return instance->isBackgroundMusicPlaying();
}

bool RhythmEngine::isPauseBGM()
{
    return pause;
}
