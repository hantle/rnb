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
    void start();
    void check();
    void setPosition(cocos2d::Point location);
    void moveBy(float duration, cocos2d::Point location);
    void moveTo(float duration, cocos2d::Point location);
    void setSpeed(int bpm);
    void checkPoint();
    void removeNode(cocos2d::Node *node);
    
    bool isBlue;
    float currentX;
    float currentY;
    cocos2d::Layer *playerNode;
private:
    cocos2d::DrawNode *blueDot;
    cocos2d::DrawNode *redDot;
    cocos2d::DrawNode *line;
    
    float speed;
    cocos2d::Size visibleSize;
    cocos2d::Vec2 origin;
    cocos2d::Layer *mainLayer;
};

#endif /* defined(__rnb__Player__) */
