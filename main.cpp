//
//  main.cpp
//  ProjectThreeFinal
//
//  Created by George Muresan on 4/28/19.
//  Copyright © 2019 George Muresan. All rights reserved.
//

#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include <cstdlib>
#include <algorithm>
#include <ctime>
#include "main.h"

using namespace std;


bool Is_Prime(int Number) // function that checks if the number is prime
{
    bool isPrime = true;
    for(unsigned i = 2; i < Number/2; i++)
    {
        if(Number % i == 0)
        {
            isPrime = false;
        }
    }
    
    return isPrime; // returns 1 if it is prime and 0 if it isn't prime
}

int LargestPrime(int Number) // function that finds the maximum prime number smaller than Number
{
    bool found = false;
    unsigned largestPrime = Number;
    while (!found)
    {
        largestPrime++;
        if(Is_Prime(largestPrime))
        {
            found = true;
        }
    }
    
    return largestPrime; // returns the max prime smaller or equal to Number
}


int main(int argc, const char * argv[])
{
    
    string inputFile = "/Users/georgemuresan/Downloads/inputFile2.txt";
    string DictionaryFile = "/Users/georgemuresan/Downloads/dictionaryFile.txt";
    //string inputFile = "inputFile1.txt";
    //string DictionaryFile = "dictionaryFile.txt";
    
    //string inputFile = argv[2];
    //string DictionaryFile = argv[1];
    
    ifstream input(inputFile.c_str());
    ifstream scan(DictionaryFile.c_str());
    string word;
    unsigned size = 0;
    
    while(scan >> word)
    {
        size++;
    }
    
    clock_t TimeStartChain;
    clock_t TimeStopChain;
    
    
    
    ChainHash DictionaryHash;//MAKE A PRIME NUMBER, FIND METHOD ONLINE
    unsigned primeSize = LargestPrime(size * 2);
    DictionaryHash = ChainHash(primeSize);
    
    scan.close();

    TimeStartChain = clock();
    ifstream Dictionary2(DictionaryFile.c_str());
    DictionaryHash.readDictionary(Dictionary2);
    
    DictionaryHash.readInput(input);
    cout << "Chain - # of words misspelled: " << DictionaryHash.getErrors() << endl;
    input.close();
    Dictionary2.close();
    TimeStopChain = clock();
    
    double timeChain = (double) (TimeStopChain - TimeStartChain) / CLOCKS_PER_SEC;
    cout << "Chain Time: " << timeChain << endl;
    //
    //
    //
    //
    //
    //
    
    clock_t TimeStartQuad;
    clock_t TimeStopQuad;
    
    ifstream inputQuad(inputFile.c_str());
    ifstream scanQuad(DictionaryFile.c_str());
    string temp;
    unsigned sizeQuad = 0;
    
    while(scanQuad >> temp)
    {
        sizeQuad++;
        //cout << "loop" << endl;
    }
    //cout << "wahts good" << endl;
    QuadHash DictionaryHashQuad;//MAKE A PRIME NUMBER, FIND METHOD ONLINE
    unsigned primeSizeQuad = LargestPrime(sizeQuad * 2);
    DictionaryHashQuad = QuadHash(primeSizeQuad);
    scanQuad.close();
    
    //cout << "wahts good" << endl;
    TimeStartQuad = clock();
    ifstream DictionaryQuad2(DictionaryFile.c_str());
    DictionaryHashQuad.readDictionary(DictionaryQuad2);

    
    DictionaryHashQuad.readInput(inputQuad);
    cout << "Quad - # of words misspelled: " << DictionaryHashQuad.getErrors() << endl;
    inputQuad.close();
    DictionaryQuad2.close();
    TimeStopQuad = clock();
    
    
    double timeQuad = (double) (TimeStopQuad - TimeStartQuad) / CLOCKS_PER_SEC;
    cout << "Quadratic Time: " << timeQuad << endl;
    
    
    /*
    ChainHash testHash(5);
    testHash.InsertWord("cow");
    testHash.InsertWord("dog");
    testHash.InsertWord("cat");
    testHash.InsertWord("pig");
    testHash.InsertWord("bird");
    
    testHash.print();
    cout << testHash.spellCheck("");
     */
    
    return 0;
}
