//
//  CsvUtil.cpp
//  Chapter14_2_CardDefence01
//
//  Created by 闫鑫 on 14-7-11.
//
//

#include "CsvUtil.h"
#include "FileLoadUtil.h"
#include "StringUtil.h"


CsvUtil* CsvUtil::mCsvUtil = NULL;

CsvUtil::CsvUtil():mCsvMap(nullptr)
{
}

CsvUtil::~CsvUtil()
{
    CC_SAFE_DELETE(mCsvMap);
}

CsvUtil* CsvUtil::getInstance()
{
    if (!mCsvUtil)
    {
        mCsvUtil = new CsvUtil();
        if (mCsvUtil && mCsvUtil->init()) mCsvUtil->autorelease();
        else CC_SAFE_DELETE(mCsvUtil);
    }
    return mCsvUtil;
}

bool CsvUtil::init()
{
    mCsvMap = new CsvMap();
    return true;
}

void CsvUtil::loadFile(const char *sPath)
{
    //判断传入路径是否有效
    if(std::string("") == sPath) return;
    
    //读取文件工具
    FileLoadUtil tFileLoadUtil;
    
    //存放从文件读取的每行字符串的列表
    auto linesVec = tFileLoadUtil.getDataLines(sPath);
    
//    tFileLoadUtil.print(linesVec);
    
    //存放将每行字符串分解后的数据
    StrVec strsVec;
    //存放文件名和数据的字典
    StrDict dict;

    StringUtil tStringUtil;
    
    //对文件中每行信息进行解析,将解析好的字符串放入字典中
    for(const auto &linesVecIter : linesVec)
    {
        strsVec = tStringUtil.split(linesVecIter.c_str(), ",");
        dict.push_back(strsVec);
    }
    mCsvMap->insert(std::make_pair(std::string(sPath), dict));
}

void CsvUtil::releaseFile(const char *sPath)
{
//    StrDict* dict = const_cast<StrDict*>(getFileDict(sPath));
//    for (auto &dictIter : *dict)
//    {
//        dictIter.clear();
//        dictIter.resize(0);
//        dictIter = NULL;
//    }
//    dict->clear();
//    dict->resize(0);
//    delete dict;
//    dict = NULL;
    mCsvMap->erase(sPath);
}

cocos2d::Size CsvUtil::getFileRowColNum(const char *csvFilePath)
{
    const StrDict dict = getFileDict(csvFilePath);
    
//    const auto lineDatas = *(dict.begin());
    
//    int iColNum = lineDatas.size();
    //字典中拥有的元素个数为行数,每个vector元素中包含的元素个数为列数
    int iRowNum = dict.size();
    int iColNum = (*dict.begin()).size();

    return cocos2d::Size(iColNum, iRowNum);
}

std::string CsvUtil::get(const int &rRow, const int &rCol, const char *csvFilePath)
{
    const auto dict = getFileDict(csvFilePath);
    
    const auto lineDatas = dict.at(rRow);
    
    return lineDatas.at(rCol);
}

int CsvUtil::getInt(const int &rRow, const int &rCol, const char *csvFilePath)
{
    return atoi(get(rRow, rCol, csvFilePath).c_str());
}

float CsvUtil::getFloat(const int &rRow, const int &rCol, const char *csvFilePath)
{
    return atof(get(rRow, rCol, csvFilePath).c_str());
}

const StrDict &CsvUtil::getFileDict(const char *csvFilePath)
{
    return (*mCsvMap)[csvFilePath];
}

int CsvUtil::findValueInWithLine(const char *chValue, const int &rICol, const char *csvFilePath)
{
    auto iRowCount = getFileRowColNum(csvFilePath).height;
    
    auto ret = -1;
//    cocos2d::log("value : %s", chValue);
    std::string findValue(chValue);
    
    for (int iRow = 0; iRow < iRowCount; ++iRow)
    {
        std::string tmpValue = get(iRow, rICol, csvFilePath);
//        cocos2d::log("value: %s", tmpValue.c_str());
        if (findValue == tmpValue)
        {
            ret = iRow;
            break;
        }
    }
    return ret;
}