/* 
 * File:   main.cpp
 * Author: Jake Smith
 *
 * Created on February 19, 2020, 1:09 PM
 */
#include <cstdlib>
#include "Dictionary.h"

using namespace std;
/*
 * 
 */
int main(int argc, char** argv) {
    string choice2;
    while(choice2 != "N" && choice2 != "No" && choice2 != "n"){
    Dictionary call;
    int choice;
    cout << "Choose one of the sample texts: "<< endl;
    cout << "(1) for sample text 1" << endl;
    cout << "(2) for sample text 2" << endl;
    cout << "(3) for sample text 3" << endl;
    cout << "(4) for sample text 4" << endl;
    cout << "(5) for sample text 5" << endl;

    cout << "Choice: " ;
    cin >> choice;
    switch(choice)
    {
        case 1:
            call.read_Rank("words.txt");
            call.readSample("sample1.txt"); 
            break;
        case 2:
            call.read_Rank("words.txt");
            call.readSample("sample2.txt");
            break;
        case 3:
            call.read_Rank("words.txt");
            call.readSample("sample3.txt");
            break;
        case 4:
            call.read_Rank("words.txt");
            call.readSample("sample4.txt");
            break;    
        case 5:
            call.read_Rank("words.txt");
            call.readSample("sample5.txt");
            break;
        default:
            cout << "Not a valid input: " << endl;
            break;
            
    }
    cout << "Would you like to choose another one? (Y/N) ";
    cin >> choice2;
    }
   
    //system("pause");
    return 0;
}

