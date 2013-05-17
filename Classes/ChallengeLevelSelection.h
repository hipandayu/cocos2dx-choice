#ifndef __ChallengeLevelSelection_SCENE_H__
#define __ChallengeLevelSelection_SCENE_H__

#include "cocos2d.h"
using namespace cocos2d;

class ChallengeLevelSelection : public cocos2d::CCLayer
{
public:
    // Here's a difference. Method 'init' in cocos2d-x returns bool, instead of returning 'id' in cocos2d-iphone
    virtual bool init();  

    // there's no 'id' in cpp, so we recommend returning the class instance pointer
    static cocos2d::CCScene* scene();
    
    //bg
    CCSprite *bg;
    
    //back button
    CCMenuItem *backButton;
    
    //menu items
    CCMenuItem *newbieMenuItem;
    CCMenuItem *coderMenuItem;
    CCMenuItem *hackerMenuItem;
    CCMenuItem *masterMenuItem;
    CCMenuItem *monsterMenuItem;
    
    //menu item position
    CCPoint newbieMenuItemPosition;
    CCPoint coderMenuItemPosition;
    CCPoint hackerMenuItemPosition;
    CCPoint masterMenuItemPosition;
    CCPoint monsterMenuItemPosition;
    
    CCMenu *levelMenu;
    CCLabelTTF *wrong_tips;

    void addBg();
    void backButtonPressed();
    void addBackButton();
    void setMenuLocation();
    void addLevelSelectionMenu();
    void backToStartScene();
    void enterChallengeGameScene(CCNode* sender);
    void playBackgroundMusic();
    void alertPopUp();
    void removeAlertPopUp();
    // implement the "static node()" method manually
    CREATE_FUNC(ChallengeLevelSelection);
};

#endif // __ChallengeLevelSelection_SCENE_H__
