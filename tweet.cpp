#include "tweet.h"

//default constructor for tweet class
tweet::tweet(){
      rowNum = 0;
      IDNum = 0;
      positivity = 0;
      username = " ";
      text = " ";

}

//constructor for tweet class
tweet::tweet(int myRowNum,long myIDNum, DSString myusername, DSString mytext){
    rowNum = myRowNum;
    IDNum = myIDNum;
    username = myusername;
    text = mytext;
    positivity = 0;

}

//return the rownumber of the tweet
int tweet :: getrowNum(){
    return rowNum;
}

//set rownumber of the tweet
void tweet :: setrowNum(int myRowNum){
    rowNum = myRowNum;
}

//get the IDNumber of the tweet
long tweet :: getIDNum(){
    return IDNum;
}

//set the IDNumber of the tweet
void tweet :: setIDNum(long myIDNum){
    IDNum = myIDNum;
}

//get the username of the tweet
DSString tweet :: getusername(){
    return username;
}

//set username for the tweet
void tweet :: setusername(DSString myusername){
     username = myusername;
}

//get message text of the tweet
DSString tweet:: getText(){
    return text;
}

//set message text of the tweet.
void tweet :: setText(DSString mytext){
    text = mytext;
}

//return the positivity of the tweet
int tweet:: getPositivity(){
    return positivity;
}

//set the positivity of the tweet
void tweet::setPositivity(int myPositivity){
    positivity = myPositivity;
}


