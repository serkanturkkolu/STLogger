#include "stlogger.h"
#include <ctime>
#include <cctype>
#include <fstream>

STLogger::STLogger(std::ostream* os)
{
    m_os = new std::ostream{os->rdbuf()};
    m_os->setf(std::ios::boolalpha);
    m_os->setf(std::ios::showbase);

}

STLogger::STLogger(std::string str)
{
    m_os = new std::ofstream(str,std::ios::out | std::ios::app | std::ios::binary | std::ios::ate);
    m_os->setf(std::ios::boolalpha);
    m_os->setf(std::ios::showbase);
}

STLogger::STLogger():STLogger("log.txt") //current directory
{

}

void STLogger::__log(std::string str,std::string _file_name,std::string _func_name,int _line_number){
    *m_os << logInfoTime() << " => " << logInfoLocation(_file_name,_func_name,_line_number) << str << std::endl;
}

STLogger::~STLogger(){
    *m_os << logInfoTime() << " => " << " Program ended." << std::endl;
    if(m_os){
        std::ofstream *t_fst = (std::ofstream*)m_os;
        if(t_fst){
            if(t_fst->is_open()){
                t_fst->close();
            }
        }
        delete m_os;
    }

}

std::string STLogger::logInfoTime(){
    auto t=time(nullptr);
    struct tm *tim=localtime(&t);
    char *temp=asctime(tim) ;
    for(unsigned int i=0;i<strlen(temp);++i){
        temp[i]=std::toupper(temp[i]);
    }

    temp[strlen(temp)-1]=0;
    return std::string(temp);
}

std::string STLogger::logInfoLocation(std::string _file_name,std::string _func_name,int _line_number){
    std::string s_temp;
    s_temp += "File: [";
    s_temp += _file_name;
    s_temp += "] , Function: [";
    s_temp += _func_name;
    s_temp += "] , Line: [";
    s_temp += std::to_string(_line_number);
    s_temp += "] : ";
    return s_temp;
}

