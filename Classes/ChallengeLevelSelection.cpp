
#include "ChallengeLevelSelection.h"
#include "SceneManager.h"
#include "GameData.h"
#include "SimpleAudioEngine.h"
#include "Constants.h"

using namespace cocos2d;
using namespace CocosDenshion;


CCScene* ChallengeLevelSelection::scene()
{
    // 'scene' is an autorelease object
    CCScene *scene = CCScene::create();
    
    // 'layer' is an autorelease object
    ChallengeLevelSelection *layer = ChallengeLevelSelection::create();

    // add layer as a child to scene
    scene->addChild(layer);

    // return the scene
    return scene;
}

//添加背景图片
void ChallengeLevelSelection::addBg(){

    CCSize size=CCDirector::sharedDirector()->getWinSize();

    bg = CCSprite::create("bg_common-ipad.png");
    bg->setPosition(ccp(size.width/2,size.height/2));
    
    this->addChild(bg,-1);
    
}

//button pressed
void ChallengeLevelSelection::backButtonPressed(){

    backButton->runAction(CCRotateBy::create(0.5,360));
    this->runAction(CCSequence::create(CCDelayTime::create(0.5),CCCallFunc::create(this, callfunc_selector(ChallengeLevelSelection::backToStartScene)),NULL));

}

//返回游戏开始界面
void ChallengeLevelSelection::backToStartScene(){
    
    //播放音效
    SimpleAudioEngine::sharedEngine()->playEffect("menuenter.wav");
    
    SceneManager::goStartGame();
    
}

//添加返回按钮
void ChallengeLevelSelection::addBackButton(){

    CCSize size=CCDirector::sharedDirector()->getWinSize();
    backButton = CCMenuItemImage::create("button_back-ipad.png",NULL,this,menu_selector(ChallengeLevelSelection::backButtonPressed));
    backButton->setPosition(ccp(size.width*0.85,size.height*0.85));
    CCMenu *menu = CCMenu::create(backButton,NULL);
    menu->setPosition(ccp(0,0));
    this->addChild(menu);
}

//背景音乐

//添加背景音乐
void ChallengeLevelSelection::playBackgroundMusic(){
    
    
    GameData *data =GameData::sharedData();
    if ( data->backgroundMusicMuted == false ) {
        
        if(SimpleAudioEngine::sharedEngine()->isBackgroundMusicPlaying() == false)
        {
            SimpleAudioEngine::sharedEngine()->playBackgroundMusic("start.mp3",true);       
        }
        
    }
}

//设置视觉元素位置
void ChallengeLevelSelection::setMenuLocation(){
    CCSize size=CCDirector::sharedDirector()->getWinSize();
    newbieMenuItemPosition = ccp(size.width*0.25,size.height*0.5);
    coderMenuItemPosition = ccp(size.width*0.5,size.height*0.5);
    hackerMenuItemPosition = ccp(size.width*0.75,size.height*0.5);
    masterMenuItemPosition = ccp(size.width*0.25,size.height*0.3);
    monsterMenuItemPosition = ccp(size.width*0.5,size.height*0.3);

}


void ChallengeLevelSelection::addLevelSelectionMenu(){
    
    CCLog("addLevelSelectionMenu:%d,%d,%d,%d",GameData::sharedData()->isLevel2Unlocked,GameData::sharedData()->isLevel3Unlocked,GameData::sharedData()->isLevel4Unlocked,GameData::sharedData()->isLevel5Unlocked);
    
    newbieMenuItem = CCMenuItemImage::create("button_newbie-ipad.png",NULL,this,menu_selector(ChallengeLevelSelection::enterChallengeGameScene));
    
    if(GameData::sharedData()->isLevel2Unlocked == true){
        
        coderMenuItem = CCMenuItemImage::create("button_coder-ipad.png",NULL,this,menu_selector(ChallengeLevelSelection::enterChallengeGameScene));
        
    }else if(GameData::sharedData()->isLevel2Unlocked == false){
        
        coderMenuItem = CCMenuItemImage::create("button_locked-ipad.png",NULL,this,menu_selector(ChallengeLevelSelection::alertPopUp));
        
    }
    if(GameData::sharedData()->isLevel3Unlocked == true){
                
        hackerMenuItem = CCMenuItemImage::create("button_hacker-ipad.png",NULL,this,menu_selector(ChallengeLevelSelection::enterChallengeGameScene));
        
    }else if(GameData::sharedData()->isLevel3Unlocked == false){
        
        hackerMenuItem = CCMenuItemImage::create("button_locked-ipad.png",NULL,this,menu_selector(ChallengeLevelSelection::alertPopUp));
        
    }
    if(GameData::sharedData()->isLevel4Unlocked == true){
        
        masterMenuItem = CCMenuItemImage::create("button_master-ipad.png",NULL,this,menu_selector(ChallengeLevelSelection::enterChallengeGameScene));
        
    }else if(GameData::sharedData()->isLevel4Unlocked == false){
        
        masterMenuItem = CCMenuItemImage::create("button_locked-ipad.png",NULL,this,menu_selector(ChallengeLevelSelection::alertPopUp));
        
    }
    
    if(GameData::sharedData()->isLevel5Unlocked == true){
        monsterMenuItem = CCMenuItemImage::create("button_monster-ipad.png",NULL,this,menu_selector(ChallengeLevelSelection::enterChallengeGameScene));
        
    }else if(GameData::sharedData()->isLevel5Unlocked == false){
        monsterMenuItem = CCMenuItemImage::create("button_locked-ipad.png",NULL,this,menu_selector(ChallengeLevelSelection::alertPopUp));
        
    }

    
    newbieMenuItem->setPosition(newbieMenuItemPosition);
    coderMenuItem->setPosition(coderMenuItemPosition);
    hackerMenuItem->setPosition(hackerMenuItemPosition);
    masterMenuItem->setPosition(masterMenuItemPosition);
    monsterMenuItem->setPosition(monsterMenuItemPosition);
    

    newbieMenuItem->setTag(kTagLevelNewbie);
    coderMenuItem->setTag(kTagLevelCoder);
    hackerMenuItem->setTag(kTagLevelHacker);
  
    masterMenuItem->setTag(kTagLevelMaster);
    monsterMenuItem->setTag(kTagLevelMonster);
    
    
    levelMenu = CCMenu::create(newbieMenuItem,coderMenuItem,hackerMenuItem,masterMenuItem,monsterMenuItem, NULL);
    levelMenu->setPosition(CCPointZero);
  
    this->addChild(levelMenu,0);
    
}

void ChallengeLevelSelection::alertPopUp(){
    CCSize size=CCDirector::sharedDirector()->getWinSize();
    wrong_tips = CCLabelTTF::create("该关未解锁，请先完成上一关卡","ChalkboardSE-Bold",50.0);
    wrong_tips->setPosition(ccp(size.width/2,size.height/2));
    wrong_tips->setColor(ccc3(255,0,0));

    this->addChild(wrong_tips,11);
    
    this->runAction(CCSequence::create(CCDelayTime::create(2),CCCallFunc::create(this, callfunc_selector(ChallengeLevelSelection::removeAlertPopUp)),NULL));
}
void ChallengeLevelSelection::removeAlertPopUp(){
    this->removeChild(wrong_tips, true);
}
void ChallengeLevelSelection::enterChallengeGameScene(CCNode* sender){
    
    CCMenuItem *item = (CCMenuItem*)sender;
    int selectedItem = item->getTag();
    CCLog("%d",selectedItem);
    switch (selectedItem) {
        case kTagLevelNewbie:
            GameData::sharedData()->selectedLevel = 1;
            break;
        case kTagLevelCoder:
            GameData::sharedData()->selectedLevel = 2;
            break;
        case kTagLevelHacker:
            GameData::sharedData()->selectedLevel = 3;
            break;
        case kTagLevelMaster:
            GameData::sharedData()->selectedLevel = 4;
            break;
        case kTagLevelMonster:
            GameData::sharedData()->selectedLevel = 5;
            break;
        default:
            break;
    }
    SceneManager::goChallengeGameScene();
}


//场景初始化
bool ChallengeLevelSelection::init()
{
    //////////////////////////////
    // 1. super init first
    if ( !CCLayer::init() )
    {
        return false;
    }
    this->setMenuLocation();
    this->addBackButton();
    this->addBg();
    this->playBackgroundMusic();
    this->addLevelSelectionMenu();
    return true;
}


