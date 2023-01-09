#pragma once
#include <chrono>

/* PROFILER CODE */
typedef long long unsigned int ll;
std::chrono::time_point<std::chrono::high_resolution_clock> startTime, stopTime;
std::chrono::duration<ll, std::micro> duration_time;
#define MICROSECS_IN_SEC 1'000'000
#define MILISECS_IN_SEC 1'000
#define MICROSECS_IN_MILISEC MILISECS_IN_SEC
#define START \
        startTime = std::chrono::high_resolution_clock::now();
#define END \
        stopTime = std::chrono::high_resolution_clock::now(); \
        duration_time = std::chrono::duration_cast<std::chrono::microseconds>(stopTime - startTime);
#define PRINT_TIME \
        std::cout << (double) duration_time.count() / MICROSECS_IN_MILISEC << " milisecs\n";
#define PRINT_TIME_IN_MICROSECS \
        std::cout << (double) duration_time.count() << " microsecs\n";
#define PRINT_TIME_IN_SECS \
        std::cout << (double) duration_time.count() / (MICROSECS_IN_MILISEC * MILISECS_IN_SEC)<< " secs\n";
#define HELP \
        std::cout << "------- Simple fortov profiler -------\n"; \
        std::cout << "Simple profiler for measuring execution time in .cpp programms;\nCommands: START, END, ENDP(=ENDR=ENDF=ENDf), PRINT_TIME, PRINT_TIME_IN_MICROSECS, PRINT_TIME_IN_SECS\n"; \
        std::cout << "dev's email: ekfortov@edu.hse.ru";
#define ENDP \
        stopTime = std::chrono::high_resolution_clock::now(); \
        duration_time = std::chrono::duration_cast<std::chrono::microseconds>(stopTime - startTime); \
        std::cout << (double) duration_time.count() / MICROSECS_IN_MILISEC << " milisecs\n";
#define ENDR ENTP
#define ENDF ENDP
#define ENDf ENDP
