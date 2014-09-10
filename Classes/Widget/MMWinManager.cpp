//
//  MMWinManager.cpp
//  testXml2
//
//  Created by 闫鑫 on 14-7-15.
//
//

#include "MMWinManager.h"
#include "MMWinXmlData.h"
#include "MMWinSystem.h"
#include "MMWinDesktop.h"
#include "MMWinXmlDataSetting.h"
#include "GloblaPath.h"


MMWinManager *MMWinManager::mGWinManager = NULL;


MMWinManager::MMWinManager(): mPWinXmlDataSetting(nullptr), mPWinSystem(nullptr)
{
}

MMWinManager::~MMWinManager()
{
    CC_SAFE_RELEASE_NULL(mPWinSystem);
    CC_SAFE_RELEASE_NULL(mPWinXmlDataSetting);
}

MMWinDesktop *MMWinManager::getDesktopFromXml(const char *sXmlPath)
{
    MMWinDesktop *pWinDesktop = nullptr;
    do
    {
        auto pXmlData = createXmlDataFromXML(sXmlPath);

        CC_BREAK_IF(!pXmlData);
        
        pWinDesktop = mPWinSystem->createDesktopByXmlData(*pXmlData, false);
        
        if(!pWinDesktop)
        {
            cocos2d::log("create WinDesktop failed!");
            return nullptr;
        }
    }
    while (0);
    return pWinDesktop;
}


MMWinManager* MMWinManager::getInstance()
{
    if(!mGWinManager)
    {
        mGWinManager = new MMWinManager();
        if(mGWinManager && mGWinManager->init()) mGWinManager->autorelease();
        else CC_SAFE_DELETE(mGWinManager);
    }
    return mGWinManager;
}

bool MMWinManager::init()
{
    //xmldata属性设置对象
    mPWinXmlDataSetting = MMWinXmlDataSetting::create();
    mPWinXmlDataSetting->retain();
    
    //控件系统对象
    mPWinSystem = MMWinSystem::create();
    mPWinSystem->retain();
    
    return true;
}

MMWinXmlData* MMWinManager::createXmlDataFromXML(const char *sXmlPath)
{
    unsigned char *pBuf = nullptr;
    //创建一个xml文档对象
    auto xmlDoc = new tinyxml2::XMLDocument();
    
    ssize_t bufSize = 0;
    
    //将xml文件内容读取到pBuf缓存中
    pBuf = cocos2d::FileUtils::getInstance()->getFileData(sXmlPath, "r", &bufSize);
    
    //通过xml文档对象解析xml文件内容,如果xml文件中无内容则返回空
    if(pBuf) xmlDoc->Parse((const char*)pBuf);
    else
    {
        cocos2d::log("xmldoc parse failed!");
        return nullptr;
    }
    
    //通过xml文档对象获得该xml对象的根节点
    auto pRootElement = xmlDoc->RootElement();
    
    //如果根节点为空则返回空
    if(!pRootElement)
    {
        cocos2d::log("pRootElement is nullptr");
        return nullptr;
    }
    
    //通过xml文档对象返回的根节点对象创建xmldata数据对象
    //将xml文档对象的"根节点"传下去
    auto pXmlData = createXmlData(pRootElement);
    //由于xmlDoc对象是动态分配的,所以需要进行手动释放
    delete xmlDoc;
    
    if(!pXmlData)
    {
        cocos2d::log("xmldata create failed!");
        return nullptr;
    }
    
    //用WinSystem对象通过xmldata对象来创建控件桌面
//    auto baseWin = mPWinSystem->createWinsByXmlData(pXmlData, false);
//    
//    if(!baseWin)
//    {
//        cocos2d::log("createWinsByXmlData failed!");
//        return nullptr;
//    }
//    //判断该控件是否有子控件,如果有则递归设置控件属性
//    if(!baseWin->isHasChildWin()) mPWinSystem->dressProertiesByType(baseWin, pXmlData);
//    
//    //将生成的控件添加到桌面控件当中
//    mPWinDesktop->addChild(baseWin, LAYER_DESKTOP, DESKTOP_NODE_TAG);
//    
//    return baseWin;
    return pXmlData;
}

MMWinXmlData *MMWinManager::createXmlData(tinyxml2::XMLElement *pXmlElement)
{
    //如果xml根节点为空则打出错误信息,并返回空
    if(!pXmlElement)
    {
        cocos2d::log("createxmlData failed!");
        return nullptr;
    }
    
    //创建一个xmldata数据对象
    auto pXmlData = MMWinXmlData::create();
    
    //获得根节点的第一个子节点
    auto cldElement = pXmlElement->FirstChildElement();
    
    //对其进行属性设置.属性设置需要传入子节点指针和xmldata指针对象
    setWinXmlData(pXmlData, cldElement->FirstChildElement());
    
//    xmlData->print();
    return pXmlData;
}

void MMWinManager::setWinXmlData(MMWinXmlData *pXmlData, tinyxml2::XMLElement *pXmlElement)
{
    if(!pXmlData || !pXmlElement)
    {
        cocos2d::log("xmldata or xmlElement is failed!");
        return;
    }
    //对子节点进行递归遍历
    while(pXmlElement)
    {
        //判断该子节点是否有文字信息,如果没有文字信息则有子节点,深层遍历
        if(!pXmlElement->GetText())
        {
            auto pChildXmlData = MMWinXmlData::create();
            setWinXmlData(pChildXmlData, pXmlElement->FirstChildElement());
            pXmlData->addCldXmlDate(pChildXmlData);
        }
        else
        {
            //设置xmldata节点属性
            setXmlDataProperty(pXmlData, pXmlElement->Value(), pXmlElement->GetText());
        }
        pXmlElement = pXmlElement->NextSiblingElement();
    }
}

void MMWinManager::setXmlDataProperty(MMWinXmlData *pXmlData, const char *sName, const char *sText)
{
    mPWinXmlDataSetting->setXmlDataProperty(*pXmlData, sName, sText);
}

