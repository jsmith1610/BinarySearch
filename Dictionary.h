/* 
 * File:   Dictionary.h
 * Author: Jake Smith
 *
 * Created on February 19, 2020, 1:09 PM
 */

#ifndef DICTIONARY_H
#define DICTIONARY_H

#include <iostream>
#include <fstream>
#include <string>


using namespace std;
const int Num_Words = 1000;
class Dictionary {
public:
   
    Dictionary();
    Dictionary(const Dictionary& orig);
    int binarySearch(int high, int low, string value);
    void read_Rank(string RankFile);
    void readSample(string filename);
    virtual ~Dictionary();
private:
   int wordRank[Num_Words];
   string word[Num_Words];
   int count1 = 0;
};

#endif /* DICTIONARY_H */

