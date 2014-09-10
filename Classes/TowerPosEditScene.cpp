//
//  TowerPosEditScene.cpp
//  Chapter14_2_CardDefence01
//
//  Created by 闫鑫 on 14-6-22.
//
//

#include "TowerPosEditScene.h"
#include "TowerPosEditorLayer.h"
#include "TowerPosEditorOperateLayer.h"
#include "I18N.h"
#include "SimpleAudioEngine.h"
//#include "CsvUtil.h"


//class TowerPosEditorLayer;

//cocos2d::Scene * TowerPosEditScene::scene()
//{
//    auto pTowerPosEditorScene = cocos2d::Scene::create();
//    
//    if(!pTowerPosEditorScene) return nullptr;
//    
//    TowerPosEditorLayer *pTowerPosEditorLayer = TowerPosEditorLayer::create();
//        
//    if(!pTowerPosEditorLayer) return nullptr;
//    
//    TowerPosEditorOperateLayer *pOperateLayer = TowerPosEditorOperateLayer::create(*pTowerPosEditorLayer);
//    
//    if(!pOperateLayer) return nullptr;
//    
//    pTowerPosEditorScene->addChild(pTowerPosEditorLayer);
//    
//    pTowerPosEditorScene->addChild(pOperateLayer);
//
////    TowerPos * pos = TowerPos::create(cocos2d::Point(200, 200), true);
////    
////    scene->addChild(pos);
//    
////    std::string path(cocos2d::FileUtils::getInstance()->getWritablePath());
////    path.append("test.csv");
////    const char* cPath = path.c_str();
////    CsvUtil::getInstance()->loadFile(cPath);
////    
////    const char* firstMonsterName = CsvUtil::getInstance()->get(2, 1, cPath);
////    
////    log("%s", firstMonsterName);
////    log("I18N test :%s", I18N::getInstance()->getCStringByKey(I18N::en_StrKey_Public_Confirm));
//    
//    return pTowerPosEditorScene;
//}

bool TowerPosEditScene::init()
{
    bool bRet = false;
    
    do
    {
        CC_BREAK_IF(!cocos2d::Scene::init());
        
        TowerPosEditorLayer *pTowerPosEditorLayer = TowerPosEditorLayer::create();
        
        CC_BREAK_IF(!pTowerPosEditorLayer);
        
        TowerPosEditorOperateLayer *pOperateLayer = TowerPosEditorOperateLayer::create(*pTowerPosEditorLayer);
        
        CC_BREAK_IF(!pOperateLayer);
        
        this->addChild(pTowerPosEditorLayer);
        
        this->addChild(pOperateLayer);
        
        bRet = true;
    }
    while (0);
    return bRet;
}