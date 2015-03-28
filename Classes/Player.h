//
//  Player.h
//  rnb
//
//  Created by Macbook on 2015. 3. 28..
//
//

#ifndef __rnb__Player__
#define __rnb__Player__

#include "cocos2d.h"
#include "ui/CocosGUI.h"

class Player
{
public:
    Player(cocos2d::Layer *layer);
    void initPlayer(cocos2d::Layer *layer);
    
private:
    cocos2d::Size visibleSize;
    cocos2d::Vec2 origin;
    cocos2d::Layer *mainLayer;
};

#endif /* defined(__rnb__Player__) */