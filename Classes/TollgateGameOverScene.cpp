//
//  TollgateGameOverScene.cpp
//  Chapter14_2_CardDefence01
//
//  Created by 闫鑫 on 14-8-9.
//
//

#include "TollgateGameOverScene.h"
#include "GloblaPath.h"
#include "SceneManager.h"

bool TollgateGameOverScene::init()
{
    bool bRet = false;
    
    do
    {
        this->getBoundingBox();
        CC_BREAK_IF(!cocos2d::Scene::init());
        
        auto visibleSize = cocos2d::Director::getInstance()->getVisibleSize();
        
        auto pWinLab = cocos2d::Label::createWithSystemFont("You Win!", PATH_FONT_PUBLIC, 40);
        
        pWinLab->setPosition(cocos2d::Point(visibleSize.width / 2, visibleSize.height - 100));
        
        auto pLayer = cocos2d::Layer::create();
        
        pLayer->addChild(pWinLab);
        
        addChild(pLayer);
        
        schedule(schedule_selector(TollgateGameOverScene::backToTollgateSelectScene), 3.0f);
        
        bRet = true;
    }
    while (0);
    
    return bRet;
}

void TollgateGameOverScene::backToTollgateSelectScene(const float dt)
{
    SceneManager::getInstance()->changeScene(SceneManager::en_TollgateSelectScene);
}