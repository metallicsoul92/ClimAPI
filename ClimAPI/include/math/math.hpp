#ifndef MATH_HPP
#define MATH_HPP

namespace clim{

    namespace math{

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


    }

}


#endif // MATH_HPP
