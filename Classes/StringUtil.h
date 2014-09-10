//
//  StringUtil.h
//  Chapter9_6_LoadCsv
//
//  Created by 闫鑫 on 14-6-14.
//
//

#ifndef __Chapter9_6_LoadCsv__StringUtil__
#define __Chapter9_6_LoadCsv__StringUtil__

#include "GloblaDefine.h"

class StringUtil
{
public:
    
    StrVec split(const char *srcStr, const char *sSep)
    {
        StrVec stringList;
        
        int size = strlen(srcStr);
        
        std::string str(srcStr);
        
        int startIndex = 0;
        
        int endIndex = 0;
        
        endIndex = str.find(sSep);
        
        std::string splitStr = "";
        
        while (endIndex > 0) {
            
            splitStr = str.substr(startIndex, endIndex);
            
            stringList.push_back(splitStr);
            
            str = std::string(str.substr(endIndex + 1, size));
            
            endIndex = str.find(sSep);
            
        }
        
        if (str.compare("") != 0) {
            stringList.push_back(str);
        }
        return stringList;
    }
};


#endif /* defined(__Chapter9_6_LoadCsv__StringUtil__) */
