//
//  TollgateScene.cpp
//  Chapter14_2_CardDefence01
//
//  Created by 闫鑫 on 14-7-14.
//
//

#include "TollgateScene.h"
#include "TollgateMapLayer.h"
#include "TollgateDataLayer.h"

bool TollgateScene::init()
{
    bool bRet = false;
    
    do
    {
        CC_BREAK_IF(!cocos2d::Scene::init());
        
        bRet = true;
        
    }
    while (0);
    
    return bRet;
}

void TollgateScene::onEnter()
{
    
    Scene::onEnter();
    
    auto pDataLayer = TollgateDataLayer::create();
    
    auto pMapLayer = TollgateMapLayer::create(GlobalClient::getInstance()->getICurTollgateLevel());
    
    addChild(pDataLayer, 2, TAG_DATA_LAYER);
    
    addChild(pMapLayer, 1, TAG_MAP_LAYER);

}

void TollgateScene::onExit()
{
    Scene::onExit();
    unscheduleAllSelectors();
    removeAllChildrenWithCleanup(true);
}
