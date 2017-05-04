#ifndef HASHVALUE_HPP
#define HASHVALUE_HPP


namespace clim{

    namespace base{

    template <typename T>
    class HashValue{

    private:
        unsigned int m_key;
        T m_value;

    public:
        HashValue(unsigned int key,T val): m_key(key),m_value(val){}

        void setKey(unsigned int k){this->m_key = k;}
        void setValue(T val){this->m_value = val;}

        unsigned int getKey(){return this->m_key;}
        unsigned int Key()const {return this->m_key;}

        T getValue(){return this->m_value;}
        const T Value()const {return this->m_value;}

    };


    }

}


#endif // HASHVALUE_HPP
