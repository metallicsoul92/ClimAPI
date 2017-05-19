#ifndef NODE_HPP
#define NODE_HPP

namespace clim{
    namespace base{

    template <typename T>
    class sNode{
    private:
        T m_data;
        sNode<T> *m_next;
        sNode<T> *m_iter;

    public:
        sNode():m_data((T)NULL),m_next(nullptr),m_iter(this){

        }
        sNode(T data):m_data(data),m_next(nullptr),m_iter(this){}
        sNode(T data,sNode<T>*next):m_data(data),m_next(next),m_iter(this){}
        sNode(sNode<T> &&move):m_data(std::move(move.getData())),
                               m_next(std::move(move.getNext())),
                               m_iter(std::move(move.getIter()))
        {}

        sNode<T> *getTail(){
            sNode<T> *temp = this;
            while(temp->Next() != nullptr){
                temp = temp->Next();
            }
            return temp;
        }

        void setData(T data){this->m_data = data;}
        void setNext(sNode<T> *next){this->m_next =next;}

        T getData(){return m_data;}
        T Data()const {return m_data;}

        sNode<T> *getNext(){return m_next;}
        sNode<T> *Next()const{return m_next;}

        sNode<T> *find(T data){
            sNode<T> *temp = this;
            if(temp->Data() == data){
                return temp;
            }else
                while(temp->Next() != nullptr){
                    if(temp->Next()->Data() != data){
                        temp = temp->Next();
                    }else
                        return temp;
                }

        }
        sNode<T> *getIter()
        {
            return m_iter;
        }
        sNode<T> *iter() const  {
            return m_iter;
        }
        void setIter(sNode<T> *iter)
        {
            m_iter = iter;
        }
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
        dNode(T data,dNode<T>*next, dNode<T> *last):m_data(data),m_next(next),m_last(last){}
        dNode(dNode<T> &&move):m_data(std::move(move.getData())),
                               m_next(std::move(move.getNext())),
                               m_last(std::move(move.getLast()))
        {}


        void setData(T data){this->m_data = data;}
        void setNext(dNode<T> *next){this->m_next =next;}
        void setLast(dNode<T> *last){this->m_last = last;}

        T getData(){return m_data;}
        T Data()const {return m_data;}

        dNode<T> *getHead(){
            dNode *temp = this;
            while(temp->m_last != nullptr){
                temp = temp->getLast();
            }
            return temp;
        }
        dNode<T> *getTail(){
            dNode *temp = this;
            while(temp->m_next != nullptr){
                temp = temp->getNext();
            }
            return temp;
        }

        dNode<T> *getNext(){return m_next;}
        dNode<T> *Next()const{return m_next;}

        dNode<T> *getLast(){return m_last;}
        dNode<T> *Last()const{return m_last;}
    };

    template <typename T>
    class tNode{
    private:
        T m_data;
        tNode *m_previous;
        tNode *m_left;
        tNode *m_right;

     public:
        tNode();
        tNode(const T data);
        tNode(const T data, tNode *previous=nullptr,tNode *left=nullptr,
              tNode *right =nullptr);
        tNode(tNode &&move){
            this = move;
        }

        tNode(const tNode &copy){
            this = copy;
        }

        tNode &operator=(tNode &&move){
            this->m_data = move.getData();
            this->m_left = move.getLeft();
            this->m_right = move.getRight();
            this->m_previous = move.Previous();

            move.setData(nullptr);
            move.setLeft(nullptr);
            move.setRight(nullptr);
            move.setPrevious(nullptr);

            move = nullptr;
        }

        tNode &operator=(const tNode &copy){
            this->setData(copy.getData());
            this->setLeft(copy.getLeft());
            this->setRight(copy.getRight());
            this->setPrevious(copy.getPrevious());
        }

        ~tNode();

        T data() const
        {
            return m_data;
        }
        T getData(){
            return m_data;
        }

        void setData(const T &data)
        {
            m_data = data;
        }
        tNode *Previous(){
            return m_previous;
        }

        tNode *getPrevious() const
        {
            return m_previous;
        }
        void setPrevious(tNode *previous)
        {
            m_previous = previous;
        }
        tNode *Right(){
            return m_right;
        }

        tNode *getRight() const
        {
            return m_right;
        }
        void setRight(tNode *right)
        {
            m_right = right;
        }
        tNode *Left(){
            return m_left;
        }

        tNode *getLeft() const
        {
            return m_left;
        }
        void setLeft(tNode *left)
        {
            m_left = left;
        }
    };



















    }
}


#endif // NODE_HPP
