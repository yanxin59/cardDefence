//
//  ControllerMoveBase.cpp
//  Chapter14_2_CardDefence01
//
//  Created by 闫鑫 on 14-7-19.
//
//

#include "ControllerMoveBase.h"
#include "Entity.h"

ControllerMoveBase::ControllerMoveBase():mBIsMoving(false), mBIsXLeft(false), mBIsYUp(false), mPEntity(nullptr), mICheckMoveSpeed(CHECK_MOVE_SPEED_LVL2), mISpeed(SPEED)
{
}

ControllerMoveBase::~ControllerMoveBase()
{
    CC_SAFE_RELEASE(mPEntity);
}

cocos2d::Point ControllerMoveBase::getNextPos(const cocos2d::Point &rCurPos, const cocos2d::Point &rDestPos)
{
    cocos2d::Point curPos = rCurPos;
    
    //判断当前位置的x值和目标位置的x值,这样用于确定移动方向.比如:向左或者向右
    if(curPos.x > rDestPos.x) mBIsXLeft = true;
    else mBIsXLeft = false;
    
    //判断当前位置的y值和目标位置的y值,这样用于确定移动方向,比如:向上或者向下
    if(curPos.y < rDestPos.y) mBIsYUp = true;
    else mBIsYUp = false;

    
    //如果当前位置的x值小于目标位置的x值,且标示实体方向向右
    //则在当前位置的x值基础上加上初始速度,如果修改后的x值大于目标位置的x值,则将目标位置的x值设置为当前需要移动到得位置的x值
    
    if(curPos.x < rDestPos.x && mBIsXLeft == false)
    {
        curPos.x += mISpeed;
        if(curPos.x > rDestPos.x) curPos.x = rDestPos.x;
    }
    else if(curPos.x > rDestPos.x && mBIsXLeft == true)
    {
        curPos.x -= mISpeed;
        if(curPos.x < rDestPos.x) curPos.x = rDestPos.x;
    }
    
    if(curPos.y < rDestPos.y && mBIsYUp == true)
    {
        curPos.y += mISpeed;
        if(curPos.y > rDestPos.y) curPos.y = rDestPos.y;
    }
    else if(curPos.y > rDestPos.y && mBIsYUp == false)
    {
        curPos.y -= mISpeed;
        if(curPos.y < rDestPos.y) curPos.y = rDestPos.y;
    }
    return curPos;
}