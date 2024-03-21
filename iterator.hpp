#ifndef _ITERATOR_H_
#define _ITERATOR_H_

#include <type_traits>//should be removed later

namespace vastina{

typedef unsigned long ptrdiff_t;

template<
    class Categoty,
    class Ty,
    class Diff_Ty = ptrdiff_t,
    class Pointer = Ty*,
    class Reference = Ty& >
struct iterator
{
    typedef Categoty    iterator_category;
    typedef Ty          value_type;
    typedef Diff_Ty     difference_type;
    typedef Pointer     pointer;
    typedef Reference   reference;
};



}

#endif // _ITERATOR_H_