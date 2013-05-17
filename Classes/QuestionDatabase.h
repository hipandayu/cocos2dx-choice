#ifndef __QUESTIONDATABASE_SCENE_H__
#define __QUESTIONDATABASE_SCENE_H__

#include "cocos2d.h"
#include "sqlite3.h"
#include "QuestionDatabase.h"
#include "QuestionDetails.h"

using namespace cocos2d;

class QuestionDatabase : public cocos2d::CCObject
{
public:
    sqlite3 *_database;
    sqlite3_stmt *statement;
    
    QuestionDatabase();
    ~QuestionDatabase();

    QuestionDetails* questionDetails(int uniqueId);
    
    static QuestionDatabase* database();
    
    CCArray* quizQuestionDetails();
    CCArray* questionDetailsArr(int uniqueId);
    
};

#endif // __QUESTIONDATABASE_SCENE_H__
