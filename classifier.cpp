#include "classifier.h"
#include "dsstring.h"
#include "tweet.h"
#include <iostream>
#include <sstream>
#include <cstring>
#include <fstream>


using namespace std;
Classifier::Classifier(){

}

Classifier::Classifier(DSVector<DSString>myPositiveWords,DSVector<DSString>myNegativeWords,DSVector<DSString>myStopWords, DSVector<tweet>myTweets,DSVector<DSVector<DSString>>myTweetWords)
{
   positiveWords = myPositiveWords;
   negativeWords = myNegativeWords;
   stopWords = myStopWords;
   tweets = myTweets;
   tweetWords = myTweetWords;
}

/* read files for tweets and store them in the struct*/
void Classifier :: readtweets(char** argv){
   ifstream inFS;
   inFS.open(argv[1]);
   //inFS.open(argv[1]);
   //DSString firstline;
   char* firstline = new char[50];
   int  rownum;
	int positivity;
   char* rowtext = new char[11];
   long  idnum;
   char* idnumtext = new char[15];
   DSString username;
   char* usernametext = new char[25];
   char* messagetext = new char[150];
   DSString message;
   inFS.getline(firstline,50,'\n');
   int i = 0;

	
   while(!inFS.eof() || i > 20000){
       tweet sometweet;
       inFS.getline(rowtext,10,',');
       positivity = atoi(rowtext);
	sometweet.setPositivity(positivity);
       sometweet.setrowNum(i+1);
       inFS.getline(idnumtext,14,',');
       idnum = atol(idnumtext);
       sometweet.setIDNum(idnum);
	// get date and get query
       inFS.getline(firstline,50,',');
	inFS.getline(firstline,50,',');
	inFS.getline(usernametext,24,',');

       sometweet.setusername(usernametext);
       inFS.getline(messagetext,150, '\n');
       sometweet.setText(messagetext);
       tweets.push_back(sometweet);
       tweetWords.push_back(breakintoWords(sometweet));
       i++;
      }

   delete [] firstline;
   delete [] rowtext;
   delete [] idnumtext;
   delete [] usernametext;
   delete [] messagetext;
  }


DSVector<DSString> Classifier :: breakintoWords(tweet sometweet){
     DSString tobreak = sometweet.getText();
     char* something =tobreak.c_str();

     DSVector<DSString> words;
     //int i  = 0;
     char* tok =strtok(something,"- !\"#$%& ()*+,./:;?@[]\\^_`{}|~");
     while (tok != nullptr){
           DSString temp(tok);
           words.push_back(temp);
           tok =strtok(nullptr,"- !\"#$%& ()*+,./:;?@[]\\^_`{}|~");
     }


     return words;
}


/* train our algorithm */
void Classifier :: train(char* argv[]){

    for(int i =0; i < tweets.getSize();i++){
        for(int j = 0; j < tweetWords[i].getSize();j++){
            auto x = wordpositivity.emplace(tweetWords[i][j],0);
            if(tweets[i].getPositivity() == 4)
                x.first->second++;
            else if(tweets[i].getPositivity() == 0)
                x.first->second--;
            else {
                cout << "Error at tweet " << i << ", word " << j << endl;
            }
        }
    }
}

/* test algorithm */
void Classifier:: test(char* argv[]){
    ifstream inFS(argv[2]);
    ifstream target(argv[3]);
    ofstream outFS(argv[4]);
    tweets.clear();
    tweetWords.clear();
    char* firstline = new char[50];
    int  rownum;
    char* rowtext = new char[20];
    long  idnum;
    char* idnumtext = new char[10];
    DSString username;
    char* usernametext = new char[25];
    char* messagetext = new char[150];
    DSString message;
    inFS.getline(firstline,50,'\n');
    int i = 0;
	double numCorrect = 0.0;

	DSVector<pair<long,char>> testVector;
    char* buffer = new char[100];

	


    while(!inFS.eof()){
        tweet sometweet;
        inFS.getline(rowtext,20,',');
        idnum = atoi(rowtext);
        sometweet.setrowNum(i+1);
	sometweet.setIDNum(idnum);
        // get date and get query
       inFS.getline(firstline,50,',');
	inFS.getline(firstline,50,',');
        inFS.getline(usernametext,25,',');
        sometweet.setusername(usernametext);
        inFS.getline(messagetext,150, '\n');
        sometweet.setText(messagetext);
        tweets.push_back(sometweet);
        tweetWords.push_back(breakintoWords(sometweet));
        i++;
       }

    for(int i = 0; i < tweets.getSize();i++){
        int tempsum = 0;
        for(int j=0 ; j < tweetWords[i].getSize(); i++){
         auto x = wordpositivity.find(tweetWords[i][j]);
         int valtoadd = x->second;
         tempsum += valtoadd;
        }
        if(tempsum >= 0)
            tweets[i].setPositivity(4);
        else if(tempsum <0)
            tweets[i].setPositivity(0);
    }

    
    target.getline(firstline,50);
    i = 0;
    
    while(!target.eof())
    {
        target.getline(buffer,100,',');
        target.getline(buffer,100,',');
        int targetNum = atoi(buffer);
        target.getline(buffer,100);
        long id = atol(buffer);
        char correct;
        if(tweets[i].getPositivity() == targetNum) {
            correct = 'c';
            numCorrect++;
        }
        else {
            correct = 'i';
        }
        testVector.push_back(make_pair(id,correct));
        i++;
    }

    delete [] buffer;
    delete [] usernametext;
    delete [] messagetext;
    delete [] idnumtext;
    delete [] rowtext;
    delete [] firstline;
    double accuracy = numCorrect/i;
    outFS << accuracy << endl;
    for(int i = 0; i < testVector.getSize(); i++)
    {
        outFS << testVector[i].first << "," << testVector[i].second << endl;
    }

}










