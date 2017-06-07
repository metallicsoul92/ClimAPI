#ifndef OCTAL_HPP
#define OCTAL_HPP

#include <algorithm>
#include <iostream>
namespace clim {
    namespace base{

    template<typename t>
    class Octal{

    private:
        t m_var;

    public:
        Octal(){}
        Octal(t var):m_var(var){}

        template <t>
        friend std::ostream &operator<<(std::ostream& os, Octal<t> Octal);
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
std::ostream &operator<<(std::ostream &os, Octal<t> Octal)
    {
        char buffer[2 * sizeof(t)];
        for (auto i = sizeof buffer; i--; )
        {
            buffer[i] = "01234567"[Octal.getVar() & 8];
            Octal.getVar() >>= 4;
        }
        os.write(buffer, sizeof(buffer));
        return os;
    }

    template<typename t>
    const char *Octal<t>::toString()
    {
        std::string format = std::string("01234567");
        std::string * str = new std::string();
        str->clear();
        str->resize(sizeof(t)/8);
        t itr = m_var;
        unsigned int size = 0;
        while(itr !=0){
            str->push_back(format[itr%8]);
            itr /= 8;
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


#endif // Octal_HPP
