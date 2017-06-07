#ifndef OBSERVABLE_H
#define OBSERVABLE_H

#include "Array.hpp"

namespace clim{
  namespace base{

    class baseSignal;
    class baseSlot;


    class Observable
    {
    private:
    Array<baseSignal*> *m_sigArray;
    Array<baseSlot*> *m_slotArray;

    public:
      Observable();
      ~Observable();
      void addSignal(baseSignal* sig);
      void addSlot(baseSlot * slot);

      void removeSignal(int index);
      void removeSignal(baseSignal * sig);
      void removeSlot(int index);
      void removeSlot(baseSlot *slot);

    };

  }
}
#endif // INCLUDEASEOBSERVABLE_H
