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

                if (table[i] != NULL)

                    delete m_Map[i];

                delete[] m_Map;

            }
}
            unsigned int hashFunction(unsigned int key){
            return key % this->m_size;
        }

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
    void HashMap::insert(unsigned int k, T v)
    {
        int hash = hashFunction(k);

        while (m_Map[hash] != NULL && m_Map[hash]->Key() != k)

            {

                hash = hashFunction(hash + 1);

            }

            if (m_Map[hash] != NULL)

                delete table[hash];

            m_Map[hash] = new HashEntry<T>(k, v);

    }
    template <typename T>
    T HashMap::search(unsigned int k)
    {

        int  hash = HashFunc(k);

        while (m_Map[hash] != NULL && m_Map[hash]->Key() != k)

        {

            hash = hashFunction(hash + 1);

        }

        if (m_Map[hash] == NULL)

            return -1;

        else

            return m_Map[hash]->Value();

    }

    void HashMap::remove(unsigned int k)
    {

        int hash = HashFunc(key);

        while (m_Map[hash] != NULL)

        {

            if (m_Map[hash]->Key() == k)

                break;

            hash = hashFunction(hash + 1);

        }

            if (m_Map[hash] == NULL)

        {

                cout<<"No Element found at key "<<k<<endl;

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
