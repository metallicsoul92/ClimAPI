#include <QCoreApplication>
#include "include/math/matrix.hpp"
#include "include/math/vector.hpp"
#include "include/base/Array.hpp"
#include "include/base/bivar.hpp"
#include "include/base/metastruct.hpp"

#include <iostream>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

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

    std::cout << temp->toString();
    std::cout << sar->toString();
    std::cout << std::endl;
    std::cout << std::endl << ar.toString();

    delete sar;
   std::cout << "Hello World!" << std::endl;


   delete temp;
    return 0;
}
