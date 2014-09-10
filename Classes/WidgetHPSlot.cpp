//
//  WidgetHPSlot.cpp
//  Chapter14_2_CardDefence01
//
//  Created by 闫鑫 on 14-7-23.
//
//

#include "WidgetHPSlot.h"
#include "Entity.h"

WidgetHPSlot::WidgetHPSlot():mPEntity(nullptr), mPSlider(nullptr){}

WidgetHPSlot::~WidgetHPSlot()
{
    CC_SAFE_RELEASE_NULL(mPSlider);
    
    CC_SAFE_RELEASE_NULL(mPEntity);
}

WidgetHPSlot *WidgetHPSlot::create(Entity &rEntity)
{
    auto pHpSlot = new WidgetHPSlot();
    
    if(pHpSlot && pHpSlot->init(rEntity)) pHpSlot->autorelease();
    else CC_SAFE_DELETE(pHpSlot);
    
    return pHpSlot;
}

bool WidgetHPSlot::init(Entity &rEntity)
{
    bool bRet = false;
    do
    {
        CC_BREAK_IF(!&rEntity);
        
        CC_SAFE_RETAIN(&rEntity);
        
        mPEntity = &rEntity;
        
        mPSlider = cocos2d::extension::ControlSlider::create("sliderBg.png", "sliderValue.png", "sliderThumb.png");
        
        mPSlider->setEnabled(false);
        
        addChild(mPSlider);
        
        bRet = true;
    }
    while (0);
    return bRet;
}

cocos2d::extension::ControlSlider *WidgetHPSlot::getSlider()
{
    return mPSlider;
}