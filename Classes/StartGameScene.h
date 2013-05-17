#ifndef __STARTGAMESCENE_SCENE_H__
#define __STARTGAMESCENE_SCENE_H__

#include "cocos2d.h"

class StartGameScene : public cocos2d::CCLayer
{
public:
    virtual bool init();
    
    static cocos2d::CCScene* scene();
    
    /*变量*/
    //背景
    
    
    cocos2d::CCSprite *bg;
    
    
    //游戏标题
    cocos2d::CCSprite *gameTitle;
    
    //屏幕大小
    cocos2d::CCSize screenSize;
    
    //按钮
    
    cocos2d::CCMenuItem *startChallengeItem;
    cocos2d::CCMenuItem *endlessModeItem;
    cocos2d::CCMenuItem *aboutItem;
    
    cocos2d::CCMenuItem *settingItem;
    cocos2d::CCMenuItem *moreItem;
    cocos2d::CCMenuItem *storeItem;
    //音效设置
    
    cocos2d::CCMenu* soundMenu;
    
    
    //位置信息
    
    cocos2d::CCPoint soundMenuLocation;
    
    
    
    //位置信息
    
    
    cocos2d::CCPoint aboutMenuLocation;
    cocos2d::CCPoint moreMenuLocation;
    cocos2d::CCPoint settingMenuLocation;
    cocos2d::CCPoint startChallengeMenuLocation;
    cocos2d::CCPoint endlessModeMenuLocation;
    
    
    cocos2d::CCPoint storeMenuLocation;
    
    cocos2d::CCPoint titleLocation;
    cocos2d::CCPoint titleLabelLocation;
    cocos2d::CCPoint bgLocation;
    
    CREATE_FUNC(StartGameScene);
    
private:
    void getScreenSize();
    void addStartChallengeMenuItem();
    void addAboutItem();
    void addSettingItem();
    void addMoreItem();
    void addGameMenu();
    void startChallenge();
    void about();
    void addGameTitle();
    void addBackground();
    void enterGameSetting();
    void createSoundMenuOn();
    void createSoundMenuOff();
    void turnSoundOn();
    void turnSoundOff();
    void setMenuLocation();
    void playBackgroundMusic();
    void createSoundSettingMenu();
    void enterMoreGames();
    
};

#endif // __STARTGAMESCENE_SCENE_H__
