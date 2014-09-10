//
//  MonsterManager.cpp
//  Chapter14_2_CardDefence01
//
//  Created by 闫鑫 on 14-7-19.
//
//

#include "MonsterManager.h"
#include "PosLoadUtil.h"
#include "Monster.h"
#include "ControllerSimpleMove.h"
#include "PosBase.h"
#include "Header.h"

MonsterManager::MonsterManager():mPMonsterAllVec(nullptr), mPMonsterPosVec(nullptr), mPMonsterNotShowVec(nullptr), mFShowTimeCount(0)
{
}

MonsterManager::~MonsterManager()
{
    CC_SAFE_DELETE(mPMonsterPosVec);
    CC_SAFE_DELETE(mPMonsterNotShowVec);
    CC_SAFE_DELETE(mPMonsterAllVec);
}

MonsterManager *MonsterManager::createWithLevel(const int &rCurLevel)
{
    auto pMonsterMgr = new MonsterManager();
    
    if(pMonsterMgr && pMonsterMgr->initWithLevel(rCurLevel)) pMonsterMgr->autorelease();
    else CC_SAFE_DELETE(pMonsterMgr);
    
    return pMonsterMgr;
}

bool MonsterManager::initWithLevel(const int &rCurLevel)
{
    bool bRet = false;
    
    do
    {
        mUILevel = rCurLevel;
        
        mPMonsterAllVec = new MonsterVec();
        
        mPMonsterNotShowVec = new MonsterVec();
        
        mPMonsterPosVec = new PosVec();
        
        loadMonsterMovePos();
        
        createMonsters();
        
        bRet = true;
    }
    while (0);

    return bRet;
}

int MonsterManager::getNotShowMonsterCount()
{
    //得到未显示的怪物的数量
    int iRet = -1;
    do
    {
        CC_BREAK_IF(!mPMonsterNotShowVec);
        
        iRet = mPMonsterNotShowVec->size();
    }
    while (0);
    return iRet;
}

MonsterVec *MonsterManager::getMonsterVec()
{
    MonsterVec *pRetMonsterVec = nullptr;
    do
    {
        CC_BREAK_IF( !mPMonsterAllVec );
        pRetMonsterVec = mPMonsterAllVec;
    }
    while (0);
    return pRetMonsterVec;
}

PosBase *MonsterManager::getMonsterStartPos()
{
    PosBase *pMonsterStartPos = nullptr;
    
    do
    {
        CC_BREAK_IF( !mPMonsterPosVec );

        pMonsterStartPos = *(mPMonsterPosVec->begin());
    }
    while (0);
    
    return pMonsterStartPos;
}

PosBase *MonsterManager::getMonsterEndPos()
{
    PosBase *pMonsterEndPos = nullptr;
    
    do
    {
        CC_BREAK_IF( !mPMonsterPosVec );
        
        pMonsterEndPos = *(--mPMonsterPosVec->end());
    }
    while (0);
    
    return pMonsterEndPos;
}

void MonsterManager::createMonsters()
{

    if(mPMonsterAllVec && mPMonsterNotShowVec)
    {
        mPMonsterAllVec->clear();
        mPMonsterNotShowVec->clear();
    }
    else
    {
        return;
    }
    
    //将保存到plist中的需要显示的怪物得到
    auto monsterLevelFile = cocos2d::StringUtils::format("monster_level_%d.plist", mUILevel);
//    auto monsterLevelFile = cocos2d::StringUtils::format("%smonster_level_%d.plist", cocos2d::FileUtils::getInstance()->getWritablePath().c_str(), mUILevel);
    //通过fileutils工具将plist文件中得内容读取到
    auto confProsArr = cocos2d::FileUtils::getInstance()->getValueVectorFromFile(monsterLevelFile.c_str());
    
    //保存从plist文件中读取到的怪物的id和显示时间
    int iId = 0;
    float fShowTime = 0;
    
    for(const auto &iter : confProsArr)
    {
        cocos2d::ValueMap map = iter.asValueMap();
        
        iId = map.at(MONSTER_ID).asInt();
        
        fShowTime = map.at(MONSTER_SHOWTIME).asFloat();
        
//        cocos2d::log("id: %d, showTime: %.02f", iId, fShowTime);
        
        auto pMonster = Monster::createFromCsvFileById(iId);
        
        //设置怪物的出现时间
        pMonster->setfShowTime(fShowTime);
        //设置怪物为不可见
        pMonster->setVisible(false);
        //怪物贴图名称
        auto sMonsterFileName = cocos2d::StringUtils::format("monster_%d.png",pMonster->getiModelId());
        //生成怪物精灵贴图
//        auto pMonsterSprite = cocos2d::Sprite::create(sMonsterFileName.c_str());
        auto pMonsterSprite = cocos2d::Sprite::createWithSpriteFrame(cocos2d::SpriteFrame::create(sMonsterFileName.c_str(), cocos2d::Rect(0, 0, 32, 48)));
        //将怪物贴图绑定到怪物上
        
        pMonster->bindSprite(*pMonsterSprite);
        
        //在全部的怪物列表和为显示的怪物列表中保存怪物
        mPMonsterAllVec->pushBack(pMonster);
        mPMonsterNotShowVec->pushBack(pMonster);
        
        //将怪物添加到怪物管理器中
        addChild(pMonster);
    }
    //添加显示怪物的定时器
    schedule(schedule_selector(MonsterManager::showMonster));
    //添加检测怪物是否存活的查询定时器
    schedule(schedule_selector(MonsterManager::monsterIsDeadLogic), 0.2f);
}

void MonsterManager::showMonster(const float dt)
{
    //保证在容器有效和容器中有怪物的情况下进行怪物出场时间计算
    if(!(mPMonsterNotShowVec && mPMonsterNotShowVec->size())) return;
    
    mFShowTimeCount += dt;
    
    for(auto notShowMonsterIter = mPMonsterNotShowVec->begin(); notShowMonsterIter != mPMonsterNotShowVec->end(); ++notShowMonsterIter)
    {
        auto pMonster = *notShowMonsterIter;
        if(pMonster)
        {
            if(mFShowTimeCount >= pMonster->getfShowTime())
            {
                //设置怪物到路径起始位置
                pMonster->setPosition(getMonsterStartPos()->getPosition());
                //设置怪物为可见状态
                pMonster->setVisible(true);
                //把移动路线传给怪物,并开始移动
                pMonster->moveByPosList(*mPMonsterPosVec);
                //把怪物出场时间置0
                mFShowTimeCount = 0;
                //将怪物从引用从未显示的怪物的容器中释放掉
                notShowMonsterIter = mPMonsterNotShowVec->erase(notShowMonsterIter);
                //如果返回的迭代器到达容器的尾部则跳出循环
                if(notShowMonsterIter == mPMonsterNotShowVec->end()) break;
            }
        }
    }
    //刷新显示的怪物信息
    refreshMonsterNumInfo();
}

void MonsterManager::refreshMonsterNumInfo()
{
    std::map<std::string, int> mapMonsterInfo;
    mapMonsterInfo.insert(std::make_pair("showMonsterNum", mPMonsterNotShowVec->size()));
    NOTIFY->postNotification("MonsterCountChange", reinterpret_cast<cocos2d::Ref*>(&mapMonsterInfo));
}

void MonsterManager::monsterIsDeadLogic(const float dt)
{
    if( !mPMonsterAllVec ) return;
    
    for (auto iterMonsterVec = mPMonsterAllVec->begin(); iterMonsterVec != mPMonsterAllVec->end(); ++iterMonsterVec)
    {
        if( (*iterMonsterVec)->getisMoveEnd() || (*iterMonsterVec)->isDead() )
            iterMonsterVec = mPMonsterAllVec->erase(iterMonsterVec);
        if(iterMonsterVec == mPMonsterAllVec->end()) break;
    }
    
    if( !mPMonsterAllVec->size() )
    {
        unscheduleAllSelectors();
        NOTIFY->postNotification("AllMonsterDead");
    }
}

void MonsterManager::onExit()
{
    Node::onExit();
    unscheduleAllSelectors();
}

void MonsterManager::loadMonsterMovePos()
{
    PosLoadUtil tPosLoadUtil;
    //怪物坐标列表名称
    
    std::string sWritablePath = cocos2d::FileUtils::getInstance()->getWritablePath();
    std::string sMonsterPosPlistStr = cocos2d::StringUtils::format("%smonsterPos_level_%d.plist", sWritablePath.c_str(), mUILevel);
    //向mPMonsterPosVec中加载怪物坐标
    tPosLoadUtil.loadPosWithFile(sMonsterPosPlistStr.c_str(), *mPMonsterPosVec, enMonsterPos);
}

