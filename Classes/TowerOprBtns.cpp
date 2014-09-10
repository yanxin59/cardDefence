//
//  TowerOprBtns.cpp
//  Chapter14_2_CardDefence01
//
//  Created by 闫鑫 on 14-7-24.
//
//

#include "Hero.h"
#include "TowerOprBtns.h"
#include "TowerBorder.h"
#include "MMRoundOprBtn.h"
#include "Header.h"


TowerOprBtns::TowerOprBtns():mPHero(nullptr), mPTowerBorder(nullptr), mPMMRoundOprBtn(nullptr){}

TowerOprBtns::~TowerOprBtns()
{
    CC_SAFE_RELEASE_NULL(mPHero);
}

TowerOprBtns *TowerOprBtns::create(TowerBorder &rTowerBorder, Hero &rHero)
{
    auto pTowerOprBtns = new TowerOprBtns();
    
    if(pTowerOprBtns && pTowerOprBtns->init(rTowerBorder, rHero)) pTowerOprBtns->autorelease();
    else CC_SAFE_DELETE(pTowerOprBtns);
    
    return pTowerOprBtns;
}

bool TowerOprBtns::init(TowerBorder &rTowerBorder, Hero &rHero)
{

    bool bRet = false;
    
    do
    {
        CC_SAFE_RETAIN(&rHero);
        mPHero = &rHero;
        
        CC_SAFE_RETAIN(&rTowerBorder);
        mPTowerBorder = &rTowerBorder;
        
        createOprBtns();
        
        bRet = true;
    }
    while (0);

    return bRet;
}

void TowerOprBtns::createOprBtns()
{
    auto size = cocos2d::Size(100, 50);
    
    auto title = cocos2d::Label::createWithSystemFont("Close", PATH_FONT_PUBLIC, GLOBLA_FONT_SIZE);
    auto pCloseBtn = CONTROLBTN::create(title, SCALESPRITE::create("opr_btn_nor.png"));
    pCloseBtn->setBackgroundSpriteForState(SCALESPRITE::create("opr_btn_light.png"), CONTROL_STATE::HIGH_LIGHTED);
    pCloseBtn->setPreferredSize(size);
    pCloseBtn->addTargetWithActionForControlEvents(this, cccontrol_selector(TowerOprBtns::closeEvent), CONTROL_EVENT::TOUCH_UP_INSIDE);
    
    title = cocos2d::Label::createWithSystemFont("Delete", PATH_FONT_PUBLIC, GLOBLA_FONT_SIZE);
    auto pDeleteBtn = CONTROLBTN::create(title, SCALESPRITE::create("opr_btn_nor.png"));
    pDeleteBtn->setBackgroundSpriteForState(SCALESPRITE::create("opr_btn_light.png"), CONTROL_STATE::HIGH_LIGHTED);
    pDeleteBtn->setPreferredSize(size);
    pDeleteBtn->addTargetWithActionForControlEvents(this, cccontrol_selector(TowerOprBtns::deleteEvent), CONTROL_EVENT::TOUCH_UP_INSIDE);
    
    title = cocos2d::Label::createWithSystemFont("upgrade", PATH_FONT_PUBLIC, GLOBLA_FONT_SIZE);
    auto pUpgradeBtn = CONTROLBTN::create(title, SCALESPRITE::create("opr_btn_nor.png"));
    pUpgradeBtn->setBackgroundSpriteForState(SCALESPRITE::create("opr_btn_light.png"), CONTROL_STATE::HIGH_LIGHTED);
    pUpgradeBtn->setPreferredSize(size);
    pUpgradeBtn->addTargetWithActionForControlEvents(this, cccontrol_selector(TowerOprBtns::upgradeEvent), CONTROL_EVENT::TOUCH_UP_INSIDE);
    
    title = cocos2d::Label::createWithSystemFont("Detail", PATH_FONT_PUBLIC, GLOBLA_FONT_SIZE);
    auto pDetailBtn = CONTROLBTN::create(title, SCALESPRITE::create("opr_btn_nor.png"));
    pDetailBtn->setBackgroundSpriteForState(SCALESPRITE::create("opr_btn_light.png"), CONTROL_STATE::HIGH_LIGHTED);
    pDetailBtn->setPreferredSize(size);
    pDetailBtn->addTargetWithActionForControlEvents(this, cccontrol_selector(TowerOprBtns::detailEvent), CONTROL_EVENT::TOUCH_UP_INSIDE);

    
    mPMMRoundOprBtn = MMRoundOprBtn::createWithControlButtons(pCloseBtn, pDeleteBtn, pUpgradeBtn, pDetailBtn);
    addChild(mPMMRoundOprBtn);
}

void TowerOprBtns::closeEvent(cocos2d::Ref *pRef, CONTROL_EVENT event)
{
    mPTowerBorder->closeOprBtns();
}

void TowerOprBtns::upgradeEvent(cocos2d::Ref *pRef, CONTROL_EVENT event)
{
    mPHero->upGrade();
    mPTowerBorder->closeOprBtns();
}

void TowerOprBtns::detailEvent(cocos2d::Ref *pRef, CONTROL_EVENT event)
{
    
}

void TowerOprBtns::deleteEvent(cocos2d::Ref *pRef, CONTROL_EVENT event)
{
    mPTowerBorder->deleteHero();
    mPTowerBorder->closeOprBtns();
}

void TowerOprBtns::deleteMe()
{
    mPMMRoundOprBtn->deleteMe();
    removeAllChildrenWithCleanup(true);
}


