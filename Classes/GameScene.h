//
//  GameScene.h
//  rnb
//
//  Created by Macbook on 2015. 3. 28..
//
//

#ifndef __rnb__GameScene__
#define __rnb__GameScene__

#include "cocos2d.h"
#include "Player.h"
#include "Stage.h"
#include "RhythmEngine.h"

class GameScene : public cocos2d::Layer
{
private:
    RhythmEngine *rhythm;
    bool started;

    void countDown(float dt);
    void start(); // start after 3,2,1 count

    void removeNode(Node *node);

public:
    // there's no 'id' in cpp, so we recommend returning the class instance pointer
    static cocos2d::Scene* createScene();
    
    // Here's a difference. Method 'init' in cocos2d-x returns bool, instead of returning 'id' in cocos2d-iphone
    virtual bool init();
    
    // a selector callback
//    void menuCloseCallback(cocos2d::Ref* pSender);
    
    Player *player;
    Stage *stage;
    
    void update(float dt);
    
    bool onTouchBegan(cocos2d::Touch *touch, cocos2d::Event *unused_event);
    void onTouchMoved(cocos2d::Touch *touch, cocos2d::Event *unused_event);
    
    // implement the "static create()" method manually
    CREATE_FUNC(GameScene);
};

#endif /* defined(__rnb__GameScene__) */
