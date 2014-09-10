//
//  TollgateDataLayer.h
//  Chapter14_2_CardDefence01
//
//  Created by 闫鑫 on 14-7-24.
//
//

#ifndef __Chapter14_2_CardDefence01__TollgateDataLayer__
#define __Chapter14_2_CardDefence01__TollgateDataLayer__

#include "cocos2d.h"

class MMLabel;
class MMWinDesktop;

class TollgateDataLayer:public cocos2d::Layer
{
public:
    
    TollgateDataLayer();
    
    virtual ~TollgateDataLayer();
    
    CREATE_FUNC(TollgateDataLayer);
    
    //刷新数据层塔魂数量
    virtual void recvRefreshTowerSoulNum(cocos2d::Ref *pRef);
    
    //刷新数据层怪物数量
    virtual void recvRefreshMonsterNum(cocos2d::Ref *pRef);
    
    //刷新数据层魔法值
    virtual void recvRefreshMagicNum(cocos2d::Ref *pRef);
    
    virtual void recvMonsterDead(cocos2d::Ref *pRef);
    
    //如果怪物全部死亡则通知退出
    virtual void recvAllMonsterDead(cocos2d::Ref *pRef);
    
    //得到塔魂数量
    virtual const int &getTollgateSoulNum();
    
protected:
    
    virtual bool init();
    
    virtual void onEnter()override;
    
    virtual void onExit()override;
    
private:
    
    int mITowerSoulNum;
    
    int mIMonsterNum;
    
    int mIMagicNum;
    
    MMLabel *mPTowerSoulLabel;
    
    MMLabel *mPMonsterLabel;
    
    MMLabel *mPMagicLabel;
    
    MMWinDesktop *mPWinDesktop;
};

#endif /* defined(__Chapter14_2_CardDefence01__TollgateDataLayer__) */
