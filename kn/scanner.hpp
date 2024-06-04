#pragma once
#include <sstream>
#include <vector>
#include <iostream>

enum TokenType
{
    Exit,
    Return,
    Semicolon,
    Number,
    Identifier,
    Equal,
    OpenPare,
    ClosePare,
    Let,
    Unkown,

    Plus,
    Coma,
    OpenBRACE,
    CloseBRACE,
    Function,

};

struct Token
{
    TokenType type;
    std::string value;
};

struct Scanner
{
    std::string input;
    int arrow = 0;
    bool eof = false;
    char ch = input.at(arrow);
    std::vector<Token> tokens = {};
    std::string buff;
    void readChar()
    {
        arrow++;
        if (arrow == input.length())
        {
            eof = true;
        }
        else
        {
            ch = input.at(arrow);
        }
    }
    void tokenize()
    {

        while (!eof)
        {
            std::cout << ch << std::endl; // sssssss

            if (std::isalpha(ch))
            {

                buff.push_back(ch);
                readChar();

                while (std::isalpha(ch))
                {
                    std::cout << ch << std::endl; // sssssss
                    buff.push_back(ch);
                    readChar();
                }

                if (buff == "return")
                {
                    tokens.push_back({.type = TokenType::Return});
                    buff.clear();
                }
                if (buff == "let")
                {
                    tokens.push_back({.type = TokenType::Let});
                    buff.clear();
                }
                if (buff == "function")
                {
                    tokens.push_back({.type = TokenType::Function});
                    buff.clear();
                }
                else
                {
                    tokens.push_back({.type = TokenType::Identifier, .value = buff});
                    buff.clear();
                }
            }
            else if (std::isdigit(ch))
            {

                buff.push_back(ch);
                readChar();
                while (std::isdigit(ch))
                {
                    std::cout << ch << std::endl; // sssssss
                    buff.push_back(ch);
                    readChar();
                }
                tokens.push_back({.type = TokenType::Number, .value = buff});
                buff.clear();
            }
            else if (ch == ';')
            {
                tokens.push_back({.type = TokenType::Semicolon});
                readChar();
            }
            //
            else if (ch == '=')
            {
                tokens.push_back({.type = TokenType::Equal});
                readChar();
            }
            else if (ch == '+')
            {
                tokens.push_back({.type = TokenType::Plus});
                readChar();
            }
            else if (ch == '(')
            {
                tokens.push_back({.type = TokenType::OpenPare});
                readChar();
            }
            else if (ch == ')')
            {
                tokens.push_back({.type = TokenType::ClosePare});
                readChar();
            }
            else if (ch == '{')
            {
                tokens.push_back({.type = TokenType::OpenPare});
                readChar();
            }
            else if (ch == '}')
            {
                tokens.push_back({.type = TokenType::ClosePare});
                readChar();
            }
            else if (ch == ',')
            {
                tokens.push_back({.type = TokenType::Coma});
                readChar();
            }
            //
            else if (std::isspace(ch))
            {
                readChar();
                continue;
            }
            else
            {
                std::cout << "unnkown character: " << ch << " at :" << arrow << input.length() << std::endl;
                readChar();
            }
        }
    }
};
Scanner newScanner(std::string input)
{
    Scanner s = {.input = input};
    return s;
}
