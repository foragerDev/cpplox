#ifndef _LOX_
#define _LOX_
#include <string>
class Lox
{

public:
    void run_source_file(const std::string &filename);
    void run_prompt();

private:
    void run(const std::string &source);
    std::string read_source_file(const std::string &filename);

    bool m_had_error{false};
};

#endif // !_LOX_
