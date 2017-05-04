#include <QCoreApplication>
#include <QObject>
#include "include/math/matrix.hpp"
#include "include/math/vector.hpp"
#include "include/base/Array.hpp"
#include "include/base/bivar.hpp"
#include "include/base/metastruct.hpp"
#include "include/base/hashmap.hpp"
#include "include/base/base.hpp"
#include "include/math/math.hpp"
#include "include/base/linkedList.hpp"
#include "include/base/singleton.hpp"
#include <omp.h>




const std::string caeserCipher(const std::string data, int amount){
    std::string temp;

    for(char d : data){
        temp.push_back((char)((int)d+amount));
    }

    return temp;

}




#include <iostream>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    CREATE_CLASS_4PARAM(climTest,name,std::string,age,int ,test2,float,test3,char const *)

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

    std::cout << "Collatz Conjecture for number 153:" << clim::math::collazConjectureSteps(153) << std::endl;

   // std::cout << temp->toString();
   // std::cout << sar->toString();
   // std::cout << std::endl;
  //  std::cout << std::endl << ar.toString();

    delete sar;
   std::cout << "Hello World!" << std::endl;

#define OS WINDOWS10


   CREATE_CUSTOM_CLASS_INTERNAL_BEGIN(MyClass)
   SET_PRIVATE_MEMBER_VARIABLE(std::string,name)
   SET_PRIVATE_MEMBER_VARIABLE(int,age)
   SET_PRIVATE_MEMBER_VARIABLE(float,weight)
   SET_PUBLIC_INTERNAL()
   GETSET(std::string,name)
   GETSET(int,age)
   GETSET(float,weight)
   CREATE_CUSTOM_CLASS_INTERNAL_END()



MyClass Person;
   Person.Setname("Muj");
   Person.Setage(34);
   Person.Setweight(70.53);

   std::cout << "Person: Name:" << Person.Getname() << std::endl
             << "        Age:" << Person.Getage() << std::endl
             << "        Weight:" << Person.Getweight() << std::endl;








   std::cout << "HELLO " STRINGIFY(OS) << std::endl;

   delete temp;
    return 0;
}
