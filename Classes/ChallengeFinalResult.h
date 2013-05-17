#ifndef __CHALLENGEFINALRESULT_SCENE_H__
#define __CHALLENGEFINALRESULT_SCENE_H__

#include "cocos2d.h"
using namespace cocos2d;
class ChallengeFinalResult : public cocos2d::CCLayer
{
public:
    // Here's a difference. Method 'init' in cocos2d-x returns bool, instead of returning 'id' in cocos2d-iphone
    virtual bool init();  
    // there's no 'id' in cpp, so we recommend returning the class instance pointer
    static cocos2d::CCScene* scene();
    //背景精灵图片
    CCSprite *sceneBg;
    CCSprite *resultBg;
    
    //文本标签
    CCLabelTTF *textLabel;
    
    //屏幕大小
    CCSize screenSize;


    void addSceneBg();
    void addResultBg();
    void stopBackgroundMusic();
    void addText();
    void goStartGame();
    void addBackButton();
    void backButtonPressed();
    void playBgMusic();
    void resetDatabase();
    // implement the "static node()" method manually
    CREATE_FUNC(ChallengeFinalResult);
};

#endif // __CHALLENGEFINALRESULT_SCENE_H__
