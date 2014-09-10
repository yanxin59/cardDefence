//
//  MMWinXmlData.cpp
//  testXml
//
//  Created by 闫鑫 on 14-7-13.
//
//

#include "MMWinXmlData.h"
#include "GloblaPath.h"

MMWinXmlData::MMWinXmlData():mSScale9bgDown(nullptr), mSScale9bg(nullptr), mSDesName(nullptr), mSText(nullptr), mSBg(nullptr)
{
}

MMWinXmlData::~MMWinXmlData()
{
    CC_SAFE_DELETE(mSDesName);
    
    CC_SAFE_DELETE(mSBg);

    CC_SAFE_DELETE(mSScale9bg);
    
    CC_SAFE_DELETE(mSScale9bgDown);
    
    CC_SAFE_DELETE(mSText);
}

bool MMWinXmlData::init()
{
    mPCldXmlDataVec = new XmlDataVec();
    
    mEnWinType = en_Win_None;
    
    mIX = 0;
    
    mIY = 0;
    
    mITag = 0;
    
    mIAlpha = 255;
    
    mIOrder = LAYERORDER_LVLNORMAL;
    
    mIMarginV = 0;
    
    mIMarginH = 0;
    
    mFAnchorX = 0.5f;
    
    mFAnchorY = 0.5f;
    
    mIFontSize = GLOBLA_FONT_SIZE;

    mFScaleX = 1.0f;
    
    mFScaleY = 1.0f;
    
    mBIsVisible = true;
    
    mBIsEnable = true;
    
    mBIsTouchable = false;
    
    mBIsXLeft = false;
    
    mBIsXRight = false;
    
    mBIsYTop = false;
    
    mBIsYBottom = false;
    
    mBIsXCenter = false;
    
    mBIsYCenter = false;
    
    mBIsMaxWidth = false;
    
    mBIsMaxHeight = false;
    
    mSBg = new std::string("");
    
    mSScale9bg = new std::string("");
    
    mSScale9bgDown = new std::string("");
    
    mSText = new std::string("");
    
    mSDesName = new std::string("");
    
    return true;
}

void MMWinXmlData::addCldXmlDate(MMWinXmlData *cldXmlData)
{
    mPCldXmlDataVec->push_back(cldXmlData);
}

const MMWinXmlData::XmlDataVec* MMWinXmlData::getCldXmlDataList() const
{
    return mPCldXmlDataVec;
}

bool MMWinXmlData::isHasChild() const 
{
    return mPCldXmlDataVec->size() ? true : false;
}

void MMWinXmlData::print()
{
    cocos2d::log("is none: %s, enWinType: %d, x: %d - y: %d", isHasChild() ? "yes" : "no", this->getEnWinType(), this->getiX(), this->getiY());
    print(mPCldXmlDataVec);
}


void MMWinXmlData::print(const MMWinXmlData::XmlDataVec *pXmlDataVec)
{
    if(!pXmlDataVec->size()) return;
    
    for(const auto &xmlDataVecIter : *pXmlDataVec)
    {
        cocos2d::log("is none: %s, enWinType: %d, x: %d - y: %d", xmlDataVecIter->isHasChild() ? "yes" : "no", xmlDataVecIter->getEnWinType(), xmlDataVecIter->getiX(), xmlDataVecIter->getiY());
        if(xmlDataVecIter->isHasChild()) print(xmlDataVecIter->getCldXmlDataList());
    }
}
