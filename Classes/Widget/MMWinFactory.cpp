//
//  MMWinFactory.cpp
//  testXml2
//
//  Created by 闫鑫 on 14-7-15.
//
//

#include "MMWinFactory.h"
#include "MMLabel.h"
#include "MMNormalWin.h"

bool MMWinFactory::init()
{
    return true;
}

MMBase *MMWinFactory::createWin(EnumWinType enWinType)
{
    MMBase *win = nullptr;
    
    switch (enWinType) {
        case en_Win_None:
            win = MMNormalWin::create();
            break;
        case en_Win_NormalWin:
            win = MMNormalWin::create();
            break;
        case en_Win_Label:
            win = MMLabel::create();
            break;
        default:
            break;
    }
    if(win) win->setEnWinType(enWinType);
    
    return win;
}