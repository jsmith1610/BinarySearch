/* 
 * File:   Dictionary.cpp
 * Author: Jake Smith
 * 
 * Created on February 19, 2020, 1:09 PM
 */

#include <valarray>

#include "Dictionary.h"

Dictionary::Dictionary() {
    for(int i = 0; i < Num_Words; i++){
        word[i] = " ";
        wordRank[i] = 0;
    }
}
Dictionary::Dictionary(const Dictionary& orig) {
}
Dictionary::~Dictionary() {
}
void Dictionary::readSample(string filename){
    // Open input file
   ifstream din;
   din.open(filename.c_str());
   if (din.fail()){
      cout << "File not found\n";
      return;
   } 
   // Read strings into word array
   string sampleWord;
   int sampleCount = 0;
   double total = 0;
   double avg = 0;
   while (!din.eof()){
       din >> sampleWord;
       total += binarySearch(Num_Words, 0, sampleWord);//Adds up each word rank returned in binary function
       if(din.eof()){
           break;
       }  
       sampleCount++;
        avg = total/sampleCount;
}
   cout << "Average Reading Score: " << avg << endl;
   din.close(); 
}

void Dictionary::read_Rank(string RankFile){
    ifstream din;
   din.open(RankFile.c_str());
   if (din.fail()){
      return;
      cout << "File not found\n";
   } 
   // Read strings into word array
   int rank;
   string str;
   while(!din.eof() &&  count1 < 999){
       din >> rank >> str;
       wordRank[count1] = rank;
       word[count1] = str;
       count1++;
   }   // Read strings into word array
   din.close();
}  
int Dictionary::binarySearch(int high, int low, string str){//makes the word lower case
    for(int i = 0; i < str.length(); i++){
         str[i] = tolower(str[i]);
         if(str[i] < 'a' || str[i] > 'z'){
             str.erase(i,1);
             i--;
         }
     }
   
     // Calculate midpoint index
   int mid = (low + high) / 2;
   
    if(low > high){//checks to see if the word is outside of the rank list
       return 1001;
   }
    else if (word[mid] == ""){
        return 0;
    }
    else if(word[mid].compare(str) == 0){//shows that the word has been found
       return wordRank[mid];
   }
   else if (word[mid].compare(str) > 0){
      return binarySearch(mid-1,low,str);
   }
   else if (word[mid].compare(str) < 0)
      return binarySearch(high, mid+1 ,str); 
}