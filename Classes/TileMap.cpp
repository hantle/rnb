//
//  TileMap.cpp
//  rnb
//
//  Created by Macbook on 2015. 3. 28..
//
//

#include "TileMap.h"
#include "Define.h"

USING_NS_CC;

TileMap::TileMap(Layer *layer)
{
    mainLayer = layer;
    visibleSize = Director::getInstance()->getVisibleSize();
    
    
    /*
     0 0 0 0 0 0 0 0 0
     0 0 0 0 0 0 0 0 0
     0 0 0 0 0 0 0 0 0
     0 0 0 0 0 0 0 0 0
     0 0 0 0 0 0 0 0 0
     0 0 0 0 0 0 0 0 0
     0 0 0 0 0 0 0 0 0
     0 0 0 0 0 0 0 0 0
     0 0 0 0 0 0 0 0 0
     0 0 0 0 0 0 0 0 0
     */
    
    for (int i = 0; i < 10; i++) {
        LayerColor *tile = LayerColor::create(Color4B::GRAY, kTILESIZE, kTILESIZE);
        tile->setPosition(Point(50*i, 50*i));
        LayerColor *tile2 = LayerColor::create(Color4B::BLUE, kTILESIZE, kTILESIZE);
        tile2->setPosition(Point(50*i+50, 50*i));
        mainLayer->addChild(tile);
        mainLayer->addChild(tile2);
    }
}

void TileMap::initTileMap(Layer *layer)
{
    
}

void TileMap::loadMenu()
{
    
}
void TileMap::loadMap(int level)
{
    
}