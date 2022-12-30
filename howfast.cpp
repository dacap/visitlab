// This file is released into the public domain.
// Read LICENSE.txt for more information.

#include <benchmark/benchmark.h>

#include <sstream>
#include <string>
#include <variant>
#include <utility>

using Variant = std::variant<bool,
                             char, unsigned char,
                             int, unsigned int,
                             long, unsigned long,
                             float, double,
                             std::string>;

Variant variants[] = {
  true, '1', (unsigned char)'1',
  -1, 1u,
  (long)-1, (unsigned long)1u,
  1.1f, 1.1, "1.1" };

struct Visitor {
  std::ostream& o;
  template<typename T>
  void operator()(const T& a) {
    o << a;
  }
};

static void BM_Visit(benchmark::State& state) {
  std::stringstream ss;
  Visitor visitor{ss};
  while (state.KeepRunning()) {
    for (auto& v : variants) {
      std::visit(visitor, v);
    }
  }
}
BENCHMARK(BM_Visit);

static void BM_SwitchCase(benchmark::State& state) {
  std::stringstream ss;
  while (state.KeepRunning()) {
    for (auto& v : variants) {
      switch (v.index()) {
        case 0: ss << std::get<bool>(v); break;
        case 1: ss << std::get<char>(v); break;
        case 2: ss << std::get<unsigned char>(v); break;
        case 3: ss << std::get<int>(v); break;
        case 4: ss << std::get<unsigned int>(v); break;
        case 5: ss << std::get<long>(v); break;
        case 6: ss << std::get<unsigned long>(v); break;
        case 7: ss << std::get<float>(v); break;
        case 8: ss << std::get<double>(v); break;
        case 9: ss << std::get<std::string>(v); break;
      }
    }
  }
}
BENCHMARK(BM_SwitchCase);

BENCHMARK_MAIN();
