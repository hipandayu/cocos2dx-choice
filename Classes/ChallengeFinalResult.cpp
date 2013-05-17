#include "ChallengeFinalResult.h"
#include "SceneManager.h"
#include "Gamedata.h"
#include "SimpleAudioEngine.h"
#include "Constants.h"


using namespace cocos2d;
using namespace CocosDenshion;

CCScene* ChallengeFinalResult::scene()
{
    // 'scene' is an autorelease object
    CCScene *scene = CCScene::create();
    
    // 'layer' is an autorelease object
    ChallengeFinalResult *layer = ChallengeFinalResult::create();

    // add layer as a child to scene
    scene->addChild(layer);

    // return the scene
    return scene;
}

//添加场景的背景
void ChallengeFinalResult::addSceneBg(){
    
    
    CCSprite *background = CCSprite::create("bg_common-ipad.png");
    background->setPosition(ccp(screenSize.width/2,screenSize.height/2));
    this->addChild(background,-1);
    
}

//添加背景并设置透明度

void ChallengeFinalResult::addResultBg(){
    
    resultBg = CCSprite::create("rollbg-ipad.png");
    
    resultBg->setPosition(ccp(screenSize.width/2,screenSize.height/2));
    this->addChild(resultBg,0);
    
}



//停止播放背景音乐
void ChallengeFinalResult::stopBackgroundMusic(){
    
    SimpleAudioEngine::sharedEngine()->stopBackgroundMusic();
}




//add text
void ChallengeFinalResult::addText(){
            
    //显示过关或失败的标签
    CCLabelTTF *clear = CCLabelTTF::create("全部清空","Arial-BoldMT",50);
    
    //添加星星
    CCSprite *star = CCSprite::create("3stars-hd.png");
    
    clear->setPosition(ccp(screenSize.width*0.5,screenSize.height*0.67));
    star->setPosition(ccp(screenSize.width*0.5,screenSize.height*0.8));
    
    
    this->addChild(clear,10);
    this->addChild(star,10);
    
}

//返回关卡选择界面

void ChallengeFinalResult::goStartGame(){
    
    this->stopBackgroundMusic();
    
    SceneManager::goStartGame();
    
}

//添加返回按钮

void ChallengeFinalResult::addBackButton(){
    
    
    CCMenuItem *backButtonItem = CCMenuItemImage::create("button_backtolevelselection-ipad.png",NULL,this, menu_selector(ChallengeFinalResult::backButtonPressed));
    
    CCMenu *menu = CCMenu::create(backButtonItem, NULL);
    menu->setPosition(ccp(0,0));
    backButtonItem->setPosition(ccp(screenSize.width/2,screenSize.height*0.3));
    
    this->addChild(menu,1);
    
}

void ChallengeFinalResult::backButtonPressed(){
    
    //    [item2 runAction:[CCRotateBy actionWithDuration:0.5 angle:90]);
    
    this->goStartGame();
    
}


void ChallengeFinalResult::playBgMusic(){
    
    
    SimpleAudioEngine::sharedEngine()->playEffect("about.mp3");
    
}

void ChallengeFinalResult::resetDatabase(){
    
    //重置问题总数
    GameData::sharedData()->numberOfUnusedQuestions = TotalNumberOfQuestionInDatabase;
}


// on "init" you need to initialize your instance
bool ChallengeFinalResult::init()
{
    //////////////////////////////
    // 1. super init first
    if ( !CCLayer::init() )
    {
        return false;
    }
    
    //获取屏幕大小
    screenSize =  CCDirector::sharedDirector()->getWinSize();
    
    this->addText();
    this->addSceneBg();
    this->addResultBg();
    
    this->addBackButton();
    //播放背景音乐
    this->playBgMusic();
    //reset database
    this->resetDatabase();
    
    return true;
}


