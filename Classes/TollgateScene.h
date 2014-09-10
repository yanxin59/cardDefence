//
//  TollgateScene.h
//  Chapter14_2_CardDefence01
//
//  Created by 闫鑫 on 14-7-14.
//
//

#ifndef __Chapter14_2_CardDefence01__TollgateScene__
#define __Chapter14_2_CardDefence01__TollgateScene__

#include "GloblaDefine.h"

class TollgateScene: public cocos2d::Scene
{
    
public:
    
    CREATE_FUNC(TollgateScene);
    
protected:
    
    virtual bool init();
    
    virtual void onEnter()override;
    
    virtual void onExit()override;
    
};

#endif /* defined(__Chapter14_2_CardDefence01__TollgateScene__) */
