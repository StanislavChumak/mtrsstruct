#ifndef HASH_HPP
#define HASH_HPP

#include <cstdint>
#include <cstddef>

#include <string>

constexpr uint64_t FNV_OFFSET_BASIS_64 = 14695981039346656037ull;
constexpr uint32_t FNV_OFFSET_BASIS_32 = 2166136261u;
constexpr uint64_t FNV_PRIME_64        = 1099511628211ull;
constexpr uint32_t FNV_PRIME_32        = 16777619u;

namespace mtrs::util
{

template<typename T>
constexpr T fnv1a(const char* data, size_t size, T hash = sizeof(T) == 4 ? FNV_OFFSET_BASIS_32 : FNV_OFFSET_BASIS_64)
{
    for (size_t i = 0; i < size; i++)
    {
        hash ^= data[i];
        hash *= sizeof(T) == 4 ? FNV_PRIME_32 : FNV_PRIME_64;
    }
    return hash;
}

template<typename T>
constexpr T hash_c_string(const char *s, T seed = sizeof(T) == 4 ? FNV_OFFSET_BASIS_32 : FNV_OFFSET_BASIS_64)
{
    int i = 0;
    while (s[i]) i++;
    return fnv1a(s, i, seed);
}

template<typename T>
T hash_string(const std::string& s, T seed = sizeof(T) == 4 ? FNV_OFFSET_BASIS_32 : FNV_OFFSET_BASIS_64)
{
    return fnv1a(s.data(), s.size(), seed);
}

}

#endif
