#ifndef VECTOR_HPP_
#define VECTOR_HPP_

#include <stdexcept>
#include <sstream>


namespace clim{

namespace math {

    template <typename t,unsigned int amount>
    class vector{

    private:
        t *m_data;

    public:

        unsigned int pamount = amount;
        //Constructors
        vector(t data[amount]);
        vector();

        //Destructors
        ~vector();


        //getters
        t getData(unsigned int index);
        t *getAllData();
        t Data(unsigned int index)const;
        t AllData()const;

        //setters
        void setData(unsigned int index, t data);

        //math operations
        vector add(const vector &a, const vector &b);
        vector add(const vector &a, const t &scalar);
        vector subtract(const vector &a, const vector &b);
        vector subtract(const vector &a, const t &scalar);
        vector multiply(const vector &a, const vector &b);
        vector multiply(const vector &a, const t &scalar);
        vector divide(const vector &a, const vector &b);
        vector divide(const vector &a, const t &scalar);


        //operator overloads
        vector operator+(const vector &b);
        vector operator+(const t &scalar);
        vector operator-(const vector &b);
        vector operator-(const t &scalar);
        vector operator*(const vector &b);
        vector operator*(const t &scalar);
        vector operator/(const vector &b);
        vector operator/(const t &scalar);

        std::string toString();

    };

    template <typename t,unsigned int amount>
    vector<t,amount>::vector( t data[amount])
    {
        for(unsigned int i = 0; i < amount ; i++){
            this->m_data[i] = data[i];
        }
    }

    template <typename t,unsigned int amount>
    vector<t,amount>::vector()
    {
        m_data = new t[amount];
    }

    template <typename t,unsigned int amount>
    vector<t,amount>::~vector<t,amount>()
    {
        if(m_data)
          delete [] m_data;
    }

    template <typename t,unsigned int amount>
    t vector<t,amount>::getData(unsigned int index)
    {
        return m_data[index];
    }


    template <typename t,unsigned int amount>
    t *vector<t,amount>::getAllData()
    {
        return m_data;
    }


    template <typename t,unsigned int amount>
    t vector<t,amount>::Data(unsigned int index) const
    {
        return m_data[index];
    }


    template <typename t,unsigned int amount>
    t vector<t,amount>::AllData() const
    {
        return m_data;
    }

    template <typename t,unsigned int amount>
    void vector<t,amount>::setData(unsigned int index, t data)
    {
        m_data[index] = data;
    }
    template <typename t,unsigned int amount>
    vector<t,amount> vector<t,amount>::operator+(const vector &b)
    {
        vector<t,amount> temp;
        for(unsigned int i = 0 ; i <amount ; i++){
            temp.setData(i,this->m_data[i]+b.getData(i));
        }
        return temp;

    }

    template <typename t,unsigned int amount>
    vector<t,amount> vector<t,amount>::operator+(const t &scalar)
    {
        vector<t,amount> temp;
        for(unsigned int i = 0 ; i <amount ; i++){
            temp.setData(i,this->m_data[i]+scalar);
        }
        return temp;

    }
    template <typename t,unsigned int amount>
    vector<t,amount> vector<t,amount>::operator-(const vector &b)
    {
        vector<t,amount> temp;
        for(unsigned int i = 0 ; i <amount ; i++){
            temp.setData(i,this->m_data[i]-b.getData(i));
        }
        return temp;

    }

    template <typename t,unsigned int amount>
    vector<t,amount> vector<t,amount>::operator-(const t &scalar)
    {
        vector<t,amount> temp;
        for(unsigned int i = 0 ; i <amount ; i++){
            temp.setData(i,this->m_data[i]-scalar);
        }
        return temp;

    }


    template <typename t,unsigned int amount>
    vector<t,amount> vector<t,amount>::operator*(const vector &b)
    {
        vector<t,amount> temp;
        for(unsigned int i = 0 ; i <amount ; i++){
            temp.setData(i,this->m_data[i]*b.getData(i));
        }
        return temp;

    }

    template <typename t,unsigned int amount>
    vector<t,amount> vector<t,amount>::operator*(const t &scalar)
    {
        vector<t,amount> temp;
        for(unsigned int i = 0 ; i <amount ; i++){
            temp.setData(i,this->m_data[i]*scalar);
        }
        return temp;

    }
    template <typename t,unsigned int amount>
    vector<t,amount> vector<t,amount>::operator/(const vector &b)
    {
        vector<t,amount> temp;
        for(unsigned int i = 0 ; i <amount ; i++){
            temp.setData(i,this->m_data[i]/b.getData(i));
        }
        return temp;

    }

    template <typename t,unsigned int amount>
    vector<t,amount> vector<t,amount>::operator/(const t &scalar)
    {
        vector<t,amount> temp;
        for(unsigned int i = 0 ; i <amount ; i++){
            temp.setData(i,this->m_data[i]/scalar);
        }
        return temp;

    }

    template <typename t,unsigned int amount>
    std::string vector<t,amount>::toString()
    {
     std::stringstream stream;
     std::string str("Vector Data: ");
     stream << std::endl;
     for(unsigned int i = 0;i < this->pamount; i++){
         stream << i << " : " << this->getData(i) << std::endl;
     }
     return str.append(stream.str());
    }




    template <typename t,unsigned int amount>
    vector<t,amount> vector<t,amount>::add(const vector<t,amount> &a, const vector<t,amount> &b)
    {
        vector<t,amount> temp;
        for(unsigned int i = 0 ; i <amount ; i++){
            temp.setData(i,a.getData(i)+b.getData(i));
        }
        return temp;

    }

    template <typename t,unsigned int amount>
    vector<t,amount> vector<t,amount>::add(const vector<t,amount> &a, const t &scalar)
    {
        vector<t,amount> temp;
        for(unsigned int i = 0 ; i <amount ; i++){
            temp.setData(i,a.getData(i)+scalar);
        }
        return temp;

    }

    template <typename t,unsigned int amount>
    vector<t,amount> vector<t,amount>::subtract(const vector<t,amount> &a, const vector<t,amount> &b)
    {
        vector<t,amount> temp;
        for(unsigned int i = 0 ; i <amount ; i++){
            temp.setData(i,a.getData(i)-b.getData(i));
        }
        return temp;

    }

    template <typename t,unsigned int amount>
    vector<t,amount> vector<t,amount>::subtract(const vector<t,amount> &a, const t &scalar)
    {
        vector<t,amount> temp;
        for(unsigned int i = 0 ; i <amount ; i++){
            temp.setData(i,a.getData(i)-scalar);
        }
        return temp;

    }


    template <typename t,unsigned int amount>
    vector<t,amount> vector<t,amount>::multiply(const vector<t,amount> &a, const vector<t,amount> &b)
    {
        vector<t,amount> temp;
        for(unsigned int i = 0 ; i <amount ; i++){
            temp.setData(i,a.getData(i)*b.getData(i));
        }
        return temp;

    }

    template <typename t,unsigned int amount>
    vector<t,amount> vector<t,amount>::multiply(const vector<t,amount> &a, const t &scalar)
    {
        vector<t,amount> temp;
        for(unsigned int i = 0 ; i <amount ; i++){
            temp.setData(i,a.getData(i)*scalar);
        }
        return temp;

    }

    template <typename t,unsigned int amount>
    vector<t,amount> vector<t,amount>::divide(const vector<t,amount> &a, const vector<t,amount> &b)
    {

        vector<t,amount> temp;
        for(unsigned int i = 0 ; i <amount ; i++){
            if (b.getData(i) == 0){
                throw std::runtime_error("Error dividing by zero");
                return;
            }
            temp.setData(i,a.getData(i)/b.getData(i));
        }
        return temp;

    }

    template <typename t,unsigned int amount>
    vector<t,amount> vector<t,amount>::divide(const vector<t,amount> &a, const t &scalar)
    {
        if(scalar == 0){
          throw std::runtime_error("Error dividing by zero");
          return;


        }

        vector<t,amount> temp;
        for(unsigned int i = 0 ; i <amount ; i++){
            temp.setData(i,a.getData(i)/scalar);
        }
        return temp;

    }

    }
}


#endif //Vector.hpp
