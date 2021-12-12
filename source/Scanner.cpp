#include "../include/Scanner.hpp"
#include "../include/TokenType.hpp"
#include <stdio.h>

Scanner::Scanner(const std::string &source) : m_source(source)
{
}

char Scanner::advance(){
    char c = m_source.at(m_current++);
    if (c == '\n'){
        m_line++;
    } 
    return c;
}

// void Scanner::scan_token(){
//     char c = advance();
//     switch(c){
//         case '(': 
//     }
// }

const std::vector<Token>& Scanner::scan_tokens(){
    while(!is_at_end()){
        m_start = m_current;
    }
    m_tokens.emplace_back(TokenType::FILEEND, "", m_current, m_line);
    return m_tokens;
}

