//
//  MMWinDesktop.h
//  testXml2
//
//  Created by 闫鑫 on 14-7-15.
//
//

#ifndef __testXml2__MMWinDesktop__
#define __testXml2__MMWinDesktop__

#include "MMBase.h"
#include "GloblaDefine.h"

class MMWinDesktop: public MMBase
{
public:
    MMWinDesktop();
    
    virtual ~MMWinDesktop();
    
    CREATE_FUNC(MMWinDesktop);
    
    virtual bool init();
    
public:
    
    void addWin(MMBase *tPMMWin);
    
    MMBase* getWinByDes(const std::string &rDesName);
    
    void removeAllWins();
    
private:
    
    WinMap *mPWinMap;
};

#endif /* defined(__testXml2__MMWinDesktop__) */
