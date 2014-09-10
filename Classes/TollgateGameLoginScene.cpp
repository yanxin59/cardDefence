//
//  TollgateGameLoginScene.cpp
//  cardDefence
//
//  Created by 闫鑫 on 14-8-19.
//
//

#include "TollgateGameLoginScene.h"
#include "SceneManager.h"

bool TollgateGameLoginScene::init()
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

void TollgateGameLoginScene::onEnter()
{
    Layer::onEnter();
    loadSource();
}

cocos2d::Scene *TollgateGameLoginScene::createScene()
{
    auto pScene = cocos2d::Scene::create();
    
    auto pLayer = TollgateGameLoginScene::create();
    
    pScene->addChild(pLayer);
    
    return pScene;
}

void TollgateGameLoginScene::loadSource()
{
    auto visibleSize = cocos2d::Director::getInstance()->getVisibleSize();
    auto pBg = cocos2d::Sprite::create(PATH_GAME_LOGIN_BACKGROUND);
    pBg->setPosition(cocos2d::Vec2(visibleSize.width / 2, visibleSize.height / 2));
    addChild(pBg);
    
    auto pBtnTitle = cocos2d::Label::createWithSystemFont("选择关卡", PATH_FONT_PUBLIC, GLOBLA_FONT_SIZE_LARGE);
    auto pChooseLevelBtn = CONTROLBTN::create(pBtnTitle, SCALESPRITE::create(PATH_PublicUI_button));
    pChooseLevelBtn->addTargetWithActionForControlEvents(this, cccontrol_selector(TollgateGameLoginScene::selectScene), CONTROL_EVENT::TOUCH_UP_INSIDE);
    addChild(pChooseLevelBtn);
    pChooseLevelBtn->setPosition(cocos2d::Vec2(visibleSize.width / 2 - 100, visibleSize.height / 2));
    pChooseLevelBtn->setName("chooseLevel");
    
    pBtnTitle = cocos2d::Label::createWithSystemFont("编辑场景", PATH_FONT_PUBLIC, GLOBLA_FONT_SIZE_LARGE);
    auto pChooseEditorPosBtn = CONTROLBTN::create(pBtnTitle, SCALESPRITE::create(PATH_PublicUI_button));
    pChooseEditorPosBtn->addTargetWithActionForControlEvents(this, cccontrol_selector(TollgateGameLoginScene::selectScene), CONTROL_EVENT::TOUCH_UP_INSIDE);
    addChild(pChooseEditorPosBtn);
    pChooseEditorPosBtn->setPosition(cocos2d::Vec2(visibleSize.width / 2 + 100, visibleSize.height / 2));
    
}

void TollgateGameLoginScene::selectScene(cocos2d::Ref *pSender, CONTROL_EVENT event)
{
    auto pBtn = dynamic_cast<CONTROLBTN*>(pSender);
    SceneManager::EnumSceneType enScene;
    if(pBtn->getName() == "chooseLevel") enScene = SceneManager::EnumSceneType::en_TollgateSelectScene;
    else enScene = SceneManager::EnumSceneType::en_TollgateEditorScene;
    SceneManager::getInstance()->changeScene(enScene);
    
}
