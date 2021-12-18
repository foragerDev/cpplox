#include "Error.hpp"

Error::Error(std::size_t col, std::size_t line, const std::string &message)
    : m_col(col), m_line(line), m_message(message){};


void report() const{


}
