//
//  TowerPosEditorLayer.h
//  Chapter14_2_CardDefence01
//
//  Created by 闫鑫 on 14-6-22.
//
//

#ifndef __Chapter14_2_CardDefence01__TowerPosEditorLayer__
#define __Chapter14_2_CardDefence01__TowerPosEditorLayer__

#include "GloblaDefine.h"

class TowerPosEditorLayer: public cocos2d::Layer
{
public:
    TowerPosEditorLayer();
    
    virtual ~TowerPosEditorLayer();
    
    CREATE_FUNC(TowerPosEditorLayer);
    
protected:
    
    virtual bool init();
    
    virtual void registerTouchEvent();
    
public:
    
    virtual void outputPosToPlistFile();
    
    virtual void changeMode();
    
    virtual int nextLvl();
    
    virtual int preLvl();

private:
    
    virtual void outputPosToPlistFile(PosVec &rPosVec, const char *sFilePath);
    
    virtual void editPos(const cocos2d::Vec2 &rPos);
    
    virtual PosBase *findExistPos(const cocos2d::Vec2 &rPos);
    
    virtual void createPos(const cocos2d::Vec2 &rPos);
    
    virtual void deletePos(PosBase &rPos);
    
    virtual void loadConfigFile();
    
private:
    
    PosVec *mPPosVec;
    
    int mICurLevel;
    
    EnumEditorType m_enMode;

};

#endif /* defined(__Chapter14_2_CardDefence01__TowerPosEditorLayer__) */
