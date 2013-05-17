#ifndef __GAMEHELP_SCENE_H__
#define __GAMEHELP_SCENE_H__

#include "cocos2d.h"

class GameHelp : public cocos2d::CCLayer
{
public:
    // Here's a difference. Method 'init' in cocos2d-x returns bool, instead of returning 'id' in cocos2d-iphone
    virtual bool init();  

    // there's no 'id' in cpp, so we recommend returning the class instance pointer
    static cocos2d::CCScene* scene();
    
    double curTime;
    double nextTime;
    cocos2d::CCPoint backMenuLocation;    
    cocos2d::CCMenuItemImage* backButton;    
    cocos2d::CCSprite *bg;

    //函数
    void setMenuLocation();
    void backButtonPressed();
    void addBackItem();
    void addHelpBg();
    void addTextLabel();
    void addMailToUs();
    void addMenuBackground();
    void backToStart();
    void mailToMe();
    void updateMusic();
    void playBackgroundMusic();
    // implement the "static node()" method manually
    CREATE_FUNC(GameHelp);
};

#endif // __GAMEHELP_SCENE_H__
