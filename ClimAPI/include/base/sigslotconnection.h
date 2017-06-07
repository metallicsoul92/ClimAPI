#ifndef SIGSLOTCONNECTION_H
#define SIGSLOTCONNECTION_H




namespace clim{
  namespace base{

    class Observable;
    class baseSignal;
    class baseSlot;


    class SigSlotConnection{

    private:
      Observable *m_sigObserver;
      baseSignal *m_baseSignal;
      Observable *m_slotObserver;
      baseSlot *m_baseSlot;

    public:
      SigSlotConnection( Observable *sigObserver,
                          baseSignal *baseSignal,
                          Observable *slotObserver,
                           baseSlot *baseSlot);
      ~SigSlotConnection() = default;

      Observable *sigObserver() const;
      void setSigObserver(Observable *sigObserver);
      baseSignal *baseSignal() const;
      void setBaseSignal(class baseSignal *baseSignal);
      Observable *slotObserver() const;
      void setSlotObserver(Observable *slotObserver);
      baseSlot *baseSlot() const;
      void setBaseSlot(class baseSlot *baseSlot);
    };


  }
}


#endif // SIGSLOTCONNECTION_H
