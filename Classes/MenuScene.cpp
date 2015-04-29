//
//  MenuScene.cpp
//  rnb
//
//  Created by Macbook on 2015. 3. 28..
//
//

#include "MenuScene.h"
#include "TileMap.h"
#include "Player.h"
#include "Define.h"
#include "RhythmEngine.h"

USING_NS_CC;

Scene* MenuScene::createScene()
{
    // 'scene' is an autorelease object
    auto scene = Scene::create();
    
    // 'layer' is an autorelease object
    auto layer = MenuScene::create();
    
    // add layer as a child to scene
    scene->addChild(layer);
    
    // return the scene
    return scene;
}

// on "init" you need to initialize your instance
bool MenuScene::init()
{
    //////////////////////////////
    // 1. super init first
    if ( !Layer::init() )
    {
        return false;
    }
    
    Size visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();
    
    
    auto listener = EventListenerTouchOneByOne::create();
    listener->setSwallowTouches(true);
    listener->onTouchBegan = CC_CALLBACK_2(MenuScene::onTouchBegan, this);
    listener->onTouchMoved = CC_CALLBACK_2(MenuScene::onTouchMoved, this);
    _eventDispatcher->addEventListenerWithSceneGraphPriority(listener, this);
    
    
    
    auto tileMap = new TileMap(this);
    tileMap->loadMenu();
    
    auto rhythm = new RhythmEngine("music/sample.mp3");
    
    player = new Player(this);
    player->setSpeed(92);
    player->start();
    rhythm->play(false);
    
    schedule(schedule_selector(MenuScene::update), 90.0/276.0);
    
    return true;
}
void MenuScene::update(float dt) {
    player->check();
}
bool MenuScene::onTouchBegan(cocos2d::Touch *touch, cocos2d::Event *unused_event){
//    player->check();
    
    //    background->removeBackground(this);
    return true;
}

void MenuScene::onTouchMoved(cocos2d::Touch *touch, cocos2d::Event *event) {
    Point location = touch->getLocation();
}
