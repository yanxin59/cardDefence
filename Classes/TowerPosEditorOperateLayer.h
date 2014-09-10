//
//  TowerPosEditorOperateLayer.h
//  Chapter14_2_CardDefence01
//
//  Created by 闫鑫 on 14-6-22.
//
//

#ifndef __Chapter14_2_CardDefence01__TowerPosEditorOperateLayer__
#define __Chapter14_2_CardDefence01__TowerPosEditorOperateLayer__

#include "GloblaDefine.h"

class TowerPosEditorLayer;

class TowerPosEditorOperateLayer: public cocos2d::Layer
{
public:
    
    TowerPosEditorOperateLayer();
    
    virtual ~TowerPosEditorOperateLayer();
    
    static TowerPosEditorOperateLayer* create(TowerPosEditorLayer &rPosEditorLayer);
    
protected:
    
    virtual bool init(TowerPosEditorLayer &rPosEditorLayer);
    
private:
    
    virtual void addWins();
    
    virtual void outputToPlistFile(cocos2d::Ref * pSender, cocos2d::extension::Control::EventType event);
    
    virtual void changeMode(cocos2d::Ref *pSender, cocos2d::extension::Control::EventType event);
    
    virtual void nextLvl(cocos2d::Ref *pSender, cocos2d::extension::Control::EventType event);
    
    virtual void preLvl(cocos2d::Ref* pSender, cocos2d::extension::Control::EventType event);
    
    virtual void backLogin(cocos2d::Ref *pSender, cocos2d::extension::Control::EventType event);
    
private:
    
    TowerPosEditorLayer *mPPosEditorLayer;
    
};

#endif /* defined(__Chapter14_2_CardDefence01__TowerPosEditorOperateLayer__) */
