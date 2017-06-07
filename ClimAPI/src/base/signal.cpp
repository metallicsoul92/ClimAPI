#include "../../include/base/signal.hpp"
#include "../../include/base/observable.h"


namespace clim{
  namespace base{

    void baseSignal::setParent(Observable *parent)
    {
      m_parent = parent;
    }


    baseSignal::baseSignal(const baseSignal &copy):m_parent(copy.parent())
    {

    }

    baseSignal::baseSignal(baseSignal &&move):m_parent(move.m_parent)
    {

    }

    baseSignal &baseSignal::operator=(const baseSignal &copy)
    {
      this->m_parent = copy.parent();

      return *this;

    }

    Observable *baseSignal::getParent()
    {
      return m_parent;
    }

    Observable *clim::base::baseSignal::parent() const
    {
      return m_parent;
    }






  }
}
