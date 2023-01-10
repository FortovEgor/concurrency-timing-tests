#include <iostream>
#include <vector>
#include <pthread.h>  // c lib for posix threads
#include "profiler.h"  // handwritten simple profiler
#define QUANTITY 50'000'000

// int primes[10] = { 2, 3, 5, 7, 11, 13, 17, 19, 23, 29 };
std::vector<int> numbers;

void* routine(void* arg) {
    int index = *(int*)arg;
    int sum = 0;
    for (int j = 0; j < QUANTITY / 2; j++) {
        sum += numbers[index + j];
    }
    std::cout << "Local sum = " << sum << "\n";
    *(int*)arg = sum;
    return arg;
}

int main(int argc, char* argv[]) {
    numbers.reserve(QUANTITY);
    for (int i = 0; i < QUANTITY; ++i) {
        numbers.push_back(i % 19);
    }

    pthread_t th[2];
    START;
    for (int i = 0; i < 2; i++) {
        int* a = new int();
        *a = i * 5;
        if (pthread_create(&th[i], NULL, &routine, a) != 0) {
            perror("Failed to create thread");
        }
    }

    int globalSum = 0;
    for (int i = 0; i < 2; ++i) {
        int* r;
        if (pthread_join(th[i], (void**) &r) != 0) {
            perror("Failed to join thread");
        }
        globalSum += *r;
        free(r);
    }
    std::cout << "Execution time of two threads working in parallel: ";
    ENDP;

    START;
    int globalSumWithOnlyMainThread = 0;
    for (int elem : numbers) {
        globalSumWithOnlyMainThread += elem;
    }
    std::cout << "Execution time of main thread (no parallelism): ";
    ENDP;

    std::cout << "Global sum (2 parallel threads): " << globalSum << "\n";
    std::cout << "Global sum (main thread): " << globalSumWithOnlyMainThread << "\n";
    if (globalSum != globalSumWithOnlyMainThread) {
        std::cout << "Something happened: sums are different\n";
        return 1;
    }
    return 0;
}