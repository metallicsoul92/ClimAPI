#ifndef SINGLETON_HPP
#define SINGLETON_HPP

#include<memory>
namespace clim{

    namespace base{

    template<class T>
    class Singleton{

    private:
       static Singleton<T> *m_inst;
       static T *m_instType;
        Singleton<T>(){
            if(m_instType == nullptr){
                m_instType = new T();
            }
        }

    public:
        Singleton<T>(Singleton<T> const&) =delete;
        Singleton<T>& operator=(Singleton<T> const&) = delete;
        T *inst(){ return m_instType;}

        static std::shared_ptr<Singleton<T>> instanceShared(){


            if(m_inst == nullptr){
                static std::shared_ptr<Singleton<T>> inst{new Singleton<T>};
                m_inst = &inst;
            }
            return inst;
        }

        static Singleton<T> instanceSingleton(){
            if(m_inst == nullptr){
                m_inst = Singleton<T>();
            }
            return m_inst;
        }
        static T instanceType(){
            if(m_inst == nullptr){
                m_inst = Singleton<T>();
            }
            return m_inst->instanceType();
            }


        };
    }
}

#endif // SINGLETON_HPP
