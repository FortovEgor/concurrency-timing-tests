#include <iostream>
#include <pthread.h>  // c lib for posix threads
#include "profiler.h"  // handwritten simple profiler
#define CYCLES 1'000'000'000

void* func(void* arg1) {
    int temp = 0;
    for (int i = 0; i < CYCLES; ++i) {
        temp++;
    }
    std::cout << temp << "\n";
    return nullptr;
}

void* func2(void* arg1) {
    int temp = 0;
    for (int i = 0; i < CYCLES; ++i) {
        temp++;
    }
    std::cout << temp << "\n";
    return nullptr;
}


// compile WITHOUT optimizations (i.e. without -O1, -O2, -O3 or -O-fast)
// recommended for DEBUG:
// g++ test1.cpp -Wall -Werror -std=c++14
// recommended for RELEASE:
// g++ test1.cpp -std=c++14
// Note: c++ versions lower 14 do not support syntax sugar like 1'000, 1'000'000
// So compile with c++14 or higher
int main(void) {
    pthread_t th1, th2;
    START;
    pthread_create(&th1, NULL, &func, NULL);
    pthread_create(&th2, NULL, &func2, NULL);
    pthread_join(th1, NULL);
    pthread_join(th2, NULL);
    ENDP;


    START;
    func(nullptr);
    func2(nullptr);
    ENDP;

    
	return 0;
}
