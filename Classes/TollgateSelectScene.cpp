//
//  TollgateSelectScene.cpp
//  Chapter14_2_CardDefence01
//
//  Created by 闫鑫 on 14-7-25.
//
//

#include "TollgateSelectScene.h"
#include "SceneManager.h"

cocos2d::Scene *TollgateSelectScene::createScene()
{
    auto pScene = cocos2d::Scene::create();
    
    auto pLayer = TollgateSelectScene::create();
    
    pScene->addChild(pLayer);
    
    return pScene;
}

bool TollgateSelectScene::init()
{
    bool bRet = false;
    do
    {
        CC_BREAK_IF(!Layer::init());

        bRet = true;
    }
    while (0);
    
    return bRet;
}


void TollgateSelectScene::chooseLevel(cocos2d::Ref *pSender, CONTROL_EVENT event)
{
    auto pLevelItem = dynamic_cast<cocos2d::extension::ControlButton*>(pSender);
    auto iLevel = -1;
    if(pLevelItem->getName() == "LevelOne") iLevel = 1;
    else if(pLevelItem->getName() == "LevelTwo") iLevel = 2;
    else { SceneManager::getInstance()->changeScene(SceneManager::EnumSceneType::en_TollgateLogin); return;}
    GlobalClient::getInstance()->setICurTollgateLevel(iLevel);
    
    SceneManager::getInstance()->changeScene(SceneManager::en_TollgateScene);
}


void TollgateSelectScene::onEnter()
{
    Layer::onEnter();
    
    createLevelChooseBtn();
}

void TollgateSelectScene::createLevelChooseBtn()
{
    auto visibleSize = cocos2d::Director::getInstance()->getVisibleSize();
    
    auto pLevel_Title = cocos2d::Label::createWithSystemFont("One", "Arial", 40);
    auto pLevel_1_Btn = CONTROLBTN::create(pLevel_Title, SCALESPRITE::create(CHOOSE_BTN_NORMAL));
    pLevel_1_Btn->setBackgroundSpriteForState(SCALESPRITE::create(CHOOSE_BTN_LIGHT), CONTROL_STATE::HIGH_LIGHTED);
    pLevel_1_Btn->addTargetWithActionForControlEvents(this, cccontrol_selector(TollgateSelectScene::chooseLevel), CONTROL_EVENT::TOUCH_UP_INSIDE);
    pLevel_1_Btn->setPosition(cocos2d::Vec2(visibleSize.width / 2 - 100, visibleSize.height / 2));
    pLevel_1_Btn->setName("LevelOne");
    
    pLevel_Title = cocos2d::Label::createWithSystemFont("Two", "Arial", 40);
    auto pLevel_2_Btn = CONTROLBTN::create(pLevel_Title, SCALESPRITE::create(CHOOSE_BTN_NORMAL));
    pLevel_2_Btn->setBackgroundSpriteForState(SCALESPRITE::create(CHOOSE_BTN_LIGHT), CONTROL_STATE::HIGH_LIGHTED);
    pLevel_2_Btn->addTargetWithActionForControlEvents(this, cccontrol_selector(TollgateSelectScene::chooseLevel), CONTROL_EVENT::TOUCH_UP_INSIDE);
    pLevel_2_Btn->setPosition(cocos2d::Vec2(visibleSize.width / 2 + 100, visibleSize.height / 2));
    pLevel_2_Btn->setName("LevelTwo");
    
    addChild(pLevel_1_Btn);
    addChild(pLevel_2_Btn);
    
    pLevel_Title = cocos2d::Label::createWithSystemFont("返回主界面", PATH_FONT_PUBLIC, GLOBLA_FONT_SIZE_LARGE);
    auto pbackBtn = CONTROLBTN::create(pLevel_Title, SCALESPRITE::create(PATH_PublicUI_button));
    pbackBtn->addTargetWithActionForControlEvents(this, cccontrol_selector(TollgateSelectScene::chooseLevel), CONTROL_EVENT::TOUCH_UP_INSIDE);
    pbackBtn->setPosition(cocos2d::Vec2(visibleSize.width - pbackBtn->getContentSize().width / 2, pbackBtn->getContentSize().height / 2));
    addChild(pbackBtn);
}
