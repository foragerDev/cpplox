#include "Token.hpp"

Token::Token(TokenType type, const std::string& lexeme, std::size_t col, std::size_t line)
    :m_type(type), m_lexeme(lexeme), m_col(col), m_line(line){}

std::string Token::to_string() const{
    return "";
}
