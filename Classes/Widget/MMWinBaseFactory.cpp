//
//  MMWinBaseFactory.cpp
//  testXml2
//
//  Created by 闫鑫 on 14-7-15.
//
//

#include "MMWinBaseFactory.h"
#include "MMBase.h"
#include "MMWinManager.h"
#include "MMWinSystem.h"
#include "MMWinDesktop.h"

MMBase *MMWinBaseFactory::createWithByType(EnumWinType enWinType)
{
    MMBase *retMMWin = createWin(enWinType);
    
    //retMMWin->setTag(MMWinManager::getInstance()->getWinSystem()->createUniqueID());
    
    return retMMWin;
}

