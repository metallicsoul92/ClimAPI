#include "../../include/base/logger.hpp"
#include <fstream>
#include <chrono>


namespace clim{
namespace base{

const char *Logger::logLevelToString(Logger::LogLevel log){
    switch(log){
    case VERBOSE:
        return "Verbose: ";
    case LOG:
        return "Log: ";
    case WARNING:
        return "Warning: ";
    case CRITICAL:
        return "Critical: ";
    case ERROR:
        return "Error: ";
    }
    return "Unknown Log Type";
}

Logger::Logger():m_fileName("DefaultLog.txt")
{
   m_stream = new std::ofstream;
   m_stream->open(m_fileName,std::ios_base::out |std::ios_base::app);

}

Logger::Logger(const char *filename): m_fileName(filename)
{
    m_stream = new std::ofstream;
    m_stream->open(filename,std::ios_base::out |std::ios_base::app);
}

Logger::Logger(const char *filename, Logger::FileAttr attributes):m_fileName(filename)
{
        m_stream = new std::ofstream;
        switch(attributes){
        case APPEND:
            m_stream->open(filename,std::ios_base::out | std::ios_base::app);
            break;
        case OVERWRITE:
            m_stream->open(filename,std::ios_base::out |std::ios_base::trunc);
            break;
        case FROMEND:
            m_stream->open(filename,std::ios_base::out |std::ios_base::ate);
        break;
          default:
            break;
        }
}

Logger::~Logger()
{
    m_stream->close();
    delete m_stream;
}

void Logger::write(const char *message, Logger::LogLevel level)
{
    std::time_t time = std::chrono::system_clock::to_time_t(std::chrono::system_clock::now());

    *m_stream <<  std::ctime(&time)<< "\t" << logLevelToString(level) << "\t" << message << std::endl;
}



}
}
