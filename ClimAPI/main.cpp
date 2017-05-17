#include <QCoreApplication>
#include <QObject>
#include "include/math/matrix.hpp"
#include "include/math/vector.hpp"
#include "include/base/Array.hpp"
#include "include/base/Pair.hpp"
#include "include/base/metastruct.hpp"
#include "include/base/hashmap.hpp"
#include "include/base/base.hpp"
#include "include/math/math.hpp"
#include "include/base/linkedList.hpp"
#include "include/base/singleton.hpp"
#include "include/base/ref.hpp"
#include "include/base/logger.hpp"
#include "include/base/ByteArray.hpp"
#include "include/base/hex.hpp"
#include <omp.h>


const std::string caeserCipher(const std::string data, int amount){
    std::string temp;

    for(char d : data){
        temp.push_back((char)((int)d+amount));
    }

    return temp;

}

double power(double base, int exp){
    if(exp == 1){
        return base;
    }else
        return base * power(base, exp-1);
}




#include <iostream>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    clim::base::Logger log("ClimLogger.txt",clim::base::Logger::APPEND);
    CREATE_CLASS_4PARAM(climTest,name,std::string,age,int ,test2,float,test3,char const *)
    log.write("Hello World!",clim::base::Logger::VERBOSE);
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


    clim::base::pair<std::string, std::string> nameVariable("Name","Clim");
    clim::base::pair<std::string, int> ageVariable("Age",24);
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

#define OS WINDOWS


   std::cout << "HELLO " STRINGIFY(OS) << std::endl;


   std::cout << std::endl << std::endl;
   std::cout << "==========================================";
   std::cout << std::endl << std::endl<< std::endl << std::endl<< std::endl << std::endl;

   std::cout << power(10,5) << std::endl;
   delete temp;

   clim::base::ByteArray *bytes = new clim::base::ByteArray();
   bytes->append((uint8_t)15);
   bytes->append((uint8_t)23);
   bytes->append((uint8_t)55);
   bytes->append((uint8_t)43);

   clim::base::Hex<uint8_t> test2 = clim::base::Hex<uint8_t>(65U);

   std::cout << "Test2 Variable : " << +test2.getVar();
   std::cout << std::endl << "Test2Hex: " << test2.toString() << std::endl;

   std::cout << bytes->toString();
   std::cout << bytes->toHexString();


    return 0;
}

