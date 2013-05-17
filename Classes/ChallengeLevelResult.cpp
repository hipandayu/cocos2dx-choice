#include "ChallengeLevelResult.h"
#include "SceneManager.h"
#include "Gamedata.h"
#include "SimpleAudioEngine.h"
#include "Constants.h"


using namespace cocos2d;
using namespace CocosDenshion;


CCScene* ChallengeLevelResult::scene()
{
    // 'scene' is an autorelease object
    CCScene *scene = CCScene::create();
    
    // 'layer' is an autorelease object
    ChallengeLevelResult *layer = ChallengeLevelResult::create();

    // add layer as a child to scene
    scene->addChild(layer);

    // return the scene
    return scene;
}

//设置视觉元素的位置

void ChallengeLevelResult::setMenuLocation(){
    
    CCSize size = CCDirector::sharedDirector()->getWinSize();
    
    resultBgLocation = ccp(size.width/2,size.height/2);
    starsLocation = ccp(size.width*0.5,size.height*0.8);
    
    resultTextLocation = ccp(size.width*0.5,size.height*0.6);
    
    resultLabelLocation = ccp(size.width*0.5,size.height*0.67);

}

//读取数据

//读取LevelManager中的数据

void ChallengeLevelResult::readData(){
    
    //从GameData类中读取数据,是否通关，评价等
    
    GameData *data =GameData::sharedData();
    

    levelNumber = data->selectedLevel;
    
    levelClear = data->isCurrentLevelPassed;
    
    levelStars = data->currentLevelStar;
    
}

//解锁新场景
void ChallengeLevelResult::unlockNextLevel(){
    
    CCLog("levelClear:%d,%d",levelClear,levelNumber);
    
    if(levelClear == true){
        
        switch (levelNumber) {
            case 1:
                GameData::sharedData()->isLevel2Unlocked = true;
                break;
            case 2:
                GameData::sharedData()->isLevel3Unlocked = true;
                break;
            case 3:
                GameData::sharedData()->isLevel4Unlocked = true;
                break;
            case 4:
                GameData::sharedData()->isLevel5Unlocked = true;
                break;
            default:
                break;
        }
        
    }
    
    CCLog("unlockNextLevel:%d,%d,%d,%d,%d",levelClear,GameData::sharedData()->isLevel2Unlocked,GameData::sharedData()->isLevel3Unlocked,GameData::sharedData()->isLevel4Unlocked,GameData::sharedData()->isLevel5Unlocked);
}


//添加场景的背景
void ChallengeLevelResult::addSceneBg(){
    
    screenSize = CCDirector::sharedDirector()->getWinSize();
    CCSprite *background = CCSprite::create("bg_common-ipad.png");
    background->setPosition(ccp(screenSize.width/2,screenSize.height/2));
    this->addChild(background,-1);
    
}

//添加背景并设置透明度

void ChallengeLevelResult::addResultBg(){
    
    screenSize = CCDirector::sharedDirector()->getWinSize();
    
    resultBg = CCSprite::create("rollbg-ipad.png");
    
    resultBg->setPosition(ccp(screenSize.width/2,screenSize.height/2));
    this->addChild(resultBg,0);
    
}


//显示关卡名称和历史最高得分

//显示关卡名称和历史最高得分
void ChallengeLevelResult::addLevelTitle(){
    
    screenSize = CCDirector::sharedDirector()->getWinSize();
    //only you
    
    
    if(levelClear){
        CCLabelTTF *text1 = CCLabelTTF::create("您还未通过该关卡","Arial-BoldMT",16);
        
        text1->setPosition(resultTextLocation);
        //    text1.anchorPoint = ccp(0.5f,0.5f);
        
        this->addChild(text1,10);
        
        
        
        
    }else if(!levelClear){
        CCLabelTTF *text1 = CCLabelTTF::create("噢噢... 成绩不错哦，继续努力!","Arial-BoldMT",16);
        
        text1->setPosition(resultTextLocation);
        
        //    text1.anchorPoint = ccp(0,0.5f);
        
        this->addChild(text1,10);
        
    }
}

//显示游戏结果

void ChallengeLevelResult::addResult(){
    
    screenSize = CCDirector::sharedDirector()->getWinSize();
    //显示过关或失败的标签
    if(levelStars ==3){
        
        //显示过关或失败的标签
        CCLabelTTF *clear = CCLabelTTF::create("非常好!","ChalkboardSE-Bold",50);
        
        //添加星星
        CCSprite *star = CCSprite::create("3stars-ipad.png");
        
        clear->setPosition( resultLabelLocation);
        star->setPosition( starsLocation);
        
        
        this->addChild(clear,10);
        this->addChild(star,10);
        
    }else if(levelStars ==2){
        
        //显示过关或失败的标签
        
        CCLabelTTF *clear = CCLabelTTF::create("很好!","ChalkboardSE-Bold",50);
        
        //添加星星
        CCSprite *star = CCSprite::create("2stars-ipad.png");
        
        clear->setPosition( resultLabelLocation);
        star->setPosition( starsLocation);
        
        
        this->addChild(clear,10);
        this->addChild(star,10);
        
    }else if(levelStars ==1){
        //显示过关或失败的标签
        
        CCLabelTTF *clear = CCLabelTTF::create("完成本关!","ChalkboardSE-Bold",50);
        
        //添加星星
        CCSprite *star = CCSprite::create("1star-ipad.png");
        
        clear->setPosition( resultLabelLocation);
        star->setPosition( starsLocation);
        
        
        this->addChild(clear,10);
        this->addChild(star,10);
        
    }else if(levelStars ==0){
        
        //显示过关或失败的标签
        
        CCLabelTTF *clear = CCLabelTTF::create("闯关失败!","ChalkboardSE-Bold",50);
        
        //添加星星
        CCSprite *star = CCSprite::create("0star-ipad.png");
        
        
        clear->setPosition( resultLabelLocation);
        star->setPosition( starsLocation);
        
        this->addChild(clear,10);
        this->addChild(star,10);
        
    }
    
}

//停止播放背景音乐
void ChallengeLevelResult::stopBackgroundMusic(){
    
    SimpleAudioEngine::sharedEngine()->stopBackgroundMusic();
}


void ChallengeLevelResult::item1Pressed(){
    
    //    [item1 runAction:[CCRotateBy actionWithDuration:0.5 angle:90));
    
    this->runAction(CCSequence::create(CCDelayTime::create(0.5),CCCallFunc::create(this, callfunc_selector(ChallengeLevelResult::shareToSocialNetwork)),NULL));
    
}

void ChallengeLevelResult::shareToSocialNetwork(){
    
    /*CCString *systemVersion = [UIDevice currentDevice].systemVersion;
    bool isSystemVersionAfter6 = false;
    if([systemVersion isEqualToString:@"6.0"] || [systemVersion isEqualToString:@"6.0.1"] || [systemVersion isEqualToString:@"6.1"))  {
        isSystemVersionAfter6 = true;
    }
    
    NSLog(@"systemversion is:%@",systemVersion);
    
    if(isSystemVersionAfter6){
        
        CCString *initialText = [CCString stringWithFormat:@"I found a great game challenging your cocos2d skill,come to have a try:)");
        
        UIActivityViewController *activityViewController =
        [[UIActivityViewController alloc] initWithActivityItems:@[initialText] applicationActivities:NULL);
        [[[CCDirector sharedDirector]parentViewController]  presentViewController:activityViewController animated:YES completion:NULL);
    }
    else{
        NSURL *url = [NSURL URLWithString:@"mailto://happybubsy@126.com");
        [[UIApplication sharedApplication]openURL:url);
    }*/
}

void ChallengeLevelResult::item2Pressed(){
    
    //    [item2 runAction:[CCRotateBy actionWithDuration:0.5 angle:90));
    
    this->runAction(CCSequence::create(CCDelayTime::create(0.5),CCCallFunc::create(this, callfunc_selector(ChallengeLevelResult::backToLevelSelection)),NULL));
    
    
}
void ChallengeLevelResult::item3Pressed(){
    
    
    //    [item3 runAction:[CCRotateBy actionWithDuration:0.5 angle:90));
    
    this->runAction(CCSequence::create(CCDelayTime::create(0.5),CCCallFunc::create(this, callfunc_selector(ChallengeLevelResult::playNextLevel)),NULL));
    
}

void ChallengeLevelResult::item4Pressed(){
    
    
    //    [item4 runAction:[CCRotateBy actionWithDuration:0.5 angle:90));
    
    this->runAction(CCSequence::create(CCDelayTime::create(0.5),CCCallFunc::create(this, callfunc_selector(ChallengeLevelResult::replayCurrentLevel)),NULL));
    
}

//返回关卡选择界面

void ChallengeLevelResult::backToLevelSelection(){
    this->stopBackgroundMusic();
    
    SceneManager::goChallengeLevelSelect();
    
}

//重玩当前关卡
void ChallengeLevelResult::replayCurrentLevel(){
    
    this->stopBackgroundMusic();
    //根据关卡编号的进入不同关卡场景
    
    
    GameData::sharedData()->selectedLevel =levelNumber;
    
    SceneManager::goChallengeGameScene();
    
    
}

//进入下一个关卡
void ChallengeLevelResult::playNextLevel(){
    
    this->stopBackgroundMusic();
    GameData *gamedata =GameData::sharedData();
    
    //判断是否下一个关卡已解锁
    if(levelClear ==true && gamedata->selectedLevel < 5)
    {
        
        gamedata->selectedLevel++;
        
        
        SceneManager::goChallengeGameScene();
        
    }
    
    
}


//显示菜单选项

//显示三个菜单选项
void ChallengeLevelResult::addMenuItems(){
    
    CCSize size = CCDirector::sharedDirector()->getWinSize();
    //获取屏幕大小
    
    if(levelClear){
        
        //创建分享按钮
        item1 = CCMenuItemImage::create("button_share-ipad.png",NULL,this,menu_selector(ChallengeLevelResult::item1Pressed));

        // 创建选择按钮
        item2 = CCMenuItemImage::create("button_backtolevelselection-ipad.png",NULL,this,menu_selector(ChallengeLevelResult::item2Pressed));
        // 创建继续按钮
        item3 =  CCMenuItemImage::create("button_continue-ipad.png",NULL,this,menu_selector(ChallengeLevelResult::item3Pressed));
        // put all those three buttons on the menu
        resultMenu = CCMenu::create(item1,item2, item3, NULL);
        item1->setPosition( ccp(size.width/2,size.height*0.2));
        item2->setPosition( ccp(size.width/2,size.height*0.5));
        item3->setPosition( ccp(size.width/2,size.height*0.35));
        

        
        resultMenu->setPosition(ccp(0,0));
        
        this->addChild(resultMenu);
        
    }else if(!levelClear){
        
        //创建分享按钮
        item1 = CCMenuItemImage::create("button_share-ipad.png",NULL,this,menu_selector(ChallengeLevelResult::item1Pressed));
        
        // 创建选择按钮
        item2 = CCMenuItemImage::create("button_backtolevelselection-ipad.png",NULL,this,menu_selector(ChallengeLevelResult::item2Pressed));
        // 创建继续按钮
        item4 = CCMenuItemImage::create("button_retry-ipad.png",NULL,this,menu_selector(ChallengeLevelResult::item4Pressed));
        
        // put all those three buttons on the menu
        resultMenu = CCMenu::create(item1,item2, item4, NULL);

        item1->setPosition( ccp(size.width/2,size.height*0.2));
        item2->setPosition( ccp(size.width/2,size.height*0.5));
        item4->setPosition( ccp(size.width/2,size.height*0.35));
        
        resultMenu->setPosition(  ccp(0,0));
        
        this->addChild(resultMenu);
        
    }
    
}




void ChallengeLevelResult::playBgMusic(){
    
    if(levelClear){
        
        SimpleAudioEngine::sharedEngine()->playBackgroundMusic("levelpass.mp3",false);
        
        
    }else {
        
        SimpleAudioEngine::sharedEngine()->playBackgroundMusic("levelfail.mp3",false);
        
    }
    
}

void ChallengeLevelResult::resetDatabase(){
    
    GameData::sharedData()->numberOfUnusedQuestions = TotalNumberOfQuestionInDatabase;
}

// on "init" you need to initialize your instance
bool ChallengeLevelResult::init()
{
    //////////////////////////////
    // 1. super init first
    if ( !CCLayer::init() )
    {
        return false;
    }
    
    this->setMenuLocation();
    
    //读取LevelManager中的数据
    
    this->readData();
    
    //获取游戏关卡的背景并设置透明度
    
    this->addSceneBg();
    
    this->addResultBg();
    
    //显示关卡名称
//        this->addLevelTitle);
    
    //显示菜单选项
    
    this->addMenuItems();
    
    //显示游戏结果
    this->addResult();
    
    //显示游戏奖励
    //    this->addBonus);
    
    //播放背景音乐
    this->playBgMusic();
    
    //解锁新场景
    this->unlockNextLevel();
    
    this->resetDatabase();  
    
    return true;
}


