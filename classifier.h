#ifndef CLASSIFIER_H
#define CLASSIFIER_H
#include "tweet.h"
#include "dsstring.h"
#include <map>
#include <iostream>
#include <fstream>

class Classifier
{
public:
    Classifier();
    Classifier(DSVector<DSString>myPositiveWords,DSVector<DSString>myNegativeWords,DSVector<DSString>myStopWords, DSVector<tweet>myTweets,DSVector<DSVector<DSString>> mytweetWords);
    void readtweets(char** argv);
    DSVector<DSString> breakintoWords(tweet sometweet);
    void train(char* argv[]);
    void test(char* argv[]);

private:
    DSVector<DSString> positiveWords;
    DSVector<DSString> negativeWords;
    DSVector<DSString> stopWords;
    DSVector<tweet> tweets;
    DSVector<DSVector<DSString>> tweetWords;
    map<DSString,int> wordpositivity;

};

#endif // CLASSIFIER_H
