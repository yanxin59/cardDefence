//
//  MMWinXmlDataSetting.h
//  testXml2
//
//  Created by 闫鑫 on 14-7-14.
//
//

#ifndef __testXml2__MMWinXmlDataSetting__
#define __testXml2__MMWinXmlDataSetting__

#include "GloblaDefine.h"
#include "MMWinXmlData.h"

class MMWinXmlDataSetting: public cocos2d::Ref
{
public:
    CREATE_FUNC(MMWinXmlDataSetting);
    
    virtual bool init();
    
    virtual void setXmlDataProperty(MMWinXmlData &xmlData, const char* sName, const char* sText);
    
public:
    void setXmlEnWinType(MMWinXmlData &xmlData, const char *sText);
private:
    
    EnumWinType mEnWinType;
    
    MM_SET_XML_INT(iX)
    MM_SET_XML_INT(iY)
    MM_SET_XML_INT(iTag)
    MM_SET_XML(sBg)
    MM_SET_XML(sText)
    MM_SET_XML_INT(iWidth)
    MM_SET_XML_INT(iHeight)
    MM_SET_XML_INT(iAlpha);
    MM_SET_XML_FLOAT(fScaleX)
    MM_SET_XML_FLOAT(fScaleY)
//    MM_SET_XML(bVisible)
//    MM_SET_XML(bEnable)
//    MM_SET_XML(bTouchable)
    MM_SET_XML(sDesName)
    MM_SET_XML(sScale9bg)
    MM_SET_XML(sScale9bgDown)
    MM_SET_XML_FLOAT(fAnchorX)
    MM_SET_XML_FLOAT(fAnchorY)
    MM_SET_XML_INT(iMarginH)
    MM_SET_XML_INT(iMarginV)
    MM_SET_XML_INT(iFontSize)
    
};

#endif /* defined(__testXml2__MMWinXmlDataSetting__) */
