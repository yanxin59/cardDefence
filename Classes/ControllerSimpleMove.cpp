//
//  ControllerSimpleMove.cpp
//  Chapter14_2_CardDefence01
//
//  Created by 闫鑫 on 14-7-21.
//
//

#include "ControllerSimpleMove.h"
#include "PosBase.h"

MoveEnd::MoveEnd(const std::function<void ()> &rFunc)
{
    mFunc = rFunc;
}

void MoveEnd::moveEnd()
{
    mFunc();
}

ControllerSimpleMove::ControllerSimpleMove():mPMovePosVec(nullptr), mPCurDestPos(nullptr), mFMoveSpan(1),mPMoveEnd(nullptr),mFMoveTimeCount(0)
{
}

ControllerSimpleMove::~ControllerSimpleMove()
{
    CC_SAFE_DELETE(mPMoveEnd);
    CC_SAFE_RELEASE_NULL(mPCurDestPos);
    CC_SAFE_DELETE(mPMovePosVec);
}


ControllerSimpleMove *ControllerSimpleMove::create(Monster &rEntity, SEL_CallFuncY pFunc)
{
    auto pCtrlSimpleMove = new ControllerSimpleMove();
    
    if(pCtrlSimpleMove && pCtrlSimpleMove->init(rEntity, pFunc)) pCtrlSimpleMove->autorelease();
    else CC_SAFE_DELETE(pCtrlSimpleMove);

    return pCtrlSimpleMove;
}

bool ControllerSimpleMove::init(Monster &rEntity, SEL_CallFuncY pFunc)
{
    bool bRet = false;
    do
    {
        CC_BREAK_IF(!&rEntity);
        CC_SAFE_RETAIN(&rEntity);
        mPEntity = &rEntity;

        mPMovePosVec = new PosVec();
        
//        mPMoveEnd = new MoveEnd(std::bind(&Monster::moveEnd, &rEntity));
        mPMoveEnd = new MoveEnd([this](){ dynamic_cast<Monster*>(mPEntity)->moveEnd();});
        
        schedule(schedule_selector(ControllerSimpleMove::checkMoveUpdate));
        
        bRet = true;
    }
    while (0);
    return bRet;
}

//每帧都进行检测,如果超过设定检测时间则向下一个位置移动
void ControllerSimpleMove::checkMoveUpdate(float fDelta)
{
    if(mBIsMoving)
    {
        mFMoveTimeCount += fDelta;
        if(mFMoveTimeCount >= mFMoveSpan)
        {
            mFMoveTimeCount = 0;
            moveOneStep();
        }
    }
}

//向下一个步长移动
void ControllerSimpleMove::moveOneStep()
{
    if(mPCurDestPos)
    {
        //得到当前实体的位置
        auto entityPos = mPEntity->getPosition();
        
        //得到路径中下一目标位置
        const auto curDestPos = mPCurDestPos->getPosition();
        
        //得到下一移动目标位置
        entityPos = getNextPos(entityPos, curDestPos);
        
//        auto pos = mPEntity->getPosition();
//        auto pEntity = dynamic_cast<Monster*>(mPEntity);
//        auto disX = entityPos.x - pos.x;
//        auto disY = entityPos.y - pos.y;
//        if(abs(disX) > abs(disY))
//        {
//            if(disX < 0)
//            {
//                pEntity->move("left");
//            }
//            else
//            {
//                pEntity->move("right");
//            }
//        }
//        else
//        {
//            if(disY < 0)
//            {
//                pEntity->move("down");
//            }
//            else
//            {
//                pEntity->move("up");
//            }
//        }
        //移动实体
//        mPEntity->setPosition(entityPos);
        mPEntity->runAction(cocos2d::MoveTo::create(1, entityPos));
//        mPEntity->mov
        
//        dynamic_cast<Monster*>(mPEntity)->move("");
        
        //如果移动位置和从路径列表中取得的目标位置相同,则将列表中下一目标位置坐标获得
        if(entityPos == curDestPos)
        {
            if( mPMovePosVec && mPMovePosVec->size())
            {
                nextMovePos();
            }
            else
            {
                mBIsMoving = false;
                if(mPMoveEnd)
                {
                    mPMoveEnd->moveEnd();
                }
            }
        }
    }
}

void ControllerSimpleMove::nextMovePos()
{
    CC_SAFE_RELEASE_NULL(mPCurDestPos);
    
    if(!mPMovePosVec->size()) return;
    
    mPCurDestPos = *(mPMovePosVec->begin());
    CC_SAFE_RETAIN(mPCurDestPos);
    
    mPMovePosVec->erase(mPMovePosVec->begin());
}


void ControllerSimpleMove::moveByPosList(const PosVec &rPosVec)
{
    if(!rPosVec.size()) return ;

    for (auto &iterMonsterPos : rPosVec) mPMovePosVec->pushBack(iterMonsterPos);
    
    //将怪移动的第一个坐标得到
    nextMovePos();
    //设置为开始移动
    mBIsMoving = true;
}

void ControllerSimpleMove::moveByPosList(const PosVec &rPosVec, const int &rISpeed)
{
    mISpeed = rISpeed;
    moveByPosList(rPosVec);
}

void ControllerSimpleMove::moveByPosList(const PosVec &pPosVec, const int &rISpeed, const float &rFSpanTime)
{
    mFMoveSpan = rFSpanTime;
    moveByPosList(pPosVec, rISpeed);
}
