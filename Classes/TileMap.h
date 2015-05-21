//
//  TileMap.h
//  rnb
//
//  Created by Macbook on 2015. 3. 28..
//
//

#ifndef __rnb__TileMap__
#define __rnb__TileMap__

#include "cocos2d.h"
#include "ui/CocosGUI.h"

class TileMap : public cocos2d::Layer
{
public:
    TileMap(cocos2d::Layer *layer);
    void initTileMap(cocos2d::Layer *layer);
    void loadMenu();
    void loadMap(int level);
    
private:
    cocos2d::Size visibleSize;
    cocos2d::Vec2 origin;
    cocos2d::Layer *mainLayer;
};

#endif /* defined(__rnb__TileMap__) */
