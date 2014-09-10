//
//  MonsterPos.cpp
//  Chapter14_2_CardDefence01
//
//  Created by 闫鑫 on 14-7-6.
//
//

#include "MonsterPos.h"

MonsterPos::MonsterPos()
{
    mPos = cocos2d::Point::ZERO;
    
//    isDebug = false;
}

MonsterPos::~MonsterPos()
{
}

MonsterPos* MonsterPos::create(cocos2d::Point pos)
{
    MonsterPos *tPos = new MonsterPos();
    
    if (tPos && tPos->init(pos))    tPos->autorelease();
    else    CC_SAFE_DELETE(tPos);
    
    return tPos;
}

MonsterPos* MonsterPos::create(cocos2d::Point pos, bool isDebug)
{
    MonsterPos* tPos = new MonsterPos();
    
    if (tPos && tPos->init(pos, isDebug)) tPos->autorelease();
    else CC_SAFE_DELETE(tPos);
    return tPos;
}

bool MonsterPos::init(cocos2d::Point pos)
{
    setPos(pos);
    return true;
}

bool MonsterPos::init(cocos2d::Point pos, bool isDebug)
{
    this->isDebug = isDebug;
    return init(pos);
}

void MonsterPos::draw(cocos2d::Renderer *renderer, const cocos2d::Mat4 &transform, bool transformUpdated)
{
    if (isDebug) {
        glLineWidth(4);
        cocos2d::DrawPrimitives::drawCircle(mPos, MONSTER_RADIUS, 360, 20, false);
        glLineWidth(1);
    }
}
