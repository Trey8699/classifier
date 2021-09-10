#define CATCH_CONFIG_RUNNER
#include <iostream>
#include "classifier.h"
#include "dsstring.h"
#include "tweet.h"
#include "catch.hpp"
#include "dsvector.h"
using namespace std;


int main(int argc, char* argv[])
{
    if(argc == 1){
        return Catch::Session().run();
     }

    Classifier* classifier = new Classifier();
    classifier->readtweets(argv);
	cout << "Read Tweets: Done" << endl;
    classifier->train(argv);
cout << "Training: Done" << endl;
    classifier->test(argv);
	cout << "Testing Done" << endl;

    delete classifier;
}
