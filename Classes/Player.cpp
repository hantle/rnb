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
    
    // draw player
    blueDot = DrawNode::create();
    redDot = DrawNode::create();
    line = DrawNode::create();
    blueDot->drawDot(Point(0, 0), 20, Color4F::RED);
    redDot->drawDot(Point(0, 0), 20, Color4F::BLUE);
    blueDot->setPosition(Point(kRADIUS, 0));
    redDot->setPosition(Point(0, 0));
    line->drawLine(Point(0, 0), Point(kRADIUS, 0), Color4F::MAGENTA);
    
    // draw player on layer
    playerNode = Layer::create();
    playerNode->setContentSize(Size(kRADIUS, 0));
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
    auto rotateAction = RotateBy::create(1, speed);
    auto rotateForever = RepeatForever::create(rotateAction);
    playerNode->runAction(rotateForever);
//    playerNode->setRotation(90);
}

void Player::check()
{
    float x = cos(CC_DEGREES_TO_RADIANS(playerNode->getRotation()));
    float y = sin(CC_DEGREES_TO_RADIANS(-playerNode->getRotation()));
//    log("position: %.f, %.f", playerNode->getPosition().x, playerNode->getPosition().y);
//    log("rotation : %.f", playerNode->getRotation());
//    log("x, y = %f, %f", x, y);
//    playerNode->setRotation(playerNode->getRotation() + 90);
    
    playerNode->stopAllActions();
    if (isBlue) {
        isBlue = false;
        
        blueDot->setPosition(Point(0, 0));
        redDot->setPosition(Point(-kRADIUS, 0));
        line->setPosition(Point(-kRADIUS, 0));
        
        playerNode->setPosition(Point(playerNode->getPosition().x + x*kRADIUS, playerNode->getPosition().y + y*kRADIUS));
        this->start();
    } else {
        isBlue = true;
        
        blueDot->setPosition(Point(kRADIUS, 0));
        redDot->setPosition(Point(0, 0));
        line->setPosition(Point(0, 0));
        
        playerNode->setPosition(Point(playerNode->getPosition().x - x*kRADIUS, playerNode->getPosition().y - y*kRADIUS));
        this->start();
    }
}

void Player::setSpeed(int bpm)
{
    // 1beat = 180 degree
    // angle / s = bpm / 60 * 180
    speed = bpm * 3;
}
