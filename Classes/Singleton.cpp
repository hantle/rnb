//
//  Singleton.cpp
//  rnb
//
//  Created by Macbook on 2015. 4. 15..
//
//

#include "Singleton.h"

Singleton* Singleton::m_pInstance = NULL;
Singleton* Singleton::getInstance() {
    if (!m_pInstance) {
        m_pInstance = new Singleton;
    }
    return m_pInstance;
}

Singleton::Singleton()
{
    tilePosition = Point(0, 0);
}