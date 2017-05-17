#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <stdio.h>
#include <iostream>
#include <string>
#include <sstream>

namespace clim{

    namespace base{

    template <typename t>
    class Array{

    private:
        t *m_data;
        unsigned int m_size;
        unsigned int m_last;


    public:
        Array();
        //creating a generic constructor by the amount
        Array(unsigned int count);
        //creating a generic constructor by the type , default as 10 templates
        Array(const t &first);
        Array(const t *data, unsigned int amount):m_data(data),m_size(sizeof(data)),m_last(amount){}

        ~Array();

        void resize(unsigned int sz);

        t *getAllData();
        const t *AllData() const;
        t getData(unsigned int index);
        t operator[](unsigned int index){ return m_data[index];}

        Array<t>& operator=(const Array<t>& other){
            if(this->m_data != nullptr)
                delete[] m_data;

            this->m_data = other->Data();
            this->m_size = other->Size();
            this->m_last = other->Last();
        }

        const t Data(unsigned int index)const;
        t pop();
        const t popc();
        unsigned int getLast() const;
        unsigned int getSize() const;

        void setSize(unsigned int value);
        void setLast(unsigned int value);
        void push(t next);

        const char * toString();
    };

    template <typename t>
    void Array<t>::setSize(unsigned int value)
    {
        m_size = value;
    }
    template <typename t>
    unsigned int Array<t>::getLast() const
    {
        return m_last;
    }

    template <typename t>
    unsigned int Array<t>::getSize() const
    {
        return m_size;
    }

    template <typename t>
    void Array<t>::setLast(unsigned int value)
    {
        m_last = value;
    }

    template <typename t>
    Array<t>::Array()
    {
        m_data = new t[10];
        m_size = 10;
        m_last = 0;

    }
    template<typename t>
    Array<t>::Array(unsigned int count)
    {
        m_data = new t[count];
        m_size = count;
        m_last = 0;
    }
    template <typename t>
    Array<t>::Array(const t &first)
    {
        m_data = new t[10];
        m_data[0] = first;
        m_size = 10;
        m_last = 1;

    }


    template <typename t>
    Array<t>::~Array()
    {
        free(this->m_data);
    }

    template<typename t>
    void Array<t>::resize(unsigned int sz)
    {
        //Allocate memory double the size
        t* newData = new t[sz];
        //copy the memory into the newData
        for(unsigned int i =0; i < m_size;i++){
            newData[i] = m_data[i];
        }
        //reset the size of the array
        this->m_size = sz;
        delete []m_data;
        m_data = newData;
    }


    template <typename t>
    t *Array<t>::getAllData()
    {
        return m_data;
    }



    template <typename t>
    const t *Array<t>::AllData() const
    {
        return m_data;
    }

    template <typename t>
    t Array<t>::getData(unsigned int index)
    {
        return this->m_data[index];
    }

    template <typename t>
    const t Array<t>::Data(unsigned int index) const
    {
        return this->m_data[index];
    }

    template <typename t>
    t Array<t>::pop()
    {
        t temp;
        temp = m_data[m_last-1];
        m_data[m_last-1] = NULL;
        this->m_last--;
        return temp;
    }

    template <typename t>
    void Array<t>::push(t next)
    {
        if(m_last == m_size){
           resize(m_size*2);
        }
        this->m_data[m_last] = next;
        this->m_last++;
    }

    template <typename t>
    const char *Array<t>::toString()
    {
        std::stringstream str;
        for(unsigned int i =0; i < m_last; i++){
           str << m_data[i] << " ";
        }
        str << "\n";
        return str.str().c_str();

    }

    template <typename t>
    const t Array<t>::popc()
    {
        const t temp = m_data[m_last-1];
        m_data[m_last-1] = NULL;
        this->m_last--;
        return temp;
    }




    }


}


#endif // ARRAY_HPP
