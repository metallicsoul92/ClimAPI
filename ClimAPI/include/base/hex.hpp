#ifndef HEX_HPP
#define HEX_HPP
#include <algorithm>
#include <ostream>
namespace clim {
    namespace base{

    template<typename t>
    class Hex{

    private:
        t m_var;

    public:
        Hex(){}
        Hex(t var):m_var(var){}

        friend std::ostream &operator<<(std::ostream& os, Hex<t> hex);
        const char * toString();

        t var() const
        {
            return m_var;
        }
        t &getVar()
        {
            return this->m_var;
        }
    };




template<typename t>
std::ostream &operator<<(std::ostream &os, Hex<t> hex)
    {
        char buffer[2 * sizeof(t)];
        for (auto i = sizeof buffer; i--; )
        {
            buffer[i] = "0123456789ABCDEF"[hex.getVar() & 15];
            hex.getVar() >>= 4;
        }
        os.write(buffer, sizeof(buffer));
        return os;
    }

    template<typename t>
    const char *Hex<t>::toString()
    {
        static char * format = "0123456789ABCDEF";
        std::string * str = new std::string();
        str->clear();
        str->resize(sizeof(t)/8);
        t itr = m_var;
        unsigned int size = 0;
        while(itr !=0){
            str->push_back(format[itr%16]);
            itr /= 16;
            size++;
        }
        str->append("\0");
        std::reverse(str->begin(),str->end());

            const char * result = str->c_str();

            delete str;
            return result;

    }

}
}


#endif // HEX_HPP
