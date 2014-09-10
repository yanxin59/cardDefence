//
//  MMWinSystem.cpp
//  testXml2
//
//  Created by 闫鑫 on 14-7-15.
//
//

#include "MMWinSystem.h"
#include "MMWinXmlData.h"
#include "MMWinDesktop.h"
#include "MMWinPropertyFactory.h"
#include "MMWinFactory.h"

MMWinSystem::MMWinSystem():mPWinBaseFactory(nullptr), mPWinPropertyFactory(nullptr), mIWinID(0)
{
}

MMWinSystem::~MMWinSystem()
{
    CC_SAFE_RELEASE_NULL(mPWinPropertyFactory);
    
    CC_SAFE_RELEASE_NULL(mPWinBaseFactory);
}

bool MMWinSystem::init()
{
    bool bRet = false;
    
    do
    {
        mPWinPropertyFactory = MMWinPropertyFactory::create();
        mPWinPropertyFactory->retain();
        
        mPWinBaseFactory = MMWinFactory::create();
        mPWinBaseFactory->retain();
        
        bRet = true;
    }
    while (0);
    
    return bRet;
}

MMWinDesktop *MMWinSystem::createDesktopByXmlData(MMWinXmlData &rXmlData, const bool &rIsHasParent)
{
    auto pWinDesktop = MMWinDesktop::create();
    
    auto pWins = createWins(*pWinDesktop, rXmlData, rIsHasParent);
    if(pWins->isHasChildWin()) dressProertiesByType(*pWins, rXmlData);
    
    pWinDesktop->addChild(pWins, LAYER_DESKTOP, DESKTOP_NODE_TAG);
    return pWinDesktop;
}

MMBase *MMWinSystem::createWins(MMWinDesktop &rWinDesktop, MMWinXmlData &rXmlData, const bool &rIsHasParent)
{
    auto retBaseWin = createWinByXmlData(rXmlData);
    
    retBaseWin->setHasParentWin(rIsHasParent);
    
    retBaseWin->setHasChildWin(rXmlData.isHasChild());
    
    dressProertiesByType(*retBaseWin, rXmlData);
    
    if(rXmlData.isHasChild())
    {
        /*
         得到下一层子节点列表，并对其递归遍历
         */
        const auto pCldXmlDataList = rXmlData.getCldXmlDataList();
        
        if (pCldXmlDataList->size())
        {
            for(const auto &iter : *pCldXmlDataList)
            {
                //                cocos2d::log("enWinType: %d", (int)(iter->getEnWinType()));
                auto pCldWin = createWins(rWinDesktop, *iter, true);
                retBaseWin->addChild(pCldWin, 0, pCldWin->getTag());
                rWinDesktop.addWin(pCldWin);
            }
        }
    }
    return retBaseWin;
}

void MMWinSystem::dressProertiesByType(MMBase &rWin, MMWinXmlData &rXmlData)
{
    mPWinPropertyFactory->dressPropertiesByType(rWin, rXmlData);
}

int MMWinSystem::createUniqueID()
{
    return ++mIWinID;
}

MMBase *MMWinSystem::createWinByXmlData(MMWinXmlData &pXmlData)
{
    return createWinByType(pXmlData.getEnWinType());
}

MMBase *MMWinSystem::createWinByType(EnumWinType enWinType)
{
    return mPWinBaseFactory->createWithByType(enWinType);
}


