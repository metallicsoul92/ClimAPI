#ifndef SIGNAL_HPP
#define SIGNAL_HPP

#include <functional>

namespace clim{
   namespace base{


     class Observable;

     class baseSignal{
     private:
         Observable *m_parent;
     public:
         baseSignal(Observable *parent);
         baseSignal(const baseSignal &copy);
         baseSignal(baseSignal &&move);
         baseSignal& operator=(const baseSignal &copy);
        ~baseSignal() = default;
         Observable *getParent();
         Observable *parent() const;
         void setParent(Observable *parent);
     };



     template <class>
     class Signal:baseSignal{};

     template <class T, class ... Args>
class Signal<T(Args...)>: public baseSignal
{
private:

  std::function<T(Args...)> &m_func;

public:
  Signal(Observable *parent);
  Signal(Observable *parent, std::function<T(Args...)> func);
  ~Signal() = default;
  std::function<T (Args...)> &func() const;
  void setFunc(const std::function<T (Args...)> &func);
  T operator()(Args...args);

  bool operator==(Signal & other){
    return parent() == other.parent() && m_func == other.func();
  }
};




template<class T, class ... Args>
std::function<T (Args...)> &Signal<T(Args...)>::func() const
{
  return m_func;
}

template<class T, class ... Args>
void Signal<T(Args...)>::setFunc(const std::function<T (Args...)> &func)
{
  m_func = func;
}

template<class T, class ... Args>
T Signal<T(Args...)>::operator()(Args...args)
{
  m_func(args...);
}

template<class T, class ... Args>
Signal<T(Args...)>::Signal(Observable *parent): baseSignal(parent),
  m_func(std::function<T(Args...)>())
{

}

template<class T, class ... Args>
Signal<T(Args...)>::Signal(Observable *parent, std::function<T(Args ...)> func):
  baseSignal(parent),m_func(func)
{

}

   }
}


#endif // INCLUDEASESIGNAL_H
