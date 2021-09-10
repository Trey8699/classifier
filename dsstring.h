#ifndef DSSTRING_H
#define DSSTRING_H

#include <iostream>
#include <cstring>

class DSString
{
private:
    char* data;
    int length;
public:
    DSString();
    DSString(const char*);
    DSString(const DSString&);
    ~DSString();

    DSString& operator= (const char*);
    DSString& operator= (const DSString&);
    DSString operator+ (const DSString&);
    DSString& operator+= (const DSString&);
    DSString& operator+=(const char);
    bool operator== (const char*);
    bool operator== (const DSString&)const;
    bool operator< (const char*);
    bool operator< (const DSString&)const;
    char& operator[] (const int);
    void erase(int i);

    int size();

    DSString substring(int a, int b);

    //c_str returns c-string representation of DSString obj.
    char* c_str();

    friend std::ostream& operator<<(std::ostream&, const DSString&);
    friend std::istream& operator>>(std::istream&, DSString&);
};

#endif // DSSTRING_H
