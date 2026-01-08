# thesis-benchmarks

## C Programs
Each C program has been compiled with the following:

`gcc -O3 -march=native -std=c11 -o executable_name program.c`

## C++ Programs

Each C++ program has been compiled with the following:

`g++ -O3 -march=native -std=c++17 -o executable_name program.cpp`

## Rust Programs
Each Rust program has been compiled without Cargo, with the following:

`rustc -C opt-level=3 -o executable_name program.rs`

## Benchmarks

To gather program performances, I've used [Hyperfine](https://github.com/sharkdp/hyperfine), with the following parameters:

`hyperfine --warmup 3 --runs 50 --shell=none --export-markdown results_fib.md './fib_c' './fib_cpp' './fib_rust'`

To gather RAM consumptions, I've used the following command:

`/usr/bin/time -al ./fib_cpp 2>&1`

Reading the value `maximum resident set size` referred as Byte.