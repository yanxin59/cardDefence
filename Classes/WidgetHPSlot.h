//
//  WidgetHPSlot.h
//  Chapter14_2_CardDefence01
//
//  Created by 闫鑫 on 14-7-23.
//
//

#ifndef __Chapter14_2_CardDefence01__WidgetHPSlot__
#define __Chapter14_2_CardDefence01__WidgetHPSlot__

#include "GloblaDefine.h"

class Entity;

class WidgetHPSlot:public cocos2d::Node
{
public:
    
    WidgetHPSlot();
    
    virtual ~WidgetHPSlot();
    
    static WidgetHPSlot *create(Entity &rEntity);
    
    virtual cocos2d::extension::ControlSlider *getSlider();
    
protected:
    
    virtual bool init(Entity &rEntity);
    
private:
    
    Entity *mPEntity;
    
    cocos2d::extension::ControlSlider *mPSlider;
    
};

#endif /* defined(__Chapter14_2_CardDefence01__WidgetHPSlot__) */
