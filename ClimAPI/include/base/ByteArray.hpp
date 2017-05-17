#ifndef BYTEARRAY_HPP
#define BYTEARRAY_HPP

#include <stdint.h>
#include <iosfwd>
namespace clim{

    namespace base{

   template<typename t>
    class Array;

    class ByteArray{
    private:
        Array<uint8_t> *m_data;
        size_t m_size;

    public:
        ByteArray();
        ByteArray(Array<uint8_t> *data);
        ByteArray(Array<uint8_t> *data,size_t size);
        ByteArray(const ByteArray &copy);
        ByteArray(ByteArray &&move);

        ByteArray &operator=(const ByteArray &copy);
        ByteArray &operator=(ByteArray &&move);

        ~ByteArray();

        uint8_t operator[](unsigned int index);

        void append(uint8_t byte);
        void append(const ByteArray &bytes);
        void append(uint8_t *bytes);

        Array<uint8_t> *data() const;
        void setData(Array<uint8_t> *data);
        size_t size() const;
        void setSize(const size_t &size);

        const char * toString();
        const char * toHexString();
    };


    }
}
#endif // BYTEARRAY_HPP
