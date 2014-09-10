//
//  ControllerMoveBase.h
//  Chapter14_2_CardDefence01
//
//  Created by 闫鑫 on 14-7-19.
//
//

#ifndef __Chapter14_2_CardDefence01__ControllerMoveBase__
#define __Chapter14_2_CardDefence01__ControllerMoveBase__

#include "ControllerBase.h"

#define CHECK_MOVE_SPEED_LVL1 0.1f
#define CHECK_MOVE_SPEED_LVL2 0.04f
#define CHECK_MOVE_SPEED_LVL3 0.03f

class Entity;

#define SPEED 1

class ControllerMoveBase: public ControllerBase
{
public:
    ControllerMoveBase();
    
    virtual ~ControllerMoveBase();
    
    CC_SYNTHESIZE(int, mISpeed, iSpeed);
    
protected:
    
    //获得下一坐标的位置
    cocos2d::Point getNextPos(const cocos2d::Point &rCurPos, const cocos2d::Point &rDestPos);
    
protected:
    
    Entity *mPEntity;
    
    //标记当前绑定实体是否处于移动状态
    bool mBIsMoving;
    
    //标记当前实体的移动的方向
    bool mBIsXLeft;
    bool mBIsYUp;
    
    //设定检测实体移动时间间隔
    int mICheckMoveSpeed;
};

#endif /* defined(__Chapter14_2_CardDefence01__ControllerMoveBase__) */
