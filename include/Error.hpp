#ifndef __ERROR__
#define __ERROR__

#include <cstddef>
#include <string>

class Error
{
public:
    Error(std::size_t col, std::size_t line, const std::string &message);
    void report() const;

private:
    std::size_t m_col;
    std::size_t m_line;
    std::string m_message;
};

#endif // !__ERROR__
