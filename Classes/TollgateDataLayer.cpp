//
//  TollgateDataLayer.cpp
//  Chapter14_2_CardDefence01
//
//  Created by 闫鑫 on 14-7-24.
//
//

#include "TollgateDataLayer.h"
#include "MMWinManager.h"
#include "MMWinDesktop.h"
#include "MMLabel.h"
#include "Header.h"
#include "SceneManager.h"

TollgateDataLayer::TollgateDataLayer():mIMagicNum(0), mIMonsterNum(0), mITowerSoulNum(0), mPMagicLabel(nullptr), mPMonsterLabel(nullptr), mPTowerSoulLabel(nullptr), mPWinDesktop(nullptr)
{
}

TollgateDataLayer::~TollgateDataLayer()
{
    CC_SAFE_RELEASE_NULL(mPTowerSoulLabel);
    
    CC_SAFE_RELEASE_NULL(mPMonsterLabel);
    
    CC_SAFE_RELEASE_NULL(mPMagicLabel);
    
    CC_SAFE_RELEASE_NULL(mPWinDesktop);
}

bool TollgateDataLayer::init()
{
    bool bRet = false;
    do
    {
        mPWinDesktop = MMWinManager::getInstance()->getDesktopFromXml(PATH_UI_TollgateProMsgWin);
        mPWinDesktop->retain();
        addChild(mPWinDesktop);
        
        mPTowerSoulLabel = dynamic_cast<MMLabel*>(mPWinDesktop->getWinByDes("tollgateSoulCountLab"));
        mPTowerSoulLabel->retain();
        
        mPMagicLabel = dynamic_cast<MMLabel*>(mPWinDesktop->getWinByDes("magicCountLab"));
        mPMagicLabel->retain();
        
        mPMonsterLabel = dynamic_cast<MMLabel*>(mPWinDesktop->getWinByDes("monsterCountLab"));
        mPMonsterLabel->retain();
        
        NOTIFY->addObserver(this, callfuncO_selector(TollgateDataLayer::recvRefreshMagicNum), "MagicCountChange", nullptr);
        NOTIFY->addObserver(this, callfuncO_selector(TollgateDataLayer::recvRefreshMonsterNum), "MonsterCountChange", nullptr);
        NOTIFY->addObserver(this, callfuncO_selector(TollgateDataLayer::recvRefreshTowerSoulNum), "TowerSoulCountChange", nullptr);
        NOTIFY->addObserver(this, callfuncO_selector(TollgateDataLayer::recvMonsterDead), "MonsterDead", nullptr);
        NOTIFY->addObserver(this, callfuncO_selector(TollgateDataLayer::recvAllMonsterDead), "AllMonsterDead", nullptr);
        
        bRet = true;
    }
    while (0);
    return bRet;
}

void TollgateDataLayer::recvRefreshMagicNum(cocos2d::Ref *pRef)
{
    if(!pRef) return;
    
    auto pDict = reinterpret_cast< std::map<std::string, int> *>(pRef);
    
    auto iterMagicNum = pDict->find("magicNum");
    
    if(pDict->end() != iterMagicNum) mIMagicNum += iterMagicNum->second;
    
    iterMagicNum = pDict->find("MoveEnd");
    
    if(pDict->end() != iterMagicNum) mIMagicNum += iterMagicNum->second;
    
    mPMagicLabel->setsText(mIMagicNum);
}

void TollgateDataLayer::recvRefreshMonsterNum(cocos2d::Ref *pRef)
{
    if(!pRef) return;
    
    auto pDict = reinterpret_cast< std::map<std::string, int> *>(pRef);
    
    auto iterMonsterNum = pDict->find("notShowMonsterNum");
    if(pDict->end() != iterMonsterNum) mIMonsterNum += iterMonsterNum->second;
    
    iterMonsterNum = pDict->find("showMonsterNum");
    if(pDict->end() != iterMonsterNum) mIMonsterNum = iterMonsterNum->second;
    
    mPMonsterLabel->setsText(mIMonsterNum);
    
}

void TollgateDataLayer::recvRefreshTowerSoulNum(cocos2d::Ref *pRef)
{
    if(!pRef) return;
    
    auto pDict = reinterpret_cast<std::map<std::string, int>*>(pRef);
    
    auto pTowerSoulAltNum = pDict->find("towerSoulAltNum");
    
    if(pTowerSoulAltNum != pDict->end()) mITowerSoulNum += pTowerSoulAltNum->second;
    
    pTowerSoulAltNum = pDict->find("UpgradeTollgate");
    
    if(pDict->end() != pTowerSoulAltNum) mITowerSoulNum -= pTowerSoulAltNum->second;

    mPTowerSoulLabel->setsText(mITowerSoulNum);
}

void TollgateDataLayer::recvMonsterDead(cocos2d::Ref *pRef)
{
    mITowerSoulNum += 10;
    mPTowerSoulLabel->setsText(mITowerSoulNum);
}

void TollgateDataLayer::onEnter()
{
    cocos2d::Layer::onEnter();
}

void TollgateDataLayer::onExit()
{
    cocos2d::Layer::onExit();
    NOTIFY->removeObserver(this, "MagicCountChange");
    NOTIFY->removeObserver(this, "MonsterCountChange");
    NOTIFY->removeObserver(this, "TowerSoulCountChange");
    NOTIFY->removeObserver(this, "MonsterDead");
    NOTIFY->removeObserver(this, "AllMonsterDead");
}

const int &TollgateDataLayer::getTollgateSoulNum()
{
    return mITowerSoulNum;
}

void TollgateDataLayer::recvAllMonsterDead(cocos2d::Ref *pRef)
{
    if(mIMagicNum)
        SceneManager::getInstance()->changeScene(SceneManager::en_GameOverScene);
}