//
//  GameScene.cpp
//  rnb
//
//  Created by Macbook on 2015. 3. 28..
//
//

#include "GameScene.h"
#include "Define.h"

USING_NS_CC;

Scene* GameScene::createScene()
{
    // 'scene' is an autorelease object
    auto scene = Scene::create();
    
    // 'layer' is an autorelease object
    auto layer = GameScene::create();
    
    // add layer as a child to scene
    scene->addChild(layer);
    
    // return the scene
    return scene;
}

// on "init" you need to initialize your instance
bool GameScene::init()
{
    //////////////////////////////
    // 1. super init first
    if ( !Layer::init() )
    {
        return false;
    }
    
    Size visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();

    stage = new Stage("", this);
    rhythm = stage->getRhythmEngine();
    
    player = new Player(stage->map);
    player->setSpeed(3.0);
    player->start();
    //player->setSpeed(stage->getBPM());

    started = false;
    schedule(schedule_selector(GameScene::countDown), 1.0, 3, 0.0);
    
    auto listener = EventListenerTouchOneByOne::create();
    listener->setSwallowTouches(true);
    listener->onTouchBegan = CC_CALLBACK_2(GameScene::onTouchBegan, this);
    listener->onTouchMoved = CC_CALLBACK_2(GameScene::onTouchMoved, this);
    _eventDispatcher->addEventListenerWithSceneGraphPriority(listener, this);
    
    return true;
}

void GameScene::update(float dt) {
    player->check();
}

void GameScene::start()
{
    started = true;
    schedule(schedule_selector(GameScene::update), 1.0, -1, 2.0);
}

void GameScene::countDown(float dt) {
    static int count = 3;

    Label *countLabel;
    if(count > 0 ) {
        countLabel = Label::createWithTTF(CCString::createWithFormat("%d", count)->getCString(),
                kMARKERFELT, 60.0);
    } else {
        countLabel = Label::createWithTTF("Go!!!", kMARKERFELT, 60.0);
        start();
    }
    countLabel->setPosition(200, 200);
    auto fadeOutAndRemove = Sequence::create(FadeOut::create(1.0), 
                CallFuncN::create(CC_CALLBACK_1(GameScene::removeNode, this)), NULL);
    countLabel->runAction(fadeOutAndRemove);
    this->addChild(countLabel);

    count--;
}

void GameScene::removeNode(Node *node) 
{
    node->removeFromParent();
}

//void GameScene::menuCloseCallback(Ref* pSender)
//{
//#if (CC_TARGET_PLATFORM == CC_PLATFORM_WP8) || (CC_TARGET_PLATFORM == CC_PLATFORM_WINRT)
//    MessageBox("You pressed the close button. Windows Store Apps do not implement a close button.","Alert");
//    return;
//#endif
//    
//    Director::getInstance()->end();
//    
//#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
//    exit(0);
//#endif
//}


bool GameScene::onTouchBegan(cocos2d::Touch *touch, cocos2d::Event *unused_event)
{
    if(started)
    {
        //player->check();
        rhythm->playEffect();

        //if(!rhythm->isPlayingBGM()) {
        if(rhythm->isPauseBGM()) {
            rhythm->playBGM(false);
            // start world!!!
            stage->map->runAction(RepeatForever::create(MoveBy::create(1, Vec2(-10, 0))));
        }
        
        player->checkPoint(Point(200, 100));
    }
    return true;
}

void GameScene::onTouchMoved(cocos2d::Touch *touch, cocos2d::Event *event) {
    Point location = touch->getLocation();
}
