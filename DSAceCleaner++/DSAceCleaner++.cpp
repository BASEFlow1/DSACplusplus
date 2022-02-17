#include <iostream>
#include <vector>
#include <string>
#include <fstream>

std::vector<std::string> openFile(std::string inputFile, std::vector<std::string> chatList) {
    std::fstream newfile;
    newfile.open(inputFile, std::ios::in);
    if (newfile.is_open()) {
        std::string tp;
        while (std::getline(newfile, tp)) {
            chatList.push_back(tp);
        }
    }
    else {
        std::cout << "Input file couldn't be opened. Terminating.";
        exit(EXIT_FAILURE);
    }
    newfile.close();
    return chatList;
}

int main() {
    // SETTINGS
    std::vector<std::string> chatList;
    std::vector<std::string> nameList;
    std::vector<std::string> contentList;
    std::vector<std::string> exclusions = {"Death[0]", "Tip[0]", "Options[0]", "has requested to dock[1]", "CONSOLE[0]", "//[3]", "/[3]"};
    int exclusionLength = exclusions.size();
    std::string inputFile = "D:\\repos\\DSAceCleaner\\DSAce.log";
    std::string outputFile = "DSAce_cleaned.log";
    bool includeTimestamps = false;
    // SETTINGS

    chatList = openFile(inputFile, chatList);

    // MAIN LOOP
    for (int i = 0; i < chatList.size(); i++){
        std::string element = chatList.at(i);
        if (element.length() > 22) {
            if (!includeTimestamps) {
                element.erase(element.begin(), element.begin() + 22);
            }
            if (element.find(":") != std::string::npos) {
                
            }
        }
        else {
            chatList.erase(chatList.begin(), chatList.begin() + i);
        }

    }
}