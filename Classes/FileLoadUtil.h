//
//  FileLoadUtil.h
//  Chapter9_6_LoadCsv
//
//  Created by 闫鑫 on 14-6-14.
//
//

#ifndef __Chapter9_6_LoadCsv__FileLoadUtil__
#define __Chapter9_6_LoadCsv__FileLoadUtil__

#include "GloblaDefine.h"
#include "StringUtil.h"

class FileLoadUtil
{
public:
    
    StrVec getDataLines(const char * sFilePath)
    {
        StrVec linesList;
        
        ssize_t pSize = 0;
        
        unsigned char *chDatas = cocos2d::FileUtils::getInstance()->getFileData(sFilePath, "r", &pSize);
        
        StringUtil tStringUtil;
        
        if(chDatas) linesList = tStringUtil.split((char *)chDatas, "\n");
            //    print(linesList);
            
            return linesList;
    }
    

};

#endif /* defined(__Chapter9_6_LoadCsv__FileLoadUtil__) */
