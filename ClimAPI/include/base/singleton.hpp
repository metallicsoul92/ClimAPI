#ifndef SINGLETON_HPP
#define SINGLETON_HPP

#include<memory>
namespace clim{

    namespace base{

    template<class T>
    class Singleton{

    private:
        Singleton<T>(){}

    public:
        Singleton<T>(Singleton<T> const&) =delete;
        Singleton<T>& operator=(Singleton<T> const&) = delete;
        static std::shared_ptr<Singleton<T>> instance(){
            static std::shared_ptr<Singleton<T>> inst{new Singleton<T>};
            return inst;
        }
    };


    }
}

#endif // SINGLETON_HPP
