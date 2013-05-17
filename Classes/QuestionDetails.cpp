


#include "QuestionDetails.h"


 QuestionDetails::QuestionDetails(int uniqueId,const char* type,const char* title,const char* correctAnswer,const char* possibleAnswer2,const char* possibleAnswer3){
    // CCLog("construct:%d,%s,%s,%s",uniqueId,type,title,correctAnswer);
    _uniqueId = uniqueId;
    _type = type;
    _title = title;
    _correctAnswer = correctAnswer;
    _possibleAnswer2 = possibleAnswer2;
    _possibleAnswer3 = possibleAnswer3;

}


QuestionDetails::~QuestionDetails(){
  _title = NULL;
  _correctAnswer = NULL;
  _possibleAnswer3 = NULL;
  _possibleAnswer2 = NULL;
  
}

int QuestionDetails::getuniqueId(){
    return _uniqueId;
}

void QuestionDetails::setuniqueId(int uniqueId){
    _uniqueId=uniqueId;
}


const char* QuestionDetails::gettype(){
    return _type;
}

void QuestionDetails::settype(const char* var){
    _type =var;
}

const char* QuestionDetails::gettitle(){
    return _title;
}
void QuestionDetails::settitle(const char *var){
    _title =var;
}


void QuestionDetails::setcorrectAnswer(const char *var){
    _correctAnswer =var;
}

const char* QuestionDetails::getcorrectAnswer(){
    return _correctAnswer;
}

void QuestionDetails::setpossibleAnswer2(const char *var){
    _possibleAnswer2 =var;
}

const char* QuestionDetails::getpossibleAnswer2(){
    return _possibleAnswer2;
}
void QuestionDetails::setpossibleAnswer3(const char *var){
    _possibleAnswer3 =var;
}


const char* QuestionDetails::getpossibleAnswer3(){
    return _possibleAnswer3;
}

