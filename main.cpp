#include "Lox.hpp"
#include <iostream>

int main(int argc, char const *argv[])
{
    if(argc > 2){
        std::cerr << "Usage: " << argv[0] << " " << "filename" << std::endl;
        return -1;
    }
    Lox lox;
    if (argc == 2){
        lox.run_source_file(argv[1]);
    }
    else{
        lox.run_prompt();
    }
    return 0;
}
