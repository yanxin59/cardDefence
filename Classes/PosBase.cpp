//
//  PosBase.cpp
//  Chapter14_2_CardDefence01
//
//  Created by 闫鑫 on 14-6-22.
//
//

#include "PosBase.h"

PosBase::PosBase(): mEnEditorType(enTowerPos)
{
}

PosBase::~PosBase()
{
}

PosBase *PosBase::createPos(const cocos2d::Vec2 &rPos, EnumEditorType enEditorType)
{
    PosBase *tPos = new PosBase();
    if (tPos && tPos->init(rPos, enEditorType)) tPos->autorelease();
    else CC_SAFE_DELETE(tPos);
    
    return tPos;
}

bool PosBase::init(const cocos2d::Vec2 &rPos, EnumEditorType enEditorType)
{
    bool bRet = false;
    
    do
    {
        setAnchorPoint(cocos2d::Vec2(0.5f, 0.5f));
        mEnEditorType = enEditorType;
        if(mEnEditorType == enTowerPos)
            setContentSize(cocos2d::Size(mUITowerNodeRadius, mUITowerNodeRadius));
        else
            setContentSize(cocos2d::Size(mUIMonsterNodeRadius, mUIMonsterNodeRadius));
        this->setPosition(rPos);
    
        drawNode();
        
        bRet = true;
    }
    while (0);
    
    return bRet;
}


bool PosBase::isClick(const cocos2d::Vec2 &rPos)
{
    bool bRet = false;

    do
    {
        unsigned int tRadius = 0;
        switch (mEnEditorType)
        {
            case enTowerPos:
            {
                tRadius = mUITowerNodeRadius;
                break;
            }
            default:
            {
                tRadius = mUIMonsterNodeRadius;
                break;
            }
        }

       
        auto pos = getPosition();
        tRadius = tRadius / 2;
        
        auto srcPos = cocos2d::Vec2(pos.x - tRadius, pos.y - tRadius);
        auto destPos = cocos2d::Vec2(pos.x + tRadius, pos.y + tRadius);
        
        if (rPos.x > srcPos.x && rPos.x < destPos.x && rPos.y > srcPos.y && rPos.y < destPos.y)
        {
            bRet = true;
            cocos2d::log("click");
        }
        
    }
    while (0);

    return bRet;
}

void PosBase::drawNode()
{
    switch (mEnEditorType)
    {
        case enTowerPos:
            drawRect();
            break;
        default:
            drawCircle();
            break;
    }
}

void PosBase::drawCircle()
{
    auto pDrawNode = cocos2d::DrawNode::create();
    addChild(pDrawNode);
    pDrawNode->setPosition(cocos2d::Vec2(mUIMonsterNodeRadius / 2, mUIMonsterNodeRadius / 2));
    pDrawNode->setAnchorPoint(cocos2d::Vec2(0.5f, 0.5f));
    pDrawNode->drawDot(cocos2d::Vec2::ZERO, mUIMonsterNodeRadius, cocos2d::Color4F(1,0,0,0.8));
}

void PosBase::drawRect()
{
    auto pDrawNode = cocos2d::DrawNode::create();
    
    this->addChild(pDrawNode);
    
    cocos2d::Vec2 points[] =
    {
        cocos2d::Vec2(0, 0),
        cocos2d::Vec2(mUITowerNodeRadius, 0),
        cocos2d::Vec2(mUITowerNodeRadius, mUITowerNodeRadius),
        cocos2d::Vec2(0, mUITowerNodeRadius)
    };
    pDrawNode->drawPolygon(points, sizeof(points)/sizeof(points[0]), cocos2d::Color4F(1, 1, 1, 0.5), 2, cocos2d::Color4F::BLACK);
}


