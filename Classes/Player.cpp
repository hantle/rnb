//
//  Player.cpp
//  rnb
//
//  Created by Macbook on 2015. 3. 28..
//
//

#include "Player.h"
#include "Define.h"

USING_NS_CC;

Player::Player(Layer *layer)
{
    visibleSize = Director::getInstance()->getVisibleSize();
    mainLayer = layer;
    speed = 90; // angle per second
    
    auto blueDot = DrawNode::create();
    auto redDot = DrawNode::create();
    auto line = DrawNode::create();
    blueDot->drawDot(Point(-25, 0), 20, Color4F::RED);
    redDot->drawDot(Point(25, 0), 20, Color4F::BLUE);
    line->drawLine(Point(-25, 0), Point(25, 0), Color4F::MAGENTA);
    
    playerNode = Layer::create();
    playerNode->setAnchorPoint(Point(0, 0));
    playerNode->setPosition(Point(200, 100));
    playerNode->addChild(blueDot);
    playerNode->addChild(redDot);
    playerNode->addChild(line);
    
    mainLayer->addChild(playerNode);
    
    isBlue = true;
}

void Player::initPlayer(Layer *layer)
{
    
}
void Player::moveBy(float duration, Point location) {
    auto moveByAction = MoveBy::create(duration, location);
    playerNode->runAction(moveByAction);
}
void Player::moveTo(float duration, Point location) {
    auto moveToAction = MoveTo::create(duration, location);
    playerNode->runAction(moveToAction);
}
void Player::setPosition(Point location) {
    playerNode->setPosition(location);
}

void Player::start()
{
    log("Player::start");
    auto rotateAction = RotateBy::create(1, speed);
    auto rotateForever = RepeatForever::create(rotateAction);
    this->playerNode->runAction(rotateForever);
}

void Player::check()
{
    if (isBlue) {
        isBlue = false;
    } else {
        isBlue = true;
    }
}

void Player::setSpeed(int bpm)
{
    // 1beat = 180 degree
    // angle / s = bpm / 60 * 180
    speed = bpm * 3;
}
