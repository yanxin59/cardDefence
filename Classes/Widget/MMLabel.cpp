//
//  MMLabel.cpp
//  testXml2
//
//  Created by 闫鑫 on 14-7-18.
//
//

#include "MMLabel.h"

MMLabel::MMLabel():mLabel(nullptr){}

MMLabel::~MMLabel(){}

bool MMLabel::init()
{
    MMBase::init();

    mLabel = cocos2d::Label::createWithSystemFont("", "Arial", 40);
    
    addChild(mLabel);
    return true;
}

void MMLabel::setsText(const std::string &rSValue)
{
    mLabel->setString(rSValue);
}

void MMLabel::setsText(const int &rIValue)
{
    mLabel->setString(cocos2d::__String::createWithFormat("%d", rIValue)->getCString());
}

void MMLabel::setiFontSize(const int &rIFontSize)
{
    mLabel->setSystemFontSize(rIFontSize);
}

void MMLabel::setColorRGB(const int &rIR, const int &rIG, const int &rIB)
{
    mLabel->setColor(cocos2d::Color3B(rIR, rIG, rIB));
}

void MMLabel::setAnchorPoint(const cocos2d::Point &rAnchorPoint)
{
    cocos2d::Node::setAnchorPoint(rAnchorPoint);
    mLabel->setAnchorPoint(rAnchorPoint);
}