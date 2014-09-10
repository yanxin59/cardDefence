//
//  PosBase.h
//  Chapter14_2_CardDefence01
//
//  Created by 闫鑫 on 14-6-22.
//
//

#ifndef __Chapter14_2_CardDefence01__PosBase__
#define __Chapter14_2_CardDefence01__PosBase__

#include "cocos2d.h"
#include "EditorPosType.h"

class PosBase: public cocos2d::Node
{
public:
    
    PosBase();
    
    virtual ~PosBase();
    
    static PosBase* createPos(const cocos2d::Vec2 &rPos = cocos2d::Vec2::ZERO, EnumEditorType enEditorType = enTowerPos);
    
    virtual bool isClick(const cocos2d::Vec2 &rPos);

protected:
    
    virtual bool init(const cocos2d::Vec2 &rPos, EnumEditorType enEditorType);
    
    virtual void drawNode();
    
    virtual void drawRect();
    
    virtual void drawCircle();
    
protected:
    
    EnumEditorType mEnEditorType;
    
    const unsigned int mUITowerNodeRadius = 60;
    
    const unsigned int mUIMonsterNodeRadius = 30;
};

#endif /* defined(__Chapter14_2_CardDefence01__PosBase__) */
