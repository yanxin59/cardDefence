//
//  BulletManager.h
//  Chapter14_2_CardDefence01
//
//  Created by 闫鑫 on 14-7-22.
//
//

#ifndef __Chapter14_2_CardDefence01__BulletManager__
#define __Chapter14_2_CardDefence01__BulletManager__

#include "GloblaDefine.h"

class BulletManager: public cocos2d::Node
{
public:
    
    BulletManager();
    
    virtual ~BulletManager();
    
    static BulletManager *create();
    
    BulletBase *getAnyUnUsedBullet();
    
protected:
    
    virtual bool init();
    
    virtual void onExit()override;
    
    void createBullets(cocos2d::Node &rParent);
    
    void bulletLogicCheck(float dt);
    
private:
    
    BulletVec *mPBulletVec ;

};

#endif /* defined(__Chapter14_2_CardDefence01__BulletManager__) */
