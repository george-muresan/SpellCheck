//
//  QuadHash.h
//  ProjectThreeFinal
//
//  Created by George Muresan on 4/28/19.
//  Copyright © 2019 George Muresan. All rights reserved.
//

#ifndef QuadHash_h
#define QuadHash_h

using namespace std;

class QuadHash
{
public:
    QuadHash()
    {
        table = new string [100003];
        for(int i = 0; i < 100003; i++)
        {
            table[i] = " ";
        }
        wordCount = 0;
        errorsQuad = 0;
        size = 0;
        capacity = 100003;
    }
    QuadHash(unsigned cap)
    {
        table = new string [cap];
        for(int i = 0; i < cap; i++)
        {
            table[i] = " ";
        }
        wordCount = 0;
        errorsQuad = 0;
        size = 0;
        capacity = cap;
    }

    
    ~QuadHash()
    {
       //delete[] table;
    }
    
    unsigned int getErrors()
    {
        return errorsQuad;
    }
    
    unsigned HashingFunction(string word)
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
        string fixed = " ";
        
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
    
    void insert(string word)
    {
        int probe = 0;
        word = FixWord(word);
        unsigned value = HashingFunction(word);
        unsigned TheWord = value;
        
        while(table[value] != " ")
        {
            probe++;
            value = TheWord + (probe * probe);
            value = value % capacity;
        }
        table[value] = word;
    }
    
    bool spellCheck(string word)
    {
        int probe = 0;
        word = FixWord(word);
        unsigned value = HashingFunction(word);
        unsigned TheWord = value;
        while(table[value] != word && table[value] != " ")
        {
            probe++;
            value = TheWord + (probe*probe);
            value = value % capacity;
        }
        if(table[value] == word)
        {
            return true;
        }
        else
        {
            errorsQuad++;
            return false;
        }
        
    }
    
    void readDictionary(ifstream &inFile) throw (bad_alloc)
    {
        string input;
        int counter = 0;
        while(inFile >> input)
        {
            insert(input);
            counter++;
        }
    }
    
    void readInput(ifstream &inFile) throw (bad_alloc)
    {
        string input;
        int counter = 0;
        while(inFile >> input)
        {
            spellCheck(input);
            counter++;
        }
    }
    
    void print()
    {
        for(int i = 0; i < capacity; i++)
        {
            cout << table[i] << endl;
        }
    }
    unsigned wordCount;
    unsigned errorsQuad;
    unsigned size;
    unsigned capacity;
    
private:
    string* table;
    

};


#endif /* QuadHash_h */
