//
//  MMWinProperityFactory.h
//  testXml2
//
//  Created by 闫鑫 on 14-7-16.
//
//

#ifndef __testXml2__MMWinPropertyFactory__
#define __testXml2__MMWinPropertyFactory__

#include "GloblaDefine.h"

//控件属性设置工厂
class MMWinPropertyFactory: public cocos2d::Ref
{
public:
    
    CREATE_FUNC(MMWinPropertyFactory)
    
    virtual bool init();
    
public:
    /*给控件设置属性*/
    void dressPropertiesByType(MMBase &rWin, MMWinXmlData &rXmlData);
    
private:
    /*设置控件的公共属性*/
    void dressBaseProperties(MMBase &rWin, MMWinXmlData &rXmlData);
    
private:
    
    void dressMMNormalWin(MMNormalWin &rNormalWin, MMWinXmlData &rXmlData);
    
    void dressMMLabel(MMLabel &rLabel, MMWinXmlData &rXmlData);
};

#endif /* defined(__testXml2__MMWinProperityFactory__) */
