//
//  I118N.h
//  Chapter14_2_CardDefence01
//
//  Created by 闫鑫 on 14-7-12.
//
//

#ifndef __Chapter14_2_CardDefence01__I18N__
#define __Chapter14_2_CardDefence01__I18N__

#include "GloblaDefine.h"

class I18N: public cocos2d::Ref
{
public:
    
    virtual ~I18N();

    enum EnumStrSky
    {
        en_StrKey_Public_Confirm = 1,
        en_StrKey_Public_Monster,
        en_StrKey_Public_TowerSoul,
        en_StrKey_Public_Magic,
        en_max
    };
    
    static I18N* getInstance();
    
    virtual bool init();
    
    virtual std::string getString(EnumStrSky enStrKey);
    
    virtual const char* getCString(EnumStrSky enStrKey);
    
    virtual const char* getCStringByKey(const int& rIKey);
    
private:
    
    virtual void loadStringsFromConf(const char *cFilePath);
    
private:
    
    I18N();
    
private:
    
    static I18N *mPI18N;
    
    StrDict *mPStrDict;
};


#endif /* defined(__Chapter14_2_CardDefence01__I118N__) */
