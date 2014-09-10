//
//  BulletBase.cpp
//  Chapter14_2_CardDefence01
//
//  Created by 闫鑫 on 14-7-22.
//
//

#include "BulletBase.h"
#include "Entity.h"

BulletBase::BulletBase():mBIsUsed(false), mPAim(nullptr), mISpeed(SPEED_NORMAL), mIAtkValue(1), mBIsArrive(false)
{
}

BulletBase::~BulletBase()
{
    CC_SAFE_RELEASE_NULL(mPAim);
}

void BulletBase::setUsed(const bool &rBIsUsed)
{
    mBIsUsed = rBIsUsed;
    setVisible(mBIsUsed);
}

bool BulletBase::isUsed()
{
    return mBIsUsed;
}

void BulletBase::lockAmi(Entity &rEntity)
{
    if(&rEntity)
    {
        CC_SAFE_RELEASE_NULL(mPAim);
        CC_SAFE_RETAIN(&rEntity);

        mPAim = &rEntity;
        onLockAim(*mPAim);
    }
}

Entity *BulletBase::getAim()
{
    return mPAim;
}

bool BulletBase::isArrive()
{
    return mBIsArrive;
}

