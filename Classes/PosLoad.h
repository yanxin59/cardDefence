//
//  PosLoad.h
//  Chapter14_2_CardDefence01
//
//  Created by 闫鑫 on 14-7-19.
//
//

#ifndef __Chapter14_2_CardDefence01__PosLoad__
#define __Chapter14_2_CardDefence01__PosLoad__

#include <iostream>
#include <vector>
#include "TowerPos.h"
#include "MonsterPos.h"

namespace YxLoadPosUtil
{
    template <typename T>
    void loadPosWithFile(const char* sFileName,  T &vec, int iLevel, bool isDebug);
};

template <typename T>
void YxLoadPosUtil::loadPosWithFile(const char* sFileName, T &vec, int iLevel, bool isDebug)
{
    cocos2d::__String *sTowerPosPath = cocos2d::__String::createWithFormat("%s%s", cocos2d::FileUtils::getInstance()->getWritablePath().c_str(), sFileName);
    
    
    //    std::vector<T> *pPosVec = new std::vector<T>();
    cocos2d::ValueVector arr = cocos2d::FileUtils::getInstance()->getValueVectorFromFile(sTowerPosPath->getCString());
    
    //    log("%lu", arr.size());
    int sX = 0;
    int sY = 0;
    for(const auto &value : arr)
    {
        cocos2d::ValueMap map = value.asValueMap();
        sX = map.at("x").asInt();
        sY = map.at("y").asInt();
        //        log("x: %d, y: %d", sX, sY);
        auto pos = T::create(cocos2d::Point(sX, sY), true);
        pos->retain();
        //        container->addChild(pos, iLevel);
        vec->push_back(pos);
    }
    
    //    return pPosVec;
}
#endif /* defined(__Chapter14_2_CardDefence01__PosLoad__) */
