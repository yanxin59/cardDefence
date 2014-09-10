//
//  I118N.cpp
//  Chapter14_2_CardDefence01
//
//  Created by 闫鑫 on 14-7-12.
//
//

#include "I18N.h"
#include "CsvUtil.h"
#include <algorithm>

I18N* I18N::mPI18N = nullptr;

I18N::I18N():mPStrDict(nullptr)
{
}

I18N::~I18N()
{
    CC_SAFE_DELETE(mPStrDict);
}

I18N* I18N::getInstance()
{
    if(!mPI18N)
    {
        mPI18N = new I18N();
        if(mPI18N && mPI18N->init()) mPI18N->autorelease();
        else CC_SAFE_DELETE(mPI18N);
    }
    return mPI18N;
}

bool I18N::init()
{
    mPStrDict = new StrDict();
    
    loadStringsFromConf(PATH_I18N_PUBLIC);
    
    return true;
}

std::string I18N::getString(I18N::EnumStrSky enStrKey)
{
    return mPStrDict->size() > enStrKey ? mPStrDict->at(enStrKey).at(1) : std::string("");
}

const char* I18N::getCString(I18N::EnumStrSky enStrKey)
{
    return getString(enStrKey).c_str();
}

const char* I18N::getCStringByKey(const int &rIKey)
{
    return getString((EnumStrSky)rIKey).c_str();
}

void I18N::loadStringsFromConf(const char *cFilePath)
{
    CsvUtil::getInstance()->loadFile(cFilePath);
    
    auto size = CsvUtil::getInstance()->getFileRowColNum(cFilePath);
    
    if(size.width < 2) return;
    
//    mPStrDict = const_cast<StrDict>(CsvUtil::getInstance()->getFileDict(cFilePath));
    const auto dict = CsvUtil::getInstance()->getFileDict(cFilePath);
    for(const auto & iterDict : dict)
        mPStrDict->push_back(iterDict);
}
