#include<bits/stdc++.h>
#include "functions.h"
#include "trie.h"
#include "node.h"
using namespace std;

string toLower(string word){
    for(int i=0;i<word.length();i++){
        if(word[i]>='A' || word[i]<='Z'){
            word[i]=tolower(word[i]);
        }
    }
    return word;
}