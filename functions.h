#ifndef FUNCTIONS_H
#define FUNCTIONS_H
#include "trie.h"

extern void saveToFile();
extern void autoComplete(std::string word,std::string& autoCorrect,int ind);
extern void getInput();
extern int fileRead();
extern std::string toLower(std::string word);

#endif