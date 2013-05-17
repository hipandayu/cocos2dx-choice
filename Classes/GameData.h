#ifndef __GAMEDATA_H__
#define __GAMEDATA_H__

#include "cocos2d.h"


class GameData : public cocos2d::CCLayer
{
public:
    // Method 'init' in cocos2d-x returns bool, instead of 'id' in cocos2d-iphone (an object pointer)
    virtual bool init();
    
    static GameData* sharedData();
 
    //关卡是否解锁
    
    bool isLevel2Unlocked;
    bool isLevel3Unlocked;
    bool isLevel4Unlocked;
    bool isLevel5Unlocked;
    
    //当前玩家所拥有的道具数量
    
    //叫兽的爱
    int currentNumberOfGameProp1;
    
    //空空的胸
    int currentNumberOfGameProp2;
    
    //戴三个表
    int currentNumberOfGameProp3;
    
    //女神凝望
    int currentNumberOfGameProp4;
    
    
    
    //当前关卡答对的题目总数
    
    int numberOfCorrectAnswerOfCurrentLevel;
    
    //当前关卡已回答的题目数量
    
    int numberOfAnsweredQuestionOfCurrentLevel;
    
    //当前关卡已回答错误的题目数量
    int numberOfWrongAnswerOfCurrentLevel;
    
    //玩家生命值
    int userLife;
    
    //已经出现过的题目编号数组，在关卡跳转时需要清空
    cocos2d::CCArray *appearedQuestionIndexArray;
    
    
    //是否已购买道具4
    bool isGameProp4Purchased;
    
    
    //音效相关
    
    bool soundEffectMuted; //音效是否打开
    bool backgroundMusicMuted;//背景音乐是否打开
    
    
    //游戏相关
    
    //是否是第一次玩这款游戏
    bool notFirstTimeEnterStore;
    
    bool notFirstTimePlayThisGame;
    
    
    //是否暂停游戏
    bool gamePaused;
    
    //系统默认设置
    cocos2d::CCUserDefault* defaults;
    
    
    //关卡相关
    
    int levelsCompleted; //已通过的关卡数量
    
    
    //当前关卡是否通过
    
    bool currentLevelSolved;
    
    
    
    //当前关卡下的题目编号
    
    int currentQuestionIndex;
    
    
    //当前关卡是否解锁
    bool currentLevelUnlocked;
    
    //当前关卡是否通过
    
    //当前关卡的评级
    int currentLevelStar;
    
    bool isCurrentLevelPassed;
    
    
    //所选场景和关卡
    
    
    int selectedLevel;
    
    //当前关卡的评价（非历史最佳成绩，而是此次通关时的评价）
    
    int currentLevelStars;
    
    //未回答的问题数量
    
    int numberOfUnusedQuestions;
    
    CREATE_FUNC(GameData);
    /*//关卡是否解锁
    CC_PROPERTY(bool,_isLevel2Unlocked,isLevel2Unlocked);
    CC_PROPERTY(bool,_isLevel3Unlocked,isLevel3Unlocked);
    CC_PROPERTY(bool,_isLevel4Unlocked,isLevel4Unlocked);
    CC_PROPERTY(bool,_isLevel5Unlocked,isLevel5Unlocked);
    
    //当前玩家所拥有的道具数量

    //叫兽的爱
    CC_PROPERTY(int,_currentNumberOfGameProp1,currentNumberOfGameProp1);
    
    //空空的胸
    CC_PROPERTY(int,_currentNumberOfGameProp2,currentNumberOfGameProp2);

    //戴三个表
    CC_PROPERTY(int,_currentNumberOfGameProp3,currentNumberOfGameProp3);

    //女神凝望
    CC_PROPERTY(int,_currentNumberOfGameProp4,currentNumberOfGameProp4);



    //当前关卡答对的题目总数
    CC_PROPERTY(int,_numberOfCorrectAnswerOfCurrentLevel,numberOfCorrectAnswerOfCurrentLevel);

    //当前关卡已回答的题目数量
    CC_PROPERTY(int,_numberOfAnsweredQuestionOfCurrentLevel,numberOfAnsweredQuestionOfCurrentLevel);

    //当前关卡已回答错误的题目数量
    CC_PROPERTY(int,_numberOfWrongAnswerOfCurrentLevel,numberOfWrongAnswerOfCurrentLevel);
    //玩家生命值
    CC_PROPERTY(int,_userLife,userLife);
    //已经出现过的题目编号数组，在关卡跳转时需要清空
    CC_PROPERTY(cocos2d::CCArray*,_appearedQuestionIndexArray,appearedQuestionIndexArray);

    //是否已购买道具4
    
    CC_PROPERTY(bool,_isGameProp4Purchased,isGameProp4Purchased);

    //音效相关
    CC_PROPERTY(bool,_soundEffectMuted,soundEffectMuted);//音效是否打开
    CC_PROPERTY(bool,_backgroundMusicMuted,backgroundMusicMuted);//背景音乐是否打开

    //游戏相关

    //是否是第一次玩这款游戏
    CC_PROPERTY(bool,_notFirstTimeEnterStore,notFirstTimeEnterStore);
    CC_PROPERTY(bool,_notFirstTimePlayThisGame,notFirstTimePlayThisGame);

    //是否暂停游戏
    CC_PROPERTY(bool,_gamePaused,gamePaused);


    //系统默认设置
    CC_PROPERTY(cocos2d::CCUserDefault*,_defaults,defaults);

    //关卡相关

    //已通过的关卡数量
    CC_PROPERTY(int,_levelsCompleted,levelsCompleted);

    //当前关卡是否通过

    CC_PROPERTY(bool,_currentLevelSolved,currentLevelSolved);


    //当前关卡下的题目编号

    CC_PROPERTY(int,_currentQuestionIndex,currentQuestionIndex);

    //当前关卡是否解锁
    CC_PROPERTY(bool,_currentLevelUnlocked,currentLevelUnlocked);
    //当前关卡是否通过

    //当前关卡的评级
    
    CC_PROPERTY(int,_currentLevelStar,currentLevelStar);
    CC_PROPERTY(bool,_isCurrentLevelPassed,isCurrentLevelPassed);

    //所选场景和关卡
    CC_PROPERTY(int,_selectedLevel,selectedLevel);
    //当前关卡的评价（非历史最佳成绩，而是此次通关时的评价）

    CC_PROPERTY(int,_currentLevelStars,currentLevelStars);
    //未回答的问题数量

    CC_PROPERTY(int,_numberOfUnusedQuestions,numberOfUnusedQuestions);*/
};

#endif // __GAMEDATA_H__
