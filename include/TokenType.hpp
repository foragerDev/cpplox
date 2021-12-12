#ifndef __TOKENTYPE__
#define __TOKENTYPE__

enum class TokenType
{
    // Single Character Token
    
    LEFT_PERN,
    RIGHT_PERN,
    LEFT_BRACE,
    RIGHT_BRACE,
    COMMA,
    DOT,
    MINUS,
    PLUS,
    SEMICOLEN,
    SLASH,
    STAR,

    //One Or TWO Charater tokens

    BANG,
    BANG_EQUAL,
    EQUAL,
    EQUAL_EQUAL,
    GREATER,
    GREATER_EQUAL,
    LESS,
    LESS_EQUAL,

    //Literals

    IDENITFIER,
    STRING,
    NUMBER,

    //Keyword
    AND,
    CLASS,
    ELSE,
    FALSE,
    FUN,
    FOR,
    IF,
    NIL,
    OR,
    PRINT,
    RETURN,
    SUPER,
    THIS,
    TRUE,
    VAR,
    WHILE,
    FILEEND = -1

};

#endif // !__TOKENTYPE__