#ifndef __MOREAPPS_SCENE_H__
#define __MOREAPPS_SCENE_H__

#include "cocos2d.h"
using namespace cocos2d;
class MoreApps : public cocos2d::CCLayer
{
public:
    // Here's a difference. Method 'init' in cocos2d-x returns bool, instead of returning 'id' in cocos2d-iphone
    virtual bool init();  

    // there's no 'id' in cpp, so we recommend returning the class instance pointer
    static cocos2d::CCScene* scene();
    
    double curTime;
    double nextTime;
    
    cocos2d::CCPoint iconForSoundToysPosition;
    CCPoint backMenuLocation;
    
    CCMenuItemImage* backButton;
    
    CCSprite *bg;


    //函数
    void setMenuLocation();
    void backButtonPressed();
    void addBackItem();
    void addBg();
    void addTextLabel();
    void addMailToUs();
    void addMenuBackground();
    void addIconsForOtherApps();
    void backToStart();
    void mailToMe();
    void goAppStore(CCNode* sender);
    void playBackgroundMusic();
    // implement the "static node()" method manually
    CREATE_FUNC(MoreApps);
};

#endif // __MOREAPPS_SCENE_H__
