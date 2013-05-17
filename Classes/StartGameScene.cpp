

#include "SimpleAudioEngine.h"
#include "StartGameScene.h"
#include "GameData.h"
#include "SceneManager.h"

using namespace cocos2d;
using namespace CocosDenshion;

enum {
    //@notification
    kTagAlertForNotification = 2,
} AlertTag;


CCScene* StartGameScene::scene()
{
    CCScene *scene=CCScene::create();
    StartGameScene *layer=StartGameScene::create();
    scene->addChild(layer);
    return scene;
}



//获取屏幕大小
void StartGameScene::getScreenSize(){
    screenSize=CCDirector::sharedDirector()->getWinSize();
}

#pragma mark 添加菜单项

//添加进入挑战模式游戏菜单项
void StartGameScene::addStartChallengeMenuItem(){
    
    startChallengeItem=CCMenuItemImage::create("button_start-ipad.png", NULL, this,menu_selector(StartGameScene::startChallenge));
        
    startChallengeItem->setPosition(startChallengeMenuLocation);
    
    CCMenu *menu=CCMenu::create(startChallengeItem,NULL);
    menu->setPosition(CCPointZero);
    
    this->addChild(menu, 2);
    
    
}



//添加about菜单项
void StartGameScene::addAboutItem(){
    
    //创建菜单项
    aboutItem=CCMenuItemImage::create("button_aboutus-ipad.png", NULL, this, menu_selector(StartGameScene::about));
    aboutItem->setPosition(aboutMenuLocation);
    
    //创建菜单
    CCMenu *menu=CCMenu::create(aboutItem,NULL);
    menu->setPosition(CCPointZero);
    this->addChild(menu,2);
    
}

//add setting item

void StartGameScene::addSettingItem(){
    
    //创建菜单项
    
    settingItem=CCMenuItemImage::create("button_setting-ipad.png", NULL, this, menu_selector(StartGameScene::enterGameSetting));
    settingItem->setPosition(settingMenuLocation);    
    //创建菜单
    CCMenu *menu=CCMenu::create(settingItem,NULL);
    menu->setPosition(CCPointZero);
    this->addChild(menu,2);
    
}

//add setting item

void StartGameScene::addMoreItem(){
    
    //创建菜单项
    moreItem=CCMenuItemImage::create("button_more-ipad.png", NULL, this, menu_selector(StartGameScene::enterMoreGames));
    moreItem->setPosition(moreMenuLocation);
    
    //创建菜单
    
    CCMenu *menu=CCMenu::create(moreItem,NULL);
    menu->setPosition(CCPointZero);
    this->addChild(menu,2);
}

#pragma mark add menu

void StartGameScene::addGameMenu(){
    
    this->addStartChallengeMenuItem();
    
    //    [self addSettingItem];
    this->addMoreItem();
    this->addAboutItem();
}


#pragma mark 通过按钮进入不同的场景




//进入挑战模式的关卡选择界面

void StartGameScene::startChallenge(){
    //播放音效
    SimpleAudioEngine::sharedEngine()->playEffect("menuenter.wav");
    CCLog("startChallenge:%d,%d,%d,%d",GameData::sharedData()->isLevel2Unlocked,GameData::sharedData()->isLevel3Unlocked,GameData::sharedData()->isLevel4Unlocked,GameData::sharedData()->isLevel5Unlocked);
    SceneManager::goChallengeLevelSelect();
    
}

//进入游戏介绍画面
void StartGameScene::about(){
    
    //播放音效
    SimpleAudioEngine::sharedEngine()->playEffect("menuenter.wav");
    
    SceneManager::goAboutUs();
    
}

//enter setting
void StartGameScene::enterGameSetting(){
    
    SimpleAudioEngine::sharedEngine()->playEffect("menuenter.wav");
    
    
    SceneManager::goGameSetting();
    
}

//enter help
void StartGameScene::enterMoreGames(){
    
    SimpleAudioEngine::sharedEngine()->playEffect("menuenter.wav");
    
    //SceneManager::goMoreApps();
    
    SceneManager::goGameHelp();
}

#pragma mark 添加其它视觉元素

//添加游戏标题

void StartGameScene::addGameTitle(){
    
    gameTitle=CCSprite::create("bg_gametitle-ipad.png");
    gameTitle->setPosition(titleLocation);
    this->addChild(gameTitle,0);
    
    CCLabelTTF *label = CCLabelTTF::create("竞答", "ChalkboardSE-Bold", 90);
    label->setPosition(titleLabelLocation);
    label->setColor(ccc3(16, 174, 231));
    
    this->addChild(label,0);
}

//添加背景图片
void StartGameScene::addBackground(){
    bg = CCSprite::create("bg_startscene-ipad.png");
    bg->setPosition(bgLocation);
    
    this->addChild(bg, -1);
}


#pragma mark 播放背景音乐

//添加背景音乐
void StartGameScene::playBackgroundMusic(){
    
    GameData *data = GameData::sharedData();
    
    if ( data->backgroundMusicMuted == false ) {
        SimpleAudioEngine::sharedEngine()->playBackgroundMusic("start.mp3", true);
    }
}

#pragma  mark 创建声音设置选项
void StartGameScene::createSoundSettingMenu(){
    if(GameData::sharedData()->soundEffectMuted ==false){
        
        this->createSoundMenuOn();
    }else {
        this->createSoundMenuOff();
    }
    
}

#pragma mark 设置音效开关选项

//创建音效开关选项

void StartGameScene::createSoundMenuOn(){
    
    this->removeChild(soundMenu, true);
            
    CCMenuItem *button = CCMenuItemImage::create("musicon-ipad.png", NULL, this, menu_selector(StartGameScene::turnSoundOff));
    
    soundMenu =CCMenu::create(button,NULL);
    soundMenu->setPosition(soundMenuLocation);
    
    this->addChild(soundMenu,10);
    
}
void StartGameScene::createSoundMenuOff(){
    
    this->removeChild(soundMenu, true);
    
    CCMenuItem *button = CCMenuItemImage::create("musicoff-ipad.png", NULL, this, menu_selector(StartGameScene::turnSoundOn));
    
    soundMenu =CCMenu::create(button,NULL);
    soundMenu->setPosition(soundMenuLocation);
    
    this->addChild(soundMenu,10);
    
}


void StartGameScene::turnSoundOn(){
    
    GameData *data = GameData::sharedData();
    data->backgroundMusicMuted = false;
    SimpleAudioEngine::sharedEngine()->resumeBackgroundMusic();
    
    this->createSoundMenuOn();
}

void StartGameScene::turnSoundOff(){
    
    GameData *data = GameData::sharedData();
    data->backgroundMusicMuted = true;
    SimpleAudioEngine::sharedEngine()->pauseBackgroundMusic();
    this->createSoundMenuOff();
    
}


#pragma mark 设置菜单的位置

void StartGameScene::setMenuLocation(){
    
    this->getScreenSize();
    aboutMenuLocation = ccp(screenSize.width*0.15,screenSize.height*0.25);
    
    moreMenuLocation =ccp(screenSize.width*0.65,screenSize.height*0.25);
    
    settingMenuLocation = ccp(screenSize.width*0.65,screenSize.height*0.25);
    
    startChallengeMenuLocation = ccp(screenSize.width*0.4,screenSize.height*0.25);
    
    endlessModeMenuLocation = ccp(screenSize.width*0.5,screenSize.height*0.8);
    
    titleLocation = ccp(screenSize.width*0.5,screenSize.height*0.7);
    titleLabelLocation = ccp(screenSize.width*0.55,screenSize.height*0.5);
    bgLocation = ccp(screenSize.width*0.5,screenSize.height*0.5);
    
    soundMenuLocation = ccp(screenSize.width*0.2,screenSize.height *0.5);
    
    
}



// on "init" you need to initialize your instance
bool StartGameScene::init()
{
    //////////////////////////////
    // 1. super init first
    if ( !CCLayer::init() )
    {
        return false;
    }
    
    //推送
    
    //      [self addPushNotification];
    
    
    //设置各视觉元素在屏幕中的位置
    CCLog("startgamescene-init:%d,%d,%d,%d",GameData::sharedData()->isLevel2Unlocked,GameData::sharedData()->isLevel3Unlocked,GameData::sharedData()->isLevel4Unlocked,GameData::sharedData()->isLevel5Unlocked);
    this->setMenuLocation();
    
    //添加游戏标题和背景
    
    this->addGameTitle();
    
    this->addBackground();
    //添加菜单选项
    
    
    
    this-> addGameMenu();
    
    
    //播放背景音乐
    this->playBackgroundMusic();
    
    //添加音效设置开关
    
    this->createSoundSettingMenu();
    
    return true;
}

