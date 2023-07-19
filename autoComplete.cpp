#include<bits/stdc++.h>
#include <fstream>
#include <thread>
#include <mutex>
#include "functions.h"
#include "trie.h"
#include "node.h"
using namespace std;

void autoComplete(string word,string& autoCorrect,int ind){
    string start=word.substr(0,ind),end=word.substr(ind+1,word.length()-(ind+1));
    for(int j=0;j<26;j++){
        string temp="";
        temp+=start+(char)(j+'a')+end;
        if(obj.search(temp)){
            correct.lock();
            autoCorrect+=" "+temp;
            correct.unlock();
        }
    }
    return ;
}