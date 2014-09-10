//
//  BulletManager.cpp
//  Chapter14_2_CardDefence01
//
//  Created by 闫鑫 on 14-7-22.
//


#include "BulletManager.h"
#include "BulletNormal.h"
#include "TollgateMapLayer.h"
#include "GloblaDefine.h"

BulletManager::BulletManager():mPBulletVec(nullptr)
{
}

BulletManager::~BulletManager()
{
    CC_SAFE_DELETE(mPBulletVec);
}

BulletManager *BulletManager::create()
{
    BulletManager *pBulletManager = new BulletManager();
    
    if(pBulletManager && pBulletManager->init()) pBulletManager->autorelease();
    else CC_SAFE_DELETE(pBulletManager);
    
    return pBulletManager;
}

bool BulletManager::init()
{
    bool bRet = false;
    
    do
    {
        mPBulletVec = new BulletVec();
        
        auto pParent = GlobalClient::getInstance()->getCurTollgateScene()->getChildByTag(TAG_MAP_LAYER);
        
        createBullets(*pParent);
        
        schedule(schedule_selector(BulletManager::bulletLogicCheck));
        
        bRet = true;
    }
    while (0);
    
    return bRet;
}

void BulletManager::createBullets(cocos2d::Node &rParent)
{
    for(int count = 0; count < BULLET_MAX_CACHE_NUM; ++count)
    {
        auto *pBullet = BulletNormal::create();
        pBullet->setUsed(false);
        mPBulletVec->pushBack(pBullet);
        rParent.addChild(pBullet, BULLET_LAYER_LVL);
    }
}

void BulletManager::bulletLogicCheck(float dt)
{
    if( !(mPBulletVec && mPBulletVec->size()) ) return;
    
    //对子弹集合进行遍历,获得子弹锁定的攻击对象,如果子弹已经达到说明攻击对象受到攻击
    for(auto & bulletVecIter : *mPBulletVec)
    {
        auto pAim = bulletVecIter->getAim();
        
        if(pAim)
        {
            if(bulletVecIter->isArrive())
            {
                pAim->hurtMe(bulletVecIter->getiAtkValue());
                bulletVecIter->setUsed(false);
            }
        }
    }
}

void BulletManager::onExit()
{
    unscheduleAllSelectors();
    Node::onExit();
}


BulletBase *BulletManager::getAnyUnUsedBullet()
{
    for(auto & bulletVecIter : *mPBulletVec)
    {
        if( bulletVecIter && !bulletVecIter->isUsed() )
        {
            bulletVecIter->setUsed(true);
            return bulletVecIter;
        }
    }
    return nullptr;
}
