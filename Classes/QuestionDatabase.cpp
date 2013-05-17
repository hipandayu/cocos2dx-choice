

#include "QuestionDatabase.h"
#include "QuestionDetails.h"
#include "CCFileUtils.h"


static QuestionDatabase *myDatabase;

QuestionDatabase* QuestionDatabase::database(){
  if (myDatabase == NULL) {
    myDatabase = new QuestionDatabase();
  }
  return myDatabase;
}


QuestionDatabase::QuestionDatabase(){
    const char *sqLiteDb =CCFileUtils::sharedFileUtils()->fullPathFromRelativeFile("question.sqlite3",CCFileUtils::sharedFileUtils()->getResourceDirectory());

    if (sqlite3_open(sqLiteDb, &_database) != SQLITE_OK) {
        CCLog("Failed to open database!");
    }
}

QuestionDatabase::~QuestionDatabase(){
    sqlite3_finalize(statement);
    sqlite3_close(_database);
}

CCArray* QuestionDatabase::quizQuestionDetails(){
    
    CCArray *retval = CCArray::create();
    retval->autorelease();
    CCString *query = CCString::create("SELECT id, type, title, correctanswer, answer2,answer3 FROM questionlist ORDER BY id");
    sqlite3_stmt *statement;
    if (sqlite3_prepare_v2(_database,query->getCString(), -1, &statement, NULL) == SQLITE_OK) {
        while (sqlite3_step(statement) == SQLITE_ROW) {
            int uniqueId = sqlite3_column_int(statement, 0);
            char *type =(char *) sqlite3_column_text(statement, 1);
            char *titleChars = (char *) sqlite3_column_text(statement, 2);
            char *correctAnswerChars = (char *) sqlite3_column_text(statement, 3);
            char *answer2Chars = (char *) sqlite3_column_text(statement, 4);
            char *answer3Chars = (char *) sqlite3_column_text(statement, 5);
            
            
            CCString *title = CCString::create(titleChars);
            CCString *correctAnswer = CCString::create(correctAnswerChars);
            CCString *answer2 = CCString::create(answer2Chars);
            CCString *answer3 = CCString::create(answer3Chars);
            
            
            
            QuestionDetails *details = new QuestionDetails(uniqueId,type,titleChars,correctAnswerChars,answer2Chars,answer3Chars);
            details->autorelease();
            retval->addObject(details);
            title->release();
            correctAnswer->release();
            answer2->release();
            answer3->release();
            details->release();
        }
        sqlite3_finalize(statement);
    }
    return retval;

}

QuestionDetails* QuestionDatabase::questionDetails(int uniqueId){
    QuestionDetails *retval = NULL;
  CCString *query = CCString::createWithFormat("SELECT id, type, title, correctanswer, answer2,answer3 FROM questionlist WHERE id=%d", uniqueId);
  
  if (sqlite3_prepare_v2(_database,query->getCString(), -1, &statement, NULL) == SQLITE_OK) {
      
    while (sqlite3_step(statement) == SQLITE_ROW) {
       
        int uniqueId = sqlite3_column_int(statement, 0);
        
        char *typeChars = (char *)sqlite3_column_text(statement, 1);
        char *titleChars = (char *) sqlite3_column_text(statement, 2);
        char *correctAnswerChars = (char *) sqlite3_column_text(statement, 3);
        char *answer2Chars = (char *) sqlite3_column_text(statement, 4);
        char *answer3Chars = (char *) sqlite3_column_text(statement, 5);
        
        
        /*CCString *type = CCString::create(typeChars);
        CCString *title = CCString::create(titleChars);
        CCString *correctAnswer = CCString::create(correctAnswerChars);
        CCString *answer2 = CCString::create(answer2Chars);
        CCString *answer3 = CCString::create(answer3Chars);
        
        //retval->autorelease();
        type->release();
        title->release();
        correctAnswer->release();
        answer2->release();
        answer3->release();*/
        
        retval = new QuestionDetails(uniqueId,typeChars,titleChars,correctAnswerChars,answer2Chars,answer3Chars);
        //CCLog("string:%d,%s,%s,%s",uniqueId,type->getCString(),titleChars,correctAnswer->getCString());
        break;
    }
    
  }
  return retval;
}