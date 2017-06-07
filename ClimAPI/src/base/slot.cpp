#include "../../include/base/slot.hpp"
#include "../../include/base/signal.hpp"
#include "../../include/base/observable.h"

namespace clim{
  namespace base{

    baseSlot::baseSlot(const baseSlot &copy):m_parent(copy.parent())
    {

    }

    baseSlot::baseSlot(baseSlot &&mov):m_parent(mov.getParent()){

    }

    Observable *baseSlot::getParent()
    {
      return m_parent;
    }

    Observable *baseSlot::parent() const
    {
      return m_parent;
    }

    void baseSlot::setParent(Observable *parent)
    {
      m_parent = parent;
    }





  }
}
