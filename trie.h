#ifndef TRIE_H
#define TRIE_H

#include "node.h"

class Trie{

    private: Node* root;
    public:

    Trie(){
        root=new Node();
    }

    void insert(std::string &word);
    bool search(std::string word);
};

extern Trie obj; 
extern std::mutex correct;  //mutex for adding the auto correct word
extern std::condition_variable cv; // Condition variable for synchronization std::string userInput;  //string to store the value of the input string 
extern std::mutex mtx; // Mutex for synchronizing access to userInput
extern std::string userInput; //for taking the string input 

#endif