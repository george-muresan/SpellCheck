//
//  ChainHash.h
//  ProjectThreeFinal
//
//  Created by George Muresan on 4/28/19.
//  Copyright © 2019 George Muresan. All rights reserved.
//

#ifndef ChainHash_h
#define ChainHash_h
#include "ChainNode.h"

using namespace std;

class ChainHash
{
public:
    ChainHash()
    {
        table = new ChainNode* [100003];
        for(int i = 0; i < 100003; i++)
        {
            table[i] = NULL;
        }
        wordCount = 0;
        errors = 0;
        size = 0;
        capacity = 100003;
    }
    ChainHash(unsigned cap)
    {
        table = new ChainNode*[cap];
        for(unsigned i = 0; i < cap; i++)
        {
            table[i] = NULL;
        }
        wordCount = 0;
        errors = 0;
        size = 0;
        capacity = cap;
        
    }
    ~ChainHash()
    {
        ChainNode *prevEntry = NULL;
        ChainNode *entry = NULL;
        for(unsigned i = 0; i < capacity-1; i++)
        {
            entry = table[i];
            while(entry != NULL)
            {
                
                prevEntry = entry;
                entry = entry->getNext();
                delete prevEntry;
            }
        }
            //delete[] table;
            table = NULL;
    }
    
    unsigned int getErrors()
    {
        return errors;
    }
    
    unsigned int HashingFunction(string word) //this uses pg. 216
    {
        unsigned int hashVal = 0;
        for(int i = 0; i < word.length(); i++)
        {
            hashVal = (37 * hashVal) + word.at(i);
        }
        return hashVal % capacity;
    }
    
    
    string FixWord(string word) // return word
    {
        char ch = '0';
        string fixed = "";
        
        for(unsigned i = 0; i < word.size(); i++)
        {
            ch = word.at(i);
            
            if( (ch >= 65 && ch <= 90) || (ch >= 97 && ch <= 122) || (ch == 45))
            {
                fixed.push_back(tolower(word.at(i)));
            }
            
        }
        
        return fixed;
    }
    
    
    void InsertWord(string word) throw (bad_alloc) // void
    {
        string checkMe = FixWord(word);
        unsigned hash = HashingFunction(checkMe);
        
        
        if(table[hash] == NULL)
        {
            table[hash] = new ChainNode(checkMe);
        }
        else
        {
            ChainNode *entry = table[hash];
            if(entry->getValue() == checkMe)
            {
                 return;
            }
            
            while (entry->getNext() != NULL)
            {
                entry = entry->getNext();
            }
            if(entry->getValue() == checkMe)
            {
                entry->setValue(hash);
            }
            else
            {
                entry->setNext(new ChainNode(checkMe));
            }
        }
        
    }
    
    
    bool spellCheck(string word)
    {
        string checkMe = FixWord(word);
        unsigned hash;
        hash = HashingFunction(checkMe);
        ChainNode *temp = table[hash];
        
        while(temp != NULL)
        {
            if(temp->value == checkMe)
            {
                return true;
            }
            temp = temp->getNext();
        }
        errors++;
        return false;
    }
    
    
    
    void readDictionary(ifstream &inFile) throw (bad_alloc)
    {
        string input;
        int counter = 0;
        while(inFile)
        {
            inFile >> input;
            InsertWord(input);
            counter++;
        }
        
    }
    void readInput(istream &inReadFile)
    {
        string input;
        int counter = 0;
        while(inReadFile >> input)
        {
            spellCheck(input);
            counter++;
        }
    }
    
    void print()
    {
        for(unsigned i = 0; i < capacity; i++)
        {
            if(table[i] == NULL)
            {
                cout << " 0 " << endl;
            }
            else
            {
                ChainNode *temp = table[i];
                while(temp != NULL)
                {
                    cout << temp->getValue() << " ";
                    temp = temp->getNext();
                }
                
                cout << endl;
            }
        }
    }
    
    
    
    unsigned wordCount;
    unsigned errors;
    unsigned size;
    unsigned capacity;
    
private:
    ChainNode** table;
    
};





#endif /* ChainHash_h */
