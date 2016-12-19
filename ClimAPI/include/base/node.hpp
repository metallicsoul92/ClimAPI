#ifndef NODE_HPP
#define NODE_HPP

namespace clim{
    namespace base{

    template <typename T>
    class sNode{
    private:
        T m_data;
        sNode<T> *m_next;

    public:
        sNode():m_data((T)NULL),m_next(nullptr){}
        sNode(T data):m_data(data),m_next(nullptr){}
        sNode(T data,sNode<T>*next):m_data(data),m_next(next){}
        sNode(sNode<T> &&move):m_data(std::move(move.getData())),
                               m_next(std::move(move.getNext()))
        {}


        void setData(T data){this->m_data = data;}
        void setNext(sNode<T> *next){this->m_next =next;}

        T getData(){return m_data;}
        T Data()const {return m_data;}

        sNode<T> *getNext(){return m_next;}
        sNode<T> *Next()const{return m_next;}
    };

    template <typename T>
    class dNode{
    private:
        T m_data;
        dNode<T> *m_next;
        dNode<T> *m_last;

    public:
        dNode():m_data((T)NULL),m_next(nullptr),m_last(nullptr){}
        dNode(T data):m_data(data),m_next(nullptr),m_last(nullptr){}
        dNode(T data,dNode<T>*next):m_data(data),m_next(next),m_last(nullptr){}
        dNode(T data,dNode<T>*next, dNote<T> *last):m_data(data),m_next(next),m_last(last){}
        dNode(dNode<T> &&move):m_data(std::move(move.getData())),
                               m_next(std::move(move.getNext())),
                               m_last(std::move(move.getLast()))
        {}


        void setData(T data){this->m_data = data;}
        void setNext(dNode<T> *next){this->m_next =next;}
        void setLast(dNode<T> *last){this->m_last = last;}

        T getData(){return m_data;}
        T Data()const {return m_data;}

        dNode<T> *getNext(){return m_next;}
        dNode<T> *Next()const{return m_next;}

        dNode<T> *getLast(){return m_last;}
        dNode<T> *Last()const{return m_last;}
    };

    }
}


#endif // NODE_HPP
