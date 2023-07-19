#include<bits/stdc++.h>
#include <fstream>
#include <thread>
#include <mutex>
#include "trie.h"
#include "node.h"
using namespace std;


//declaring the member functions
void Trie::insert(string &word){
        Node* node=root;
        for(int i=0;i<word.length();i++){
            if(!node->containsKey(word[i])){
                Node* next=new Node();
                node->put(word[i],next);
            }
            node = node->link[word[i]];
        }
        node->flag=true;
    }

bool Trie::search(string word) {
        Node* node=root;
        for(int i=0;i<word.length();i++){
            if(!node->containsKey(word[i])){
                return false;
            }
            node=node->link[word[i]];
        }
        return node->flag;
    }


