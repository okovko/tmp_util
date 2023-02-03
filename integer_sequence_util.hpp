#ifndef INTEGER_SEQUENCE_UTIL_H_
#define INTEGER_SEQUENCE_UTIL_H_

#include <utility>
#include <cstddef>

/*
 * partial template specialization is necessary to retrieve the nested pack in the template param
*/
template <std::size_t, typename>
struct make_reverse_index_sequence_helper;

template <std::size_t N, std::size_t... Is>
struct make_reverse_index_sequence_helper<N, std::index_sequence<Is...>> : std::index_sequence<(N - Is - 1)...> {};

template <std::size_t N>
struct make_reverse_index_sequence : make_reverse_index_sequence_helper<N, decltype(std::make_index_sequence<N>{})> {};

#endif // INTEGER_SEQUENCE_UTIL_H_
