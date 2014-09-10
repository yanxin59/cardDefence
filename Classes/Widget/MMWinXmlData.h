//
//  MMWinXmlData.h
//  testXml
//
//  Created by 闫鑫 on 14-7-13.
//
//

#ifndef __testXml__MMWinXmlData__
#define __testXml__MMWinXmlData__


#include "GloblaDefine.h"

class MMWinXmlData: public cocos2d::Ref
{
public:
    
    MMWinXmlData();
    
    virtual ~MMWinXmlData();
    
    typedef std::vector<MMWinXmlData*> XmlDataVec;

    virtual bool init();
  
    CREATE_FUNC(MMWinXmlData);
    
    void addCldXmlDate(MMWinXmlData *cldXmlData);
    
    const MMWinXmlData::XmlDataVec* getCldXmlDataList() const;
    
    bool isHasChild() const;
    
    void print();
    
protected:
    void print(const MMWinXmlData::XmlDataVec *pXmlDataVec);
    
private:
    
    XmlDataVec* mPCldXmlDataVec;
    
private:
    
    CC_PRIVATE(EnumWinType, mEnWinType, EnWinType);
    
    CC_PRIVATE(int, mIX, iX);
    
    CC_PRIVATE(int, mIY, iY);
        
    CC_PRIVATE(int, mITag, iTag)
    
    CC_PRIVATE(int, mIWidth, iWidth)
    
    CC_PRIVATE(int, mIHeight, iHeight)
    
    CC_PRIVATE(int, mIAlpha, iAlpha)
    
    CC_PRIVATE(int, mIOrder, iOrder)
    
    CC_PRIVATE(int, mIMarginV, iMarginV)
    
    CC_PRIVATE(int, mIMarginH, iMarginH)
    
    CC_PRIVATE(int, mIFontSize, iFontSize)
    
    CC_PRIVATE(float, mFAnchorX, fAnchorX)
    
    CC_PRIVATE(float, mFAnchorY, fAnchorY)
    
    CC_PRIVATE(float, mFScaleX, fScaleX)
    
    CC_PRIVATE(float, mFScaleY, fScaleY)
    
    CC_PRIVATE_BOOL(mBIsVisible, bVisible)
    
    CC_PRIVATE_BOOL(mBIsEnable, bEnable)
    
    CC_PRIVATE_BOOL(mBIsTouchable, bTouchable)
    
    CC_PRIVATE_BOOL(mBIsXLeft, XLeft)
    
    CC_PRIVATE_BOOL(mBIsXRight, XRight)
    
    CC_PRIVATE_BOOL(mBIsXCenter, XCenter)
    
    CC_PRIVATE_BOOL(mBIsYTop, YTop)
    
    CC_PRIVATE_BOOL(mBIsYBottom, YBottom)
    
    CC_PRIVATE_BOOL(mBIsYCenter, YCenter)
    
    CC_PRIVATE_BOOL(mBIsMaxWidth, MaxWidth)
    
    CC_PRIVATE_BOOL(mBIsMaxHeight, MaxHeight)
    
    MM_XML_PRIVATE_StdStr(mSDesName, sDesName)
    
    MM_XML_PRIVATE_StdStr(mSScale9bg, sScale9bg)
    
    MM_XML_PRIVATE_StdStr(mSScale9bgDown, sScale9bgDown)
    
    MM_XML_PRIVATE_StdStr(mSBg, sBg)
    
    MM_XML_PRIVATE_StdStr(mSText, sText)
};


#endif /* defined(__testXml__MMWinXmlData__) */
