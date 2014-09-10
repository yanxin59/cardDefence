//
//  TowerBorder.h
//  Chapter14_2_CardDefence01
//
//  Created by 闫鑫 on 14-7-18.
//
//

#ifndef __Chapter14_2_CardDefence01__TowerBorder__
#define __Chapter14_2_CardDefence01__TowerBorder__

#include "Entity.h"

class Hero;
class TowerOprBtns;

class TowerBorder: public Entity
{
public:
    
    TowerBorder();
    
    virtual ~TowerBorder();
    
    CREATE_FUNC(TowerBorder);
    
public:
    
    //判断是否点击到炮台
    bool isClickMe(const cocos2d::Point &rPos);
    
    Hero *getHero();
    
    void deleteHero();
    
    void showTowerOprBtns();
    
    void closeOprBtns();
    
    //绑定英雄
    void bindHero(Hero &rHero);
    
    void createBorder();
    
protected:

    virtual bool init();
    
private:
    
    Hero *mPHero;
    
    TowerOprBtns *mPTowerOprBtns;
};

#endif /* defined(__Chapter14_2_CardDefence01__TowerBorder__) */
