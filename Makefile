all:
	g++ classifier.cpp dsstring.cpp dsvector.cpp test.cpp tweet.cpp main.cpp -o classifier
run:
	./classifier train_dataset_20k2.csv test_dataset_10k.csv test_dataset_sentiment_10k.csv out.txt