//
//  GlobalDefine.h
//  Chapter14_2_CardDefence01
//
//  Created by 闫鑫 on 14-7-11.
//
//

#ifndef Chapter14_2_CardDefence01_GloblaDefine_h
#define Chapter14_2_CardDefence01_GloblaDefine_h

#include "cocos2d.h"
#include "GloblaPath.h"
#include "cocos-ext.h"
#include "EnumWinType.h"
#include "EnumMonsterPropConfType.h"
#include "Header.h"
#include "GlobalClient.h"
#include "EnumHeroPropConfType.h"
#include "EditorPosType.h"


class MMWinDesktop;
class MMWinSystem;
class MMBase;
class TiXmlElement;
class MMWinXmlDataSetting;
class MMWinXmlData;
class MMWinPropertyFactory;
class MMWinFactory;
class MMWinBaseFactory;
class MMNormalWin;
class MMLabel;

//坐标基类
class PosBase;
//怪物实体
class Monster;
//子弹管理器
class BulletManager;
//怪物控制器
class ControllerSimpleMove;
//怪物血条控件
class WidgetHPSlot;
//子弹基类
class BulletBase;
//英雄管理器
class HeroManager;
//怪物管理器
class MonsterManager;
//炮塔
class TowerBorder;
//塔坐标
class TowerPos;
//怪物路线坐标
class MonsterPos;
//存放怪物指针的vec,使用cocos2dx封装的vector
typedef cocos2d::Vector<Monster*> MonsterVec;

//从plist文件读取怪物或者英雄塔的坐标后会先存放到StdPosVec中,StdPosVec由于是new出来的,所以需要手动释放
typedef std::vector<PosBase*> StdPosVec;

//保存怪物移动坐标点
typedef cocos2d::Vector<PosBase*> PosVec;

//保存多个子弹的集合
typedef cocos2d::Vector<BulletBase*> BulletVec;

typedef std::vector<std::string> StrVec;

typedef std::vector< StrVec > StrDict;

typedef std::map< std::string, StrDict> CsvMap;

typedef cocos2d::Map<std::string , MMBase*> WinMap;

typedef cocos2d::Vector<TowerBorder*> TowerBorderVec;

#define CC_PRIVATE(varType, varName, funName)\
private:\
    varType varName;\
public:\
    virtual varType get##funName()\
    {\
        return varName;\
    }\
    virtual void set##funName(const varType& var)\
    {\
        varName = var;\
    }

#define CC_PROTECTED(varType, varName, funName)\
protected:\
varType varName;\
public:\
virtual varType get##funName()\
{\
return varName;\
}\
virtual void set##funName(const varType& var)\
{\
varName = var;\
}

#define CC_PRIVATE_STRING(varType, varName, funName)\
private:\
    varType *varName;\
public:\
    virtual varType *get##funName()\
    {\
        return varName;\
    }\
    virtual void set##funName(const varType &rName)\
    {\
        *varName = rName;\
    }

#define CC_PROTECTED_STRING(varType, varName, funName)\
protected:\
varType *varName;\
public:\
virtual varType *get##funName()\
{\
return varName;\
}\
virtual void set##funName(const varType &rName)\
{\
*varName = rName;\
}


#define CC_PRIVATE_BOOL(varName, funName)\
private:\
    bool varName;\
public:\
    bool is##funName()const \
    {\
        return varName;\
    }\
    void set##funName(const bool &var)\
    {\
        varName = var;\
    }


#define NOTIFY cocos2d::NotificationCenter::getInstance()

#define STRING_UTIL StringUtil::SharedStrUtil()

#define INT_TO_CHAR(num) StringUtil::sharedStrUtil()::transIntToStr(num)



//xml数据中string类型值得设定方法
#define MM_SET_XML(funName)\
public:\
void setXml##funName(MMWinXmlData &xmlData, const char* sText)\
{\
xmlData.set##funName(sText);\
}

//xml数据中int类型值得设定方法
#define MM_SET_XML_INT(funName)\
public:\
void setXml##funName( MMWinXmlData &rXmlData, const char* sText ) \
{\
rXmlData.set##funName(atoi(sText));\
}

//xml数据中float类型值的设定方法
#define MM_SET_XML_FLOAT(funName)\
public:\
void setXml##funName( MMWinXmlData &rXmlData, const char* sText ) \
{\
rXmlData.set##funName(atof(sText));\
}

//xml数据中bool类型值的设定方法
#define MM_SET_XML_BOOL(funName)\
public:\
void setXml##funName( MMWinXmlData* xmlData, const bool& rBool ) \
{\
xmlData->set##funName(rBool);\
}

//定义类的string*类型属性和其setget方法,get方法返回const引用,set方法参数为const引用
#define MM_XML_PRIVATE_StdStr(varName, funName)\
private:\
std::string* varName;\
public:\
const std::string& get##funName()\
{\
return *varName;\
}\
public:\
void set##funName(const std::string &rVar)\
{ \
*varName = rVar;\
}

//怪物id
#define MONSTER_ID "id"

#define MONSTER_SHOWTIME "showTime"

//消息发送
#define NOTIFY cocos2d::NotificationCenter::getInstance()

//string工具类
#define STRING_UTIL StringUtil::SharedStrUtil()

//string工具类中int转字符串的功能
#define INT_TO_CHAR(num) StringUtil::sharedStrUtil()::transIntToStr(num)

//定义controlbutton按钮时指定触发的事件类型
#define CONTROL_EVENT cocos2d::extension::Control::EventType

//定义controlbutton按钮状态类型
#define CONTROL_STATE cocos2d::extension::Control::State

//重定义缩放精灵类型名
#define SCALESPRITE cocos2d::extension::Scale9Sprite

//重定义controlbutton类型名
#define CONTROLBTN cocos2d::extension::ControlButton

//设置xmldata的属性
#define XML_VALUE_enWinType "enWinType"
#define XML_VALUE_y "y"
#define XML_VALUE_x "x"
#define XML_VALUE_text "text"
#define XML_VALUE_tag "tag"
#define XML_VALUE_bg "bg"
#define XML_VALUE_width "width"
#define XML_VALUE_height "height"
#define XML_VALUE_alpha "alpha"
#define XML_VALUE_scaleX "scaleX"
#define XML_VALUE_scaleY "scaleY"
#define XML_VALUE_visible "visible"
#define XML_VALUE_enable "enable"
#define XML_VALUE_touchable "touchable"
#define XML_VALUE_des "des"
#define XML_VALUE_scale9bg "scale9bg"
#define XML_VALUE_scale9bgDown "scale9bgDown"
#define XML_VALUE_marginH "marginH"
#define XML_VALUE_marginV "marginV"
#define XML_VALUE_max "max"
#define XML_VALUE_AnchorX "anchorX"
#define XML_VALUE_AnchorY "anchorY"
#define XML_VALUE_fontSize "fontSize"
#define XML_TEXT_true "true"
#define XML_TEXT_false "false"
#define XML_TEXT_right "right"
#define XML_TEXT_left "left"
#define XML_TEXT_bottom "bottom"
#define XML_TEXT_top "top"
#define XML_TEXT_center "center"

//英雄类型
enum EnumHeroType
{
    enHeroType_Normal
};

//每个英雄拥有子弹数
#define BULLET_MAX_CACHE_NUM 10
#define BULLET_LOGIC_CHECK_INTERVAL 0.07f

//关卡场景中游戏图层和数据显示图层的标记
#define TAG_MAP_LAYER 1
#define TAG_DATA_LAYER 2

//关卡层
#define HOME_LAYER_LVL 3
#define HERO_LAYER_LVL 10
#define MONSTER_LAYER_LVL 15
#define BULLET_LAYER_LVL 20


#endif
