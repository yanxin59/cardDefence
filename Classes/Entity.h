//
//  Entity.h
//  Chapter14_2_CardDefence01
//
//  Created by 闫鑫 on 14-7-18.
//
//

#ifndef __Chapter14_2_CardDefence01__Entity__
#define __Chapter14_2_CardDefence01__Entity__

#include "GloblaDefine.h"

class Entity:public cocos2d::Node
{
public:
    
    Entity();
    
    virtual ~Entity();
    
    void bindSprite(cocos2d::Sprite &rSprite);
    
    cocos2d::Sprite *getRSprite();
    
    virtual void hurtMe(const int &rIHurtValue);
    
    virtual bool isDead();
    
    cocos2d::Rect boundingBox();
    
    virtual void onDead();
    
protected:
    
    virtual void onExit()override;
    
    virtual void onBindSprite();
    
    virtual void onHurt(const int &rIHurtValue);
    
protected:
    
    cocos2d::Sprite *mPSprite;
    
    bool mBIsDead;
    
    CC_PROTECTED(int, mIId, iId);
    
    CC_PROTECTED(int, mIModelId, iModelId)
    
    CC_PROTECTED(int, mIHp, iHp)
    
    CC_PROTECTED(int, mIDefense, iDefense)
    
    CC_PROTECTED(int, mISpeed, iSpeed)
    
    CC_PROTECTED(int, mILevel, iLevel)
    
    CC_PROTECTED(std::string, mSName, sName)
};



#endif /* defined(__Chapter14_2_CardDefence01__Entity__) */
