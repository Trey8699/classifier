#include "dsstring.h"
#include <iostream>
#include <fstream>

//set the default string to be nullptr.
DSString::DSString(){
   data = nullptr;
   length = 0;
}

DSString::DSString(const char* d){
   //if not null then set length create space for data and copy
   if(d){
    length = strlen(d);
    data = new char[strlen(d) + 1];
//    data[length] = '\0';
    strcpy(data,d);
   }
   //otherwise set data to nullptr
   else {
       data = nullptr;
       length = 0;
   }
}

DSString::DSString(const DSString& src){
   //if the string is not empty set length and allocate space
   //and copy data from source to current data
   if(src.data){
       length = src.length;
       data = new char[strlen(src.data) + 1];
       data[length] = '\0';
       strcpy(data, src.data);
   }
   //otherwise set data to nullptr
   else{
       data = nullptr;
       length = 0;
   }

}
//destructor for string
DSString::~DSString(){
    delete [] data;
}

DSString& DSString ::operator=(const char* d){
    int i = 1;
    //set i =1 and go until a null terminator is found
    while((*d != '\0')){
        d++;
        i++;
    }
    //if string is empty
    if(i == 1){
        delete[]data;
        data = nullptr;
        length = 0;
        return *this;
    }
    //if string is not empty
    else{
        delete[] data;
        data = new char[i - 1];
        strcpy(data,d);
        length = i - 1;
        return *this;
    }
}


//if src is empty then set data to an empty string
//otherwise allocate space and copy each character from
//the source onto the destination string.
DSString& DSString::operator=(const DSString& src ){
    if(src.data == nullptr){
        delete[] data;
        data = nullptr;
        length = 0;
        return *this;
    }


   if(this != &src){
    if(data!=nullptr){
        delete[] data;
    }
        data = new char[src.length + 1];
        strcpy(data, src.data);
        length = src.length;
   }
    return *this;
}



DSString  DSString:: operator+(const DSString& src){
    //check to see if data to be added is not empty
    if(src.data != nullptr){
        //allocate space for new string
        char* tmp = new char[length + src.length + 1];
        //go through first string and place all characters in array
        for(int i = 0; i < length; i++){
            tmp[i] = data[i];
        }
        int x = 0;
        //go through second string and start from next empty position to put second string characters in array
        for(int j = length; j < length + src.length + 1;j++){
            tmp[j] = src.data[x];
            x++;
        }
        //update length
        length = length + src.length;
        //set last character to null terminator
        data[length] = '\0';
        delete[] data;
        data = tmp;
    }
    //if string to be added is empty return original string
    else{
        return data;
    }
    //return updated string
   return *this;
}


//if string to be concatenated is not empty
//allocate space, copy existing data,and then
//add data to existing string.
DSString& DSString::operator+=(const DSString& src){
   if(src.data != nullptr) {
        char *tmp = new char[length + src.length + 1];
        strcpy(tmp, data);
        strcat(tmp, src.data);
        length = length + src.length;
        //data[length] = '\0';
        delete [] data;
        data = tmp;
    }
     return *this;


}

DSString& DSString:: operator+=(const char s){
     char *tmp = new char[310];
     strcpy(tmp,data);
     strcat(tmp, &s);
     length = length + 1;
     //data[length] = '\0';
     delete [] data;
     data = tmp;
     return *this;
}
//compare original string to string to be compared and return true if same
bool DSString::operator==(const char* src){
    return std::strcmp(data,src) == 0;
}

/*
 * if length is not equal, return false
 * otherwise check each character and if a nonmatching
 * character is found return false
 * otherwise return true
 */
bool DSString::operator==(const DSString& src)const{
   if(src.length != length){
       return false;
    }
   else{
       for(int i =0; i < src.length; i++){
           if(data[i]!= src.data[i]){
               return false;
           }
       }
   }
   return true;


}
/*
 * if original string contents less than comparing string return true
 */
bool DSString::operator<(const char* src){
    return std::strcmp(data,src) < 0;
}
/*
 * first compare length if original is less than comparing string
 * return true
 * if it is greater return false
 * otherwise go through each character one by one and if the first
 */
bool DSString:: operator < ( const DSString& src)const{
    if(length < src.length){
        return true;
    }
    else if(length > src.length){
        return false;
    }
    else{
        for(int i = 0; i < src.length; i++){
            if(data[i] < src.data[i]){
                return true;
            }
        }
    }
    return false;
}

//return character at specified index
char& DSString:: operator[](const int x){
    return data[x];
}

/*get size of object
 * start at i and go through
 * data until hitting null terminator
 * then return i*/
int DSString::size(){
    int i =0;
    while(data[i] != '\0'){
        i++;
    }
    return i ;
}
//a is starting position and b is number of characters to copy
//if b is positive count forward from position a.
//if b is negative count backward from position a.
DSString DSString :: substring(int a, int b){
    int cntr = 0;
    if(b < 0){
        char* temp = new char[-b];
        for(int i = a; i > a + b; i--){
            temp[cntr] = data[i];
            cntr++;
        }
        DSString result(temp);
        delete [] temp;
        return result;
    }

    if( b != 0) {
    char* tmp = new char[b];
    for(int i = a; i < a + b; i++){
       tmp[cntr] = data[i];
       cntr++;
    }
    DSString result(tmp);
    delete [] tmp;
    return result;
    }
   //if b = 0 then return empty string
   return DSString("");
}

//returns a cstring representation of a DSString object
char* DSString:: c_str(){
   return data;

}

void DSString :: erase(int i){

}

//takes whatever is in string and outputs to console.
std:: ostream& operator<< (std::ostream& os, const DSString& s){
    //if not empty string output all characters to stream
    if(s.length > 0){
        for(int j =0; j < s.length; j++){
            os << s.data[j];
        }
    }
    //otherwise output an empty string
    else{
        os << " ";
     }
return os;
}



//extraction operator used to extract string data
std:: istream& operator>> (std::istream& stream,  DSString& s){
    char* temp = s.data;
    s.data = new char[100];
    int i = 0;
    stream >> s.data;
    i++;
    delete[]temp;
    return stream;
}
