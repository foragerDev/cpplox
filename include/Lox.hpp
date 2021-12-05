#include <string>

class Lox
{

public:
    void run_source_file(const std::string &filename);
    void run_prompt();

private:
    void run(const std::string &source);

    bool m_had_error{false};
};