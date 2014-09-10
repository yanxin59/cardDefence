//
//  Hero.h
//  Chapter14_2_CardDefence01
//
//  Created by 闫鑫 on 14-7-19.
//
//

#ifndef __Chapter14_2_CardDefence01__Hero__
#define __Chapter14_2_CardDefence01__Hero__


#include "GloblaDefine.h"
#include "Entity.h"

class Hero:public Entity
{
public:
    
    Hero();
    
    virtual ~Hero();
    
//    static Hero *create(cocos2d::Sprite &pSprite);
    //读取csv文件,通过传入id创建英雄
    static Hero *createFromCsvById(const int &rIHeroId);
    
    //升级英雄
    void upGrade();
    //检测周围怪物
    void checkAtkMonster(float dt);
    //从怪物列表中选择攻击目标
    void chooseAim(MonsterVec &rMonsterVec);
    //指定攻击目标
    void chooseAtkMonster(Monster &rMonster);
    //检测攻击冷却
    void atkCollDownEnd(float dt);
    //攻击
    void atk();
    //检测怪物是否在攻击范围内
    void checkAmiIsOutOfRange();
    //检测是否在攻击范围内
    bool isInAtkRange(const cocos2d::Point &rPos);
    //错过攻击目标
    void missAtkMonster();
    
protected:
    
    bool init(cocos2d::Sprite &pSprite);
    
    bool initFromCsvFileById(const int &rIHeroId);
    
private:
    
    bool mBIsAktCoolDown;
    
    Monster *mPAtkMonster;
    
    BulletManager *mPBulletManager;
    
    CC_PRIVATE(EnumHeroType, mEnHeroType, HeroType)
    
    CC_PRIVATE(int, mIBaseAtk, iBaseAtk)
    
    CC_PRIVATE(int, mICurAtk, iCurAtk)
    
    CC_PRIVATE(int, mIAtkSpeed, iAtkSpeed)
    
    CC_PRIVATE(int, mIAtkRange, iAtkRange)
    
    CC_PRIVATE(int, mIUpGradeCostBase, iUpGradeCostBase)
    
    CC_PRIVATE(float, mFUpGradeAtkBase, fUpGradeAtkBase)
};

#endif /* defined(__Chapter14_2_CardDefence01__Hero__) */
