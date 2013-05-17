#ifndef __PauseLayer_SCENE_H__
#define __PauseLayer_SCENE_H__

#include "cocos2d.h"
#import "ChallengeGameScene.h"

using namespace cocos2d;
class PauseLayerProtocol : public cocos2d::CCNode
{
public:
    void pauseLayerDidPause();
    
    void pauseLayerDidUnpause();
};

class PauseLayer : public cocos2d::CCLayerColor
{
public:
    // Method 'init' in cocos2d-x returns bool, instead of 'id' in cocos2d-iphone (an object pointer)
    //virtual bool init();
    
        
    static PauseLayer* layerWithColor(ccColor4B color, ChallengeGameScene *_delegate);
    void draw();
    PauseLayer(ccColor4B color,ChallengeGameScene *_delegate);
    void pauseDelegate();
    void addScrollingBackground();
    void update(CCTimer *dt);
    void createPausedMenu();
    void storeButtonPressed();
    void backButtonPressed();
    void resumeButtonPressed();
    void resetDatabase();
    void goLevelSelection();
    void goStore();
    void doResume(CCNode* sender);
    
    ChallengeGameScene * delegate;
    
    CCSize screenSize;
    
    CCMenu *pausedMenu;
    
    CCSprite *pauseBg;
    
    CCMenu *pauseButtonMenu;
    
    CCMenu  *pauseButtonMenuText;
    
    CCLabelTTF *pauseText1;
    CCLabelTTF *pauseText2;
    
    CCMenuItemSprite *item1 ;
    CCMenuItemSprite *item2;
    CCMenuItemSprite *item3;
    
    //scrolling background
    
    CCParallaxNode *backgroundNode;
    
    CCSprite *bg;
    
    CCSprite *spacialanomaly;
    
    CCPoint pauseButtonLocation;
    
    //CREATE_FUNC(PauseLayer);
};

#endif // __PauseLayer_SCENE_H__
