#ifndef BASE_HPP
#define BASE_HPP


/**
  Pre-Processor Macros
  **/

//Dont know why i wrote this, literally this all could be done via templates
#define CREATE_CLASS_4PARAM(DTNAME,VAR1,VAR1T,VAR2,VAR2T,VAR3,VAR3T,VAR4,VAR4T)\
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
//Stringify and expand
#define UNEXPANDED_STRINGIFY(x) #x
#define STRINGIFY(x) UNEXPANDED_STRINGIFY(x)


//Macro-Class-Creation

#define CREATE_CUSTOM_CLASS_INTERNAL_BEGIN(DTNAME)\
    class DTNAME{\
    private:\

#define SET_PRIVATE_MEMBER_VARIABLE(DATATYPE,NAME)\
    DATATYPE m_##NAME;\

#define SET_PUBLIC_INTERNAL() public:


//I Didnt write this function, credits go to:
//https://cppkid.wordpress.com/2008/09/04/getters-and-setters-for-a-class-using-a-macro/
// I modified it to work with less spagetification (originally it had a private variable
//for the internal member, as well the public keyword
#define GETSET(type, var) \
   type Get##var() \
   {\
      return m_##var; \
   }\
   void Set##var(type val) \
   {\
      m_##var = val; \
   }
#define CREATE_CUSTOM_CLASS_INTERNAL_END() };

namespace clim{
    namespace base{

    template <typename t>
    inline const t toConst(t type){
        return const_cast<t>(type);
    }

    }
}



#endif // BASE_HPP
