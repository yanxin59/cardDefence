//
//  MMNormalWin.cpp
//  testXml2
//
//  Created by 闫鑫 on 14-7-18.
//
//

#include "MMNormalWin.h"

MMNormalWin::MMNormalWin():mSprint(nullptr){}

MMNormalWin::~MMNormalWin(){}

bool MMNormalWin::init()
{
    return true;
}

void MMNormalWin::setBG(const std::string &rBgPath)
{
    if(mSprint) this->removeChild(mSprint);
    
    mSprint = cocos2d::Sprite::create(rBgPath.c_str());
    mSprint->setPosition(cocos2d::Vec2(60, 40));
    mSprint->setOpacity(120);
    
    this->addChild(mSprint);
}

void MMNormalWin::setAnchorPoint(const cocos2d::Point &rAnchorPoint)
{
    cocos2d::Node::setAnchorPoint(rAnchorPoint);
    mSprint->setAnchorPoint(rAnchorPoint);
}