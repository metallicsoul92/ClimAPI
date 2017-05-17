#ifndef INCLUDEASEILE_HPP
#define INCLUDEASEILE_HPP

#include <iosfwd>

namespace clim  {
    namespace base{

    class File
    {
    public:

        File(char *name,char *path);
        File(char *name,char *path,bool readable =true, bool writable =false);

        ~File();

        void open();

        std::fstream *fileStream() const;

        char *name() const;
        void setName(char *name);

        char *directory() const;
        void setDirectory(char *directory);

        bool isOpen() const;

        bool isReadable() const;

        bool isWritable() const;

    private:
        std::fstream *m_fileStream;
        char * m_name;
        char * m_directory;

        bool m_isOpen;
        bool m_isReadable;
        bool m_isWritable;

    };

    }
}



#endif // INCLUDEASEILE_HPP
