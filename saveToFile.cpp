#include<bits/stdc++.h>
#include <fstream>
#include <thread>
#include <mutex>
#include "functions.h"
#include "trie.h"
#include "node.h"
using namespace std;

// Thread function for saving the input to the output file
void saveToFile() {
    // Save the word to the output file
    while (true) {
        std::string outputFilename = "output.txt";
        std::ofstream outFile(outputFilename, std::ios::out);
        if (!outFile) {
            std::cerr << "Error opening the output file: " << outputFilename << std::endl;
            return;
        }
        // Wait for the input to be available
        int length=0;
        std::string filename = "test.txt"; // Replace with the name of your input text file
        
        std::ifstream inFile(filename);
        if (!inFile) {
            std::cerr << "Error opening the input file: " << filename << std::endl;
            return ;
        }
        std::string word;
        while (inFile >> word) {
            // Process the word here
            word=toLower(word);
            if(!obj.search(word)){
                string autoCorrect="";
                vector<thread> threadArray(word.length());
                int len=word.length();
                for(int cnt=0;cnt<len;cnt++){
                    //creating a new thread with a task to modify the cnt index of the word
                    threadArray[cnt] = std::thread([&word,&autoCorrect,cnt]() {
                        return autoComplete(word,autoCorrect,cnt);
                    });
                }
                //wait for all thread to finish their execution and join 
                for (int i = 0; i < len; ++i) {
                    threadArray[i].join();
                }
                
                //editing the word
                string ans="?";
                ans+=word+"?";
                word=ans;
                //concatenating with the misspelled word 
                word+="(";
                word+=autoCorrect;
                word+=")";
            }
            // Write the word to the output file
            length+=word.length();
            outFile << word << " ";
            if(length>90){
                outFile<<"\n";
                length=0;
            }
        }

        userInput.clear(); // Clear the userInput after processing
        outFile.close();
        inFile.close();
        std::this_thread::sleep_for(std::chrono::milliseconds(1000)); // Wait for a while before reading the next line
    }
}