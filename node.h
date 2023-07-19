#ifndef NODE_H
#define NODE_H

struct Node{
    Node* link[260];
    bool flag=false;
    bool containsKey(char ch){
        return link[ch]!=nullptr;
    }
    void put(char ch,Node* next){
        link[ch]=next;
    }
};

#endif