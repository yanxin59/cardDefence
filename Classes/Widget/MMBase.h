//
//  MMBase.h
//  testXml2
//
//  Created by 闫鑫 on 14-7-14.
//
//

#ifndef __testXml2__MMBase__
#define __testXml2__MMBase__

#include "GloblaDefine.h"

class MMBase: public cocos2d::Node
{
public:
    MMBase(): mEnWinType(en_Win_None), mBHasParentWin(false), mBHasChildWin(true), mSDesName(new std::string("")){}
    
    virtual ~MMBase()
    {
        CC_SAFE_DELETE(mSDesName);
    }
    
private:
    
    CC_PRIVATE(EnumWinType, mEnWinType, EnWinType)
    
    CC_PRIVATE_BOOL(mBHasParentWin, HasParentWin)
    
    CC_PRIVATE_BOOL(mBHasChildWin, HasChildWin)
        
    CC_PRIVATE(int, mITag, Tag)
    
    CC_PRIVATE(int, mIOrder, Order)
    
    MM_XML_PRIVATE_StdStr(mSDesName, sDesName)
};

#endif /* defined(__testXml2__MMBase__) */
