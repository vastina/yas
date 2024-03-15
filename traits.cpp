#include <iostream>
#include <chrono>

struct __ture_type { };
struct __false_type { };

struct __a_type {
    typedef __ture_type _is_a_type;
    typedef __false_type _is_b_type;
};

struct aa : public __a_type {
    int k = 114514;
};

struct __b_type {
    typedef __false_type _is_a_type;
    typedef __ture_type _is_b_type;
};

struct bb : public __b_type {
    int k = 1919810;
};

struct __c_type {
    typedef __false_type _is_a_type;
    typedef __false_type _is_b_type;
};

struct cc : public __c_type {
    int k = 1453;
};

template <typename T>
void test(T& t, const __a_type&) {
    //std::cout << "a type: " << t.k << std::endl;
    ++t.k;
};

template <typename T>
void test(T& t, const __b_type&) {
    //std::cout << "b type: " << t.k << std::endl;
    ++t.k;
};

template <typename T>
void test(T& t, const __c_type&) {
    //std::cout << "c type: " << t.k << std::endl;
    ++t.k;
};

template <typename T>
void interface(T t) {
    test(t, t);
};

int main(){
    aa a;   bb b;   cc c;
    interface(a);
    interface(b);
    interface(c);

auto t1 = std::chrono::system_clock::now();
    for (int i = 0; i < 10000000; i++) {
        interface(a);
        interface(b);
        interface(c);
    }
auto t2 = std::chrono::system_clock::now();
std::clog << "time: " << std::chrono::duration_cast<std::chrono::milliseconds>(t2 - t1).count() << "ms" << std::endl;

t1 = std::chrono::system_clock::now();
    for(int i = 0; i < 10000000; i++) {
        test(a, a);
        test(b, b);
        test(c, c);
    }
t2 = std::chrono::system_clock::now();
std::clog << "time: " << std::chrono::duration_cast<std::chrono::milliseconds>(t2 - t1).count() << "ms" << std::endl;

t1 = std::chrono::system_clock::now();
    for(int i = 0; i < 10000000; i++) {
        ++a.k;
        ++b.k;
        ++c.k;
    }
t2 = std::chrono::system_clock::now();
std::clog << "time: " << std::chrono::duration_cast<std::chrono::milliseconds>(t2 - t1).count() << "ms" << std::endl;


    return 0;
}
