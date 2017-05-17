#ifndef REF_HPP
#define REF_HPP

namespace clim{
    namespace base{

    template<typename T>
    class reference{
    private:
        T &m_Var;

    public:
        reference();
        reference(T &data);
        reference(T &&move);

        T &Var()const;
        T &getVar();


    };

    template<typename T>
    reference<T>::reference()
    {
        m_Var = new T();
    }

    template<typename T>
    reference<T>::reference(T &data):m_Var(data){}



    template<typename T>
    reference<T>::reference(T&& move):m_Var(std::move(move))
    {
        move = nullptr;
    }

    template<typename T>
    T &reference<T>::Var() const
    {
        return m_Var;
    }

    template<typename T>
    T &reference<T>::getVar()
    {
        return m_Var;
    }
    }
}


#endif // REF_HPP
