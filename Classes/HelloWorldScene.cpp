#include "StartGameScene.h"
#include "HelloWorldScene.h"
#include "SimpleAudioEngine.h"

using namespace cocos2d;
using namespace CocosDenshion;

CCScene* HelloWorld::scene()
{
    // 'scene' is an autorelease objec
    CCScene *scene = CCScene::create();
    
    // 'layer' is an autorelease object
    HelloWorld *layer = HelloWorld::create();

    // add layer as a child to scene
    scene->addChild(layer);

    // return the scene
    return scene;
}

// on "init" you need to initialize your instance
bool HelloWorld::init()
{
    //////////////////////////////
    // 1. super init first
    if ( !CCLayer::init() )
    {
        return false;
    }

    CCSize size=CCDirector::sharedDirector()->getWinSize();
    CCSprite *background;
    
    //TargetPlatform target=getTargetPlatform();
    
    //if (target==kTargetIpad) {
        background=CCSprite::create("Default-Landscape-ipad.png");
    /*}else{
        background=CCSprite::create("Default.png");
        background->setRotation(90);
    }*/
    background->setPosition(ccp(size.width/2, size.height/2));
    this->addChild(background);
    
    return true;
}

void HelloWorld::menuCloseCallback(CCObject* pSender)
{
    CCDirector::sharedDirector()->end();

#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
    exit(0);
#endif
}
void HelloWorld::onEnter(){  
    CCLayer::onEnter();
    CCDirector::sharedDirector()->replaceScene(CCTransitionFade::create(1.0f,StartGameScene::scene()));
}

