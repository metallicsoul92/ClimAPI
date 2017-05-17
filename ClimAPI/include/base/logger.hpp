#ifndef LOGGER_HPP
#define LOGGER_HPP

#include <iosfwd>

namespace clim{
    namespace base{
        class Logger{

            //public internal items
        public:
            enum LogLevel{
               VERBOSE,
               LOG,
               WARNING,
               CRITICAL,
               ERROR
           };

            static char *logLevelToString(LogLevel log);

            enum FileAttr{
                APPEND,OVERWRITE,FROMEND
            };

            private:
            const char *m_fileName;
            std::ofstream *m_stream;

            public:
            //Constructors
            Logger();
            Logger(const char * filename);
            Logger(const char * filename,FileAttr attributes);

            Logger(const Logger& log) = delete; // cant be copied
            Logger operator=(const Logger &log) = delete;

            Logger(Logger && log) = delete; // cant be moved
            Logger operator=(Logger && log) = delete;

            //Deconstructor
            ~Logger();

            void write(const char * message, LogLevel level);




};
}
}
#endif // LOGGER_H
