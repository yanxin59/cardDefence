//
//  MMWinFactory.h
//  testXml2
//
//  Created by 闫鑫 on 14-7-15.
//
//

#ifndef __testXml2__MMWinFactory__
#define __testXml2__MMWinFactory__

#include "MMWinBaseFactory.h"
#include "EnumWinType.h"

class MMBase;

//控件工厂,继承自控件工厂基类
class MMWinFactory: public MMWinBaseFactory
{
public:
    
    CREATE_FUNC(MMWinFactory)
    
    virtual bool init();
    
protected:
    //实现创建窗口的抽象方法
    virtual MMBase *createWin(EnumWinType enWinType);

};

#endif /* defined(__testXml2__MMWinFactory__) */
