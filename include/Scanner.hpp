#ifndef __SCANNER__
#define __SCANNER__

#include <string>
#include <vector>
#include "Token.hpp"

class Scanner {
private:
    //Data Memebers
    std::string m_source;
    std::vector<Token> m_tokens;
    size_t m_start = 0;
    size_t m_current = 0;
    size_t m_line = 1;

    
private:
    //Private helper functions
    bool is_at_end(){
        return m_current >= m_source.length();
    }

    void scan_token();
    char advance();
    char peek();
    bool match(char expected);

public:
    explicit Scanner(const std::string& source);
    const std::vector<Token>& scan_tokens();

    void add_token(TokenType type);
    void add_token(TokenType type, std::unique_ptr<Object> obj);
}; 

#endif // !__SCANNER__
