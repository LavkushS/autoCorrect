#include<bits/stdc++.h>
#include <fstream>
#include <thread>
#include <mutex>
#include "functions.h"
#include "trie.h"
#include "node.h"
using namespace std;

int fileRead(){
    string filename= "input.txt";
    ifstream inFile(filename);
    if (!inFile) {
        std::cerr << "Error opening the file: " << filename << std::endl;
        return 1;
    }

    std::string word;
    while (inFile >> word) {
        // getting the words one by one 
        word=toLower(word);
        obj.insert(word);
    }

    inFile.close();
    return 1;
}