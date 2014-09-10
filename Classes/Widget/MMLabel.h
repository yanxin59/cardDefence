//
//  MMLabel.h
//  testXml2
//
//  Created by 闫鑫 on 14-7-18.
//


#ifndef __testXml2__MMLabel__
#define __testXml2__MMLabel__

#include "MMBase.h"

class MMLabel: public MMBase
{
    
public:
    
    MMLabel();
    
    virtual ~MMLabel();
    
    CREATE_FUNC(MMLabel)
    
    virtual bool init();
    
    virtual void setAnchorPoint(const cocos2d::Point& rAnchorPoint);
    
    void setsText(const std::string &rSValue);
    
    void setsText(const int &rIValue);
    
    void setiFontSize(const int &rIFontSize);
    
    void setColorRGB(const int& rIR, const int& rIG, const int&rIB);
    
private:
    
    cocos2d::Label* mLabel;
    
};
#endif /* defined(__testXml2__MMLabel__) */
