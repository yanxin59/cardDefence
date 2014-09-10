
//
//  TowerPos.cpp
//  Chapter14_2_CardDefence01
//
//  Created by 闫鑫 on 14-6-22.
//
//

#include "TowerPos.h"
#include <memory>

TowerPos::TowerPos()
{
    mPos = cocos2d::Point(0, 0);
    
//    isDebug = false;
}

TowerPos::~TowerPos(){}

TowerPos *TowerPos::create(cocos2d::Point pos)
{
    TowerPos *tPos = new TowerPos();
    
    if (tPos && tPos->init(pos))
    {
        tPos->autorelease();
    }
    else
    {
        CC_SAFE_DELETE(tPos);
    }
    return tPos;
}

TowerPos *TowerPos::create(cocos2d::Point pos, bool isDebug)
{
    TowerPos *tPos = new TowerPos();
    
    if(tPos && tPos->init(pos, isDebug))
    {
        tPos->autorelease();
    }
    else
    {
        CC_SAFE_DELETE(tPos);
    }
    return tPos;
}

bool TowerPos::init(cocos2d::Point pos)
{
    bool bRet = false;
    
    if (!PosBase::init(pos))
    {
        return bRet;
    }
    
    bRet = true;
    
    return bRet;
}

bool TowerPos::init(cocos2d::Point pos, bool isDebug)
{
    bool bRet = false;
    
    if (!PosBase::init(pos, isDebug))
        return bRet;
    bRet = true;
    
    return bRet;
}

void TowerPos::draw(cocos2d::Renderer *renderer, const cocos2d::Mat4 &transform, bool transformUpdated)
{
    if (isDebug) {
        glLineWidth(5);
//        Node::draw(renderer,transform,transformUpdated);
        cocos2d::Point srcPos = cocos2d::Point(mPos.x - RADIUS, mPos.y + RADIUS);
        
        cocos2d::Point destPos = cocos2d::Point(mPos.x + RADIUS, mPos.y - RADIUS);
        
        cocos2d::DrawPrimitives::drawRect(srcPos, destPos);
//        auto t = cocos2d::DrawNode::create();

//        t->drawPolygon(cocos2d::V>), 4, cocos2d::Color4F(0, 0, 0, 0) , 5, cocos2d::Color4F(1, 0, 0, 1));
//        t->drawSegment(srcPos, destPos, 20, cocos2d::Color4F(1, 0, 0, 1));
        glLineWidth(1);
    }
}

