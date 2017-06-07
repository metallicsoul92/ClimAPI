#include "../../include/base/sigslotconnection.h"


#include "../../include/base/observable.h"
#include "../../include/base/signal.hpp"
#include "../../include/base/slot.hpp"

namespace clim{
  namespace base{

    baseSignal *SigSlotConnection::baseSignal() const
    {
      return m_baseSignal;
    }

    void SigSlotConnection::setBaseSignal(class baseSignal *baseSignal)
    {
      m_baseSignal = baseSignal;
    }

    Observable *SigSlotConnection::slotObserver() const
    {
      return m_slotObserver;
    }

    void SigSlotConnection::setSlotObserver(Observable *slotObserver)
    {
      m_slotObserver = slotObserver;
    }

    baseSlot *SigSlotConnection::baseSlot() const
    {
      return m_baseSlot;
    }

    void SigSlotConnection::setBaseSlot(class baseSlot *baseSlot)
    {
      m_baseSlot = baseSlot;
    }

    Observable *SigSlotConnection::sigObserver() const
    {
      return m_sigObserver;
    }

    void SigSlotConnection::setSigObserver(Observable *sigObserver)
    {
      m_sigObserver = sigObserver;
    }


  }
}
