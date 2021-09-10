#ifndef TWEET_H
#define TWEET_H
#include "dsstring.h"
#include "dsvector.h"


class tweet{
public:
    tweet();
    tweet(int myRowNum,long myIDNum, DSString myusername, DSString mytext);
    int getrowNum();
    void setrowNum(int myRowNum);
    long getIDNum();
    void setIDNum(long myIDNum);
    DSString getusername();
    void setusername(DSString myusername);
    DSString getText();
    void setText(DSString mytext);
    int getPositivity();
    void setPositivity(int myPositivity);


private:
    int rowNum;
    long IDNum;
    DSString username;
    DSString text;
    int positivity;
};

#endif // TWEET_H
