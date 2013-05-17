#include "GameSetting.h"
#include "SceneManager.h"
#include "GameData.h"
#include "SimpleAudioEngine.h"

using namespace cocos2d;
using namespace CocosDenshion;

CCScene* GameSetting::scene()
{
    // 'scene' is an autorelease object
    CCScene *scene = CCScene::create();
    
    // 'layer' is an autorelease object
    GameSetting *layer = GameSetting::create();

    // add layer as a child to scene
    scene->addChild(layer);

    // return the scene
    return scene;
}

void GameSetting::addBackButton(){


    CCSize size=CCDirector::sharedDirector()->getWinSize();
    
    backButton = CCMenuItemImage::create("button_back-ipad.png",NULL,this,menu_selector(GameSetting::backToStartScene));

    backButton->setPosition(ccp(size.width*0.85,size.height*0.85));
    
    CCMenu *menu = CCMenu::create(backButton,NULL);
    menu->setPosition(ccp(0,0));
    this->addChild(menu);
    
}

void GameSetting::backToStartScene(){
    
    SceneManager::goStartGame();
}


//添加背景图片
void GameSetting::addBg(){
    
    CCSize size=CCDirector::sharedDirector()->getWinSize();

    CCSprite *bg = CCSprite::create("bg_common-ipad.png");
    bg->setPosition(ccp(size.width/2,size.height/2));
    
    this->addChild(bg,-1);
}
//背景音乐

//添加背景音乐
void GameSetting::playBackgroundMusic(){
    
    SimpleAudioEngine::sharedEngine()->playBackgroundMusic("about.mp3",true);
    
}

// on "init" you need to initialize your instance
bool GameSetting::init()
{
    //////////////////////////////
    // 1. super init first
    if ( !CCLayer::init() )
    {
        return false;
    }
    
    this->addBackButton();
    this->playBackgroundMusic();
    this->addBg();    
    
    return true;
}


