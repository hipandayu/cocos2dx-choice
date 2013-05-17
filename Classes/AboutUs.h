#ifndef __ABOUTUS_SCENE_H__
#define __ABOUTUS_SCENE_H__

#include "cocos2d.h"


class AboutUs : public cocos2d::CCLayer
{
public:
    // Method 'init' in cocos2d-x returns bool, instead of 'id' in cocos2d-iphone (an object pointer)
    virtual bool init();
    
    double curTime;
    double nextTime;
    
    cocos2d::CCPoint backMenuLocation;
    
    cocos2d::CCMenuItemImage* backButton;
    
    cocos2d::CCSprite *bg;
    
    // there's no 'id' in cpp, so we recommend to return the class instance pointer
    static cocos2d::CCScene* scene();
    
    //返回游戏开始界面
    void backToStart();
    
    //添加返回按钮
    void addBackItem();
    
    //添加背景图片
    void addBg();
    
    
    //添加文字标签
    void addTextLabel();
    
    void backButtonPressed();
    
    //给作者写邮件
    void mailToMe();
    void setMenuLocation();
    void addMenuBackground();
    void updateMusic();
    void playBackgroundMusic();
    // preprocessor macro for "static create()" constructor ( node() deprecated )
    CREATE_FUNC(AboutUs);
};

#endif // __ABOUTUS_SCENE_H__
