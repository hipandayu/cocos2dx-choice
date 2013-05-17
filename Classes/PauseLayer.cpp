

#include "PauseLayer.h"
#include "SceneManager.h"
#include "SimpleAudioEngine.h"
#include "GameData.h"
#include "Constants.h"

using namespace cocos2d;
using namespace CocosDenshion;

PauseLayer* PauseLayer::layerWithColor(ccColor4B color,ChallengeGameScene *_delegate)
{
    PauseLayer *pauselayer = new PauseLayer(color,_delegate);
    pauselayer->autorelease();
    return pauselayer;
}

PauseLayer::PauseLayer(ccColor4B color,ChallengeGameScene *_delegate){
    
    //CCLog("new");
    
    delegate = _delegate;
    
    this->pauseDelegate();
    this->createPausedMenu();
    
}

void PauseLayer::draw(){
    
    CCLog("draw123");
    
    //this->createPausedMenu();
}

//添加滚动背景
void PauseLayer::addScrollingBackground(){
    
    CCSize size = CCDirector::sharedDirector()->getWinSize();
    
    backgroundNode = CCParallaxNode::create();
    
    this->addChild(backgroundNode,-1);
    
    bg = CCSprite::create("bg_iphone-retina4.jpg");
    spacialanomaly = CCSprite::create("bg_spacialanomaly.png");
    
    
    CCPoint bgSpeed = ccp(0.05,0.05);
    backgroundNode->addChild(bg,-1,bgSpeed,ccp(300,size.height*0.5));
    
    backgroundNode->addChild(spacialanomaly,-1,bgSpeed,ccp(size.width/2,size.height*0.3));
    
}

void PauseLayer::update(CCTimer *dt){
    
    CCSize size = CCDirector::sharedDirector()->getWinSize();
    CCPoint backgroundScrollVel = ccp(-size.width,0);
    
    backgroundNode->setPosition(ccpAdd(backgroundNode->getPosition(), ccpMult(backgroundScrollVel,dt->getInterval())));
    CCArray *backgrounds = CCArray::create(bg,spacialanomaly,NULL);
    for(int i=0;i<backgrounds->count();i++){
        CCSprite *background =(CCSprite *) backgrounds->objectAtIndex(i);
        if (backgroundNode->convertToWorldSpace(background->getPosition()).x<-background->getContentSize().width) {
       // if([backgroundNode convertToWorldSpace:background.position].x <-background.contentSize.width) {
            backgroundNode->setPosition(size.width*1.7,0);
            //[backgroundNode incrementOffset:ccp(2000,0) forChild:background];
        }
    }
    
}

//创建暂停画面

void PauseLayer::createPausedMenu(){
    
    screenSize = CCDirector::sharedDirector()->getWinSize();
    
    CCLog("createPausedMenu");
    
    pauseBg = CCSprite::create("rollbg-ipad.png");
    //  pauseBg.opacity = 50;
    
    
    //创建文字2
    pauseText2 = CCLabelTTF::create("暂停","Arial-BoldMT",50);
    
    // 创建选择按钮
    item2 =CCMenuItemSprite::create(CCSprite::create("button_backtolevelselection-ipad.png"), NULL,this, menu_selector(PauseLayer::backButtonPressed));
    
    // 创建继续按钮
    item3 =CCMenuItemSprite::create(CCSprite::create("button_continue-ipad.png"), NULL, this, menu_selector(PauseLayer::resumeButtonPressed));
   
    // put all those three buttons on the menu
    pausedMenu = CCMenu::create(item2, item3, NULL);
    
    pausedMenu->setPosition(ccp(0,0));
    
    item2->setPosition(ccp(screenSize.width/2,screenSize.height*0.5));
    item3->setPosition(ccp(screenSize.width/2,screenSize.height*0.3));
    
    pauseBg->setPosition(ccp(screenSize.width/2,screenSize.height/2));
    
    pauseText2->setPosition(ccp(screenSize.width*0.5,screenSize.height*0.74));
    
    
    // add the Paused sprite and menu to the current layer
    this->addChild(pauseBg,0);
    this->addChild(pausedMenu,100);
    this->addChild(pauseText2,10);
}

void PauseLayer::storeButtonPressed(){
    item1->runAction(CCRotateBy::create(0.5,0));
    
    this->runAction(CCSequence::create(CCDelayTime::create(0.1),CCCallFunc::create(this, callfunc_selector(PauseLayer::goStore)),NULL));
    
}
void PauseLayer::backButtonPressed(){
    
    item2->runAction(CCRotateBy::create(0.5,0));
    this->runAction(CCSequence::create(CCDelayTime::create(0.1),CCCallFunc::create(this, callfunc_selector(PauseLayer::goLevelSelection)),NULL));
    
}

void PauseLayer::resumeButtonPressed(){
    
    item3->runAction(CCRotateBy::create(0.5,0));
    
    this->runAction(CCSequence::create(CCDelayTime::create(0.1),CCCallFunc::create(this, callfunc_selector(PauseLayer::doResume)),NULL));
}

void PauseLayer::resetDatabase(){
    
    //重置问题总数
    GameData::sharedData()->numberOfUnusedQuestions = TotalNumberOfQuestionInDatabase;
}

void PauseLayer::goLevelSelection(){
    
    CCLog("goLevelSelection");
    
    SimpleAudioEngine::sharedEngine()->stopBackgroundMusic();
    this->resetDatabase();
    SceneManager::goChallengeLevelSelect();
}

void PauseLayer::goStore(){
    SceneManager::goGameStore();
}


void PauseLayer::pauseDelegate(){

    
    //if([delegate respondsToSelector:@selector(pauseLayerDidPause)])
        
    //delegate->pauseLayerDidPause();
    
    delegate->onExit();
    delegate->getParent()->addChild(this,30);
    
}

void PauseLayer::doResume(CCNode* sender)
{
    
    delegate->onEnter();
    CCLog("doResume");
    //if([delegate respondsToSelector:@selector(pauseLayerDidUnpause)])
    
    //delegate->pauseLayerDidUnpause();
    delegate->getParent()->removeChild(this,true);
}

//PauseLayerProtocol
void PauseLayerProtocol::pauseLayerDidPause(){
    
}

void PauseLayerProtocol::pauseLayerDidUnpause(){
    
}
