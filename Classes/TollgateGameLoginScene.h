//
//  TollgateGameLoginScene.h
//  cardDefence
//
//  Created by 闫鑫 on 14-8-19.
//
//

#ifndef __cardDefence__TollgateGameLoginScene__
#define __cardDefence__TollgateGameLoginScene__

#include "GloblaDefine.h"

class TollgateGameLoginScene: public cocos2d::Layer
{
public:
    
    CREATE_FUNC(TollgateGameLoginScene);
    
    static cocos2d::Scene *createScene();
protected:
    
    virtual bool init();
    
    virtual void onEnter()override;
    
    virtual void loadSource();
    
    virtual void selectScene(cocos2d::Ref *, CONTROL_EVENT);

};

#endif /* defined(__cardDefence__TollgateGameLoginScene__) */
