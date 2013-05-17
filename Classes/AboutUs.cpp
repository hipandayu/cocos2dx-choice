
#include "AboutUs.h"
//#include "GameSounds.h"
#include "SceneManager.h"
#include "GameData.h"
#include "SimpleAudioEngine.h"

using namespace cocos2d;
using namespace CocosDenshion;

CCScene* AboutUs::scene()
{
    // 'scene' is an autorelease objec
    CCScene *scene = CCScene::create();
    
    // 'layer' is an autorelease object
    AboutUs *layer = AboutUs::create();
    
    // add layer as a child to scene
    scene->addChild(layer);
    
    // return the scene
    return scene;
}



//设置视觉元素位置
void AboutUs::setMenuLocation(){
    CCSize screenSize = CCDirector::sharedDirector()->getWinSize();
    
    backMenuLocation = ccp(screenSize.width*0.85,screenSize.height*0.85);
    
}


//button pressed
void AboutUs::backButtonPressed(){
    
    backButton->runAction(CCRotateBy::create(0.5, 360));
    this->runAction(CCSequence::create(CCDelayTime::create(0.5),CCCallFunc::create(this, callfunc_selector(AboutUs::backToStart)),NULL));
}

//返回游戏开始界面
void AboutUs::backToStart(){
    
    //播放音效
    SimpleAudioEngine::sharedEngine()->playBackgroundMusic("menuenter.wav");
    SceneManager::goStartGame();
    
}

//添加返回按钮
void AboutUs::addBackItem(){
    
    backButton=CCMenuItemImage::create("button_back-ipad.png", NULL, this,menu_selector(AboutUs::backButtonPressed));
    
    CCMenu *menuButton=CCMenu::create(backButton,NULL);
    
    menuButton->setPosition(backMenuLocation);
    this->addChild(menuButton,1);
    
}

//添加背景图片
void AboutUs::addBg(){
    
    CCSize size = CCDirector::sharedDirector()->getWinSize();
    
    bg = CCSprite::create("bg_common-ipad.png");
    bg->setPosition(ccp(size.width/2, size.height/2));
    this->addChild(bg, -1);
    
}


//添加字幕
void AboutUs::addTextLabel(){
    
    CCSize screenSize =CCDirector::sharedDirector()->getWinSize();
    
    //游戏标题
    CCSprite *gameTitle = CCSprite::create("bg_gametitle-ipad.png");
    gameTitle->setPosition(ccp(screenSize.width*0.5, screenSize.height*1.1));
    gameTitle->setScale(0.8);
    
    CCFiniteTimeAction *titleAction=CCSequence::create(CCMoveTo::create(1.0, ccp(screenSize.width*0.5, screenSize.height*0.7)),CCMoveTo::create(1.0,ccp(screenSize.width*0.5, screenSize.height*0.8)),CCMoveTo::create(1.0,ccp(screenSize.width*0.5, screenSize.height*0.7)),NULL);
    
    gameTitle->runAction(titleAction);
    this->addChild(gameTitle,2);
    
    //第一行 工作室
    CCLabelTTF *label1 = CCLabelTTF::create("@Copyright 2013 xiandanboke.com.cn", "ChalkboardSE-Bold", 45 );
    label1->setPosition(ccp(screenSize.width/2, screenSize.height/2));
    label1->setColor(ccc3(16, 174, 231));
    
    this->addChild(label1,2);
    
    //第二行 主策划
    CCLabelTTF *label2 = CCLabelTTF::create("咸蛋策划", "ChalkboardSE-Bold", 45);
    label2->setPosition(ccp(screenSize.width/2, screenSize.height*0.4));
    label2->setColor(ccc3(16, 174, 231));
    this->addChild(label2,2);
    
    //第三行 主美
    
    CCLabelTTF *label3 = CCLabelTTF::create("咸蛋设计", "ChalkboardSE-Bold", 45);
    label3->setPosition(ccp(screenSize.width/2, screenSize.height*0.3));
    label3->setColor(ccc3(16, 174, 231));
    this->addChild(label3,2);
    
    //第四行 主音效
    CCLabelTTF *label4 = CCLabelTTF::create("咸蛋音乐", "ChalkboardSE-Bold", 45);
    label4->setPosition(ccp(screenSize.width/2, screenSize.height*0.2));
    label4->setColor(ccc3(16, 174, 231));
    this->addChild(label4,2);
   
    
    
    
    //copyright
    
}


#pragma mark more apps

#pragma mark title




//给作者写邮件
void AboutUs::mailToMe(){
    
    //CCApplication::sharedApplication()->openURL("http://www.google.com");
    //NSURL *url = [NSURL URLWithString:@"mailto://eseedo@gmail.com"];
    //[[UIApplication sharedApplication] openURL:url];
}


//music


void AboutUs::updateMusic(){
    
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
void AboutUs::addMenuBackground(){
    
    CCSize size = CCDirector::sharedDirector()->getWinSize();
    
    CCSprite *menuBackground = CCSprite::create("rollbg-ipad.png");
    menuBackground->setOpacity(50);
    
    menuBackground->setPosition(ccp(size.width/2, size.height/2));
    
    this->addChild(menuBackground,0);
    
}

//背景音乐

//添加背景音乐
void AboutUs::playBackgroundMusic(){
    
    SimpleAudioEngine::sharedEngine()->playBackgroundMusic("about.mp3", true);
    
}

//场景初始化
bool AboutUs::init()
{
    //////////////////////////////
    // 1. super init first
    if ( !CCLayer::init() )
    {
        return false;
    }
    this->setMenuLocation();
    this->addBg();
    this->addMenuBackground();
    this->addBackItem();
    this->addTextLabel();
    this->playBackgroundMusic();
    
    this->schedule(schedule_selector(AboutUs::updateMusic), 6.0);
    return true;
}

