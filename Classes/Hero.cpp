//
//  Hero.cpp
//  Chapter14_2_CardDefence01
//
//  Created by 闫鑫 on 14-7-19.
//
//

#include "Hero.h"
#include "CsvUtil.h"
#include "GloblaDefine.h"
#include "TollgateScene.h"
#include "TollgateMapLayer.h"
#include "Monster.h"
#include "BulletManager.h"
#include "BulletNormal.h"
#include "TollgateDataLayer.h"

Hero::Hero():mPAtkMonster(nullptr), mBIsAktCoolDown(false), mPBulletManager(nullptr)
{
}

Hero::~Hero()
{
    CC_SAFE_RELEASE_NULL(mPAtkMonster);
    CC_SAFE_RELEASE_NULL(mPBulletManager);
}

bool Hero::init(cocos2d::Sprite &rSprite)
{
//    MyLog;
    bool ret = false;
    do
    {
        //判断绑定的精灵是否有效,无效则跳出循环
        bindSprite(rSprite);
        
        //创建子弹管理器,并检测是否创建成功
        mPBulletManager = BulletManager::create();
        mPBulletManager->retain();
        
        addChild(mPBulletManager);
        ret = true;
    }
    while (0);
    return ret;
}

Hero *Hero::createFromCsvById(const int &rIHeroId)
{
    Hero *pHero = new Hero();
    
    if(pHero && pHero->initFromCsvFileById(rIHeroId)) pHero->autorelease();
    else CC_SAFE_DELETE(pHero);
    
    return pHero;
}

bool Hero::initFromCsvFileById(const int &rIHeroId)
{
    bool bRet = false;
//    cocos2d::log("level: %d", rIHeroId);
    do
    {
        auto pCsvUtil = CsvUtil::getInstance();

        auto sHeroId = cocos2d::StringUtils::format("%d", rIHeroId);
    
        int iLine = pCsvUtil->findValueInWithLine(
                                                  sHeroId.c_str(),
                                                  EnumHeroPropConfType::enHeroPropConf_Type,
                                                  PATH_CSV_HERO_CONF
                                                  );
        
        CC_BREAK_IF(iLine < 0);
        
        setiId(rIHeroId);
        
        //设置模型id
        setiModelId(pCsvUtil->getInt(iLine, EnumHeroPropConfType::enHeroPropConf_ModelID, PATH_CSV_HERO_CONF));
        
        //设置基础攻击力
        setiBaseAtk(pCsvUtil->getInt(iLine, EnumHeroPropConfType::enHeroPropConf_BaseAtk, PATH_CSV_HERO_CONF));
        
        //设置当前攻击力
        setiCurAtk(getiBaseAtk());
        
        //设置攻击速度
        setiAtkSpeed(pCsvUtil->getInt(iLine, EnumHeroPropConfType::enHeroPropConf_AtkSpeed, PATH_CSV_HERO_CONF));
        
        //设置攻击范围
        setiAtkRange(pCsvUtil->getInt(iLine, EnumHeroPropConfType::enHeroPropConf_AtkRange, PATH_CSV_HERO_CONF));
        
        //设置升级需要消耗的塔魂数
        setiUpGradeCostBase(pCsvUtil->getInt(iLine, EnumHeroPropConfType::enHeroPropConf_UpgradeCostBase, PATH_CSV_HERO_CONF));
        
        //设置升级所需基础攻击力
        setfUpGradeAtkBase(pCsvUtil->getFloat(iLine, EnumHeroPropConfType::enHeroPropConf_UpgradeAtkBase, PATH_CSV_HERO_CONF));
        
        //创建英雄
        auto pSprite = cocos2d::Sprite::create(cocos2d::StringUtils::format("hero_%d.png", rIHeroId).c_str());
        
        //初始化英雄
        CC_BREAK_IF(!init(*pSprite));
        
        //设置定时器,将英雄设置为待攻击状态
        schedule(schedule_selector(Hero::checkAtkMonster), 0.3f);

        bRet = true;
        
    }while(0);
    
    return bRet;
}

void Hero::checkAtkMonster(float dt)
{
    //得到当前运行场景
    auto pScene = GlobalClient::getInstance()->getCurTollgateScene();
    //得到英雄所在的图层
    auto pLayer = dynamic_cast<TollgateMapLayer*>(pScene->getChildByTag(TAG_MAP_LAYER));
    
    if(!pLayer) return;
    
    //从图层获得怪物列表
    auto pMonsterVec = pLayer->getMonsterVec();
    if(!pMonsterVec || !pMonsterVec->size()) return;
    
    /*如果当前准备攻击的怪物为空,则从列表中选择一个怪物
     *如果当前准备攻击的怪物不为空,则判断该怪物是否死亡
     *如果该怪物死亡,则从列表中将该怪物删除,并将锁定的怪物设置为空
     *如果冷却时间为假则进行攻击
     */
    
    if(!mPAtkMonster)
    {
        chooseAim(*pMonsterVec);
    }
    else
    {
        if(mPAtkMonster->isDead())
        {
            auto iterDeadMonster = pMonsterVec->find(mPAtkMonster);
            if(pMonsterVec->end() != iterDeadMonster) pMonsterVec->erase(iterDeadMonster);
            CC_SAFE_RELEASE_NULL(mPAtkMonster);
            return;
        }
        //判断是否攻击冷却
        if(!mBIsAktCoolDown)
        {
            atk();
        }
        //判断该目标是否在攻击范围内
        checkAmiIsOutOfRange();
    }
}

void Hero::chooseAim(MonsterVec &rMonsterVec)
{
    //遍历在场怪物列表,将检测到的第一个在攻击范围内的怪物设置为攻击目标
    for(auto & monsterVecIter : rMonsterVec)
    {
        if(monsterVecIter)
        {
            //判断该怪物是否在攻击范围内
            if(isInAtkRange(monsterVecIter->getPosition()))
            {
                //将该怪物设置为攻击目标,并跳出循环
                chooseAtkMonster(*monsterVecIter);
                break;
            }
        }
    }
}

bool Hero::isInAtkRange(const cocos2d::Point &rPos)
{
    bool bRet = false;
    
    do
    {
        auto iDoubleAtkRange = getiAtkRange();
        
        auto heroPos = getPosition();
        
        auto fLength = (rPos - heroPos).getLengthSq();
        
        if(fLength < iDoubleAtkRange * iDoubleAtkRange) bRet = true;
    }
    while (0);
    
    return bRet;
}

void Hero::chooseAtkMonster(Monster &rMonster)
{
    CC_SAFE_RELEASE_NULL(mPAtkMonster);
    CC_SAFE_RETAIN(&rMonster);
    mPAtkMonster = &rMonster;
}

void Hero::atk()
{
    auto pBullet = mPBulletManager->getAnyUnUsedBullet();
    
    if(pBullet)
    {
        pBullet->setPosition(getPosition());
        pBullet->setiAtkValue(getiCurAtk());
        pBullet->lockAmi(*mPAtkMonster);
        
        mBIsAktCoolDown = true;
        scheduleOnce(schedule_selector(Hero::atkCollDownEnd), getiAtkSpeed() / 1000.0f);
    }
}

void Hero::atkCollDownEnd(float dt)
{
    mBIsAktCoolDown = false;
}

void Hero::checkAmiIsOutOfRange()
{
    //判断攻击目标是否存在,并判断是否在攻击范围内,如果不在攻击范围内,则将其忽略
    if(mPAtkMonster)
        if(!isInAtkRange(mPAtkMonster->getPosition()))
            missAtkMonster();
}

void Hero::missAtkMonster()
{
    CC_SAFE_RELEASE_NULL(mPAtkMonster);
}

void Hero::upGrade()
{
    
    if(!getRSprite() || mILevel >= 4) return;
    
    TollgateDataLayer *layer = (TollgateDataLayer*)GlobalClient::getInstance()->getCurTollgateScene()->getChildByTag(TAG_DATA_LAYER);
    
    int iCurMagicNum = layer->getTollgateSoulNum() ;
    
    if(iCurMagicNum < mIUpGradeCostBase * (mILevel + 1)) return;
    
    ++mILevel;
    
    cocos2d::Sprite *pHeroTop = nullptr;
    
    auto contentSize = getRSprite()->getContentSize();
    
    auto pos = cocos2d::Point(contentSize.width / 2, contentSize.height / 2);
    
    if(mILevel == 2)
    {
        pHeroTop = cocos2d::Sprite::create("hero_top_1.png");
        mIBaseAtk += 50;
    }
    else if(mILevel == 3)
    {
        pHeroTop = cocos2d::Sprite::create("hero_top_2.png");
        pHeroTop->setOpacity(255);
        mIBaseAtk += 100;
    }
    else if(mILevel == 4)
    {
        pHeroTop = cocos2d::Sprite::create("hero_top_3.png");
        auto pRotateBy = cocos2d::RotateBy::create(10.0f, 360, 360);
        auto pRepeat = cocos2d::RepeatForever::create(pRotateBy);
        pHeroTop->runAction(pRepeat);
        mIBaseAtk += 1000;
    }
    
    pHeroTop->setPosition(pos);
    
    getRSprite()->addChild(pHeroTop);
    
    setiCurAtk(mIBaseAtk);
    
    std::map<std::string, int> mapUpGradeHero;

    mapUpGradeHero.insert(std::make_pair("UpgradeTollgate", mIUpGradeCostBase * mILevel));
    
    NOTIFY->postNotification("TowerSoulCountChange", reinterpret_cast<cocos2d::Ref*>(&mapUpGradeHero));

}