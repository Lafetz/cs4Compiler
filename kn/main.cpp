#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include "scanner.hpp"
#include "parser.hpp"

int main(int argc, char *argv[])
{

    std::stringstream fileStream;
    std::fstream file = std::fstream("file.kn", std::ios::in);
    fileStream << file.rdbuf();
    file.close();
    std::string test = fileStream.str();
    Scanner s = newScanner(test);
    s.tokenize();
    std::vector<Token> x = s.tokens;

    return 0;
}