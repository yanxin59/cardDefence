//
//  GlobalClient.cpp
//  Chapter14_2_CardDefence01
//
//  Created by 闫鑫 on 14-7-22.
//
//

#include "GlobalClient.h"
#include "TollgateScene.h"

GlobalClient *GlobalClient::mPGlobalClient = nullptr;

GlobalClient::GlobalClient():mPCurTollgateScene(nullptr)
{
}

GlobalClient::~GlobalClient()
{
    CC_SAFE_RELEASE_NULL(mPCurTollgateScene);
}

GlobalClient *GlobalClient::getInstance()
{
    if(!mPGlobalClient)
    {
        mPGlobalClient = new GlobalClient();
        
        if(mPGlobalClient && mPGlobalClient->init()) mPGlobalClient->autorelease();
        else CC_SAFE_DELETE(mPGlobalClient);
    }
    return mPGlobalClient;
}

bool GlobalClient::init()
{
    bool bRet = false;
    do
    {
        CC_BREAK_IF( !Node::init() );
        bRet = true;
    }
    while (0);
    return bRet;
}

void GlobalClient::setCurTollgateScene(cocos2d::Scene &rTollgateScene)
{
    //对传入的场景retain一下
    CC_SAFE_RETAIN(&rTollgateScene);
    
    //安全的将当前运行的场景release掉
    CC_SAFE_RELEASE_NULL(mPCurTollgateScene);
    
    mPCurTollgateScene = &rTollgateScene;
}

cocos2d::Scene *GlobalClient::getCurTollgateScene()
{
    return mPCurTollgateScene;
}

int GlobalClient::getICurTollgateLevel()
{
    return mICurTollgateLevel;
}

void GlobalClient::setICurTollgateLevel(const int &rILevel)
{
    mICurTollgateLevel = rILevel;
}