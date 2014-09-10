//
//  HeroManager.cpp
//  Chapter14_2_CardDefence01
//
//  Created by 闫鑫 on 14-7-18.
//
//

#include "HeroManager.h"
#include "PosLoadUtil.h"
#include "TowerBorder.h"
#include "Hero.h"
#include "PosBase.h"

HeroManager::HeroManager():mPTowerBorderVec(nullptr), mPTowerPosVec(nullptr)
{
}

HeroManager::~HeroManager()
{
    CC_SAFE_DELETE(mPTowerBorderVec);
    CC_SAFE_DELETE(mPTowerPosVec);
}

HeroManager *HeroManager::createWithLevel(const unsigned int &rICurLevel)
{
    HeroManager *pHeroManager = new HeroManager();
    
    if(pHeroManager && pHeroManager->initWithLevel(rICurLevel)) pHeroManager->autorelease();
    else CC_SAFE_DELETE(pHeroManager);
    
    return pHeroManager;
}

bool HeroManager::initWithLevel(const unsigned int &rICurLevel)
{
    bool bRet = false;
    do
    {
        CC_BREAK_IF(!Layer::init());
        
        mPTowerBorderVec = new TowerBorderVec();
        
        mPTowerPosVec = new PosVec();
        
        mUICurLevel = rICurLevel;
        
        bRet = true;
    }
    while (0);

    return bRet;
}

void HeroManager::createTowerBorder(const unsigned int &rICurLevel)
{
    for(const auto & rTowerPosVecIter : *mPTowerPosVec)
    {
        if(rTowerPosVecIter)
        {
            auto towerPos = rTowerPosVecIter->getPosition();
            auto border = TowerBorder::create();
            border->setPosition(cocos2d::Vec2(towerPos.x, towerPos.y));
            mPTowerBorderVec->pushBack(border);
            addChild(border);
        }
    }
}

TowerBorder *HeroManager::findClickTowerBorder(const cocos2d::Point &rPos)
{
    for(auto & towerBorderVecIter : *mPTowerBorderVec)
    {
        if(towerBorderVecIter)
            if(towerBorderVecIter->isClickMe(rPos))
                return towerBorderVecIter;
    }
    
    return nullptr;
}

void HeroManager::onEnter()
{
    Layer::onEnter();
    
    auto sTowerPosPath = cocos2d::StringUtils::format("%stowerPos_level_%d.plist", cocos2d::FileUtils::getInstance()->getWritablePath().c_str(), mUICurLevel);
//    auto sTowerPosPath = cocos2d::StringUtils::format("towerPos_level_%d.plist", mUICurLevel);
    PosLoadUtil tPosLoadUtil;
    
    tPosLoadUtil.loadPosWithFile(sTowerPosPath.c_str(), *mPTowerPosVec, enTowerPos);
    
    createTowerBorder(mUICurLevel);
    
    registeTouchDispatcher();
}

void HeroManager::onExit()
{
    Layer::onExit();
}

void HeroManager::registeTouchDispatcher()
{
    auto dispatcher = cocos2d::Director::getInstance()->getEventDispatcher();
    
    auto listener = cocos2d::EventListenerTouchOneByOne::create();
    
    listener->setSwallowTouches(false);
    
    listener->onTouchBegan = [this](cocos2d::Touch *pTouch, cocos2d::Event *pEvent)
    {
        return true;
    };

    listener->onTouchEnded = [this](cocos2d::Touch *pTouch, cocos2d::Event *pEvent)
    {
        auto pos = cocos2d::Director::getInstance()->convertToGL(pTouch->getLocationInView());
        
        auto clickBorder = findClickTowerBorder(pos);
        
        if(!clickBorder) return;
        
        if(!clickBorder->getHero())
        {
            auto pHero = Hero::createFromCsvById(1);
            pHero->setPosition(clickBorder->getPosition());
            addChild(pHero, 10);
            clickBorder->bindHero(*pHero);
        }
        else
        {
            clickBorder->showTowerOprBtns();
        }
    };
    
    dispatcher->addEventListenerWithSceneGraphPriority(listener, this);
}

