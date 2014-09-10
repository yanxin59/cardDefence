//
//  SceneManager.cpp
//  Chapter14_2_CardDefence01
//
//  Created by 闫鑫 on 14-7-11.
//

#include "SceneManager.h"
#include "TowerPosEditScene.h"
#include "TollgateScene.h"
#include "GlobalClient.h"
#include "TollgateSelectScene.h"
#include "TollgateGameOverScene.h"
#include "TollgateGameLoginScene.h"

SceneManager* SceneManager::mSceneManager = NULL;

SceneManager* SceneManager::getInstance()
{
    if(!mSceneManager)
    {
        mSceneManager = new SceneManager();
        if(mSceneManager && mSceneManager->init()) mSceneManager->autorelease();
        else CC_SAFE_DELETE(mSceneManager);
    }
    return mSceneManager;
}

void SceneManager::delInstance()
{
    CC_SAFE_DELETE(mSceneManager);
}

bool SceneManager::init()
{
    return true;
}

void SceneManager::changeScene(EnumSceneType enSceneType)
{
    cocos2d::Scene* pScene = NULL;
    switch (enSceneType)
    {
        case en_TollgateLogin:
            pScene = TollgateGameLoginScene::createScene();
            break;
        case en_TollgateScene:
            pScene = TollgateScene::create();
            break;
        case en_TollgateEditorScene:
            pScene = TowerPosEditScene::create();
            break;
        case en_WinSnene:
            break;
        case en_GameOverScene:
            pScene = TollgateGameOverScene::create();
            break;
        case en_TollgateSelectScene:
            pScene = TollgateSelectScene::createScene();
            break;
        default:
            break;
    }
    
    if(!pScene) return;
    
    GlobalClient::getInstance()->setCurTollgateScene(*pScene);
    
    auto pDirector = cocos2d::Director::getInstance();
    
    auto pCurScene = pDirector->getRunningScene();
    
    auto pTransScene = cocos2d::TransitionFade::create(1.0f, pScene);

    pCurScene ? pDirector->replaceScene(pTransScene) : pDirector->runWithScene(pTransScene);
}

