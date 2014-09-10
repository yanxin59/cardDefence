//
//  MMWinBaseFactory.h
//  testXml2
//
//  Created by 闫鑫 on 14-7-15.
//
//

#ifndef __testXml2__MMWinBaseFactory__
#define __testXml2__MMWinBaseFactory__

#include "cocos2d.h"
#include "EnumWinType.h"

class MMBase;
//控件工厂基类
class MMWinBaseFactory: public cocos2d::Ref
{
public:
    //通过参数指定的控件类型生成控件
    virtual MMBase *createWithByType(EnumWinType enWinType);
    
    virtual MMBase *createWin(EnumWinType enWinType) = 0;
    
};


#endif /* defined(__testXml2__MMWinBaseFactory__) */
