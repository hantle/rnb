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
    
    //    http://www.cocos2d-x.org/wiki/TileMap
//    // creating tmx node
//    auto tilemap = TMXTiledMap::create("TileMap.tmx");
//    tilemap->getLayer("background");
//    this->addChild(tilemap);
//    for (const auto& child : tilemap->getChildren()) {
//        static_cast<SpriteBatchNode*>(child)->getTexture()->setAntiAliasTexParameters();
//    }
//    // get/add/delete/modify a tile
//    auto tileLayer = tilemap->getLayer("background");
//    auto tile = tileLayer->getTileAt(Vec2(1, 1));
//    unsigned int gid = tileLayer->getTileGIDAt(Vec2(1, 1));
//    tileLayer->setTileGID(gid, Vec2(3, 3));
//    tileLayer->removeTileAt(Vec2(5, 5));
//    // iterate a layer
//    unsigned int newGid = 1;
//    Size s = tileLayer->getLayerSize();
//    for (int x = 0; x < s.width; ++x)
//    {
//        for (int y = 0; y < s.height; ++y)
//        {
//            tileLayer->setTileGID(newGid, Vec2(x, y));
//        }
//    }
    
    
    
    for (int i = 0; i < 10; i++) {
        LayerColor *backgroundTile = LayerColor::create(Color4B::GRAY, kTILESIZE, kTILESIZE);
        LayerColor *frontTile = LayerColor::create(Color4B::BLUE, kTILESIZE-4, kTILESIZE-4);
        backgroundTile->setPosition(Point(25 + 50*i, 25 + 50*i));
        frontTile->setPosition(Point(25 + 50*i+2, 25 + 50*i+2));
        this->addChild(backgroundTile);
        this->addChild(frontTile);
    }
    mainLayer->addChild(this);
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
