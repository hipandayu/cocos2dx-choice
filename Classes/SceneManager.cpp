

#include "SceneManager.h"


using namespace cocos2d;

void SceneManager::goStartGame() {
    go(StartGameScene::create());
}


void SceneManager::goGameSetting() {
    SceneManager::go(GameSetting::create());
}

void SceneManager::goGameHelp(){
    SceneManager::go(GameHelp::create());
}

void SceneManager::goMoreApps(){
    SceneManager::go(MoreApps::create());
}

void SceneManager::goAboutUs(){
    SceneManager::go(AboutUs::create());
}

void SceneManager::goChallengeLevelSelect(){
    
    SceneManager::go(ChallengeLevelSelection::create());
}

void SceneManager::goChallengeGameScene(){
    
    SceneManager::go(ChallengeGameScene::create());
}

void SceneManager::gochallengeLevelResult(){
    
    SceneManager::go(ChallengeLevelResult::create());
    
}

void SceneManager::goChallengeFinalResult(){
    SceneManager::go(ChallengeFinalResult::create());
}
/*
void SceneManager::goCrazyModeGuide(){
    SceneManager::go(CrazyModeGuide:create());
}

void SceneManager::goCrazyModeGameScene(){
    SceneManager::go(CrazyModeGameScene:create());
}

void SceneManager::goCrazyModeResultScene(){
    SceneManager::go(CrazyModeResultScene:create());
}
*/
void SceneManager::goGameStore(){
    //SceneManager::go(GameStore:create());
}


void SceneManager::go(CCLayer * layer){
    CCDirector *director = CCDirector::sharedDirector();
    CCScene *newScene = SceneManager::wrap(layer);
    if (!director->isPaused()) {
        director->replaceScene(newScene);
    }
    else {
        director->runWithScene(newScene);
    }
}


CCScene* SceneManager::wrap(CCLayer * layer){
    
    CCScene *newScene = CCScene::create();
    newScene->addChild(layer);
    return newScene;
}
