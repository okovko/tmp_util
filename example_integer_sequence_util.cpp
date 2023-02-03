#include "integer_sequence_util.hpp"
#include <tuple>
#include <iostream>

int main() {
  std::tuple tup{1, 2.0, true};
  std::tuple<bool, double, int> rev_tup = [&tup]<std::size_t... Is>(std::index_sequence<Is...>) {
    return std::tuple{std::get<Is>(tup)...};
  }(make_reverse_index_sequence<std::tuple_size_v<decltype(tup)>>{});
  std::apply([](const auto&... x) {
    ((std::cout << x), ...);
  }, rev_tup);
}
