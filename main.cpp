#include<bits/stdc++.h>
#include <fstream>
#include <thread>
#include <mutex>
#include "functions.h"
#include "trie.h"
#include "node.h"
using namespace std;

Trie obj; 
std::mutex correct;  //mutex for adding the auto correct word
std::condition_variable cv; // Condition variable for synchronization std::string userInput;  //string to store the value of the input string 
std::mutex mtx; // Mutex for synchronizing access to userInput
std::string userInput; //for taking the string input 

int main()
{
    //inserting words in the dictionary 
    cout<<"start\n";
    fileRead();
    cout<<"done\n";
    //now here i will be making threads for all the other parts 
    std::thread inputThread(getInput);
    std::thread saveThread(saveToFile);

    // Wait for both threads to finish
    inputThread.join();
    saveThread.join();
    
    return 0;
}