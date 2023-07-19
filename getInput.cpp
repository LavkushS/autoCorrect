#include<bits/stdc++.h>
#include <fstream>
#include <thread>
#include <mutex>
#include "functions.h"
#include "trie.h"
#include "node.h"
using namespace std;

void getInput() {
    std::string filename = "test.txt"; // Replace with the name of your input text file
    while (true) {
        std::ifstream inFile(filename);
        if (!inFile) {
            std::cerr << "Error opening the input file: " << filename << std::endl;
            return;
        }
        while (getline(inFile, userInput, ' ')) {
            // Notify the other thread that the input is ready
            cv.notify_one();

            std::this_thread::sleep_for(std::chrono::milliseconds(1000)); // Wait for a while before reading the next line
        }

        inFile.close();
    }
}