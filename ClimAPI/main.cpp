#include <QCoreApplication>
#include <QObject>

#include <omp.h>

#include "include/base/logger.hpp"
#include "include/base/file.hpp"
#include "include/base/Array.hpp"
#include "include/base/signal.hpp"
#include "include/base/slot.hpp"
#include "include/base/observable.h"
#include "include/base/ref.hpp"

#include <iostream>
#include <fstream>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);


    clim::base::Array<int> *clim = clim::base::createNewArray<int,10>();


    clim::base::reference<clim::base::Array<int>*> ref(clim);

    ref.getVar()->push(10);
    ref.getVar()->push(15);
    std::cout << ref.getVar()->getData(0);

    clim::base::Logger log("Test.txt",clim::base::Logger::APPEND);

    log.write("This is just a test",clim::base::Logger::LOG);

    clim::base::File file("Test.txt",
                          "C:\\Users\\metal\\OneDrive\\Documents\\GitHub\\ClimAPI\\build-ClimAPI-Desktop_Qt_5_8_0_MinGW_32bit3-Debug"
                          ,true,true);

  file.open();

  std::string line;
  while(std::getline(*file.getFStream(),line) ){
      std::cout << line << "\n";
    }

    return 0;
}

