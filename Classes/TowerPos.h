//
//  TowerPos.h
//  Chapter14_2_CardDefence01
//
//  Created by 闫鑫 on 14-6-22.
//
//

#ifndef __Chapter14_2_CardDefence01__TowerPos__
#define __Chapter14_2_CardDefence01__TowerPos__

#include "PosBase.h"

#define RADIUS 32

class TowerPos : public PosBase
{
public:
    TowerPos();
    
    virtual ~TowerPos();
    
    static TowerPos * create(cocos2d::Point pos);
    
    static TowerPos * create(cocos2d::Point pos, bool isDebug);
    
protected:
    virtual bool init(cocos2d::Point pos);
    
    virtual bool init(cocos2d::Point pos, bool isDebug);
    
    void draw(cocos2d::Renderer *renderer, const cocos2d::Mat4 &transform, bool transformUpdated);
    
};

#endif /* defined(__Chapter14_2_CardDefence01__TowerPos__) */
