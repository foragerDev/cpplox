#ifndef __SCANNER__
#define __SCANNER__

#include <string>
#include <vector>
#include <unordered_map>
#include "Token.hpp"

class Scanner {
private:
    //Data Memebers
    std::string m_source;
    std::vector<Token> m_tokens;
    size_t m_start = 0;
    size_t m_current = 0;
    size_t m_line = 1;
    static inline std::unordered_map<std::string, TokenType> m_keywords {
        {"and", TokenType::AND},
        {"class", TokenType::CLASS},
        {"else", TokenType::ELSE},
        {"false", TokenType::FALSE},
        {"for", TokenType::FOR},
        {"fun", TokenType::FUN},
        {"if", TokenType::IF},
        {"nil", TokenType::NIL},
        {"or", TokenType::OR},
        {"print", TokenType::PRINT},
        {"return", TokenType::RETURN},
        {"true", TokenType::TRUE},
        {"super", TokenType::SUPER},
        {"this", TokenType::THIS},
        {"var", TokenType::VAR},
        {"while", TokenType::WHILE}
    };
    
private:
    //Private helper functions
    bool is_at_end(){
        return m_current >= m_source.length();
    }

    void scan_token();
    char advance();
    char peek();
    char peek_next();
    bool match(char expected);
    void string_literal();
    void number_literal();
    void idenitfier();
    void process_multiline_comment();

public:
    Scanner() = default;
    explicit Scanner(const std::string& source);
    const std::vector<Token>& scan_tokens();

    void add_token(TokenType type);
    void add_token(TokenType type, std::unique_ptr<Object> obj);
}; 

#endif // !__SCANNER__
