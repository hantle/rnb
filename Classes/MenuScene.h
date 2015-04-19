//
//  MenuScene.h
//  rnb
//
//  Created by Macbook on 2015. 3. 28..
//
//

#ifndef __rnb__MenuScene__
#define __rnb__MenuScene__

#include "cocos2d.h"
#include "Player.h"

class MenuScene : public cocos2d::Layer
{
public:
    // there's no 'id' in cpp, so we recommend returning the class instance pointer
    static cocos2d::Scene* createScene();
    
    // Here's a difference. Method 'init' in cocos2d-x returns bool, instead of returning 'id' in cocos2d-iphone
    virtual bool init();
    
    
    Player *player;
    
    bool onTouchBegan(cocos2d::Touch *touch, cocos2d::Event *unused_event);
    void onTouchMoved(cocos2d::Touch *touch, cocos2d::Event *unused_event);
    
    void update(float dt);
    
    // implement the "static create()" method manually
    CREATE_FUNC(MenuScene);
};

#endif /* defined(__rnb__MenuScene__) */
