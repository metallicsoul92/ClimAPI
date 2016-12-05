#ifndef MATRIX_HPP_
#define MATRIX_HPP_

namespace clim{

namespace math {

    template <typename t, unsigned int row, unsigned int column>
    class matrix{

    private:
        t   m_data[column][row];


    public:
        //Constructors
        matrix();
        matrix(const t data[column][row]);
        //Destructors
        ~matrix();

        //setter
        void setData(const unsigned int tcolumn, const unsigned int trow, t data);

        //getters
        t getData(const unsigned int tcolumn, const unsigned int trow);
        t getAllData();


    };

    template <typename t,unsigned int column, unsigned int row>
    t matrix<t,column,row>::getAllData(){return m_data;}

    template <typename t,unsigned int column, unsigned int row>
    void matrix<t,column,row>::setData(const unsigned int tcolumn, const unsigned int trow, t data)
    {
        m_data[tcolumn][trow] = data;
    }

    template <typename t,unsigned int column, unsigned int row>
    t matrix<t,column,row>::getData(const unsigned int tcolumn, const unsigned int trow){ return m_data[tcolumn][trow];}



}



}



#endif //Matrix.hpp
