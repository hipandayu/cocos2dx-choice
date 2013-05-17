#ifndef __SCENEMANAGER_H__
#define __SCENEMANAGER_H__

#include "cocos2d.h"
#include "AboutUs.h"

#include "StartGameScene.h"

#include "GameSetting.h"
#include "GameHelp.h"

#include "MoreApps.h"

#include "ChallengeLevelSelection.h"
#include "ChallengeGameScene.h"

#include "ChallengeLevelResult.h"
#include "ChallengeFinalResult.h"
/*
#include "CrazyModeGuide.h"
#include "CrazyModeGameScene.h"
#include "CrazyModeResultScene.h"

#include "GameStore.h"*/

class SceneManager : public cocos2d::CCObject
{
public:
    static void goStartGame();
    
    static void goGameSetting();
    
    static void goGameHelp();
    
    static void goMoreApps();
    
    static void goAboutUs();
    
    static void goChallengeLevelSelect();
    
    static void goChallengeGameScene();
    
    static void gochallengeLevelResult();
    
    static void goChallengeFinalResult();
    
    static void goCrazyModeGuide();
    
    static void goCrazyModeGameScene();
    
    static void goCrazyModeResultScene();
    
    static void goGameStore();
    
    static void go(cocos2d::CCLayer * layer);
    static cocos2d::CCScene * wrap(cocos2d::CCLayer * layer);
};

#endif // __SCENEMANAGER_H__
