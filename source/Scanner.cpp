#include "../include/Scanner.hpp"
#include "../include/TokenType.hpp"
#include "Literal.hpp"
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

bool Scanner::match(char expected){
    if(is_at_end()) return false;
    if (m_source.at(m_current) != expected) return false;

    m_current++;
    return true;
}

char Scanner::peek(){
    if(is_at_end()) return '\0';
    return m_source.at(m_current);
}

char Scanner::peek_next(){
    if(m_current + 1 >= m_source.length()) return '\0';
    return m_source.at(m_current + 1);
}

void Scanner::string_literal(){
    while(peek() != '"' && !is_at_end()) {
        if (peek() == '\n') m_line++;
        advance();
    }

    if (is_at_end()){
        //report error.
    }

    advance();

    std::string value(m_start + 1, m_current - 1);
    add_token(TokenType::STRING, object_factory(value));
}

void Scanner::number_literal(){
    while(std::isdigit(peek())) advance();
    if (peek() == '.' && isdigit(peek_next())){
        advance();
        while(isdigit(peek())) advance();
    }

    std::string numeral_string(m_start, m_current);
    auto numeral = stod(numeral_string);
    add_token(TokenType::NUMBER, object_factory(numeral));
}

void Scanner::idenitfier() {
    while(isalnum(peek())) advance();
    std::string text(m_start, m_current);
    auto type = Scanner::m_keywords.find(text);
    if(type == Scanner::m_keywords.end()) {
        add_token(TokenType::IDENITFIER);
    }
}

void Scanner::scan_token(){
    char c = advance();
    switch(c){
        case '(': add_token(TokenType::LEFT_PERN); break;
        case ')': add_token(TokenType::RIGHT_PERN); break;
        case '{': add_token(TokenType::LEFT_BRACE); break;
        case '}': add_token(TokenType::RIGHT_BRACE); break;
        case ',': add_token(TokenType::COMMA); break;
        case '.': add_token(TokenType::DOT); break;
        case '-': add_token(TokenType::MINUS); break;
        case '+': add_token(TokenType::PLUS); break;
        case ';': add_token(TokenType::SEMICOLEN); break;
        case '*': add_token(TokenType::STAR); break;
        case '!':
            add_token(match('=') ? TokenType::BANG_EQUAL : TokenType::EQUAL);
            break;
        case '=':
            add_token(match('=') ? TokenType::EQUAL_EQUAL : TokenType::EQUAL);
            break;
        case '<':
            add_token(match('=') ? TokenType::LESS_EQUAL : TokenType::LESS);
            break;
        case '>':
            add_token(match('=') ? TokenType::GREATER_EQUAL : TokenType::GREATER);
        case '/':
            if (match('/')){
                while(peek() != '\n' && !is_at_end()) advance();
            }
            else {
                add_token(TokenType::SLASH);
            }
            break;
        case ' ':
        case '\t':
        case '\r':
            break;
        case '\n':
            m_line++;
            break;
        default:
            if (isdigit(c)){
                number_literal();
            } else if (isalpha(c)){

            }
//            break;
//            //handle errors here,lets figure it out to report our compiler some how.

    }
}

const std::vector<Token>& Scanner::scan_tokens(){
    while(!is_at_end()){
        m_start = m_current;
        scan_token();
    }
    m_tokens.emplace_back(TokenType::FILEEND, "", nullptr, m_current, m_line);
    return m_tokens;
}

void Scanner::add_token(TokenType type){
    add_token(type, nullptr);
}

void Scanner::add_token(TokenType type, std::unique_ptr<Object> literal){
    std::string text(m_source.begin() + m_start, m_source.begin() + m_current);
    m_tokens.emplace_back(type, text, literal, m_current, m_line);
}
