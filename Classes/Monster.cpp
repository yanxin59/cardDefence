//
//  Monster.cpp
//  Chapter14_2_CardDefence01
//
//  Created by 闫鑫 on 14-7-19.
//
//

#include "Monster.h"
#include "ControllerSimpleMove.h"
#include "CsvUtil.h"
#include "WidgetHPSlot.h"

Monster::Monster():mPMoveController(nullptr), mPHpSlider(nullptr), mBIsMoveEnd(false)
{
    mISpeed = en_Monster_Prop_Conf_Speed;
}

Monster::~Monster()
{
    CC_SAFE_RELEASE_NULL(mPMoveController);
    CC_SAFE_RELEASE_NULL(mPHpSlider);
}

bool Monster::init()
{
    bool bRet = false;
    
    do
    {
        mPMoveController = ControllerSimpleMove::create(*this, SEL_CallFuncY(&Monster::moveEnd));
        mPMoveController->retain();
        
        addChild(mPMoveController);
        bRet = true;
    }
    while (0);
    return true;
}

Monster *Monster::createFromCsvFileById(const int &rIMonsterId)
{
    auto pMonster = new Monster();
    if(pMonster && pMonster->initFromCsvFileById(rIMonsterId)) pMonster->autorelease();
    else CC_SAFE_DELETE(pMonster);
    return pMonster;
}

bool Monster::initFromCsvFileById(const int &rIMonsterId)
{
    bool bRet = false;
    
    do
    {
        CC_BREAK_IF(!init());
        
        auto pCsvUtil = CsvUtil::getInstance();
        
        auto chMonsterId = cocos2d::StringUtils::format("%d", rIMonsterId);
        
        auto iLine = pCsvUtil->findValueInWithLine(chMonsterId.c_str(), en_Monster_Prop_Conf_Id, PATH_CSV_MONSTER_CONF);
    
        
        CC_BREAK_IF(iLine < 0);
        
        setiId(rIMonsterId);
        
        setsName(pCsvUtil->get(iLine, en_Monster_Prop_Conf_Name, PATH_CSV_MONSTER_CONF));
        
        setiLevel(pCsvUtil->getInt(iLine, en_Monster_Prop_Conf_Level, PATH_CSV_MONSTER_CONF));
        
        setiModelId(pCsvUtil->getInt(iLine, en_Monster_Prop_Conf_ModelId, PATH_CSV_MONSTER_CONF));
        
        setiDefense(pCsvUtil->getInt(iLine, en_Monster_Prop_Conf_Defense, PATH_CSV_MONSTER_CONF));
        
        setiHp(pCsvUtil->getInt(iLine, en_Monster_Prop_Conf_Hp, PATH_CSV_MONSTER_CONF));
        
        setiSpeed(pCsvUtil->getInt(iLine, en_Monster_Prop_Conf_Speed, PATH_CSV_MONSTER_CONF));
        
        loadAnimation();
        
        bRet = true;
    }
    while (0);
    
    return bRet;
}

void Monster::loadAnimation()
{
    auto sFileName = cocos2d::StringUtils::format("monster_%d.png", mIModelId);
    auto pAnimation = cocos2d::Animation::create();
    auto pAnimationCache = cocos2d::AnimationCache::getInstance();
    std::string vec[4]{"down", "left", "right", "up"};
    for(int i = 0; i < 4; ++i)
    {
        for (int j = 0; j < 4; ++j)
        {
            pAnimation->addSpriteFrame(cocos2d::SpriteFrame::create(sFileName.c_str(), cocos2d::Rect(j * 32, i * 48, 32, 48)));
        }
        pAnimation->setDelayPerUnit(0.1f);
        pAnimation->setLoops(-1);
        pAnimationCache->addAnimation(pAnimation, vec[i].c_str());
    }
}

void Monster::moveByPosList(const PosVec &rPosVec)
{
    if(rPosVec.size() > 0) mPMoveController->moveByPosList(rPosVec, getiSpeed(), 1);
}

void Monster::move(const std::string &rVec2)
{
    auto pAnimationCache = cocos2d::AnimationCache::getInstance();
    mPSprite->runAction(cocos2d::Animate::create(pAnimationCache->getAnimation(rVec2)));
}

void Monster::onDead()
{
    stopAllActions();
    removeFromParentAndCleanup(true);
    NOTIFY->postNotification("MonsterDead");
}

void Monster::onBindSlider()
{
    if(!mPHpSlider)
    {
        cocos2d::Point pos = getPosition();
        
        mPHpSlider = WidgetHPSlot::create(*this);
        mPHpSlider->setPosition(cocos2d::Point(pos.x, pos.y + getRSprite()->getContentSize().height / 2));
        mPHpSlider->getSlider()->setMaximumValue(getiHp());
        mPHpSlider->getSlider()->setMinimumValue(0);
        mPHpSlider->getSlider()->setValue(getiHp());
        mPHpSlider->retain();

        addChild(mPHpSlider);
    }
}

void Monster::onBindSprite()
{
    onBindSlider();
}

void Monster::onHurt(const int &rIHurtValue)
{
    if(mPHpSlider)
    {
        int iCurValue = mPHpSlider->getSlider()->getValue();
        
        iCurValue -= rIHurtValue;
        
        if(iCurValue < 0) iCurValue = 0;
        
        mPHpSlider->getSlider()->setValue(iCurValue);
    }
}

void Monster::moveEnd()
{
    //将怪物从父节点删除
    stopAllActions();
    removeFromParentAndCleanup(true);
    mBIsMoveEnd = true;
    
    std::map<std::string, int> mapMonsterInfo;
    mapMonsterInfo.insert(std::make_pair("MoveEnd", -10));
    NOTIFY->postNotification("MagicCountChange", reinterpret_cast<cocos2d::Ref*>(&mapMonsterInfo));
}
