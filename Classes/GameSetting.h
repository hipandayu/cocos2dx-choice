#ifndef __GAMESETTING_SCENE_H__
#define __GAMESETTING_SCENE_H__

#include "cocos2d.h"

using namespace cocos2d;
class GameSetting : public cocos2d::CCLayer
{
public:
    // Here's a difference. Method 'init' in cocos2d-x returns bool, instead of returning 'id' in cocos2d-iphone
    virtual bool init();  

    // there's no 'id' in cpp, so we recommend returning the class instance pointer
    static cocos2d::CCScene* scene();
    
    CCMenuItem *backButton;

    void addBackButton();
    void addBg();
    void backToStartScene();
    void playBackgroundMusic();
    // implement the "static node()" method manually
    CREATE_FUNC(GameSetting);
};

#endif // __GAMESETTING_SCENE_H__
