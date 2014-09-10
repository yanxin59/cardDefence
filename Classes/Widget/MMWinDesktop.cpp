//
//  MMWinDesktop.cpp
//  testXml2
//
//  Created by 闫鑫 on 14-7-15.
//
//

#include "MMWinDesktop.h"


MMWinDesktop::MMWinDesktop():mPWinMap(nullptr)
{
}

MMWinDesktop::~MMWinDesktop()
{
    CC_SAFE_DELETE(mPWinMap);
}

bool MMWinDesktop::init()
{
    mPWinMap = new WinMap();
    return true;
}

void MMWinDesktop::addWin(MMBase *tPMMWin)
{
    
    auto iterWinMap = mPWinMap->find(tPMMWin->getsDesName());
    if(iterWinMap != mPWinMap->end()) mPWinMap->erase(iterWinMap);
    
    mPWinMap->insert(tPMMWin->getsDesName(), tPMMWin);
}

MMBase *MMWinDesktop::getWinByDes(const std::string &rDesName)
{
    auto iterWinMap = mPWinMap->find(rDesName);
    
    return iterWinMap == mPWinMap->end() ? nullptr : iterWinMap->second;
}

void MMWinDesktop::removeAllWins()
{
    mPWinMap->clear();
    removeAllChildrenWithCleanup(true);
}
