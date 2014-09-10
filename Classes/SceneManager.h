//
//  SceneManager.h
//  Chapter14_2_CardDefence01
//
//  Created by 闫鑫 on 14-7-11.
//
//

#ifndef __Chapter14_2_CardDefence01__SceneManager__
#define __Chapter14_2_CardDefence01__SceneManager__


//场景助手,勇于切换场景
#include "cocos2d.h"

class SceneManager :public cocos2d::Ref
{
public:
    
    enum EnumSceneType
    {
        en_TollgateLogin,   //游戏启动界面
        en_TollgateScene,   //游戏场景
        en_TollgateEditorScene, //游戏中英雄和怪物位置编辑场景
        en_WinSnene,    //控件界面场景
        en_GameOverScene,   //游戏结束场景
        en_TollgateSelectScene  //游戏关卡选择场景
    };
    
    static SceneManager* getInstance();
    
    void changeScene(EnumSceneType enSceneType);

    static void delInstance();
    
protected:
    
    virtual bool init();
    
private:
    
    static SceneManager* mSceneManager;

private:
    
    SceneManager(){}
    
    SceneManager(const SceneManager&) = delete;
    
    SceneManager &operator=(const SceneManager&) = delete;
    
};


#endif /* defined(__Chapter14_2_CardDefence01__SceneManager__) */
