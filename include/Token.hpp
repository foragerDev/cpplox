#ifndef __TOKEN__
#define __TOKEN__

#include "../include/TokenType.hpp"
#include "Literal.hpp"
#include <string>

class Token
{
private:
    TokenType m_type;
    std::string m_lexeme;
    std::unique_ptr<Object> m_literal = nullptr;
    std::size_t m_col;
    std::size_t m_line;

public:
    Token() = default;
    Token(
        TokenType type,
        const std::string &lexeme,
        std::unique_ptr<Object> object,
        std::size_t col,
        std::size_t line);
    std::string to_string() const;
};

#endif // !__TOKEN__
