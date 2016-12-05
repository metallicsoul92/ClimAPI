#ifndef BIVAR_HPP
#define BIVAR_HPP

namespace clim{

    namespace base{

    template <typename First,typename Second>
    class bivar{

    private:
        First m_first;
        Second m_second;


    public:
        bivar():m_first(First()),m_second(Second()){}
        bivar(First Args1 ,Second Args2): m_first(Args1),m_second(Args2){}
        ~bivar(){}

        void setFirst(const First &f){ m_first = f;}
        void setSecond(const Second &s){ m_second =s;}

        First first()const{return m_first;}
        First getFirst(){return m_first;}

        Second second()const{return m_second;}
        Second getSecond(){return m_second;}



    };




    }


}

#endif // BIVAR_HPP
