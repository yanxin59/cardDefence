//
//  MonsterPos.h
//  Chapter14_2_CardDefence01
//
//  Created by 闫鑫 on 14-7-6.
//
//

#ifndef __Chapter14_2_CardDefence01__MonsterPos__
#define __Chapter14_2_CardDefence01__MonsterPos__

#include "PosBase.h"

class Monster;
#define MONSTER_RADIUS 10

class MonsterPos: public PosBase
{
public:
    MonsterPos();
    virtual ~MonsterPos();
    
    static MonsterPos* create(cocos2d::Point pos);
    
    static MonsterPos* create(cocos2d::Point pos, bool isDebug);
    
    bool init(cocos2d::Point pos);
    
    bool init(cocos2d::Point pos, bool isDebug);
    
    void draw(cocos2d::Renderer *renderer, const cocos2d::Mat4 &transform, bool transformUpdated);
    
private:
    
    Monster *mMonster;
    
};

#endif /* defined(__Chapter14_2_CardDefence01__MonsterPos__) */
