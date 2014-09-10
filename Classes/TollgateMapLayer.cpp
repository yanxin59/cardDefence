//
//  TollgateMapLayer.cpp
//  Chapter14_2_CardDefence01
//
//  Created by 闫鑫 on 14-7-18.
//
//

#include "TollgateMapLayer.h"
#include "HeroManager.h"
#include "MonsterManager.h"
#include "Monster.h"
#include "PosBase.h"

TollgateMapLayer::TollgateMapLayer(const unsigned int &rUILevel):mPHeroMgr(nullptr), mPMonsterMgr(nullptr), mICurLevel(rUILevel)
{
}

TollgateMapLayer::~TollgateMapLayer()
{
    CC_SAFE_RELEASE_NULL(mPMonsterMgr);
    CC_SAFE_RELEASE_NULL(mPHeroMgr);
}

TollgateMapLayer *TollgateMapLayer::create(const unsigned int &rUILevel)
{
    auto pTollgateMapLayer = new TollgateMapLayer(rUILevel);
    
    if(pTollgateMapLayer && pTollgateMapLayer->init()) pTollgateMapLayer->autorelease();
    else CC_SAFE_DELETE(pTollgateMapLayer);
    
    return pTollgateMapLayer;
}

bool TollgateMapLayer::init()
{
    bool bRet = false;
    do
    {
        loadMap();
        
        bRet = true;
    }
    while (0);

    return bRet;
}

void TollgateMapLayer::loadMap()
{
    auto visibleSize = cocos2d::Director::getInstance()->getVisibleSize();
    
    auto pMap = cocos2d::Sprite::create(cocos2d::StringUtils::format("level_%d.jpg", mICurLevel).c_str());
    
    pMap->setPosition(cocos2d::Point(visibleSize.width / 2, visibleSize.height / 2));
    
    this->addChild(pMap);
}

MonsterVec *TollgateMapLayer::getMonsterVec()
{
    return mPMonsterMgr->getMonsterVec();
}

void TollgateMapLayer::createHome()
{
    auto pPos = (nullptr != mPMonsterMgr) ? mPMonsterMgr->getMonsterEndPos() : nullptr;
    
    auto pHome = cocos2d::Sprite::create("home.png");
    
    pHome->setPosition(pPos ? pPos->getPosition() : cocos2d::Vec2::ZERO);
    
    auto pRotateBy = cocos2d::RotateBy::create(15.0f, 360, 360);
    
    auto pRepeat = cocos2d::RepeatForever::create(pRotateBy);
    
    pHome->runAction(pRepeat);
    
    addChild(pHome, HOME_LAYER_LVL);
}

void TollgateMapLayer::createStartPoint()
{
    auto pPos = (nullptr != mPMonsterMgr) ? mPMonsterMgr->getMonsterStartPos() : nullptr;
    
    auto pStart = cocos2d::Sprite::create("start.png");
    
    pStart->setPosition(pPos ? pPos->getPosition() : cocos2d::Vec2::ZERO);
    
    auto pRotateBy = cocos2d::RotateBy::create(15.0f, 360, 360);
    
    auto pRepeat = cocos2d::RepeatForever::create(pRotateBy);
    
    pStart->runAction(pRepeat);
    
    addChild(pStart, HOME_LAYER_LVL);
}


void TollgateMapLayer::sendStartInfo()
{
    std::map<std::string ,int> startInfo;
    
    startInfo.insert(std::make_pair("towerSoulAltNum", 0));
    startInfo.insert(std::make_pair("magicNum", 100));
    startInfo.insert(std::make_pair("notShowMonsterNum", mPMonsterMgr->getNotShowMonsterCount()));
    
    NOTIFY->postNotification("TowerSoulCountChange",reinterpret_cast<cocos2d::Ref*>(&startInfo));
    NOTIFY->postNotification("MonsterCountChange", reinterpret_cast<cocos2d::Ref*>(&startInfo));
    NOTIFY->postNotification("MagicCountChange", reinterpret_cast<cocos2d::Ref*>(&startInfo));
}

void TollgateMapLayer::onEnter()
{
    Layer::onEnter();
    mPMonsterMgr = MonsterManager::createWithLevel(mICurLevel);
    mPMonsterMgr->retain();
    
    mPHeroMgr = HeroManager::createWithLevel(mICurLevel);
    mPHeroMgr->retain();
    
    addChild(mPMonsterMgr, MONSTER_LAYER_LVL);
    addChild(mPHeroMgr, HERO_LAYER_LVL);
    
    createHome();
    
    createStartPoint();
    
    sendStartInfo();

}

void TollgateMapLayer::onExit()
{
    Layer::onExit();
    
//    unscheduleAllSelectors();
    
    removeAllChildrenWithCleanup(true);
}


