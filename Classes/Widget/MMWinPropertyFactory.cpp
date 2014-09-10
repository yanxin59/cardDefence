//
//  MMWinProperityFactory.cpp
//  testXml2
//
//  Created by 闫鑫 on 14-7-16.
//
//

#include "MMWinPropertyFactory.h"
#include "MMWinXmlData.h"
#include "MMLabel.h"
#include "MMNormalWin.h"

bool MMWinPropertyFactory::init()
{
    return true;
}

void MMWinPropertyFactory::dressPropertiesByType(MMBase &rWin, MMWinXmlData &rXmlData)
{
    switch (rWin.getEnWinType())
    {
        case en_Win_None:
            break;
        case en_Win_Label:
            dressMMLabel(dynamic_cast<MMLabel&>(rWin), rXmlData);
            break;
        case en_Win_NormalWin:
            dressMMNormalWin(dynamic_cast<MMNormalWin&>(rWin), rXmlData);
            break;
        default:
            break;
    }
    dressBaseProperties(rWin, rXmlData);
}

void MMWinPropertyFactory::dressBaseProperties(MMBase &rWin, MMWinXmlData &rXmlData)
{
    MMBase *mmParent = nullptr;
    
    if(rWin.isHasParentWin()) mmParent = static_cast<MMBase*>(rWin.getParent());
    
    int iPosOffset = 1;
    
    if(!mmParent) iPosOffset = -1;
    
    rWin.setsDesName(rXmlData.getsDesName());
    
//    mmWin->setPosition(cocos2d::Point(xmlData->getiX(), xmlData->getiY() * iPosOffset));
}

void MMWinPropertyFactory::dressMMNormalWin(MMNormalWin &rNormalWin, MMWinXmlData &rXmlData)
{
    rNormalWin.setBG(rXmlData.getsBg());
    rNormalWin.setPosition(cocos2d::Point(rXmlData.getiX(), rXmlData.getiY()));
}

void MMWinPropertyFactory::dressMMLabel(MMLabel &rLabel, MMWinXmlData &rXmlData)
{
    rLabel.setsText(rXmlData.getsText());
    rLabel.setPosition(cocos2d::Point(rXmlData.getiX(), rXmlData.getiY()));
    rLabel.setiFontSize(rXmlData.getiFontSize());
}