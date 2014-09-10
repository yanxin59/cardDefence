//
//  TollgateGameOverScene.h
//  Chapter14_2_CardDefence01
//
//  Created by 闫鑫 on 14-8-9.
//
//

#ifndef __Chapter14_2_CardDefence01__TollgateGameOverScene__
#define __Chapter14_2_CardDefence01__TollgateGameOverScene__

#include "cocos2d.h"

class TollgateGameOverScene:public cocos2d::Scene
{
public:
    
    CREATE_FUNC(TollgateGameOverScene);

protected:
    
    virtual bool init();
    
    virtual void backToTollgateSelectScene(const float dt);
};

#endif /* defined(__Chapter14_2_CardDefence01__TollgateGameOverScene__) */
