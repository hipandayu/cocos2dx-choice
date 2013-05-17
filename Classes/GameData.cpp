

#include "GameData.h"
#include "SimpleAudioEngine.h"

using namespace cocos2d;
using namespace CocosDenshion;

static GameData *mySharedData = NULL;

 GameData* GameData::sharedData(){
    if (mySharedData ==NULL) {
        //CCLog("gamedata-newnewnewnewnewnewnewnewnewnewnewnewnewnewnewnew");
        mySharedData=GameData::create();
    }
    CCLog("gamedata-share:%d,%d,%d,%d",mySharedData->isLevel2Unlocked,mySharedData->isLevel3Unlocked,mySharedData->isLevel4Unlocked,mySharedData->isLevel5Unlocked);
    return mySharedData;
}
// on "init" you need to initialize your instance
bool GameData::init()
{
    //////////////////////////////
    // 1. super init first
    if ( !CCLayer::init() )
    {
        return false;
    }
    defaults=CCUserDefault::sharedUserDefault();
    currentNumberOfGameProp1=defaults->getIntegerForKey("currentNumberOfGameProp1");
    currentNumberOfGameProp2=defaults->getIntegerForKey("currentNumberOfGameProp2");
    currentNumberOfGameProp3=defaults->getIntegerForKey("currentNumberOfGameProp3");
    currentNumberOfGameProp4=defaults->getIntegerForKey("currentNumberOfGameProp4");
    
    numberOfCorrectAnswerOfCurrentLevel = defaults->getIntegerForKey("correctAnswerOfCurrentLevel");
    numberOfAnsweredQuestionOfCurrentLevel = defaults->getIntegerForKey("numberOfAnsweredQuestionOfCurrentLevel");
    numberOfWrongAnswerOfCurrentLevel = defaults->getIntegerForKey("numberOfWrongAnswerOfCurrentLevel");
    
    userLife = defaults->getIntegerForKey("userLife");
    
    currentQuestionIndex = defaults->getIntegerForKey("currentQuestionIndex",1);
    numberOfUnusedQuestions = defaults->getIntegerForKey("numberOfUnusedQuestions");
    
    
    currentLevelSolved = defaults->getBoolForKey("currentLevelSolved",false);
    
    currentLevelUnlocked = defaults->getBoolForKey("currentLevelUnlocked",false);
    
    
    
    soundEffectMuted = defaults->getBoolForKey("soundEffectMuted");   //默认值为NO
    backgroundMusicMuted = defaults->getBoolForKey("backgroundMusicMuted");   //默认值为NO
    
    
    gamePaused = defaults->getBoolForKey("gamePaused");
    
    
    
    notFirstTimePlayThisGame = defaults->getBoolForKey("notFirstTimePlayThisGame");
    notFirstTimeEnterStore = defaults->getBoolForKey("notFirstTimeEnterStore");
    
    
    levelsCompleted = defaults->getIntegerForKey("levelsCompletedTotal");
    
    currentLevelStar = defaults->getIntegerForKey("currentLevelStar");
    
    
    isLevel2Unlocked = defaults->getBoolForKey("isLevel2Unlocked",false);
    isLevel3Unlocked = defaults->getBoolForKey("isLevel3Unlocked",false);
    isLevel4Unlocked = defaults->getBoolForKey("isLevel4Unlocked",false);
    isLevel5Unlocked = defaults->getBoolForKey("isLevel5Unlocked",false);
    
    isCurrentLevelPassed = defaults->getBoolForKey("isCurrentLevelPassed",false);
    
    //默认选择的关卡
    
    selectedLevel =1;
    
    
    //关卡成就相关
    
    //默认数值是否改变
    //_appearedQuestionIndexArray = defaults->get("appearedQuestionIndexArray");
    return true;
}


