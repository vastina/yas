#ifndef _STRING_H_
#define _STRING_H_

#include <alloca.h>
#include <cstdlib>
#include <cstring>
#include <iostream>

#include "temp.hpp"

namespace vastina
{

template<typename Char_t>
class m_basic_string{

public:
    typedef size_t size_type;


private:
    Char_t* m_data;
    size_type m_size;

    // enum { _local_capacity = 15 / sizeof(Char_t) };
    // union string_union{
    //     size_type m_capacity;
    //     Char_t m_local_buffer[_local_capacity+1];
    // } m_union;
    // 以后再说。。。
    
public:
    m_basic_string() : m_size(0), m_data(nullptr){};
    m_basic_string(const Char_t* str) : m_size(strlen(str)){
        m_data = new Char_t[m_size+1];
        memcpy(m_data, str, m_size);
    }
    m_basic_string(const m_basic_string& str);
    m_basic_string(m_basic_string&& str);

    constexpr m_basic_string& append(const Char_t* str){
        size_type len = strlen(str);
        if(true)
            construct(m_data+m_size, len);
        else{

        }
        memcpy(m_data+m_size, str, len);
        m_size += len; //this is really not thread safe
        return *this;
    }

    constexpr m_basic_string& append(const m_basic_string& str){
        return append(str.m_data());
    }

    constexpr size_type size() const{
        return m_size;
    }

    friend std::ostream& operator<<(std::ostream& out, const m_basic_string<char>& str);
};

std::ostream& operator<<(std::ostream& out, const m_basic_string<char>& str){
    out << str.m_data;
    return out;
}

}


#endif // _STRING_H_