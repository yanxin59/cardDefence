//
//  HeroManager.h
//  Chapter14_2_CardDefence01
//
//  Created by 闫鑫 on 14-7-18.
//
//

#ifndef __Chapter14_2_CardDefence01__HeroManager__
#define __Chapter14_2_CardDefence01__HeroManager__


#include "GloblaDefine.h"

class HeroManager: public cocos2d::Layer
{
public:
    
    static HeroManager *createWithLevel(const unsigned int &rICurLevel);
    
    virtual ~HeroManager();

private:
    
    virtual void createTowerBorder(const unsigned int &rICurLevel);
    
protected:
    
    //初始化炮台管理器
    virtual bool initWithLevel(const unsigned int &rICurLevel);
    
    //注册触摸事件
    virtual void registeTouchDispatcher();
    
    virtual void onEnter()override;
    
    virtual void onExit()override;
    
private:
    
    //判断是否点击炮台
    TowerBorder *findClickTowerBorder(const cocos2d::Point &rPos);
    
private:
    
    unsigned int mUICurLevel = 0;
    
    //炮台坐标集合,从文件中读取
    PosVec *mPTowerPosVec;
    
    //炮台集合
    TowerBorderVec *mPTowerBorderVec;
    
private:
    
    HeroManager();
    
    HeroManager(const HeroManager &) = delete;
    
    HeroManager &operator=(const HeroManager &) = delete;
};

#endif /* defined(__Chapter14_2_CardDefence01__HeroManager__) */
