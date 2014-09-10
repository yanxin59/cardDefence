#include "AppDelegate.h"
#include "TowerPosEditScene.h"
#include "TowerPosEditorLayer.h"
#include "SceneManager.h"
#include "PosLoadUtil.h"
#include "CsvUtil.h"
#include "GloblaDefine.h"
#include "GlobalClient.h"
#include "MMWinManager.h"

USING_NS_CC;

AppDelegate::AppDelegate()
{
    CC_SAFE_RETAIN(SceneManager::getInstance());
    CC_SAFE_RETAIN(GlobalClient::getInstance());
    CC_SAFE_RETAIN(MMWinManager::getInstance());
    CC_SAFE_RETAIN(CsvUtil::getInstance());
}

AppDelegate::~AppDelegate()
{
    CC_SAFE_RELEASE(CsvUtil::getInstance());
    CC_SAFE_RELEASE(SceneManager::getInstance());
    CC_SAFE_RELEASE(GlobalClient::getInstance());
    CC_SAFE_RELEASE(MMWinManager::getInstance());
}

bool AppDelegate::applicationDidFinishLaunching() {
    // initialize director
    auto director = Director::getInstance();
    auto glview = director->getOpenGLView();
    if(!glview) {
        glview = GLView::create("My Game");
        director->setOpenGLView(glview);
    }

    // turn on display FPS
    director->setDisplayStats(true);

    // set FPS. the default value is 1.0/60 if you don't call this
    director->setAnimationInterval(1.0 / 60);

    CsvUtil::getInstance()->loadFile(PATH_CSV_HERO_CONF);
    CsvUtil::getInstance()->loadFile(PATH_CSV_MONSTER_CONF);
    
//    CocosDenshion::SimpleAudioEngine::getInstance()->playBackgroundMusic(cocos2d::StringUtils::format("tollgate_%d.mp3", 1).c_str(), true);
    
    SceneManager::getInstance()->changeScene(SceneManager::en_TollgateLogin);
    
    return true;
}

void AppDelegate::loadAnimation()
{    
}

// This function will be called when the app is inactive. When comes a phone call,it's be invoked too
void AppDelegate::applicationDidEnterBackground() {
    Director::getInstance()->stopAnimation();

    // if you use SimpleAudioEngine, it must be pause
    // SimpleAudioEngine::getInstance()->pauseBackgroundMusic();
}

// this function will be called when the app is active again
void AppDelegate::applicationWillEnterForeground() {
    Director::getInstance()->startAnimation();

    // if you use SimpleAudioEngine, it must resume here
    // SimpleAudioEngine::getInstance()->resumeBackgroundMusic();
}
