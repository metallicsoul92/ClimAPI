#ifndef HASHMAP_HPP
#define HASHMAP_HPP

#include<iostream>
#include<cstdlib>
#include<string>
#include<cstdio>

#include "hashvalue.hpp"

namespace clim{

    namespace base{

    template <typename T>
    class HashMap{

    private:
        HashValue<T> **m_Map;
        unsigned int m_size;

    public:
        HashMap(unsigned int amount);
        ~HashMap()

    {

            for (unsigned int i = 0; i < this->m_size; i++)

            {

                if (m_Map[i] != NULL)

                    delete m_Map[i];

                delete[] m_Map;

            }
}
            unsigned int hashFunction(unsigned int key)
            {
            return key % this->m_size;}

        void insert(unsigned int k,T v);
        T search(unsigned int k);
        void remove(unsigned int k);


    };

    template<typename T>
    HashMap<T>::HashMap(unsigned int amount){
        this->m_Map = new HashValue<T> *[amount];
        this->m_size = amount;
        for(int i = 0;i < amount;i++){
            m_Map[i] = NULL;
        }
    }

    template<typename T>
    void HashMap<T>::insert(unsigned int k, T v)
    {
        int hash = this->hashFunction(k);

        while (m_Map[hash] != NULL && m_Map[hash]->Key() != k)

            {

                hash = this->hashFunction(hash + 1);

            }

            if (m_Map[hash] != NULL)

                delete m_Map[hash];

            m_Map[hash] = new HashValue<T>(k, v);

    }
    template <typename T>
    T HashMap<T>::search(unsigned int k)
    {

        int  hash = hashFunction(k);

        while (m_Map[hash] != NULL && m_Map[hash]->Key() != k)

        {

            hash = this->hashFunction(hash + 1);

        }

        if (m_Map[hash] == NULL)

            return -1;

        else

            return m_Map[hash]->Value();

    }
    template <typename T>
    void HashMap<T>::remove(unsigned int k)
    {

        int hash = this->hashFunction(k);

        while (m_Map[hash] != NULL)

        {

            if (m_Map[hash]->Key() == k)

                break;

            hash = this->hashFunction(hash + 1);

        }

            if (m_Map[hash] == NULL)

        {

                std::cout<<"No Element found at key "<<k<<std::endl;

                return;

            }

            else

            {

                delete m_Map[hash];

            }

            std::cout<<"Element Deleted"<<std::endl;

        }


    }

}

#endif // HASHMAP_HPP
