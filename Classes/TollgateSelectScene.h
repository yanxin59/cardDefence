//
//  TollgateSelectScene.h
//  Chapter14_2_CardDefence01
//
//  Created by 闫鑫 on 14-7-25.
//
//

#ifndef __Chapter14_2_CardDefence01__TollgateSelectScene__
#define __Chapter14_2_CardDefence01__TollgateSelectScene__


#include "GloblaDefine.h"

class TollgateSelectScene:public cocos2d::Layer
{
public:
    
    static cocos2d::Scene *createScene();
    
    CREATE_FUNC(TollgateSelectScene);
    
protected:
    
    virtual void onEnter()override;
    
    virtual void createLevelChooseBtn();
    
    virtual void chooseLevel(cocos2d::Ref *pSender, CONTROL_EVENT event);
    
    virtual bool init();

};

#endif /* defined(__Chapter14_2_CardDefence01__TollgateSelectScene__) */
