#include <iostream>
#include <fstream>
#include <string>
#include <cctype>
#include <algorithm>
#include <vector>

std::vector<std::string> tokenize(const std::string& line) {
    std::vector<std::string> tokens;
    std::string currentToken;
    
    for (char c : line) {
        if (std::isalpha(c)) {
            // add alphabetic character to the current token
            currentToken += std::tolower(c);
        } else if (!currentToken.empty()) {
            // Non-alphabetic character encountered after a token
            // Push the current token to the vector and reset it
            tokens.push_back(currentToken);
            currentToken.clear();
        }
    }
    
    // Add the last token if the line ends with a valid token
    if (!currentToken.empty()) {
        tokens.push_back(currentToken);
    }
    
    return tokens;
}

int main() {
    std::string filename = "book.txt";
    // Open the file
    std::ifstream inputFile(filename);
    // Check if the file was opened successfully
    if (!inputFile.is_open()) {
        std::cerr << "Error: Unable to open file " << filename << std::endl;
        return 1;
    }
    // Read the file line by line
    std::string line;
    while (std::getline(inputFile, line)) {
        // Tokenize the line
        std::vector<std::string> tokens = tokenize(line);
        // Print each token for verification
        for (const std::string& token : tokens) {
            std::cout << token << ' ';
        }
    }
    std::cout << std::endl;
    // Close the file
    inputFile.close();
    return 0;
}
