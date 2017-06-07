#ifndef VARIANT_HPP
#define VARIANT_HPP

#include <inttypes.h>
#include <iosfwd>
#include <utility>


namespace clim{
  namespace base{
  enum class DataType{
    BOOL, BOOLPTR, UINT8, UINT16, UINT32, UINT64,
    INT8, INT16, INT32, INT64, FLOAT, DOUBLE,
    UINT8PTR, UINT16PTR, UINT32PTR, UINT64PTR,
    INT8PTR, INT16PTR, INT32PTR, INT64PTR, FLOATPTR, DOUBLEPTR,
    VOIDPTR ,USRDATA, USRDATAPTR
  };


  struct nullDataType{

    nullDataType(){}
    nullDataType(const nullDataType &ndt)= default;
    ~nullDataType()= default;
  };


  template <typename UserData = nullDataType >
    union customVariantData{
      //Value types
      bool asbool;
      uint8_t asuint8;
      uint16_t asuint16;
      uint32_t asuint32;
      uint64_t asuint64;
      int8_t asint8;
      int16_t asint16;
      int32_t asint32;
      int64_t asint64;
      float asfloat;
      double asdouble;

      //pointer types
      bool *asboolptr;
      uint8_t *asuint8ptr;
      uint16_t *asuint16ptr;
      uint32_t *asuint32ptr;
      uint64_t *asuint64ptr;
      int8_t *asint8ptr;
      int16_t *asint16ptr;
      int32_t *asint32ptr;
      int64_t *asint64ptr;
      float *asfloatptr;
      double *asdoubleptr;
      void* asvoidptr;

      //UserData type
      UserData asusrdata;
      UserData *asusrdataptr;

      customVariantData(const bool b):asbool(b){}
      customVariantData(bool* bp):asboolptr(bp){}
      customVariantData(const uint8_t &u8):asuint8(u8){}
      customVariantData(uint8_t *u8ptr):asuint8ptr(u8ptr){}
      customVariantData(const uint16_t &u16):asuint16(u16){}
      customVariantData(uint16_t *u16ptr):asuint16ptr(u16ptr){}
      customVariantData(const uint32_t &u32):asuint32(u32){}
      customVariantData(uint32_t *u32ptr):asuint32ptr(u32ptr){}
      customVariantData(const uint64_t &u64):asuint64(u64){}
      customVariantData(uint64_t *u64ptr):asuint64ptr(u64ptr){}
      customVariantData(const int8_t &i8):asint8(i8){}
      customVariantData(int8_t *i8ptr):asint8ptr(i8ptr){}
      customVariantData(const int16_t &i16):asint16(i16){}
      customVariantData(int16_t *i16ptr):asint16ptr(i16ptr){}
      customVariantData(const int32_t &i32):asint32(i32){}
      customVariantData(int32_t *i32ptr):asint32ptr(i32ptr){}
      customVariantData(const int64_t &i64):asint64(i64){}
      customVariantData(int64_t *i64ptr):asint64ptr(i64ptr){}
      customVariantData(const UserData &usr):asusrdata(UserData(usr)){}
      customVariantData(UserData *usrptr):asusrdataptr(new UserData(usrptr)){}
    };


    template<typename usr = nullDataType>
    class variant{
    private:
      DataType m_datatype;
      customVariantData<usr> m_data;
    public:
      variant():m_datatype(DataType::UINT8),m_data(0U){}
      variant(const bool b):m_datatype(DataType::BOOL),m_data(b){}
      variant(const uint8_t &u8):m_datatype(DataType::UINT8),m_data(u8){}
      variant(const uint16_t &u16):m_datatype(DataType::UINT16),m_data(u16){}
      variant(const uint32_t &u32):m_datatype(DataType::UINT32),m_data(u32){}
      variant(const uint64_t &u64):m_datatype(DataType::UINT64),m_data(u64){}
      variant(const int8_t &i8):m_datatype(DataType::INT8),m_data(i8){}
      variant(const int16_t &i16):m_datatype(DataType::INT16),m_data(i16){}
      variant(const int32_t &i32):m_datatype(DataType::INT32),m_data(i32){}
      variant(const int64_t &i64):m_datatype(DataType::INT64),m_data(i64){}
      variant(const float &f):m_datatype(DataType::FLOAT),m_data(f){}
      variant(const double &d):m_datatype(DataType::DOUBLE),m_data(d){}
      variant(usr &u):m_datatype(DataType::USRDATA),m_data(u){}

      variant(bool* bptr):m_datatype(DataType::BOOLPTR),m_data(bptr){}
      variant(uint8_t* u8ptr):m_datatype(DataType::UINT8PTR),m_data(u8ptr){}
      variant(uint16_t* u16ptr):m_datatype(DataType::UINT16PTR),m_data(u16ptr){}
      variant(uint32_t* u32ptr):m_datatype(DataType::UINT32PTR),m_data(u32ptr){}
      variant(uint64_t* u64ptr):m_datatype(DataType::UINT64PTR),m_data(u64ptr){}
      variant(int8_t* i8ptr):m_datatype(DataType::INT8PTR),m_data(i8ptr){}
      variant(int16_t* i16ptr):m_datatype(DataType::INT16PTR),m_data(i16ptr){}
      variant(int32_t* i32ptr):m_datatype(DataType::INT32PTR),m_data(i32ptr){}
      variant(int64_t* i64ptr):m_datatype(DataType::INT64PTR),m_data(i64ptr){}
      variant(float* fptr):m_datatype(DataType::FLOATPTR),m_data(fptr){}
      variant(double* dptr):m_datatype(DataType::DOUBLEPTR),m_data(dptr){}
      variant(void* vptr):m_datatype(DataType::VOIDPTR),m_data(vptr){}
      variant(usr* uptr):m_datatype(DataType::USRDATAPTR),m_data(uptr){}
      variant(const variant &copy):m_datatype(copy.datatype()),m_data(copy.data()){}
      variant(variant &&move):m_datatype(std::move(move.getDataType())),m_data(std::move(move.getData())){}

      ~variant() = default;
      DataType dataType() const;
      DataType getDataType();
      void setDatatype(const DataType &datatype);
      customVariantData<usr> getData();
      customVariantData<usr> data() const;

      void setData(const customVariantData<usr> &data);
    };

    template <typename usr>
    customVariantData<usr> variant<usr>::data() const
    {
      return m_data;
    }
   template <typename usr>
    void variant<usr>::setData(const customVariantData<usr> &data)
    {
      m_data = data;
    }
   template <typename usr>
    DataType variant<usr>::dataType() const
    {
      return m_datatype;
    }

    template<typename usr>
    DataType variant<usr>::getDataType()
    {
      return m_datatype;
    }
    template <typename usr>
    void variant<usr>::setDatatype(const DataType &datatype)
    {
      m_datatype = datatype;
    }

    template<typename usr>
    customVariantData<usr> variant<usr>::getData()
    {
        return m_data;
    }

  }
}


#endif // VARIANT_HPP
