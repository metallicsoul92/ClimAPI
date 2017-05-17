#include "../../include/base/file.hpp"

#include <fstream>
#include <iostream>

#ifdef __WIN32
    #define DELIMITER "\\"
#else
    #define DELIMITER "/"
#endif

namespace clim{
    namespace base{

    File::~File()
    {
        m_fileStream->close();

    }

    File::File(char *name, char *path):m_name(name),m_directory(path)
      ,m_isOpen(false),m_isReadable(false),m_isWritable(false)
    {

    }

    File::File(char *name, char *path, bool readable, bool writable):
        m_name(name),m_directory(path),m_isOpen(false),m_isReadable(readable),m_isWritable(writable)
    {

    }

    void File::open()
    {
        if(m_name == nullptr|| m_directory == nullptr){
            std:: cout << "Error in opening File... No File Name or Path Specified!";
        };
        std::string fullPath = std::string(m_directory);
        fullPath.append(DELIMITER).append(m_name);
        //Time for nasty if statements :/
        int fileCase = 0;
        m_isReadable ? fileCase++ : fileCase ;
        m_isWritable ? fileCase+=2 : fileCase ;

        switch(fileCase){
            case 1:
            m_fileStream->open(fullPath,std::ios::in);
            break;
        case 2:
        m_fileStream->open(fullPath,std::ios::out);
        break;
        case 3:
        m_fileStream->open(fullPath,std::ios::in | std::ios::out);
        break;
        default:
            std::cout << "Error, File is neither Readable nor Writable!";
            break;
        }

        m_isOpen = true;
    }

    std::fstream *File::fileStream() const
    {
        return m_fileStream;
    }

    char *File::name() const
    {
        return m_name;
    }

    void File::setName(char *name)
    {
        m_name = name;
    }

    char *File::directory() const
    {
        return m_directory;
    }

    void File::setDirectory(char *directory)
    {
        m_directory = directory;
    }

    bool File::isOpen() const
    {
        return m_isOpen;
    }

    bool File::isReadable() const
    {
        return m_isReadable;
    }

    bool File::isWritable() const
    {
        return m_isWritable;
    }

    }
}
