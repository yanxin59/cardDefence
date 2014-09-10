//
//  MMRoundOprBtn.h
//  Chapter14_2_CardDefence01
//
//  Created by 闫鑫 on 14-7-24.
//
//

#ifndef __Chapter14_2_CardDefence01__MMRoundOprBtn__
#define __Chapter14_2_CardDefence01__MMRoundOprBtn__

#include "GloblaDefine.h"

#define DEFAULT_DISTANCE 60

class MMRoundOprBtn: public cocos2d::Node
{
    
public:
    
    virtual bool init();
    
    CREATE_FUNC(MMRoundOprBtn);
    
    static MMRoundOprBtn *createWithControlButtons(CONTROLBTN *pBtn1,
                                                   CONTROLBTN *pBtn2,
                                                   CONTROLBTN *pBtn3,
                                                   CONTROLBTN *pBtn4);
    
    bool initWithControlButtons(CONTROLBTN *pBtn1,
                                CONTROLBTN *pBtn2,
                                CONTROLBTN *pBtn3,
                                CONTROLBTN *pBtn4);
    
    void deleteMe();
    
private:
    
    void addOneBtn(cocos2d::Node *pNode, cocos2d::Vec2 rPos);
    
};

#endif /* defined(__Chapter14_2_CardDefence01__MMRoundOprBtn__) */
