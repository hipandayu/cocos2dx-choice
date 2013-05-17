
#include "ChallengeGameScene.h"
#include "SceneManager.h"
#include "Gamedata.h"
#include "SimpleAudioEngine.h"
#include "Constants.h"

#include "AppDelegate.h"


#include "QuestionDatabase.h"
#include "QuestionDetails.h"

#include "PauseLayer.h"
#include "CCString.h"

using namespace cocos2d;
using namespace CocosDenshion;


CCScene* ChallengeGameScene::scene()
{
    // 'scene' is an autorelease object
    CCScene *scene = CCScene::create();
    
    // 'layer' is an autorelease object
    ChallengeGameScene *layer = ChallengeGameScene::create();

    // add layer as a child to scene
    scene->addChild(layer);

    // return the scene
    return scene;
}

//设置各视觉元素的位置

void ChallengeGameScene::setMenuLocation(){
    
    screenSize = CCDirector::sharedDirector()->getWinSize();
    
    storeButtonLocation = ccp(screenSize.width*0.1,screenSize.height*0.92);
    
    bgLocation = ccp(screenSize.width*0.5,screenSize.height*0.5);
    
    pauseButtonLocation = ccp(screenSize.width*0.87,screenSize.height*0.88);
    
    zeroLocation = ccp(0,0);
    
    questionLocation = ccp(screenSize.width*0.5,screenSize.height*0.65);
    
    countDownLabelLocation = ccp(screenSize.width*0.15,screenSize.height*0.45);
    
    
    currentQuestionNumberLabelLocation = ccp(screenSize.width*0.5,screenSize.height*0.85);
    
    quizFramePosition = ccp(screenSize.width*0.5,screenSize.height*0.6);
    
    userAnswerFeedbackLocation = ccp(screenSize.width*0.75,screenSize.height*0.5);
    
    answer1Location = ccp(screenSize.width*0.5,screenSize.height*0.32);
    answer2Location = ccp(screenSize.width*0.5,screenSize.height*0.2);
    answer3Location = ccp(screenSize.width*0.5,screenSize.height*0.08);
    
    
    answer1FramePosition = ccp(screenSize.width*0.5,screenSize.height*0.32);
    answer2FramePosition = ccp(screenSize.width*0.5,screenSize.height*0.2);
    answer3FramePosition = ccp(screenSize.width*0.5,screenSize.height*0.08);
    
    answer1IndexLocation = ccp(screenSize.width*0.465,screenSize.height*0.32);
    answer2IndexLocation = ccp(screenSize.width*0.465,screenSize.height*0.2);
    answer3IndexLocation = ccp(screenSize.width*0.465,screenSize.height*0.08);
    
     happyBubsySpritePosition = ccp(screenSize.width*0.85,screenSize.height*0.5);
    
    
}


//添加当前场景的背景图片
//添加滚动背景
void ChallengeGameScene::addBackground(){
    
    bg = CCSprite::create("bg_common-ipad.png");
    bg->setPosition(bgLocation);
    
    this->addChild(bg,-1);
    
}


void backToStore(){
    //先旋转90度
    
    //播放音效
    SimpleAudioEngine::sharedEngine()->playEffect("menuenter.wav");
    //然后切换到商城界面
//    SceneManager::goMyStore);
    
    
}

//添加暂停按钮（右边）
//add pause menu
void ChallengeGameScene::addPauseMenu(){
    
    pauseMenuItem = CCMenuItemImage::create("button_pause-ipad.png",NULL,this, menu_selector(ChallengeGameScene::pauseButtonPressed));
    
    pauseMenuItem->setPosition(pauseButtonLocation);
    pauseMenuItem->setScale(0.8);
    
    CCMenu *menu = CCMenu::create(pauseMenuItem, NULL);
    menu->setPosition(ccp(0,0));
    this->addChild(menu);
    
}

void ChallengeGameScene::pauseButtonPressed(){
    
    //播放音效
    SimpleAudioEngine::sharedEngine()->playEffect("menuenter.wav");
    //旋转
    pauseMenuItem->runAction(CCRotateBy::create(0.5,360));
    this->runAction(CCSequence::create(CCDelayTime::create(0.5),CCCallFunc::create(this, callfunc_selector(ChallengeGameScene::pauseGame)),NULL));
}


void ChallengeGameScene::pauseGame(){
    
    //暂停游戏
    
    ccColor4B c = {0,0,0,0};
    PauseLayer::layerWithColor(c,this);
    //pause->setTag(1122);
    //this->addChild(pause,20);
    //PauseLayer layerWithColor:c delegate:self);
    
}

//添加默认卡通形象
void ChallengeGameScene::addCartoonAvatar(){
    
    thinkingface =  CCSprite::create("thinkingface-ipad.png");
    thinkingface->setPosition(happyBubsySpritePosition);
    this->addChild(thinkingface,2);
    
}

//更新卡通形象

void ChallengeGameScene::updateCartoonAvatar(){
    
    if(thinkingface!=NULL){
        
        this->removeChild(thinkingface,true);
        thinkingface = NULL;
    }   
    
    if(isUserCorrect == true){
        
        smilingface = CCSprite::create("smilingface-ipad.png");
        smilingface->setPosition(happyBubsySpritePosition);
        addChild(smilingface,2);
        
    }else if(isUserCorrect ==false){
        
        sadface = CCSprite::create("sadface-ipad.png");
        sadface->setPosition(happyBubsySpritePosition);
        this->addChild(sadface,2);
    }
}


// 添加答案的ABC序号

void ChallengeGameScene::addAnswerIndexLabel(){
    
    answer1index = CCSprite::create("answer1_index-ipad.png");
    answer2index = CCSprite::create("answer2_index-ipad.png");
    answer3index = CCSprite::create("answer3_index-ipad.png");
    
    //set positions
    answer1index->setPosition(answer1IndexLocation);
    answer2index->setPosition(answer2IndexLocation);
    answer3index->setPosition(answer3IndexLocation);
    
    //add to layer
    
    this->addChild(answer1index,3);
    this->addChild(answer2index,3);
    this->addChild(answer3index,3);
    
}

//添加答案的底部框
void ChallengeGameScene::addAnswerMenu(){
    

    if(answerMenuItem1Selected == false){
        
        possibleAnswer1MenuItem = CCMenuItemImage::create("answerInitialframe-ipad.png" ,NULL,this, menu_selector(ChallengeGameScene::AnswerMenuItem1Selected));
    }else {
        possibleAnswer1MenuItem = CCMenuItemImage::create("answerSelectedframe-ipad.png" ,NULL,this, menu_selector(ChallengeGameScene::AnswerMenuItem1Selected));
        
    }
    
    if(answerMenuItem2Selected == false){
        
        possibleAnswer2MenuItem = CCMenuItemImage::create("answerInitialframe-ipad.png" ,NULL,this, menu_selector(ChallengeGameScene::AnswerMenuItem2Selected));
    }else {
        possibleAnswer2MenuItem = CCMenuItemImage::create("answerSelectedframe-ipad.png" ,NULL,this, menu_selector(ChallengeGameScene::AnswerMenuItem2Selected));
        
    }
    
    if(answerMenuItem3Selected == false){
        
        possibleAnswer3MenuItem = CCMenuItemImage::create("answerInitialframe-ipad.png" ,NULL,this, menu_selector(ChallengeGameScene::AnswerMenuItem3Selected));
    }else {
        possibleAnswer3MenuItem = CCMenuItemImage::create("answerSelectedframe-ipad.png" ,NULL,this, menu_selector(ChallengeGameScene::AnswerMenuItem3Selected));
        
    }
    
    
    possibleAnswer1MenuItem->setPosition(answer1FramePosition);
    possibleAnswer2MenuItem->setPosition(answer2FramePosition);
    possibleAnswer3MenuItem->setPosition(answer3FramePosition);
    
    possibleAnswerMenu = CCMenu::create(possibleAnswer1MenuItem,possibleAnswer2MenuItem,possibleAnswer3MenuItem, NULL);
    possibleAnswerMenu->setPosition(zeroLocation);
    
    this->addChild(possibleAnswerMenu,0);
    
}


//选中答案1的菜单项
void ChallengeGameScene::AnswerMenuItem1Selected(){
    
    selectedAnswerIndex = 1;
    
    answerMenuItem1Selected = true;
    answerMenuItem2Selected = false;
    answerMenuItem3Selected = false;
    
    if(possibleAnswerMenu !=NULL){
        this->removeChild(possibleAnswerMenu,true);
        possibleAnswerMenu = NULL;
        this->addAnswerMenu();
        
    }
    
    //播放音效
    SimpleAudioEngine::sharedEngine()->playEffect("button.mp3");
    
    
    //判断是否正确
    
    this->judgeCorrectOrWrong();
    
}
//选中答案2的菜单项
void ChallengeGameScene::AnswerMenuItem2Selected(){
    
    selectedAnswerIndex = 2;
    
    answerMenuItem2Selected = true;
    answerMenuItem1Selected = false;
    answerMenuItem3Selected = false;
    
    if(possibleAnswerMenu !=NULL){
        this->removeChild(possibleAnswerMenu,true);
        possibleAnswerMenu = NULL;
        this->addAnswerMenu();
        
    }
    
    //播放音效
    SimpleAudioEngine::sharedEngine()->playEffect("button.mp3");
    
    
    //判断是否正确
    
    this->judgeCorrectOrWrong();
    
}
//选中答案3的菜单项
void ChallengeGameScene::AnswerMenuItem3Selected(){
    
    selectedAnswerIndex = 3;
    
    answerMenuItem3Selected = true;
    answerMenuItem1Selected = false;
    answerMenuItem2Selected = false;
    
    if(possibleAnswerMenu !=NULL){
        this->removeChild(possibleAnswerMenu,true);
        possibleAnswerMenu = NULL;
        this->addAnswerMenu();
        
    }
    //播放音效
    SimpleAudioEngine::sharedEngine()->playEffect("button.mp3");
    
    
    //判断是否正确
    
    this->judgeCorrectOrWrong();
    
}


//添加问题的底部框
void ChallengeGameScene::addQuizFrame(){
    
    CCSprite * quizFrame = CCSprite::create("quizframe-ipad.png");
    quizFrame->setPosition(quizFramePosition);
    this->addChild(quizFrame,1);
    
}

//添加当前题目的序号
void ChallengeGameScene::addCurrentQuestionIndex(){
    
    CCString *questionIndex = CCString::createWithFormat("问题:%d /%d",currentQuestionIndex,totalQuestionNumberOfCurrentLevel);
    CCLabelTTF *currentQuestionIndexLabel = CCLabelTTF::create(questionIndex->getCString(),"ChalkboardSE-Bold",30.0);
    currentQuestionIndexLabel->setPosition(currentQuestionNumberLabelLocation);
    currentQuestionIndexLabel->setColor(ccc3(0,153,68));
    
    this->addChild(currentQuestionIndexLabel,1);
    
}

//添加倒计时的时间计数
void ChallengeGameScene::addCountDownLabel(){
    
    CCString *countdown = CCString::createWithFormat("%d",leftTimeForThisQuestion);
    countdownLabel = CCLabelTTF::create(countdown->getCString(),"ChalkboardSE-Bold",30);
    countdownLabel->setPosition(countDownLabelLocation);
    countdownLabel->setColor(ccc3(255,0,0));
    this->addChild(countdownLabel,1);
    
    
}
//更新标签
void ChallengeGameScene::updateCountDownLabel(){
    
    if(countdownLabel!=NULL){
        
        this->removeChild(countdownLabel,true);
        countdownLabel = NULL;
        this->addCountDownLabel();
    }
    
}




//对当前题目进行倒计时
void ChallengeGameScene::updateCountDown(CCTime *dt){
    
    //如果剩余时间少于1，则当前题目失败，并跳转到下一题目
    
    if(leftTimeForThisQuestion <1)
    {
        SimpleAudioEngine::sharedEngine()->playEffect("wrong.wav");
        CCLOG("当前题目失败，进行相关处理，并跳转到下一题目");
        
        numberOfAnsweredQuestions ++;
        numberOfWrongAnswers ++;
        userLife --;
        
        isUserCorrect = false;
        this->updateCartoonAvatar();
        
       
        
        //无论结果如何，需要让游戏延迟0.5秒钟，然后调用游戏结束逻辑
        this->runAction(CCSequence::create(CCDelayTime::create(0.5),CCCallFunc::create(this, callfunc_selector(ChallengeGameScene::gameLogic)) ,NULL));
        
    }
    
    //播放倒计时音效
    
    if(leftTimeForThisQuestion <=5){
        //播放音效2
        SimpleAudioEngine::sharedEngine()->playEffect("countdown.wav");
    }
    
    //如果剩余时间大于1，则进行以下处理
    if(leftTimeForThisQuestion >=1){
        
        
        //剩余时间减少
        leftTimeForThisQuestion --;
        
        
        //倒计时的标签更新
        
        this->updateCountDownLabel();
    }
    
}

//从GameData中读取游戏相关数据，并设置初始值
void ChallengeGameScene::readGameData(){
    
    //生成单例对象
    
    GameData *data = GameData::sharedData();
    
    //设置倒计时计数为15秒
    leftTimeForThisQuestion = CountDownTimeForEachQuestion;
    
    
    //当前关卡的题目编号
    currentQuestionIndex = data->currentQuestionIndex;
    
    if(currentQuestionIndex ==0){
        currentQuestionIndex =1;
    }
    
    //剩余道具数量
    if(data->notFirstTimePlayThisGame == false){
        //剩余问题数量的初始值为问题总数

        data->numberOfUnusedQuestions = TotalNumberOfQuestionInDatabase;
        numberOfLeftQuestions = data->numberOfUnusedQuestions;
        
        //允许错误的初始值
        userLife = MaximumNumberOfWrongAnswer +1;
        
        
    }else{
        
        userLife = data->userLife;
        numberOfLeftQuestions = data->numberOfUnusedQuestions;
        
        
    }
    

    
    data->notFirstTimePlayThisGame = true;
    
    //题目相关
    numberOfAnsweredQuestions = data->numberOfAnsweredQuestionOfCurrentLevel;
    numberOfCorrectAnswers =  data->numberOfCorrectAnswerOfCurrentLevel;
    numberOfWrongAnswers = data->numberOfWrongAnswerOfCurrentLevel;
    
    //关卡相关
    levelNumber = data->selectedLevel;
    
    switch (levelNumber) {
        case 1:
            totalQuestionNumberOfCurrentLevel = Level1QuestionNumber;
            break;
        case 2:
            totalQuestionNumberOfCurrentLevel = Level2QuestionNumber;
            break;
        case 3:
            totalQuestionNumberOfCurrentLevel = Level3QuestionNumber;
            break;
        case 4:
            totalQuestionNumberOfCurrentLevel = Level4QuestionNumber;
            break;
        case 5:
            totalQuestionNumberOfCurrentLevel = Level5QuestionNumber;
            break;
        default:
             totalQuestionNumberOfCurrentLevel = Level1QuestionNumber;
            break;
    }
    
}

//读取数据库
void ChallengeGameScene::readDatabase(){
    
    //需要增加1个校验来防止出现重复的题目
    
    questionIndexOfDatabase = (arc4random()%TotalNumberOfQuestionInDatabase)+1;
    
    QuestionDatabase *base=QuestionDatabase::database();
    preciseDetails = base->questionDetails(questionIndexOfDatabase);
    
    
    //读取到数组中
    //quizDetails = base->quizQuestionDetails();
    
    //questionIndexOfDatabase = (arc4random()%numberOfLeftQuestions)+1;
    
    //preciseDetails =(QuestionDetails*) quizDetails->objectAtIndex(questionIndexOfDatabase);
    
}


//获取问题的精确细节信息
void ChallengeGameScene::loadQuestionDetails(){
    
    screenSize = CCDirector::sharedDirector()->getWinSize();
    CCSize questionTitleSize = CCSizeMake(screenSize.width*0.6, screenSize.height*0.29);
    
    if (preciseDetails != NULL)
    {
        
        //中央对齐，自动换行        
        //questionTitle = CCLabelTTF::create(preciseDetails->title,"ChalkboardSE-Bold",28,questionTitleSize,kCCTextAlignmentLeft   ,kCCVerticalTextAlignmentCenter,UILineBreakModeWordWrap);
        
        questionTitle = CCLabelTTF::create(preciseDetails->gettitle(),"ChalkboardSE-Bold",40,questionTitleSize ,kCCTextAlignmentLeft ,kCCVerticalTextAlignmentCenter);
        
    }
    else
    {       
        questionTitle = CCLabelTTF::create("噢噢,错误回答太多了哦","ChalkboardSE-Bold",40);
        
    }
    
    
//    questionTitle.visible = false;
    
    questionTitle->setPosition(questionLocation);
    
    this->addChild(questionTitle,3);
    
//        [questionTitle runAction:[CCFadeIn actionWithDuration:1.0]);
    //播放音效
    SimpleAudioEngine::sharedEngine()->playEffect("newtitle.wav");
    
    //  CCLOG("正常吗？");
}


//加载问题所对应的答案

void ChallengeGameScene::loadAnswers(){
    
    if(preciseDetails !=NULL){
        
        correctAnswerIndex = (arc4random()%3)+1;
        
        if(correctAnswerIndex ==1){
            possibleAnswer1 = CCLabelTTF::create(preciseDetails->getcorrectAnswer(),"ChalkboardSE-Bold",30,CCSizeMake(430, 80),kCCTextAlignmentLeft,kCCVerticalTextAlignmentCenter);
            
            possibleAnswer2 = CCLabelTTF::create(preciseDetails->getpossibleAnswer2(),"ChalkboardSE-Bold",30,CCSizeMake(430, 80),kCCTextAlignmentLeft  ,kCCVerticalTextAlignmentCenter);
            
            possibleAnswer3 = CCLabelTTF::create(preciseDetails->getpossibleAnswer3(),"ChalkboardSE-Bold",30,CCSizeMake(430, 80),kCCTextAlignmentLeft ,kCCVerticalTextAlignmentCenter);
            
            
        }
        else if(correctAnswerIndex ==2){
            
            possibleAnswer1 = CCLabelTTF::create(preciseDetails->getpossibleAnswer2(),"ChalkboardSE-Bold",30,CCSizeMake(430, 80),kCCTextAlignmentLeft ,kCCVerticalTextAlignmentCenter);
            
            possibleAnswer2 = CCLabelTTF::create(preciseDetails->getcorrectAnswer(),"ChalkboardSE-Bold",30,CCSizeMake(430, 80),kCCTextAlignmentLeft ,kCCVerticalTextAlignmentCenter);
            
            possibleAnswer3 = CCLabelTTF::create(preciseDetails->getpossibleAnswer3(),"ChalkboardSE-Bold",30,CCSizeMake(430, 80),kCCTextAlignmentLeft ,kCCVerticalTextAlignmentCenter);
            
        }
        else if(correctAnswerIndex ==3){
            
            possibleAnswer1 = CCLabelTTF::create(preciseDetails->getpossibleAnswer3(),"ChalkboardSE-Bold",30,CCSizeMake(480, 80),kCCTextAlignmentLeft ,kCCVerticalTextAlignmentCenter);
            
            possibleAnswer2 = CCLabelTTF::create(preciseDetails->getpossibleAnswer2(),"ChalkboardSE-Bold",30,CCSizeMake(480, 80),kCCTextAlignmentLeft ,kCCVerticalTextAlignmentCenter);
            
            possibleAnswer3 = CCLabelTTF::create(preciseDetails->getcorrectAnswer(),"ChalkboardSE-Bold",30,CCSizeMake(480, 80),kCCTextAlignmentLeft ,kCCVerticalTextAlignmentCenter);
            
        }
        
        
        
    }else{
        possibleAnswer1 = CCLabelTTF::create("噢噢,可能是错误回答哦","ChalkboardSE-Bold",30,CCSizeMake(480, 80),kCCTextAlignmentLeft );
        
        possibleAnswer2 = CCLabelTTF::create("加油,去核对答案咯","ChalkboardSE-Bold",30,CCSizeMake(480, 80),kCCTextAlignmentLeft );
        
        possibleAnswer3 = CCLabelTTF::create("加油,错误回答太多了哦","ChalkboardSE-Bold",30,CCSizeMake(480, 80),kCCTextAlignmentLeft );
        
    }
    
    possibleAnswer1->setPosition(answer1Location);
    possibleAnswer2->setPosition(answer2Location);
    possibleAnswer3->setPosition(answer3Location);
    
    possibleAnswer1->setColor(ccc3(0, 154, 224));
    possibleAnswer2->setColor(ccc3(0, 154, 224));
    possibleAnswer3->setColor(ccc3(0, 154, 224));
    
    this->addChild(possibleAnswer1,5);
    this->addChild(possibleAnswer2,5);
    this->addChild(possibleAnswer3,5);
    
    
}

// 游戏逻辑判断

void ChallengeGameScene::judgeCorrectOrWrong(){
    
    //判断选择的答案是否正确
    
    if(selectedAnswerIndex == correctAnswerIndex){
        
        isUserCorrect = true;
        numberOfAnsweredQuestions ++;
        numberOfCorrectAnswers ++;
        
        
        
    }else if(selectedAnswerIndex != correctAnswerIndex){
        
        isUserCorrect = false;
        
        numberOfAnsweredQuestions ++;
        numberOfWrongAnswers ++;
        userLife --;
        
        
    }
    
    
    //显示结果反馈
    this->showFeedbackOfCurrentQuestion();
    
    
    //无论结果如何，需要让游戏延迟0.5秒钟，然后调用游戏结束逻辑
    this->runAction(CCSequence::create(CCDelayTime::create(0.5),CCCallFunc::create(this, callfunc_selector(ChallengeGameScene::gameLogic)),NULL));
    
    
}

//游戏通用逻辑判断
void ChallengeGameScene::gameLogic(){
    
    if(numberOfWrongAnswers > MaximumNumberOfWrongAnswer){
        //当前关卡失败，结束当前关卡
        CCLOG("当前关卡失败");
        
        this->endGameScene(kEndReasonLose);
        
        
    }else if(numberOfAnsweredQuestions >= totalQuestionNumberOfCurrentLevel){
        //当前关卡通过，结束当前关卡
        CCLOG("当前关卡通过");
        
        this->endGameScene(kEndReasonWin);
        
    }else {
        //切换到下一题
        CCLOG("切换到第%d题",numberOfAnsweredQuestions+1);
        
        
        this->changeToNextQuestion();
        
    }
    
    
    
}

//当前关卡结束
void ChallengeGameScene::endGameScene(EndReason endReason){
    
    if(endReason == kEndReasonWin){
        levelClear = true;
        
        
    }else{
        levelClear = false;

    }
    
    //保存当前关卡的相关结果
    this->saveGameData();
    
    
    //切换到关卡结束界面
    
    if(levelNumber == 5 &&levelClear){

        SceneManager::goChallengeFinalResult();
    }else {
        
        //无论结果如何，需要让游戏延迟0.5秒钟，然后显示游戏结果
        this->runAction(CCSequence::create(CCDelayTime::create(0.5),CCCallFunc::create(this, callfunc_selector(ChallengeGameScene::showLevelResult)) ,NULL));
    }
    
}

//切换到关卡结果界面
void ChallengeGameScene::showLevelResult(){
    
     SceneManager::gochallengeLevelResult();

}

//显示当前题目的反馈结果
void ChallengeGameScene::showFeedbackOfCurrentQuestion(){
    
    this->updateCartoonAvatar();
    
    if(isUserCorrect == true){
        
        //显示绿色的圈
        CCSprite *correctCircle = CCSprite::create("answercorrect-ipad.png");

            
            if(selectedAnswerIndex ==1){
                correctCircle->setPosition(answer1IndexLocation);
            }else if(selectedAnswerIndex ==2){
                correctCircle->setPosition(answer2IndexLocation);
            }else if(selectedAnswerIndex ==3){
                correctCircle->setPosition(answer3IndexLocation);
            }

        
        this->addChild(correctCircle,4);
        
        
        //播放音效
        SimpleAudioEngine::sharedEngine()->playEffect("right.wav");
        
        
    }else if(isUserCorrect == false){
        
        //显示红色的圈
        
        CCSprite *wrongCircle = CCSprite::create("answerwrong-ipad.png");
        
        if(selectedAnswerIndex ==1){
            wrongCircle->setPosition(answer1IndexLocation);
        }else if(selectedAnswerIndex ==2){
            wrongCircle->setPosition(answer2IndexLocation);
        }else if(selectedAnswerIndex ==3){
            wrongCircle->setPosition(answer3IndexLocation);
        }
        this->addChild(wrongCircle,4);
        //播放音效
        SimpleAudioEngine::sharedEngine()->playEffect("wrong.wav");
        

        
    }
  
    
}


//切换到下一题
void ChallengeGameScene::changeToNextQuestion(){
    
    currentQuestionIndex ++;
    
    //游戏数据保存
    GameData *data = GameData::sharedData();
    
    //题目相关
    data->numberOfAnsweredQuestionOfCurrentLevel =  numberOfAnsweredQuestions;
    data->numberOfWrongAnswerOfCurrentLevel = numberOfWrongAnswers;
    data->numberOfCorrectAnswerOfCurrentLevel = numberOfCorrectAnswers;
    
    data->currentQuestionIndex = currentQuestionIndex;
    
    //更新道具数量
    
    data->userLife = userLife;
    
    //重新加载当前界面
    
    SceneManager::goChallengeGameScene();
}

//保存当前关卡的游戏结果

void ChallengeGameScene::saveGameData(){
    
    GameData *data = GameData::sharedData();
    
    //题目相关
    
    data->numberOfAnsweredQuestionOfCurrentLevel = 0;
    data->numberOfWrongAnswerOfCurrentLevel = 0;
    data->numberOfCorrectAnswerOfCurrentLevel = 0;
    data->currentQuestionIndex = 1;
    data->userLife = 3;
    
    
    //关卡信息
    
    data->isCurrentLevelPassed = levelClear;
    
    if(numberOfWrongAnswers ==0){
        data->currentLevelStar =3;
    }else if(numberOfWrongAnswers ==1){
        data->currentLevelStar = 2;
    }else if(numberOfWrongAnswers ==2){
        data->currentLevelStar = 1;
    }else if(numberOfWrongAnswers >=3){
        data->currentLevelStar = 0;
    }
    
    //无论关卡和章节编号是多少，先保存当前关卡的信息
    //设置当前关卡是否通关
    //设置当前关卡评价
    //设置下一关卡解锁
    //设置下一关卡
    
    //如果当前关卡编号不为5，则将下一关卡解锁
   
    //如果关卡编号是5，且已通关，则进入最终画面

    
    
}

#pragma mark 音乐音效相关
//添加背景音乐
void ChallengeGameScene::playBackgroundMusic(){
    
    GameData *data = GameData::sharedData();
    if ( data->backgroundMusicMuted == false ) {
        
        SimpleAudioEngine::sharedEngine()->playBackgroundMusic("challenge.mp3",true);
        
    }
}


//场景初始化
bool ChallengeGameScene::init()
{
    //////////////////////////////
    // 1. super init first
    if ( !CCLayer::init() )
    {
        return false;
    }
    //设置视觉元素的所在位置
    this->setMenuLocation();
    
    
    //读取游戏数据
    this->readGameData();
    
    //读取数据库
    this->readDatabase();
    
    this->loadQuestionDetails();
    
    this->loadAnswers();
    
    
    //添加基本的视觉元素
    
    //添加背景图片
    
    this->addBackground();
    
    
    //添加暂停按钮
    this->addPauseMenu();
    
    //添加答案序号ABC
    this->addAnswerIndexLabel();
    
    //添加答案的底部框
    this->addAnswerMenu();
    
    //添加问题的底部框
    this->addQuizFrame();
    
    //添加当前问题的序号
    this->addCurrentQuestionIndex();
    
    //添加倒计时计数
    this->addCountDownLabel();
    
    //添加卡通形象
    this->addCartoonAvatar();
    
    //实时更新游戏状态
    
    //开始倒计时
    this->schedule(schedule_selector(ChallengeGameScene::updateCountDown), 1);
    //播放背景音乐
    this->playBackgroundMusic();
    
    //    //启用加速计（检测摇晃事件）
    //    self.isAccelerometerEnabled = YES;
    //    [[UIAccelerometer sharedAccelerometer]setUpdateInterval:1/60();
    //    shake_once = false;

    return true;
}

// 检测摇晃事件并进行处理
/*
void accelerometer:(UIAccelerometer *)accelerometer didAccelerate:(UIAcceleration *)acceleration{
 
    float THRESHOLD = 2;
    if (acceleration.x > THRESHOLD || acceleration.x < -THRESHOLD ||
        acceleration.y > THRESHOLD || acceleration.y < -THRESHOLD ||
        acceleration.z > THRESHOLD || acceleration.z < -THRESHOLD) {
        
        if (!shake_once) {
            //      int derp = 22/7;
            shake_once = true;
            
            //玩家在摇晃屏幕
            CCLOG("玩家在摇晃屏幕");
            
            
            //使用道具2

        }
        
    }
    else {
        shake_once = false;
    }
    
}


#pragma mark  内存释放

// on "dealloc" you need to release all your retained objects
void dealloc()
{
    // in case you have something to dealloc, do it in this method
    // in this particular example falsething needs to be released.
    // cocos2d will automatically release all the children (Label)
    
    // don't forget to call "super dealloc"
    super->dealloc();
}

#pragma mark GameKit delegate
*/

int ChallengeGameScene::getUniqueId(){
    return _uniqueId;
}

void ChallengeGameScene::setUniqueId(int uniqueId){
    _uniqueId=uniqueId;
}


int ChallengeGameScene::getType(){
    return _type;
}

void ChallengeGameScene::setType(int uniqueId){
    _type=uniqueId;
}
int ChallengeGameScene::getQuestionIndex(){
    return _questionIndex;
}

void ChallengeGameScene::setQuestionIndex(int uniqueId){
    _questionIndex=uniqueId;
}
