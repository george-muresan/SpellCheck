//
//  ChainNode.h
//  ProjectThreeFinal
//
//  Created by George Muresan on 4/28/19.
//  Copyright © 2019 George Muresan. All rights reserved.
//

#ifndef ChainNode_h
#define ChainNode_h

using namespace std;

class ChainNode
{
public:
    string value;
    ChainNode *next;
    
    ChainNode();
    ChainNode(const string);
    string getValue()
    {
        return value;
    }
    void setValue(int value);
    
    ChainNode *getNext()
    {
        return next;
    }
    
    void setNext(ChainNode *next)
    {
        this->next = next;
    }
    
};

ChainNode::ChainNode()
{
    value = " ";
    this->next = NULL;
}

ChainNode::ChainNode(string value)
{
    this->value = value;
    next = NULL;
}

void ChainNode::setValue(int value)
{
    this->value = value;
}


#endif /* ChainNode_h */
