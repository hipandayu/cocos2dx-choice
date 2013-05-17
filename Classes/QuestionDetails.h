#ifndef __QUESTIONDETAILS_SCENE_H__
#define __QUESTIONDETAILS_SCENE_H__

#include "cocos2d.h"
using namespace cocos2d;
class QuestionDetails : public cocos2d::CCObject
{
public:
    virtual ~QuestionDetails();
    
    QuestionDetails(int uniqueId,const char* type,const char* title,const char* correctAnswer,const char* possibleAnswer2,const char* possibleAnswer3);
    
    
    CC_PROPERTY(int, _uniqueId, uniqueId);
    CC_PROPERTY(const char*, _type, type);
    CC_PROPERTY(const char*, _title, title);
    CC_PROPERTY(const char*, _correctAnswer, correctAnswer);
    CC_PROPERTY(const char*, _possibleAnswer2, possibleAnswer2);
    CC_PROPERTY(const char*, _possibleAnswer3, possibleAnswer3);
    /*
    int _uniqueId;
    int _type;
    CCString *_title;
    CCString *_correctAnswer;
    CCString *_possibleAnswer2;
    CCString *_possibleAnswer3;*/
    //CCObject* initWithUniqueId(int uniqueId,int type,CCString* title,CCString* correctAnswer,CCString* possibleAnswer2,CCString* possibleAnswer3);
    //CREATE_FUNC(QuestionDetails);
};

#endif // __QUESTIONDETAILS_SCENE_H__
