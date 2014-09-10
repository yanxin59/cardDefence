//
//  Monster.h
//  Chapter14_2_CardDefence01
//
//  Created by 闫鑫 on 14-7-19.
//
//

#ifndef __Chapter14_2_CardDefence01__Monster__
#define __Chapter14_2_CardDefence01__Monster__

#include "Entity.h"
#include "GloblaDefine.h"

class Monster: public Entity
{
public:
    
    Monster();
    
    virtual ~Monster();
    
    CREATE_FUNC(Monster);
    
    static Monster *createFromCsvFileById(const int &rIMonsterId);
    
    virtual void onDead();
    
    virtual void onHurt(const int &rIHurtValue);
    
    //驱动怪物沿着点路径行动
    virtual void moveByPosList(const PosVec &rPosVec);
    
    virtual void moveEnd();
    
    virtual void move(const std::string &rVec2);
    
    virtual void loadAnimation();

protected:

    virtual bool initFromCsvFileById(const int &rIMonsterId);
    
    virtual bool init();
    
    //重写父类函数
    virtual void onBindSprite();
    //给怪物添加血条
    virtual void onBindSlider();
    
private:

    ControllerSimpleMove *mPMoveController;
    
    WidgetHPSlot *mPHpSlider;
    
    CC_PRIVATE(float, mFShowTime, fShowTime);
    
    CC_SYNTHESIZE(bool, mBIsMoveEnd, isMoveEnd);
};

#endif /* defined(__Chapter14_2_CardDefence01__Monster__) */
