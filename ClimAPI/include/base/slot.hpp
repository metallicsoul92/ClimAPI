#ifndef SLOT_HPP
#define SLOT_HPP

#include <functional>

namespace clim{
  namespace base{

    class baseSignal;

    class Observable;

    class baseSlot{
    private:
        Observable *m_parent;
    public:
        baseSlot(Observable *parent);
        baseSlot(const baseSlot& copy);
        baseSlot(baseSlot &&mov);
        ~baseSlot() = default;
        Observable *getParent();
        Observable *parent() const;
        void setParent(Observable *parent);
    };

    template<class>
    class Slot : baseSlot{};

    template<class T,class ...Args>
    class Slot<T(Args...)> : baseSlot{
    private:
      std::function<T(Args...)> &m_func;
      baseSignal *m_signal;
      bool m_connected;

    public:
      Slot(Observable &parent);  // isConnected == false
      Slot(Observable &parent,
           std::function<T(Args...)> func);  // isConnected == false
      Slot(Observable &parent,
           std::function<T(Args...)> func,
           baseSignal *signal); // isConnected == true
      ~Slot() = default;

      bool operator==(Slot & other){
        return m_func == other.func() && m_signal == other.signal() && parent() ==other.parent();
      }


      std::function<T (Args...)> &func() const;
      void setFunc(const std::function<T (Args...)> &func);
      baseSignal *signal() const;
      void setSignal(baseSignal *signal);
      bool connected() ;
      void setConnected(bool connected);
  };

  template<class T, class ... Args>
  Slot<T(Args...)>::Slot(Observable &parent, std::function<T(Args...)> func, baseSignal *signal):
    baseSlot(parent),m_func(func),m_signal(signal),m_connected(true)
  {

  }

  template<class T, class... Args>
  Slot<T (Args...)>::Slot(Observable &parent, std::function<T (Args...)> func):
    baseSlot(parent),m_func(func),m_connected(false)
  {

  }

  template<class T, class ... Args>
  void Slot<T (Args...)>::setFunc(const std::function<T (Args...)> &func)
  {
    this->m_func = func;
  }


  template<class T, class ... Args>
  std::function<T (Args...)> &Slot<T (Args...)>::func() const
  {
    return this->m_func;
  }

  template<class T, class ... Args>
  void Slot<T(Args...)>::setConnected(bool connected)
  {
    this->m_connected = connected;
  }

  template<class T, class... Args>
  bool Slot<T(Args ...)>::connected()
  {
    return this->m_connected;

  }

  template<class T, class ... Args>
  Slot<T(Args ...)>::Slot(Observable &parent):baseSlot(parent),
      m_connected(false)
    {

    }

  }
}


#endif // SLOT_H
