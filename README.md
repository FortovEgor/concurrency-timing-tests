# concurrency-timing-tests
This repo is done in order to check concurrent evaluations efficiency by using handwritten profiler (see profile.h file)

Компилиция программы, RELEASE:
```sh
g++ test1.cpp -std=c++14
```
Note 1. Compile WITHOUT optimizations (i.e. without -O1, -O2, -O3 or -O-fast)
Note 2. Do not forget -std=c++14 flag. Otherwise your code will fail to deal with syntax sugar like perfoming integer as 1'000 or 50'000'000.

Компилиция программы, DEBUG:
```sh
g++ test1.cpp -Wall -Werror -std=c++14
```
Notes. -||-.
