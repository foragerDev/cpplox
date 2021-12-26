#include "Lox.hpp"
#include "Scanner.hpp"

#include <fstream>
#include <sstream>
#include <iostream>

void Lox::run_source_file(const std::string& path){
    std::string source = read_source_file(path);
    std::cout << source << std::endl;
    //Run the code here.
    run(source);
}

void Lox::run_prompt(){
    std::string buffer;
    for(;;){
        std::cout << "> ";
        std::cin >> buffer;
        if(std::cin.eof()) break;
        Scanner scanner(buffer);
//        auto result = scanner.scan_tokens();
        run(buffer);
    }
}

std::string Lox::read_source_file(const std::string& path){
    std::ifstream file(path);
    std::stringstream stream;
    stream << file.rdbuf();

    return stream.str();
}

void Lox::run(const std::string& source){
    std::cout << "I am working on it bro" << std::endl;
}