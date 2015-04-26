//
//  GameScene.cpp
//  rnb
//
//  Created by Macbook on 2015. 3. 28..
//
//

#include "GameScene.h"
#include "TileMap.h"

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
        
    auto tileMap = new TileMap(this);
    tileMap->loadMap(0);
    
    rhythm = new RhythmEngine("/music/sample.mp3");
    rhythm->preLoad();

    player = new Player(this);
    player->setSpeed(92);
    // immediately start for testing
    // we need to make 3, 2, 1, count before starting

    start();
    
    auto listener = EventListenerTouchOneByOne::create();
    listener->setSwallowTouches(true);
    listener->onTouchBegan = CC_CALLBACK_2(GameScene::onTouchBegan, this);
    listener->onTouchMoved = CC_CALLBACK_2(GameScene::onTouchMoved, this);
    _eventDispatcher->addEventListenerWithSceneGraphPriority(listener, this);
    
    return true;
}

void GameScene::start()
{
    player->start();
    rhythm->play(false);
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


bool GameScene::onTouchBegan(cocos2d::Touch *touch, cocos2d::Event *unused_event){
//    player->check();
    
    //    background->removeBackground(this);
    return true;
}

void GameScene::onTouchMoved(cocos2d::Touch *touch, cocos2d::Event *event) {
    Point location = touch->getLocation();
}
