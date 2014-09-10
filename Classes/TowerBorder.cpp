//
//  TowerBorder.cpp
//  Chapter14_2_CardDefence01
//
//  Created by 闫鑫 on 14-7-18.
//
//

#include "TowerBorder.h"
#include "Hero.h"
#include "TowerOprBtns.h"
#include "Header.h"

TowerBorder::TowerBorder():mPHero(nullptr), mPTowerOprBtns(nullptr)
{
}

TowerBorder::~TowerBorder()
{
    CC_SAFE_RELEASE_NULL(mPHero);
    CC_SAFE_RELEASE_NULL(mPTowerOprBtns);
}

bool TowerBorder::init()
{
    bool bRet = false;
    
    do
    {
        CC_BREAK_IF(!Entity::init());
        createBorder();
        bRet = true;
    }
    while (0);
    
    return bRet;
}


void TowerBorder::createBorder()
{
    if(getRSprite()) getRSprite()->stopAllActions();
    
    auto sBorderPath = cocos2d::StringUtils::format("border_%d.png", mILevel);
    
    auto sprite = cocos2d::Sprite::create(sBorderPath.c_str());
    
    this->bindSprite(*sprite);
}

bool TowerBorder::isClickMe(const cocos2d::Point &rPos)
{
    bool bRet = false;
    
    do
    {
        CC_BREAK_IF(!getRSprite());
        
        auto spriteContentSize = getRSprite()->getContentSize();

        auto borderPos = getPosition();
        
        auto srcPos = cocos2d::Point(borderPos.x - spriteContentSize.width / 2, borderPos.y - spriteContentSize.height / 2);
        
        auto destPos = cocos2d::Point(borderPos.x + spriteContentSize.width / 2, borderPos.y + spriteContentSize.height / 2);
        
        if(rPos.x >= srcPos.x && rPos.x <= destPos.x && rPos.y >= srcPos.y && rPos.y <= destPos.y) bRet = true;
    }
    while (0);
    
    return bRet;
}

void TowerBorder::bindHero(Hero &rHero)
{
    CC_SAFE_RELEASE_NULL(mPHero);
    
    CC_SAFE_RETAIN(&rHero);
    
    mPHero = &rHero;
}

Hero *TowerBorder::getHero()
{
    return mPHero;
}

void TowerBorder::deleteHero()
{
    mPHero->removeFromParentAndCleanup(true);
    CC_SAFE_RELEASE_NULL(mPHero);
}

void TowerBorder::showTowerOprBtns()
{
    closeOprBtns();
    auto pOperBtns = TowerOprBtns::create(*this, *mPHero);
    pOperBtns->setPosition(cocos2d::Point::ZERO);
    
    addChild(pOperBtns);
    CC_SAFE_RETAIN(pOperBtns);
    mPTowerOprBtns = pOperBtns;
}

void TowerBorder::closeOprBtns()
{
    if(mPTowerOprBtns)
    {
        mPTowerOprBtns->deleteMe();
        CC_SAFE_RELEASE_NULL(mPTowerOprBtns);
    }
}
