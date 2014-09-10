//
//  Entity.cpp
//  Chapter14_2_CardDefence01
//
//  Created by 闫鑫 on 14-7-18.
//
//

#include "Entity.h"

Entity::Entity(): mPSprite(nullptr), mIDefense(1), mIHp(1), mBIsDead(false), mISpeed(1), mILevel(1), mSName("")
{
}

Entity::~Entity()
{
    CC_SAFE_RELEASE_NULL(mPSprite);
}

void Entity::bindSprite(cocos2d::Sprite &rSprite)
{
    if(!&rSprite) return;
    
    if(mPSprite) mPSprite->removeFromParent();
    
    mPSprite = &rSprite;
    mPSprite->retain();
    
    addChild(mPSprite);
    
    onBindSprite();
}

cocos2d::Sprite *Entity::getRSprite()
{
    return mPSprite;
}

void Entity::hurtMe(const int &rIHurtValue)
{
    if(mBIsDead) return;
    
    auto iHurtValue = 0;
    
    if(rIHurtValue < getiDefense()) iHurtValue = rIHurtValue;
    else iHurtValue = getiDefense();
    
    auto iCurHp = getiHp();
    
    auto iAfterHp = iCurHp - iHurtValue;
    
    onHurt(iHurtValue);
    
    if(iAfterHp > 0) setiHp(iAfterHp);
    else
    {
        mBIsDead = true;
        onDead();
    }
}

void Entity::onExit()
{
    Node::onExit();
    unscheduleAllSelectors();
}

cocos2d::Rect Entity::boundingBox()
{
    if(!getRSprite())
        return cocos2d::Rect::ZERO;
    return mPSprite->getBoundingBox();
}

bool Entity::isDead()
{
    return mBIsDead;
}

void Entity::onDead()
{
}

void Entity::onBindSprite()
{
}

void Entity::onHurt(const int &rIHurtValue)
{
}