//
//  CsvUtil.h
//  Chapter14_2_CardDefence01
//
//  Created by 闫鑫 on 14-7-11.
//
//

#ifndef __Chapter14_2_CardDefence01__CsvUtil__
#define __Chapter14_2_CardDefence01__CsvUtil__

#include "GloblaDefine.h"

class CsvUtil: public cocos2d::Ref
{
public:
    
    static CsvUtil* getInstance();
    
    virtual bool init();
    
    //加载某文件数据到字典中
    virtual void loadFile(const char *sPath);
    //从字典中释放某文件数据
    virtual void releaseFile(const char *sPath);
    
    //得到某文件中,某行某列的字符串
    virtual std::string get(const int &rRow, const int &rCol, const char *csvFilePath);
    //得到某文件中,某行某列的数值
    virtual int getInt(const int &rRow, const int &rCol, const char *csvFilePath);
    virtual float getFloat(const int &rRow, const int &rCol, const char *csvFilePath);
    
    //得到某文件的行数,列数
    virtual cocos2d::Size getFileRowColNum(const char *csvFilePath);
    
    //查询某文件中,某项数据
    virtual int findValueInWithLine(const char *chValue, const int &rIValueCol, const char *csvFilePath);
    
    //得到某文件对应的数据集
    virtual const StrDict &getFileDict(const char *csvFilePath);
    
    virtual ~CsvUtil();
    
private:
    
    CsvUtil();
    
    CsvUtil(const CsvUtil &rCsvUtil) = delete;
    
    CsvUtil &operator=(const CsvUtil &rCsvUtil) = delete;
    
private:
    
    static CsvUtil* mCsvUtil;
    
    CsvMap* mCsvMap;
    
};

#endif /* defined(__Chapter14_2_CardDefence01__CsvUtil__) */
