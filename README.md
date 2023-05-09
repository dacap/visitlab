# visitlab

This benchmark compares [std::visit()](https://en.cppreference.com/w/cpp/utility/variant/visit)
vs. using a switch-case of [std::variant::index()](https://en.cppreference.com/w/cpp/utility/variant/index)
to do a specific task depending on the [std::variant](https://en.cppreference.com/w/cpp/utility/variant) type.

## Benchmark

It looks like `std::visit()` is faster on Windows (msvc) & macOS
(clang), and the switch-case is faster on Linux (gcc).

### Local Run

Compiler: `g++ (Ubuntu 11.3.0-1ubuntu1~22.04) 11.3.0`
Flags: `-O2 -g -DNDEBUG`

```
2023-05-09T16:19:06-03:00
Running ./visitlab
Run on (24 X 5100 MHz CPU s)
CPU Caches:
  L1 Data 48 KiB (x12)
  L1 Instruction 32 KiB (x12)
  L2 Unified 1280 KiB (x12)
  L3 Unified 30720 KiB (x1)
Load Average: 1.29, 0.96, 0.78
***WARNING*** CPU scaling is enabled, the benchmark real time measurements may be noisy and will incur extra overhead.
--------------------------------------------------------
Benchmark              Time             CPU   Iterations
--------------------------------------------------------
BM_Visit             325 ns          325 ns      2188033
BM_SwitchCase        317 ns          317 ns      2214635
```

### GitHub Actions

**Windows** (MSVC 19.34.31944.0)

```
2023-05-09T19:38:58+00:00
Running D:\a\visitlab\visitlab\build\visitlab.exe
Run on (2 X 2594 MHz CPU s)
CPU Caches:
  L1 Data 32 KiB (x2)
  L1 Instruction 32 KiB (x2)
  L2 Unified 1024 KiB (x2)
  L3 Unified 36608 KiB (x1)
--------------------------------------------------------
Benchmark              Time             CPU   Iterations
--------------------------------------------------------
BM_Visit            3418 ns         3376 ns       203636
BM_SwitchCase       3493 ns         3516 ns       213333
```

**macOS** (AppleClang 14.0.0.14000029)

```
2023-05-09T19:35:03+00:00
Running build/visitlab
Run on (3 X 3337 MHz CPU s)
CPU Caches:
  L1 Data 32 KiB
  L1 Instruction 32 KiB
  L2 Unified 256 KiB (x3)
  L3 Unified 12288 KiB
Load Average: 19.07, 10.54, 4.42
--------------------------------------------------------
Benchmark              Time             CPU   Iterations
--------------------------------------------------------
BM_Visit            1601 ns         1599 ns       438069
BM_SwitchCase       2474 ns         1666 ns       441081
```

**Linux** (g++ GNU 11.3.0)

```
2023-05-09T19:34:37+00:00
Running build/visitlab
Run on (2 X 2593.91 MHz CPU s)
CPU Caches:
  L1 Data 32 KiB (x2)
  L1 Instruction 32 KiB (x2)
  L2 Unified 1024 KiB (x2)
  L3 Unified 36608 KiB (x1)
Load Average: 1.21, 0.58, 0.23
--------------------------------------------------------
Benchmark              Time             CPU   Iterations
--------------------------------------------------------
BM_Visit             836 ns          836 ns       830642
BM_SwitchCase        769 ns          769 ns       901695
```

## License

This is free and unencumbered software released into the public
domain. Read [LICENSE.txt](LICENSE.txt) for more information.
