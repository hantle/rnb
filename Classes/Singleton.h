//
//  Singleton.h
//  rnb
//
//  Created by Macbook on 2015. 4. 15..
//
//

#ifndef __rnb__Singleton__
#define __rnb__Singleton__

#include "cocos2d.h"

USING_NS_CC;

class Singleton : public cocos2d::Node
{
private:
    Singleton();
    static Singleton* m_pInstance;
public:
    static Singleton* getInstance();
    
    Point tilePosition;
};

#endif /* defined(__rnb__Singleton__) */
