//
//  MMRoundOprBtn.cpp
//  Chapter14_2_CardDefence01
//
//  Created by 闫鑫 on 14-7-24.
//
//

#include "MMRoundOprBtn.h"
#include "Header.h"

bool MMRoundOprBtn::init()
{
    bool bRet = false;
    
    do
    {
        int iDistance = DEFAULT_DISTANCE;

        addOneBtn(nullptr, cocos2d::Point(iDistance, 0));
        addOneBtn(nullptr, cocos2d::Point(0, -iDistance));
        addOneBtn(nullptr, cocos2d::Point(-iDistance, 0));
        addOneBtn(nullptr, cocos2d::Point(0, iDistance));
        
        bRet = true;
    }
    while (0);

    return bRet;
}

MMRoundOprBtn *MMRoundOprBtn::createWithControlButtons(CONTROLBTN *pBtn1,
                                                       CONTROLBTN *pBtn2,
                                                       CONTROLBTN *pBtn3,
                                                       CONTROLBTN *pBtn4)
{

    auto pMMRoundOprBtn = new MMRoundOprBtn();
    
    if(pMMRoundOprBtn && pMMRoundOprBtn->initWithControlButtons(pBtn1, pBtn2, pBtn3, pBtn4)) pMMRoundOprBtn->autorelease();
    else CC_SAFE_DELETE(pMMRoundOprBtn);
    
    return pMMRoundOprBtn;
}

bool MMRoundOprBtn::initWithControlButtons(CONTROLBTN *pBtn1,
                                           CONTROLBTN *pBtn2,
                                           CONTROLBTN *pBtn3,
                                           CONTROLBTN *pBtn4)
{
    
    bool bRet = false;
    
    do
    {
        int iDistance = DEFAULT_DISTANCE;
        
        addOneBtn(pBtn1, cocos2d::Point(iDistance, 0));
        addOneBtn(pBtn2, cocos2d::Point(0, -iDistance));
        addOneBtn(pBtn3, cocos2d::Point(-iDistance, 0));
        addOneBtn(pBtn4, cocos2d::Point(0, iDistance));
        
        bRet = true;
    
    }
    while (0);

    return bRet;
}
void MMRoundOprBtn::addOneBtn(cocos2d::Node *pNode, cocos2d::Vec2 rPos)
{
    if(nullptr == pNode)
    {
        pNode = cocos2d::Sprite::create("border_2.png");
    }
    
    addChild(pNode);
    
    auto pMoveOut = cocos2d::MoveBy::create(2.2f, rPos);
    auto pMoveBack = cocos2d::EaseElasticOut::create(pMoveOut);
    
    pNode->runAction(pMoveBack);

}

void MMRoundOprBtn::deleteMe()
{
    removeFromParentAndCleanup(true);
}