#ifndef __CHALLENGEGAMESCENE_SCENE_H__
#define __CHALLENGEGAMESCENE_SCENE_H__

#include "cocos2d.h"
#include "QuestionDetails.h"
using namespace cocos2d;

//当前关卡结束的原因

typedef enum {
    kEndReasonWin,
    kEndReasonLose
} EndReason;

class ChallengeGameScene : public cocos2d::CCLayer
{
public:
    // Here's a difference. Method 'init' in cocos2d-x returns bool, instead of returning 'id' in cocos2d-iphone
    virtual bool init();  

    // there's no 'id' in cpp, so we recommend returning the class instance pointer
    static cocos2d::CCScene* scene();
    

    //数据库信息
    CC_PROPERTY(int, _uniqueId, UniqueId);
    CC_PROPERTY(int, _type, Type);
    CC_PROPERTY(int, _questionIndex, QuestionIndex);
    QuestionDetails *preciseDetails;
    QuestionDetails *details;
    
    
    //视觉元素的位置
    
    //屏幕大小
    CCSize screenSize;
    //按钮的位置
    
    CCPoint backButtonLocation;
    CCPoint storeButtonLocation;
    
    //背景图片的位置
    CCPoint bgLocation;
    
    //远点
    CCPoint zeroLocation;
    
    //暂停按钮
    
    CCPoint pauseButtonLocation;
    
    //问题所在位置
    
    CCPoint questionLocation;
    
    //倒计时标签所在位置
    CCPoint countDownLabelLocation;
    
    //倒计时血条所在位置
    CCPoint countDownBarLocation;
    
    //玩家血条所在位置
    CCPoint lifeBar1Location;
    CCPoint lifeBar2Location;
    CCPoint lifeBar3Location;
    
    
    //当前题目编号所在位置
    CCPoint currentQuestionNumberLabelLocation;
    
    //答错的题目编号
    CCPoint wrongAnswerNumberLabelLocation;
    
    //道具1所在位置
    CCPoint gameProp1Location;
    
    
    
    //道具2所在位置
    CCPoint gameProp2Location;
    
    //道具3所在位置
    CCPoint gameProp3Location;
    
    //道具1数量所在位置
    
    CCPoint gameProp1NumberLocation;
    
    //道具2数量所在位置
    
    CCPoint gameProp2NumberLocation;
    
    //道具3数量所在位置
    
    CCPoint gameProp3NumberLocation;
    
    //玩家是否回答正确的结果所在位置
    
    CCPoint userAnswerFeedbackLocation;
    
    
    //答案所在位置
    
    CCPoint answer1Location;
    CCPoint answer2Location;
    CCPoint answer3Location;
    
    
    //答案框所在位置
    CCPoint answer1FramePosition;
    CCPoint answer2FramePosition;
    CCPoint answer3FramePosition;
    
    //答案序号所在位置
    CCPoint answer1IndexLocation;
    CCPoint answer2IndexLocation;
    CCPoint answer3IndexLocation;
    
    //笑脸的位置
    CCPoint happyBubsySpritePosition;
    
    //界面视觉元素
    
    //问题
    CCLabelTTF *questionTitle;
    
    //倒计时标签
    CCLabelTTF *countdownLabel;
    
    //暂停菜单
    CCMenuItem *pauseMenuItem;
    
    //问题框位置
    CCPoint quizFramePosition;
    
    //答案菜单项
    CCMenu *possibleAnswerMenu;
    
    CCMenuItem *possibleAnswer1MenuItem;
    CCMenuItem *possibleAnswer2MenuItem;
    CCMenuItem *possibleAnswer3MenuItem;
    
    //答案内容
    CCLabelTTF *possibleAnswer1;
    CCLabelTTF *possibleAnswer2;
    CCLabelTTF *possibleAnswer3;
    
    //答案数字编号标签
    CCSprite *answer1index;
    CCSprite *answer2index;
    CCSprite *answer3index;
    
    //卡通形象
    CCSprite *thinkingface;
    CCSprite *smilingface;
    CCSprite *sadface;
    
    
    //数据信息
    int correctAnswerIndex;
    
    //问题类型
    
    //  int questionType;
    
    //当前题目编号（关卡中）
    int currentQuestionIndex;
    
    //当前关卡的问题数量
    int totalQuestionNumberOfCurrentLevel;
    
    //倒计时剩余时间
    int leftTimeForThisQuestion;
    
    //玩家生命
    int userLife;
    
    
    //道具1- 叫兽的爱 的剩余数量
    
    int leftNumberOfGameProp1;
    
    //道具2- 空空的胸 的剩余数量
    
    int leftNumberOfGameProp2;
    
    //道具3- 戴三个表 的剩余数量
    
    int leftNumberOfGameProp3;
    
    //道具4- 女神凝望 的剩余数量（暂不启用）
    int leftNumberOfGameProp4;
    
    //所选答案的选项编号
    int selectedAnswerIndex;
    
    //当前答案选项是否选中
    bool answerMenuItem1Selected;
    bool answerMenuItem2Selected;
    bool answerMenuItem3Selected;
    
    //当前问题是否回答正确
    bool isUserCorrect;
    
    //是否使用了道具
    bool isGameProp1Used;
    bool isGameProp2Used;
    bool isGameProp3Used;
    bool isGameProp4Used;
    
    //已经回答的问题数量
    int numberOfAnsweredQuestions;
    
    //已经错误回答的问题数量
    int numberOfWrongAnswers;
    
    //已经正确回答的问题数量
    int numberOfCorrectAnswers;
    
    //当前关卡是否通过
    bool levelClear;
    
    //关卡编号

    int levelNumber;
    
    //题目在数据库中的编号
    int questionIndexOfDatabase;
    
    //剩余的问题数量
    int numberOfLeftQuestions;
    
    CCArray *quizDetails;
    
    //是否摇晃
    bool shake_once;
    
    //scrolling background
    
    CCSprite *bg;

    //函数
    void setMenuLocation();
    void addBackground();
    void addPauseMenu();
    void pauseButtonPressed();
    void addCartoonAvatar();
    void updateCartoonAvatar();
    void addAnswerIndexLabel();
    void addAnswerMenu();
    void AnswerMenuItem1Selected();
    void AnswerMenuItem2Selected();
    void AnswerMenuItem3Selected();
    void addQuizFrame();
    void addCurrentQuestionIndex();
    void addCountDownLabel();
    void updateCountDownLabel();
    void updateCountDown(CCTime *dt);
    void readGameData();
    void readDatabase();
    void loadQuestionDetails();
    void loadAnswers();
    void judgeCorrectOrWrong();
    void gameLogic();
    void endGameScene(EndReason endReason);
    void showLevelResult();
    void showFeedbackOfCurrentQuestion();
    void changeToNextQuestion();
    void saveGameData();
    void pauseGame();
    void playBackgroundMusic();
    // implement the "static node()" method manually
    CREATE_FUNC(ChallengeGameScene);
};

#endif // __ChallengeGameScene_SCENE_H__
