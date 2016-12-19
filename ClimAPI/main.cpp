#include <QCoreApplication>
#include "include/math/matrix.hpp"
#include "include/math/vector.hpp"
#include "include/base/Array.hpp"
#include "include/base/bivar.hpp"
#include "include/base/metastruct.hpp"
#include "include/base/hashmap.hpp"
#include <omp.h>


#define createNewDataType(DTNAME,VAR1,VAR1T,VAR2,VAR2T,VAR3,VAR3T,VAR4,VAR4T)\
        class DTNAME{\
        private:\
        VAR1T VAR1; \
        VAR2T VAR2; \
        VAR3T VAR3;\
        VAR4T VAR4;\
        public:\
        DTNAME(VAR1T a,VAR2T b,VAR3T c,VAR4T d):VAR1(a),VAR2(b),VAR3(c),VAR4(d){}\
        ~DTNAME(){}\
        VAR1T getVAR1(){return VAR1;}\
        VAR2T getVAR2(){return VAR2;}\
        VAR3T getVAR3(){return VAR3;}\
        VAR4T getVAR4(){return VAR4;}\
        void setVAR1(VAR1T dat){VAR1 = dat;}\
        void setVAR2(VAR2T dat){VAR2 = dat;}\
        void setVAR3(VAR3T dat){VAR3 = dat;}\
        void setVAR4(VAR4T dat){VAR4 = dat;}\
};\

const std::string caeserCipher(const std::string data, int amount){
    std::string temp;

    for(char d : data){
        temp.push_back((char)((int)d+amount));
    }

    return temp;

}

int collazConjectureSteps(unsigned int i){

    int k=0;

    while(i !=1){
        if(i %2 == 0){
            std::cout << "i is even, divide: ";
            i /= 2;
            std::cout << i<< std::endl;
            k++;
        }else{
            std::cout << "i is odd, multiply :";
            i *=3;
            i +=1;
            std::cout << i<< std::endl;
            k++;
    }
    }

    return k;

}


#include <iostream>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    createNewDataType(climTest,name,std::string,age,int ,test2,float,test3,char *);

    std::cout << "Hello World!" <<std::endl << "Ciphered by 2:" << std::endl << caeserCipher("Hello World!",2) << std::endl;
    std::cout << caeserCipher(caeserCipher("Hello World!",2),-2) << std::endl;
    climTest test("Clim",24,3.14,"Data");
    std::cout << test.getVAR1() << " : "<< test.getVAR2() << " : "<< test.getVAR3() << " : "<< test.getVAR4() << " : ";

    int tempdata[5] = {9,15,32,53,26};
    clim::base::Array<int> ar = clim::base::Array<int>(10);
    ar.push(10);
    ar.push(-50);
    ar.push(30);
    ar.push(-20);

    clim::base::bivar<std::string, std::string> nameVariable("Name","Clim");
    clim::base::bivar<std::string, int> ageVariable("Age",24);
    std::cout << nameVariable.getFirst() << ":" << nameVariable.getSecond() << std::endl;
    std::cout << ageVariable.getFirst() << ":" << ageVariable.getSecond() << std::endl;


    clim::math::vector<int,5> *temp = new clim::math::vector<int,5>(tempdata);

    clim::base::Array<const char *> *sar =  new clim::base::Array<const char *>("Hello world!");
    sar->push("This Is");
    sar->push("Clim..");

    std::cout << "Collatz Conjecture for number 153:" << collazConjectureSteps(153) << std::endl;

   // std::cout << temp->toString();
   // std::cout << sar->toString();
   // std::cout << std::endl;
  //  std::cout << std::endl << ar.toString();

    delete sar;
   std::cout << "Hello World!" << std::endl;


   delete temp;
    return 0;
}
