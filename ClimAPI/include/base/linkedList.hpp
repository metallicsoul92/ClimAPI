#ifndef LINKEDLIST_HPP
#define LINKEDLIST_HPP

#include "node.hpp"
namespace clim{
    namespace base{

    template <typename t>
    class sLinkedList{

    private:
        sNode<t> *m_head;
        unsigned int m_count;

    public:
        sLinkedList(size_t capacity):m_head(new sNode<t>()),
                                     m_count(0){}
        sLinkedList(sNode<t> *head,size_t capacity):m_head(head)
        {
         unsigned int i = 0;
            while(head->getNext() != nullptr){
                i++;
                head = head->getNext();
            }
            m_count = i;
        }

        sLinkedList(const sLinkedList<t> *copy):m_head(copy->head()),
                                                m_count(copy->count()){

        }
        sNode<t> *operator[](int index){
            if(index >m_count){
                //Error check and break
                return nullptr;
            }else
            {
                int i = 0;
                sNode<t> *temp = m_head;
                while(i != m_count){
                    temp = temp->getNext();
                    i++;
                }
                 return temp;
            }

        }

        void push(sNode<t> *next){
                m_head->getTail()->setNext(next);
                m_count++;

        }

        sNode<t> *pop(){
            sNode<t> *temp = m_head->getTail();
             sNode<t> *temp2 = m_head;

             while(temp2->Next() != temp){
                 temp2 = temp2->getNext();
             }
                temp2->setNext(nullptr);
                m_count--;
                return temp;
        }

        sNode<t> *findValue(t value){
           return m_head->find(value);
        }

        unsigned int last() const
        {
            return m_count;
        }
        void setLast(unsigned int last)
        {
            m_count = last;
        }
        sNode<t> *head() const
        {
            return m_head;
        }
        void setHead(sNode<t> *head)
        {
            m_head = head;
        }
        unsigned int count() const
        {
            return m_count;
        }
        void setCount(unsigned int count)
        {
            m_count = count;
        }
    };


















    }}
#endif // LINKEDLIST_HPP
