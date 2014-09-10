//
//  TowerPosEditorLayer.cpp
//  Chapter14_2_CardDefence01
//
//  Created by 闫鑫 on 14-6-22.
//
//

#include "TowerPosEditorLayer.h"
#include "PosBase.h"
#include "PosLoadUtil.h"
#include "TowerPosEditorOperateLayer.h"


TowerPosEditorLayer::TowerPosEditorLayer():mPPosVec(nullptr), m_enMode(enTowerPos),mICurLevel(1)
{
}

TowerPosEditorLayer::~TowerPosEditorLayer()
{
    CC_SAFE_DELETE(mPPosVec);
}

bool TowerPosEditorLayer::init()
{
    bool bRet = false;
    
    do
    {
        CC_BREAK_IF(!Layer::init());
        
        mPPosVec = new PosVec;
        
        auto visibleSize = cocos2d::Director::getInstance()->getVisibleSize();
        
        auto sBG = cocos2d::StringUtils::format("level_%d.jpg", mICurLevel);
        
        auto map = cocos2d::Sprite::create(sBG.c_str());
        
        map->setName("map");
        
        map->setPosition(cocos2d::Point(visibleSize.width / 2, visibleSize.height / 2));
        
        addChild(map, -10);
        
        registerTouchEvent();
        
        loadConfigFile();
        
        bRet = true;
    }
    while (0);

    return bRet;
}

void TowerPosEditorLayer::registerTouchEvent()
{
    auto pDispatcher = cocos2d::Director::getInstance()->getEventDispatcher();
    
    auto pListener = cocos2d::EventListenerTouchOneByOne::create();
    
    pListener->setSwallowTouches(false);

    pListener->onTouchEnded = [this](cocos2d::Touch *pTouch, cocos2d::Event *pEvent)
    {
        auto pos = cocos2d::Director::getInstance()->convertToUI(pTouch->getLocationInView());
//        cocos2d::log("%.02f, %.02f", pos.x, pos.y);
        editPos(pos);
    };
    
    pListener->onTouchBegan = [](cocos2d::Touch *pTouch, cocos2d::Event *pEvent)
    {
        return true;
    };
    
    pDispatcher->addEventListenerWithSceneGraphPriority(pListener, this);
}

void TowerPosEditorLayer::outputPosToPlistFile()
{
    std::string sPosPlist;
    auto sWritablePath = cocos2d::FileUtils::getInstance()->getWritablePath();
    if(m_enMode == enMonsterPos)
        sPosPlist = cocos2d::StringUtils::format("%smonsterPos_level_%d.plist", sWritablePath.c_str(), mICurLevel);
    else
        sPosPlist = cocos2d::StringUtils::format("%stowerPos_level_%d.plist", sWritablePath.c_str(), mICurLevel);

    
    outputPosToPlistFile(*mPPosVec, sPosPlist.c_str());
    
}

void TowerPosEditorLayer::outputPosToPlistFile(PosVec &rPosVec, const char *sFilePath)
{
    FILE* file = fopen(sFilePath, "w");
    
	fprintf(file, "<?xml version=\"1.0\" encoding=\"UTF-8\"?>\n");
    
	fprintf(file, "<!DOCTYPE plist PUBLIC \"-//Apple//DTD PLIST 1.0//EN\" \"http://www.apple.com/DTDs/PropertyList-1.0.dtd\">\n");
    
	fprintf(file,"<plist version=\"1.0\">\n");
	
	fprintf(file,"<array>\n");
	
    for (const auto & iterPosVec : rPosVec)
    {
		if(iterPosVec != NULL)
        {
	
			fprintf(file,"    <dict>\n");
            
	
			fprintf(file,"        <key>x</key>\n");
            
	
			fprintf(file,"        <integer>%.0f</integer>\n", iterPosVec->getPosition().x);
            
	
			fprintf(file,"        <key>y</key>\n");
            
	
			fprintf(file,"        <integer>%.0f</integer>\n", iterPosVec->getPosition().y);
            
	
			fprintf(file,"    </dict>\n");
		}
	}

	fprintf(file,"</array>\n");

	fprintf(file,"</plist>\n");
    
	fclose(file);

}

void TowerPosEditorLayer::loadConfigFile()
{
    if(mPPosVec && mPPosVec->size())
    {
        for(auto &iterPosNode : *mPPosVec)
        {
            iterPosNode->removeAllChildrenWithCleanup(true);
        }
        mPPosVec->clear();
    }
    
    auto sBG = cocos2d::StringUtils::format("level_%d.jpg", mICurLevel);
    
    (dynamic_cast<cocos2d::Sprite*>(this->getChildByName("map")))->setTexture(sBG);
    
    PosLoadUtil tPosLoadUtil;
    
    std::string sTypePlist;
    std::string sWritablePath = cocos2d::FileUtils::getInstance()->getWritablePath();
    if(m_enMode == enTowerPos)
        sTypePlist = cocos2d::StringUtils::format("%stowerPos_level_%d.plist", sWritablePath.c_str(), mICurLevel);
    else
        sTypePlist = cocos2d::StringUtils::format("%smonsterPos_level_%d.plist", sWritablePath.c_str(), mICurLevel);
    
    tPosLoadUtil.loadPosWithFile(sTypePlist.c_str(), *mPPosVec, m_enMode);
    
    for(auto &iterPosVec : *mPPosVec)
        addChild(iterPosVec);
    
}

void TowerPosEditorLayer::editPos(const cocos2d::Vec2 &rPos)
{
    auto pExistPos = findExistPos(rPos);
    
    if (NULL != pExistPos) deletePos(*pExistPos);
    else createPos(rPos);
}

PosBase *TowerPosEditorLayer::findExistPos(const cocos2d::Vec2 &rPos)
{
    for(auto &iterPosVec : *mPPosVec)
    {
        if(iterPosVec)
            if(iterPosVec->isClick(rPos))
                return iterPosVec;
    }
    return nullptr;
}

void TowerPosEditorLayer::createPos(const cocos2d::Vec2 &rPos)
{
    auto tPos = PosBase::createPos(rPos, m_enMode);
    this->addChild(tPos);
    tPos->setPosition(rPos);
    mPPosVec->pushBack(tPos);
}

void TowerPosEditorLayer::deletePos(PosBase &rPos)
{
    this->removeChild(&rPos);

    auto iterExistPos = mPPosVec->find(&rPos);
    if(mPPosVec->end() != iterExistPos)
        mPPosVec->erase(iterExistPos);

}

void TowerPosEditorLayer::changeMode()
{
    m_enMode = (m_enMode == enMonsterPos ? enTowerPos : enMonsterPos);
    loadConfigFile();
}

int TowerPosEditorLayer::nextLvl()
{
    ++mICurLevel;
    loadConfigFile();
    return mICurLevel;
}

int TowerPosEditorLayer::preLvl()
{
    if(1 == mICurLevel)
        return mICurLevel;
    --mICurLevel;
    loadConfigFile();
    return mICurLevel;
}
