//
//  TowerOprBtns.h
//  Chapter14_2_CardDefence01
//
//  Created by 闫鑫 on 14-7-24.
//
//

#ifndef __Chapter14_2_CardDefence01__TowerOprBtns__
#define __Chapter14_2_CardDefence01__TowerOprBtns__

#include "cocos2d.h"

class Hero;
class TowerBorder;
class MMRoundOprBtn;

class TowerOprBtns: public cocos2d::Node
{
public:
    TowerOprBtns();
    
    virtual ~TowerOprBtns();
    
    static TowerOprBtns *create(TowerBorder &rTowerBorder, Hero &rHero);
    
    bool init(TowerBorder &rTowerBorder, Hero &rHero);
    
    void deleteMe();
    
private:
    
    void closeEvent(cocos2d::Ref *pRef, cocos2d::extension::Control::EventType event);
    
    void upgradeEvent(cocos2d::Ref *pRef, cocos2d::extension::Control::EventType event);
    
    void detailEvent(cocos2d::Ref *pRef, cocos2d::extension::Control::EventType event);
    
    void deleteEvent(cocos2d::Ref *pRef, cocos2d::extension::Control::EventType event);
    
    void createOprBtns();
    
private:
    
    Hero *mPHero;
    
    TowerBorder *mPTowerBorder;
    
    MMRoundOprBtn *mPMMRoundOprBtn;
};

#endif /* defined(__Chapter14_2_CardDefence01__TowerOprBtns__) */
