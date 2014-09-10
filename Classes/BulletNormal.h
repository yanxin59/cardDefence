//
//  BulletNormal.h
//  Chapter14_2_CardDefence01
//
//  Created by 闫鑫 on 14-7-22.
//
//

#ifndef __Chapter14_2_CardDefence01__BulletNormal__
#define __Chapter14_2_CardDefence01__BulletNormal__

#include "BulletBase.h"

class BulletNormal: public BulletBase
{
public:
    
    BulletNormal();
    
    virtual ~BulletNormal();
    
    CREATE_FUNC(BulletNormal);
    
protected:
    
    virtual bool init();
    
    virtual void onLockAim(Entity &rEntity);
    
private:
    
    void moveEnd();
};

#endif /* defined(__Chapter14_2_CardDefence01__BulletNormal__) */
