//
//  MMNormalWin.h
//  testXml2
//
//  Created by 闫鑫 on 14-7-18.
//
//

#ifndef __testXml2__MMNormalWin__
#define __testXml2__MMNormalWin__

#include "MMBase.h"

class MMNormalWin: public MMBase
{
public:
    
    MMNormalWin();
    
    virtual ~MMNormalWin();
    
    virtual bool init();
    
    CREATE_FUNC(MMNormalWin);
    
    virtual void setAnchorPoint(const cocos2d::Point& rAnchorPoint);
    
    virtual void setBG(const std::string &rBgPath);
    
private:
    
    cocos2d::Sprite *mSprint;
};

#endif /* defined(__testXml2__MMNormalWin__) */
