//
//  GlobalClient.h
//  Chapter14_2_CardDefence01
//
//  Created by 闫鑫 on 14-7-22.
//
//

#ifndef __Chapter14_2_CardDefence01__GlobalClient__
#define __Chapter14_2_CardDefence01__GlobalClient__

#include "cocos2d.h"

class TollgateScene;

class GlobalClient: public cocos2d::Node
{
public:

    static GlobalClient *getInstance();
    
    //设置和得到当前运行场景
    void setCurTollgateScene(cocos2d::Scene &rTollgateScene);
    cocos2d::Scene *getCurTollgateScene();
    
    //设置当前游戏级别
    void setICurTollgateLevel(const int &rILevel);
    int getICurTollgateLevel();
    
    virtual ~GlobalClient();

protected:
    
    virtual bool init();
    
private:
    
    //单例对象
    static GlobalClient *mPGlobalClient;
    
    //保存当前运行场景
    cocos2d::Scene *mPCurTollgateScene;
    
    //保存当前场景级别
    int mICurTollgateLevel = -1;
    
private:
    //单例,防止赋值和复制
    GlobalClient();
    
    GlobalClient(const GlobalClient &rGlobalClient) = delete;
    
    GlobalClient &operator=(const GlobalClient &rGlobalClient) = delete;

};

#endif /* defined(__Chapter14_2_CardDefence01__GlobalClient__) */
