//
//  TollgateMapLayer.h
//  Chapter14_2_CardDefence01
//
//  Created by 闫鑫 on 14-7-18.
//
//

#ifndef __Chapter14_2_CardDefence01__TollgateMapLayer__
#define __Chapter14_2_CardDefence01__TollgateMapLayer__

#include "GloblaDefine.h"

class TollgateMapLayer: public cocos2d::Layer
{
public:
    
    TollgateMapLayer(const unsigned int &rUILevel);
    
    static TollgateMapLayer *create(const unsigned int &rUILevel);
    
    virtual ~TollgateMapLayer();
    
    MonsterVec *getMonsterVec();
    
protected:
    
    virtual bool init() override;
    
    virtual void onEnter()override;
    
    virtual void onExit()override;
    
    virtual void createHome();
    
    virtual void createStartPoint();
    
    virtual void loadMap();
    
    virtual void sendStartInfo();
    
private:
    
    MonsterManager *mPMonsterMgr;
    
    HeroManager *mPHeroMgr;
    
    int mICurLevel;

};

#endif /* defined(__Chapter14_2_CardDefence01__TollgateMapLayer__) */
