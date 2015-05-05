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
    speed = 0; // angle per second
    
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
    float targetRotation = playerNode->getRotation();
    int rotationRemainder = (int)targetRotation % 90;
    if (rotationRemainder > 45) {
        targetRotation = ((int)(targetRotation / 90) + 1) * 90;
    } else {
        targetRotation = (int)(targetRotation / 90) * 90;
    }
//    log("rotation : %.f ... %d ->  %.f", playerNode->getRotation(), rotationRemainder, targetRotation);
    playerNode->setRotation(targetRotation);
//    log("x, y = %f, %f", x, y);
//    playerNode->setRotation(playerNode->getRotation() + 90);
    
    Point target;
    playerNode->stopAllActions();
    if (isBlue) {
        log("isBlue");
        isBlue = false;
        
        blueDot->setPosition(Point(0, 0));
        redDot->setPosition(Point(-kRADIUS, 0));
        line->setPosition(Point(-kRADIUS, 0));
        target = Point(playerNode->getPosition().x + x * kRADIUS, playerNode->getPosition().y + y * kRADIUS);
    } else {
        log("isRed");
        isBlue = true;
        
        blueDot->setPosition(Point(kRADIUS, 0));
        redDot->setPosition(Point(0, 0));
        line->setPosition(Point(0, 0));
        target = Point(playerNode->getPosition().x - x*kRADIUS, playerNode->getPosition().y - y*kRADIUS);
    }
    
    this->start();
    
    
    // checking playerNode position to Closest map position
    // check up down left right
    int remainderX = (int)target.x % (int)kRADIUS;
    int remainderY = (int)target.y % (int)kRADIUS;
//    log("remainder : %d, %d", remainderX, remainderY);
    float closeX = (int)(target.x/kRADIUS) * kRADIUS;
    float closeY = (int)(target.y/kRADIUS) * kRADIUS;
    closeX = closeX + (remainderX > 25 ? 50 : 0);
    closeY = closeY + (remainderY > 25 ? 50 : 0);
    
    playerNode->setPosition(Point(closeX, closeY));
    
    const float dist = target.getDistance(Vec2(0, 0));
//    log("distance : %.f target : %.f, %.f", dist, closeX, closeY);
    DrawNode *dot = DrawNode::create();
    dot->drawDot(target, 2.0, Color4F::YELLOW);
    mainLayer->addChild(dot);
}

void Player::setSpeed(int bpm)
{
    // 1beat = 180 degree
    // angle / s = bpm / 60 * 180
    speed = 180.0 / bpm * 3;
}

void Player::checkPoint()
{
    const char* skillName_temp[] = {"FAILED", "BAD", "GOOD", "GREAT", "PERFECT"};
    
    auto lbPoint = Label::createWithTTF(skillName_temp[2], kMARKERFELT, 20.0);
    lbPoint->setTextColor(Color4B::YELLOW);
    lbPoint->setPosition(playerNode->getPosition());
    
    auto moveUp = MoveBy::create(1.0, Point(0, 50));
    auto fadeOut = FadeOut::create(1.0);
    auto moveAndRemove = Sequence::create(moveUp, CallFuncN::create(CC_CALLBACK_1(Player::removeNode, this)), NULL);
    lbPoint->runAction(moveAndRemove);
    lbPoint->runAction(fadeOut);
    
    mainLayer->addChild(lbPoint);
}

void Player::removeNode(Node *node)
{
    node->removeFromParent();
}