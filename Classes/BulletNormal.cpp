//
//  BulletNormal.cpp
//  Chapter14_2_CardDefence01
//
//  Created by 闫鑫 on 14-7-22.
//
//

#include "BulletNormal.h"
#include "GloblaDefine.h"
#include "Entity.h"

BulletNormal::BulletNormal()
{
    mISpeed = SPEED_NORMAL;
}

BulletNormal::~BulletNormal()
{
}


void BulletNormal::onLockAim(Entity &rEntity)
{
    mBIsArrive = false;
    
    auto pMoveTo = cocos2d::MoveTo::create(0.2f, rEntity.getPosition());
    auto pMoveEnd = cocos2d::CallFunc::create(CC_CALLBACK_0(BulletNormal::moveEnd, this));
    auto pActions = cocos2d::Sequence::create(pMoveTo, pMoveEnd, NULL);
    
    runAction(pActions);
}

bool BulletNormal::init()
{
    bool bRet = false;
    do
    {
        CC_BREAK_IF(!BulletBase::init());
        
        auto pSprite = cocos2d::Sprite::create(PATH_BULLET_NOR);
        
        bindSprite(*pSprite);
        
        bRet = true;
    }
    while (0);

    return bRet;
}

void BulletNormal::moveEnd()
{
    mBIsArrive = true;
}

