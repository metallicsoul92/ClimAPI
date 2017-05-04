#ifndef METASTRUCT_HPP
#define METASTRUCT_HPP

#include <iostream>
#include "bivar.hpp"
#include "Array.hpp"

namespace clim{

    namespace base{

    template<typename t>
    struct variableData{
        bivar<std::string,t> Data;
        std::string getName(){ return this->Data.x();}
        t getVariable(){ return this->Data.y();}


        variableData(bivar<std::string ,t > data):Data(data){}
        variableData(std::string name, t data):Data(bivar<std::string,t>(name,data)){}
        variableData(variableData && data):Data(data.Data){data = nullptr;}

    };

    /**
      This will work of the bivar's principle of 2 diffrent types. the first will always be a string
      */
    template <typename t>
    class metaStruct{

    private:
        Array<variableData<t>> m_data;
    public:
        metaStruct(Array<variableData<t>> data):m_data(data.getAllData()){}
        metaStruct(metaStruct<t> && data):m_data(data.data()){
        data = nullptr;
        }
          variableData<t> data() const
        {
            return m_data;
        }
        void setData(const variableData<t> &data)
        {
            m_data = data;
        }

        void addMemberVariables(const variableData<t> data){
            m_data.push(data);
        }


    };







    }


}


#endif // METASTRUCT_HPP
