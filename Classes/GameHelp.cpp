
#include "GameHelp.h"
#include "SceneManager.h"
#include "GameData.h"
#include "SimpleAudioEngine.h"
//#include "GameSounds.h"
#include "Constants.h"

using namespace cocos2d;
using namespace CocosDenshion;


CCScene* GameHelp::scene()
{
    // 'scene' is an autorelease object
    CCScene *scene = CCScene::create();
    
    // 'layer' is an autorelease object
    GameHelp *layer = GameHelp::create();

    // add layer as a child to scene
    scene->addChild(layer);

    // return the scene
    return scene;
}

//设置视觉元素位置
void GameHelp::setMenuLocation(){
    CCSize screenSize=CCDirector::sharedDirector()->getWinSize();
    backMenuLocation = ccp(screenSize.width*0.85,screenSize.height*0.85);
    
}

//button pressed
void GameHelp::backButtonPressed(){
    
    backButton->runAction(CCRotateBy::create(0.5,360));
    this->runAction(CCSequence::create(CCDelayTime::create(0.5),CCCallFunc::create(this, callfunc_selector(GameHelp::backToStart)),NULL));

}

//返回游戏开始界面
void GameHelp::backToStart(){
    
    
    //播放音效
    SimpleAudioEngine::sharedEngine()->playEffect("menuenter.wav");
    
    SceneManager::goStartGame();
    
}

//添加返回按钮
void GameHelp::addBackItem(){

    backButton = CCMenuItemImage::create("button_back-ipad.png",NULL,this,menu_selector(GameHelp::backButtonPressed));
    
    CCMenu *menu = CCMenu::create(backButton,NULL);
    menu->setPosition(backMenuLocation);
    this->addChild(menu,1);
}

//添加背景图片
void GameHelp::addHelpBg(){

    CCSize size=CCDirector::sharedDirector()->getWinSize();

    bg = CCSprite::create("bg_common-ipad.png");
    bg->setPosition(ccp(size.width/2,size.height/2));
    
    this->addChild(bg,-1);
    
}


//添加字幕
void GameHelp::addTextLabel(){
    
    CCSize screenSize=CCDirector::sharedDirector()->getWinSize();
    
    CCSize labelSize = CCSizeMake(screenSize.width*0.8, screenSize.height*0.7);
    
    
    //游戏标题
    CCSprite *gameTitle = CCSprite::create("bg_gametitle-ipad.png");
    gameTitle->setPosition(ccp(screenSize.width*0.5,screenSize.height*1.1));
    gameTitle->setScale(0.8);
    
    CCFiniteTimeAction*  titleAction = CCSequence::create(CCMoveTo::create(1.0,ccp(screenSize.width*0.5,screenSize.height*0.7)),CCMoveTo::create(1.0,ccp(screenSize.width*0.5,screenSize.height*0.8)),CCMoveTo::create(1.0,ccp(screenSize.width*0.5,screenSize.height*0.7)),NULL);
    
    gameTitle->runAction(titleAction);
    this->addChild(gameTitle,2);


    //第一行 工作室
    CCLabelTTF *label1 = CCLabelTTF::create("欢迎使用乐知问答游戏! 该游戏集学习与娱乐为一休，在玩游戏的同学丰富自己的大脑，学的愉快哦","ChalkboardSE-Bold",45,labelSize,kCCTextAlignmentLeft,kCCVerticalTextAlignmentCenter);
    /*
    String *helpText = [NSString stringWithFormat:@"Welcome to Cocos2D Challenge! This game is designed to help you improve your cocos2d skill. In this version we provide 5 levels for newbie, coder,hacker,master and monster :) Each level has different number of questions. You've to pass the previous level to unlock the next level. Now it's time to challenge your cocos2d skill. Go enjoy it!"];
    
    CCLabelTTF *label1 = CCLabelTTF::create("欢迎使用乐学知识问答游戏! 该游戏集学习与娱乐为一休，在玩游戏的同学丰富自己的大脑，学的愉快哦","ChalkboardSE-Bold" fontSize:28 dimensions:labelSize hAlignment:kCCTextAlignmentLeft   vAlignment:kCCVerticalTextAlignmentCenter lineBreakMode:UILineBreakModeWordWrap);
    */
    
    label1->setPosition(ccp(screenSize.width/2,screenSize.height*0.4));
    label1->setColor(ccc3(16,174,231));

    this->addChild(label1,2);
    
}


#pragma mark mail to us

void GameHelp::addMailToUs(){
    
    CCSize screenSize=CCDirector::sharedDirector()->getWinSize();
    

    CCMenuItemImage *mailToItem = CCMenuItemImage::create("button_mailtous-ipad.png",NULL,this,menu_selector(GameHelp::mailToMe));
    mailToItem->setPosition(ccp(screenSize.width/2,screenSize.height*0.1));
    
    CCMenu *menu =CCMenu::create(mailToItem,NULL);
    menu->setPosition(ccp(0,0));

    this->addChild(menu,3);
    
}




//给作者写邮件
void GameHelp::mailToMe(){

     //NSURL *url = [NSURL URLWithString:@"mailto://815099602@qq.com"];
     //[[UIApplication sharedApplication] openURL:url];
}


//music


void GameHelp::updateMusic(){
    
    int soundChoice = (arc4random()%5);
    
    switch (soundChoice)
    {
        case 0:
            SimpleAudioEngine::sharedEngine()->playEffect("saveme.mp3");
            break;
        case 1:
            SimpleAudioEngine::sharedEngine()->playEffect("magic3.mp3");
        case 2:
            SimpleAudioEngine::sharedEngine()->playEffect("magic2.mp3");
            
        case 3:
            SimpleAudioEngine::sharedEngine()->playEffect("attack-add2.mp3");
            
        case 4:
            SimpleAudioEngine::sharedEngine()->playEffect("magic1-2.mp3");
            
        default:
            SimpleAudioEngine::sharedEngine()->playEffect("saveme.mp3");
            break;
            
    }
}

//添加卷轴
void GameHelp::addMenuBackground(){
    
    CCSize size=CCDirector::sharedDirector()->getWinSize();


    CCSprite *menuBackground = CCSprite::create("rollbg-ipad.png");
    menuBackground->setOpacity(50);

    menuBackground->setPosition(ccp(size.width/2,size.height*0.5));
    
    this->addChild(menuBackground,0);
    
}

//背景音乐

//添加背景音乐
void GameHelp::playBackgroundMusic(){
    
    SimpleAudioEngine::sharedEngine()->playBackgroundMusic("about.mp3",true);
}

//场景初始化
bool GameHelp::init()
{
    //////////////////////////////
    // 1. super init first
    if ( !CCLayer::init() )
    {
        return false;
    }
    
    this->setMenuLocation();
    this->addHelpBg();
    this->addMenuBackground();
    this->addBackItem();
    this->addTextLabel();
    this->playBackgroundMusic();
    this->addMailToUs();
    this->schedule(schedule_selector(GameHelp::updateMusic), 6.0);
    return true;
}


