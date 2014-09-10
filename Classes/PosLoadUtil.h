//
//  PosLoadUtil.h
//  Chapter14_2_CardDefence01
//
//  Created by 闫鑫 on 14-7-5.
//
//

#ifndef __Chapter14_2_CardDefence01__PosLoadUtil__
#define __Chapter14_2_CardDefence01__PosLoadUtil__

#include "GloblaDefine.h"
#include "PosBase.h"

class PosLoadUtil
{
public:
    
    void loadPosWithFile(const char* sFileName, PosVec &rPosVec, EnumEditorType enEditorType)
    {
        cocos2d::ValueVector arr = cocos2d::FileUtils::getInstance()->getValueVectorFromFile(sFileName);
        
        int sX = 0;
        int sY = 0;
        for(const auto &value : arr)
        {
            cocos2d::ValueMap map = value.asValueMap();
            sX = map.at("x").asInt();
            sY = map.at("y").asInt();

            rPosVec.pushBack(PosBase::createPos(cocos2d::Vec2(sX, sY), enEditorType));
        }
    }
};

#endif /* defined(__Chapter14_2_CardDefence01__PosLoadUtil__) */
