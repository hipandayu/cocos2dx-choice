#ifndef __CHALLENGELEVELRESULT_SCENE_H__
#define __CHALLENGELEVELRESULT_SCENE_H__

#include "cocos2d.h"
using namespace cocos2d;

class ChallengeLevelResult : public cocos2d::CCLayer
{
public:
    // Here's a difference. Method 'init' in cocos2d-x returns bool, instead of returning 'id' in cocos2d-iphone
    virtual bool init();  

    // there's no 'id' in cpp, so we recommend returning the class instance pointer
    static cocos2d::CCScene* scene();
    
   
   	//scrolling background
    
    CCParallaxNode *backgroundNode;
    
    CCSprite *bg;
    
    CCSprite *spacialanomaly;
    
    //当前关卡是否成功通过
    bool levelClear;
    
    //当前关卡的编号
    int levelNumber;
    
    //当前关卡所属的场景
    int chapterNumber;
    
    //当前场景已通过的关卡数量
    int levelSolvedOfThisChapter;
    
    //当前关卡答对的题目总数
    
    int numberOfWrongAnswers;
    
    //当前关卡的得分
    int scoreOfCurrentLevel;
    
    //当前关卡的评价
    int levelStars;
    
    //背景精灵图片
    CCSprite *sceneBg;
    CCSprite *resultBg;
    
    //屏幕大小
    CCSize screenSize;
    
    //菜单选项
    CCMenu *resultMenu;
    
    
    //位置
    CCPoint resultLabelLocation;
    CCPoint starsLocation;
    CCPoint resultTextLocation;
    CCPoint resultBgLocation;
    CCPoint resultMenuLocation;
    
    
    //menu items
    CCMenuItem *item1;
    CCMenuItem *item2;
    CCMenuItem *item3;
    CCMenuItem *item4;


    void setMenuLocation();
    void readData();
    void unlockNextLevel();
    void addSceneBg();
    void addResultBg();
    void addLevelTitle();
    void addResult();
    void stopBackgroundMusic();
    void item1Pressed();
    void shareToSocialNetwork();
    void item2Pressed();
    void item3Pressed();
    void item4Pressed();
    void backToLevelSelection();
    void replayCurrentLevel();
    void playNextLevel();
    void addMenuItems();
    void playBgMusic();
    void resetDatabase();
    // implement the "static node()" method manually
    CREATE_FUNC(ChallengeLevelResult);
};

#endif // __CHALLENGELEVELRESULT_SCENE_H__
