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



#include <iostream>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);


   clim::base::Hex<uint8_t> test8 = clim::base::Hex<uint8_t>(65U);
   clim::base::Hex<uint16_t> test16 = clim::base::Hex<uint16_t>(15432U);
   clim::base::Hex<uint32_t> test32 = clim::base::Hex<uint32_t>(35492343U);

   std::cout << "Test8 Variable : " << +test8.getVar();
   std::cout << std::endl << "Test2Hex: " << test8.toString() << std::endl;

   std::cout << "Test16 Variable : " << +test16.getVar();
   std::cout << std::endl << "Test16 to Hex: " << test16.toString() << std::endl;

   std::cout << "Test32 Variable : " << +test32.getVar();
   std::cout << std::endl << "Test32 to Hex: " << test32.toString() << std::endl;




    return 0;
}

