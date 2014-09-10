//
//  BulletBase.h
//  Chapter14_2_CardDefence01
//
//  Created by 闫鑫 on 14-7-22.
//
//

#ifndef __Chapter14_2_CardDefence01__BulletBase__
#define __Chapter14_2_CardDefence01__BulletBase__

#include "Entity.h"
//#include "cocos2d.h"

#define SPEED_DEFAULT 10
#define SPEED_NORMAL 5

class Entity;

class BulletBase: public Entity
{
public:
    
    BulletBase();
    
    virtual ~BulletBase();
    
    //锁定攻击目标
    void lockAmi(Entity &rEntity);
    
    Entity *getAim();
    
    void setUsed(const bool &rBIsUsed);
    
    bool isUsed();
    
    bool isArrive();
    
protected:
    
    virtual void onLockAim(Entity &rEntity) = 0;
    
    bool mBIsArrive;
    
    bool mBIsUsed;
    
    Entity *mPAim;
    
    CC_SYNTHESIZE(int, mIAtkValue, iAtkValue);
    
    CC_SYNTHESIZE(int, mISpeed, iSpeed);

};

#endif /* defined(__Chapter14_2_CardDefence01__BulletBase__) */
