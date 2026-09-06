#ifndef DEFERRED_FIELDS
#include <cstdint>
#include <array>
template<typename Arg, typename... Args>
constexpr std::array<Arg*, sizeof...(Args) + 1> make_array(Arg &arg, Args &...args)
{
    if constexpr (sizeof...(Args) == 0)
        return std::array<Arg*, 1>{&arg};
    else
        return std::array<Arg*, sizeof...(Args) + 1>{&arg, (&args)...};
}

#define DEFERRED_FIELDS(...) \
    auto get_deferred_fields() { return make_array(__VA_ARGS__); } \
    uint64_t __VA_ARGS__
#endif
