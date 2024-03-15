#include <iostream>
#include <thread>

#define call(fn, ...) fn(__VA_ARGS__)

enum class STATE {
    START,
    CONTINUE,
    STOP
};

//__LINE__, __FILE__ and __func__ are predefined macros in C++.
void coroutine() {
    static int i;
    static STATE state = STATE::START;
    switch (state) {
        case STATE::START:
            for (i = 0; i < 10; i++) {
                state = STATE::CONTINUE;
                //submit([](const std::string& s, int i){std::cout << s << i <<'\n';}, "coroutine(): ", i);
                call([](const std::string& s, int i){std::cout << s << i <<'\n';}, "coroutine(): ", i);
                return;
        case STATE::CONTINUE:
                std::cout << "continue from stop place last time\n";
            }
    }
}

int main() {
    coroutine();
    std::thread t([]{coroutine();});    t.join();
    std::jthread jt([]{coroutine();});
    coroutine();
}