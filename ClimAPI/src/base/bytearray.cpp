#include "../../include/base/ByteArray.hpp"
#include "../../include/base/Array.hpp"
#include "../../include/base/hex.hpp"
namespace clim{


namespace base{

void clim::base::ByteArray::setData(Array<uint8_t> *data)
{
    m_data = data;
}

ByteArray::ByteArray()
{
    m_data = new Array<uint8_t>();
}

ByteArray::ByteArray(Array<uint8_t> *data):m_data(data),m_size(data->getSize())
{

}

ByteArray::ByteArray(Array<uint8_t> *data, size_t size):m_data(data),m_size(size)
{

}

ByteArray::ByteArray(const ByteArray &copy):m_data(copy.data()),m_size(copy.size())
{

}

ByteArray::ByteArray(ByteArray &&move):m_data(std::move(move.data())),m_size(std::move(move.size()))
{

}

ByteArray &ByteArray::operator=(const ByteArray &copy)
{
    this->m_data = copy.data();
    this->m_size = copy.size();
    return *this;
}

ByteArray &ByteArray::operator=(ByteArray &&move)
{
    this->m_data = move.m_data;
    this->m_size = move.m_size;
    move.~ByteArray();
    return *this;

}

ByteArray::~ByteArray()
{
    delete m_data;
}

uint8_t ByteArray::operator[](unsigned int index)
{
    return m_data->Data(index);
}

void ByteArray::append(uint8_t byte)
{
    m_data->push(byte);
}

void ByteArray::append(const ByteArray &bytes)
{
    for(unsigned int i = 0; i < bytes.data()->getLast();i++){
        m_data->push(bytes.data()->Data(i));
    }
}

void ByteArray::append(uint8_t *bytes)
{
         while(bytes != NULL){
             m_data->push(*bytes);
             bytes++;
         }
}

Array<uint8_t> *ByteArray::data() const
{
    return m_data;
}

void ByteArray::setSize(const size_t &size)
{
    m_size = size;
}

const char *ByteArray::toString()
{
    return m_data->toString();
}

const char *ByteArray::toHexString()
{
   // std::stringstream  *str = new std::stringstream();
    std::string *str = new std::string();
    Hex<uint8_t> byte;
    for(unsigned int i = 0; i<m_data->getLast();i++){
       byte =  Hex<uint8_t>(m_data->Data(i));
       str->append(byte.toString());
       str->append(" ");
    }
        const char * result = str->c_str();
        delete str;
    return result;
}

size_t ByteArray::size() const
{
    return m_size;
}


}
}
