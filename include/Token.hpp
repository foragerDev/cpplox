#ifndef __TOKEN__
#define __TOKEN__

#include "../include/TokenType.hpp"
#include <string>

class Token {
private:
    TokenType type;
    std::string lexeme;
    std::size_t col;
    std::size_t line;
    //Object literal;

public:
    Token(TokenType type, std::string lexeme, std::size_t col, std::size_t line);
    std::string to_string() const;
};

#endif // !__TOKEN__
