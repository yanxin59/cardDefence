//
//  MMWinSystem.h
//  testXml2
//
//  Created by 闫鑫 on 14-7-15.
//
//

#ifndef __testXml2__MMWinSystem__
#define __testXml2__MMWinSystem__

#include "GloblaDefine.h"

class MMWinSystem: public cocos2d::Ref
{
public:
    
    virtual ~MMWinSystem();

    /*根据控件根节点创建控件生成系统对象*/
    CREATE_FUNC(MMWinSystem);

    /*
     根据xmldata结构数据创建空间
     可能创建树形结构空间
     但是只有一个根节点
     最后返回一个顶级控件
     参数：xmldata控件结构数据，rIsHasParent是否有父控件
     */
    MMWinDesktop *createDesktopByXmlData(MMWinXmlData &rXmlData, const bool &rIsHasParent);
    
protected:
    
    virtual bool init();
    /*
     根据空间类型给控件设置属性
     */
    void dressProertiesByType(MMBase &rWin, MMWinXmlData &rXmlData);
    
    /*
     生成一个唯一的id供控件使用
     */
    int createUniqueID();
    
    MMBase *createWins(MMWinDesktop &rWinDesktop, MMWinXmlData &rXmlData, const bool &rIsHasParent);
    
private:
    /*
     根据xml文件创建一个控件
     */
    MMBase *createWinByXmlData(MMWinXmlData &pXmlData);
    
    /*
     根据控件类型创建一个控件
     */
    MMBase *createWinByType(EnumWinType enWinType);
    
private:
    
    /*控件工厂*/
    MMWinBaseFactory *mPWinBaseFactory;
    /*控件树形加工工厂*/
    MMWinPropertyFactory *mPWinPropertyFactory;
    /*控件id*/
    int mIWinID;
    
private:
    
    MMWinSystem(const MMWinSystem &) = delete;
    
    MMWinSystem &operator=(const MMWinSystem &) = delete;
    
    MMWinSystem();

};

#endif /* defined(__testXml2__MMWinSystem__) */
