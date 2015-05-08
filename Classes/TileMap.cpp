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
        LayerColor *backgroundTile = LayerColor::create(Color4B::GRAY, kTILESIZE, kTILESIZE);
        LayerColor *frontTile = LayerColor::create(Color4B::BLUE, kTILESIZE-4, kTILESIZE-4);
        backgroundTile->setPosition(Point(25 + 50*i, 25 + 50*i));
        frontTile->setPosition(Point(25 + 50*i+2, 25 + 50*i+2));
        mainLayer->addChild(backgroundTile);
        mainLayer->addChild(frontTile);
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
