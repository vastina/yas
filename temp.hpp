#ifndef _TEMP_H_
#define _TEMP_H_

#include <new>
#include <alloca.h>

//something to be finished will be stored here first
template<typename ty>
void construct(ty* prt, const ty& val){
    new (prt) ty(val);
}

template<typename ty>
void construct(ty* prt, ty&& val){
    new (prt) ty(std::move(val));
}

template<typename ty>
void construct(ty* prt, unsigned long long length){
    new (prt) ty[length];
}

#endif