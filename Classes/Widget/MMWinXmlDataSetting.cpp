//
//  MMWinXmlDataSetting.cpp
//  testXml2
//
//  Created by 闫鑫 on 14-7-14.
//
//

#include "MMWinXmlDataSetting.h"

bool MMWinXmlDataSetting::init()
{
    return true;
}

void MMWinXmlDataSetting::setXmlDataProperty(MMWinXmlData &rXmlData, const char *sName, const char *sText)
{
    if(std::string(sName) == XML_VALUE_enWinType) setXmlEnWinType(rXmlData, sText);
    else if(std::string(sName) == XML_VALUE_x) setXmliX(rXmlData, sText);
    else if(std::string(sName) == XML_VALUE_y) setXmliY(rXmlData, sText);
    else if(std::string(sName) == XML_VALUE_bg) setXmlsBg(rXmlData, sText);
    else if(std::string(sName) == XML_VALUE_tag) setXmliTag(rXmlData, sText);
    else if(std::string(sName) == XML_VALUE_text) setXmlsText(rXmlData, sText);
    else if(std::string(sName) == XML_VALUE_width) setXmliWidth(rXmlData, sText);
    else if(std::string(sName) == XML_VALUE_height) setXmliHeight(rXmlData, sText);
    else if(std::string(sName) == XML_VALUE_scaleX) setXmlfScaleX(rXmlData, sText);
    else if(std::string(sName) == XML_VALUE_scaleY) setXmlfScaleY(rXmlData, sText);
    else if(std::string(sName) == XML_VALUE_AnchorX) setXmlfAnchorX(rXmlData, sText);
    else if(std::string(sName) == XML_VALUE_AnchorY) setXmlfAnchorY(rXmlData, sText);
    else if(std::string(sName) == XML_VALUE_alpha) setXmliAlpha(rXmlData, sText);
    else if(std::string(sName) == XML_VALUE_fontSize) setXmliFontSize(rXmlData, sText);
    else if(std::string(sName) == XML_VALUE_marginH) setXmliMarginH(rXmlData, sText);
    else if(std::string(sName) == XML_VALUE_marginV) setXmliMarginV(rXmlData, sText);
    else if(std::string(sName) == XML_VALUE_scale9bg) setXmlsScale9bg(rXmlData, sText);
    else if(std::string(sName) == XML_VALUE_scale9bgDown) setXmlsScale9bgDown(rXmlData, sText);
    else if(std::string(sName) == XML_VALUE_des) setXmlsDesName(rXmlData, sText);
//    else if(std::string(sName) == XML_VALUE_touchable) setXmlbTouchable(xmlData, sText);
//    else if(std::string(sName) == XML_VALUE_visible) setXmlbVisible(xmlData, sText);
//    else if(std::string(sName) == XML_VALUE_enable) setXmlbEnable(xmlData, sText);
}

void MMWinXmlDataSetting::setXmlEnWinType(MMWinXmlData &rXmlData, const char *sText)
{
//    cocos2d::log("value %s", sText);
    if(std::string(sText) == WINType_C_en_Win_None) rXmlData.setEnWinType(en_Win_None);
    else if(std::string(sText) == WINType_C_en_Win_NormalWin) rXmlData.setEnWinType(en_Win_NormalWin);
    else if(std::string(sText) == WINType_C_en_Win_Label) rXmlData.setEnWinType(en_Win_Label);
}
