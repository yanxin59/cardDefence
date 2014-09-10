//
//  TowerPosEditorOperateLayer.cpp
//  Chapter14_2_CardDefence01
//
//  Created by 闫鑫 on 14-6-22.
//
//

#include "TowerPosEditorOperateLayer.h"
#include "TowerPosEditorLayer.h"
#include "SceneManager.h"

TowerPosEditorOperateLayer::TowerPosEditorOperateLayer():mPPosEditorLayer(nullptr){}

TowerPosEditorOperateLayer::~TowerPosEditorOperateLayer()
{
    CC_SAFE_RELEASE_NULL(mPPosEditorLayer);
}

TowerPosEditorOperateLayer* TowerPosEditorOperateLayer::create(TowerPosEditorLayer &rPosEditorLayer)
{
    TowerPosEditorOperateLayer *pOprLayer = new TowerPosEditorOperateLayer();
    
    if (pOprLayer && pOprLayer->init(rPosEditorLayer)) pOprLayer->autorelease();
    else CC_SAFE_DELETE(pOprLayer);
    
    return pOprLayer;
}

bool TowerPosEditorOperateLayer::init(TowerPosEditorLayer &rPosEditorLayer)
{
    bool bRet = false;
    
    do {
        
        CC_BREAK_IF(!Layer::init());
    
        CC_SAFE_RETAIN(&rPosEditorLayer);
        mPPosEditorLayer = &rPosEditorLayer;
        
        addWins();
        
        bRet = true;
    }
    while (0);
    
    return bRet;
}


void TowerPosEditorOperateLayer::addWins()
{
    auto visibleSize = cocos2d::Director::getInstance()->getVisibleSize();
    
    //创建输出坐标的按钮
    auto btnTitle = cocos2d::Label::createWithSystemFont("保存自定义坐标", PATH_FONT_PUBLIC, 30);
    auto norSprite = SCALESPRITE::create(PATH_PublicUI_BlueBtn);
    auto highLightSprite = SCALESPRITE::create(PATH_PublicUI_GreenBtn);
    auto outputBtn = CONTROLBTN::create(btnTitle, norSprite);
    outputBtn->setBackgroundSpriteForState(highLightSprite, CONTROL_STATE::HIGH_LIGHTED);
    outputBtn->setPosition(cocos2d::Vec2(visibleSize.width - norSprite->getContentSize().width / 2, norSprite->getContentSize().height * 2));
    outputBtn->addTargetWithActionForControlEvents(this, cccontrol_selector(TowerPosEditorOperateLayer::outputToPlistFile), CONTROL_EVENT::TOUCH_UP_INSIDE);
    addChild(outputBtn, 2);
    
    
    //创建修改模式按钮
    btnTitle = cocos2d::Label::createWithSystemFont("切换编辑坐标类型", PATH_FONT_PUBLIC, 30);
    norSprite = SCALESPRITE::create(PATH_PublicUI_BlueBtn);
    highLightSprite = SCALESPRITE::create(PATH_PublicUI_GreenBtn);
    auto changeModeBtn = CONTROLBTN::create(btnTitle, norSprite);
    changeModeBtn->setBackgroundSpriteForState(highLightSprite, CONTROL_STATE::HIGH_LIGHTED);
    changeModeBtn->setPosition(cocos2d::Vec2(visibleSize.width - norSprite->getContentSize().width / 2,
                                     norSprite->getContentSize().height * 3));
    changeModeBtn->addTargetWithActionForControlEvents(this, cccontrol_selector(TowerPosEditorOperateLayer::changeMode), CONTROL_EVENT::TOUCH_UP_INSIDE);
    addChild(changeModeBtn, 3);
    
    //创建下一关按钮
    btnTitle = cocos2d::Label::createWithSystemFont("后一关卡", PATH_FONT_PUBLIC, 30);
    norSprite = SCALESPRITE::create(PATH_PublicUI_BlueBtn);
    highLightSprite = SCALESPRITE::create(PATH_PublicUI_GreenBtn);
    auto nextLvlBtn = CONTROLBTN::create(btnTitle, norSprite);
    nextLvlBtn->setBackgroundSpriteForState(highLightSprite, CONTROL_STATE::HIGH_LIGHTED);
    nextLvlBtn->setPosition(cocos2d::Vec2(visibleSize.width - norSprite->getContentSize().width / 2,
                                           norSprite->getContentSize().height * 4));
    nextLvlBtn->addTargetWithActionForControlEvents(this, cccontrol_selector(TowerPosEditorOperateLayer::nextLvl), CONTROL_EVENT::TOUCH_UP_INSIDE);
    addChild(nextLvlBtn, 1);
    
    //创建上一关卡的按钮
    btnTitle = cocos2d::Label::createWithSystemFont("前一关卡", PATH_FONT_PUBLIC, 30);
    norSprite = SCALESPRITE::create(PATH_PublicUI_BlueBtn);
    highLightSprite = SCALESPRITE::create(PATH_PublicUI_GreenBtn);
    auto preLvlBtn = CONTROLBTN::create(btnTitle, norSprite);
    preLvlBtn->setBackgroundSpriteForState(highLightSprite, CONTROL_STATE::HIGH_LIGHTED);
    preLvlBtn->setPosition(cocos2d::Vec2(visibleSize.width - norSprite->getContentSize().width / 2,
                                          norSprite->getContentSize().height * 5));
    preLvlBtn->addTargetWithActionForControlEvents(this, cccontrol_selector(TowerPosEditorOperateLayer::preLvl), CONTROL_EVENT::TOUCH_UP_INSIDE);
    addChild(preLvlBtn, 1);
    
    btnTitle = cocos2d::Label::createWithSystemFont("返回主界面", PATH_FONT_PUBLIC, 30);
    auto backBtn = CONTROLBTN::create(btnTitle, SCALESPRITE::create(PATH_PublicUI_BlueBtn));
    backBtn->setBackgroundSpriteForState(SCALESPRITE::create(PATH_PublicUI_GreenBtn), CONTROL_STATE::HIGH_LIGHTED);
    backBtn->addTargetWithActionForControlEvents(this, cccontrol_selector(TowerPosEditorOperateLayer::backLogin), CONTROL_EVENT::TOUCH_UP_INSIDE);
    backBtn->setPosition(visibleSize.width - backBtn->getContentSize().width / 2, backBtn->getContentSize().height);
    addChild(backBtn);
}

void TowerPosEditorOperateLayer::backLogin(cocos2d::Ref *pSender, cocos2d::extension::Control::EventType event)
{
    SceneManager::getInstance()->changeScene(SceneManager::EnumSceneType::en_TollgateLogin);
}

void TowerPosEditorOperateLayer::outputToPlistFile(cocos2d::Ref *pSender, cocos2d::extension::Control::EventType event)
{
    mPPosEditorLayer->outputPosToPlistFile();
}

void TowerPosEditorOperateLayer:: changeMode(cocos2d::Ref *pSender, cocos2d::extension::Control::EventType event)
{
    mPPosEditorLayer->changeMode();
}

void TowerPosEditorOperateLayer::nextLvl(cocos2d::Ref *pSender, cocos2d::extension::Control::EventType event)
{
    mPPosEditorLayer->nextLvl();
}

void TowerPosEditorOperateLayer::preLvl(cocos2d::Ref *pSender, cocos2d::extension::Control::EventType event)
{
    mPPosEditorLayer->preLvl();
}

