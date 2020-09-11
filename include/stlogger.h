#ifndef STLOGGER_H
#define STLOGGER_H
#include <string>
#include <iostream>

class STLogger
{
public:
    STLogger(std::ostream*);
    STLogger(std::string str);
    STLogger();
#define log(str) __log(str,__FILE__,__PRETTY_FUNCTION__,__LINE__) // void log(std::string); this should be used.
    void __log(std::string,std::string,std::string,int);
    ~STLogger();
private:
    std::ostream *m_os{};
    static std::string logInfoTime();
    static std::string logInfoLocation(std::string _file_name,std::string _func_name,int _line_number);
};

#endif // STLOGGER_H
