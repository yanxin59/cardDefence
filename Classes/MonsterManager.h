//
//  MonsterManager.h
//  Chapter14_2_CardDefence01
//
//  Created by 闫鑫 on 14-7-19.
//
//

#ifndef __Chapter14_2_CardDefence01__MonsterManager__
#define __Chapter14_2_CardDefence01__MonsterManager__

#include "GloblaDefine.h"

class MonsterManager:public cocos2d::Node
{
public:
    
    virtual ~MonsterManager();
    
    //通过传入当前选择的关卡级别创建怪物级别
    static MonsterManager *createWithLevel(const int &rCurLevel);
    
    //得到未显示出的怪物的数量
    virtual int getNotShowMonsterCount();
    //得到怪物列表
    virtual MonsterVec *getMonsterVec();
    //得到怪物开始运动的坐标
    virtual PosBase *getMonsterStartPos();
    //得到怪物结束运动的坐标
    virtual PosBase *getMonsterEndPos();
    
protected:
    
    virtual void onExit()override;
//    virtual void onExitTransitionDidStart()override;
    //通过关卡级别初始化和创建怪物
    virtual void createMonsters();
    virtual bool initWithLevel(const int &rCurLevel);
    
    //将怪物的移动路线坐标保存到monsterPosVec中
    virtual void loadMonsterMovePos();
    
    //刷新怪物的出场信息到mapdata层
    virtual void refreshMonsterNumInfo();

protected:
    //显示怪物
    virtual void showMonster(const float dt);
    //判断怪物是否死亡
    virtual void monsterIsDeadLogic(const float dt);
    
private:
    
    //保存未显示的怪物的列表
    MonsterVec *mPMonsterNotShowVec;
    
    //保存怪物行走路径的点的坐标
    PosVec *mPMonsterPosVec;
    
    //保存所有怪物
    MonsterVec *mPMonsterAllVec;
    //设置怪物显示时间
    float mFShowTimeCount;
    
    unsigned int mUILevel;
    
private:
    
    MonsterManager();
    
    MonsterManager(const MonsterManager&) = delete;
    
    MonsterManager &operator=(const MonsterManager&) = delete;
};

#endif /* defined(__Chapter14_2_CardDefence01__MonsterManager__) */
