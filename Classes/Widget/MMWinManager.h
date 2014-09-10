//
//  MMWinManager.h
//  testXml2
//
//  Created by 闫鑫 on 14-7-15.
//
//

#ifndef __testXml2__MMWinManager__
#define __testXml2__MMWinManager__

#include "GloblaDefine.h"
#include "external/tinyxml2/tinyxml2.h"

class MMWinManager: public cocos2d::Ref
{
public:
    //监控助手单例
    static MMWinManager* getInstance();
    
    //得到通过控件助手生成的控件桌面
    MMWinDesktop * getDesktopFromXml(const char *sXmlPath);
    
protected:
    
    //通过xmldata数据生成控件
    MMWinXmlData *createXmlDataFromXML(const char *sXmlPath);
    
    virtual bool init();
    
    //通过xml文件生成xmldata数据对象
    MMWinXmlData *createXmlData(tinyxml2::XMLElement *xmlElement);
    
    //设置xmldata数据对象的属性
    void setXmlDataProperty(MMWinXmlData *xmlData, const char *sName, const char *sText);
    
    //设置xml节点数据到xmldata对象中
    void setWinXmlData(MMWinXmlData *tXmlData, tinyxml2::XMLElement *rXmlElement);
    
private:
    //单例对象
    static MMWinManager *mGWinManager;
    
private:
    
    //控件系统
    MMWinSystem *mPWinSystem;
    
    //xmldata属性设置对象
    MMWinXmlDataSetting *mPWinXmlDataSetting;
    
private:
    
    MMWinManager();
    
    virtual ~MMWinManager();

};

#endif /* defined(__testXml2__MMWinManager__) */
