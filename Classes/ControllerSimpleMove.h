//
//  ControllerSimpleMove.h
//  Chapter14_2_CardDefence01
//
//  Created by 闫鑫 on 14-7-21.
//
//

#ifndef __Chapter14_2_CardDefence01__ControllerSimpleMove__
#define __Chapter14_2_CardDefence01__ControllerSimpleMove__

#include "ControllerMoveBase.h"
#include "Monster.h"
#include "GloblaDefine.h"

typedef void (Monster::*SEL_CallFuncY)();

#define callFuncX_selector(func) (SEL_CallFuncY)(&func)

class MoveEnd
{
public:
//    MoveEnd(Monster &rTarget, SEL_CallFuncY);
    MoveEnd(const std::function<void ()> &rFunc);
    
    void moveEnd();
    
private:
    //用怪物自身的指针和其对应的移动结束函数初始化
//    SEL_CallFuncY mPFunc;
//    Monster *mPTarget;
    std::function<void ()> mFunc;

};

class ControllerSimpleMove:public ControllerMoveBase
{
public:
    ControllerSimpleMove();
    
    virtual ~ControllerSimpleMove();
    
    //用简单工厂方法创建实体移动控制器,需要一个参数为某实体引用和当怪物到达终点时的回调函数
    static ControllerSimpleMove *create(Monster &rEntity, SEL_CallFuncY pFunc);

    //怪物通过坐标集合,速度,间隔时间来移动
    void moveByPosList(const PosVec &rPosVec);
    void moveByPosList(const PosVec &rPosVec, const int &rISpeed, const float &rFSpanTime);
    void moveByPosList(const PosVec &rPosVec, const int &rISpeed);
    
    //移动至参数坐标处
//    void moveByPos(const PosBase &pPos);
    
protected:
    
    bool init(Monster &rEntity, SEL_CallFuncY pFunc);
    
    //移动检测
    void checkMoveUpdate(const float fDelta);
    
    void moveOneStep();
    
    void nextMovePos();
    
private:
    //终点回调对象
    MoveEnd *mPMoveEnd;
    
    //移动坐标集合
    PosVec *mPMovePosVec;

    //当前移动坐标
    PosBase *mPCurDestPos;
    
    //移动时间间隔
    float mFMoveSpan;
    
    //移动时间控制
    float mFMoveTimeCount;
};



#endif /* defined(__Chapter14_2_CardDefence01__ControllerSimpleMove__) */
