#ifndef HASH_HPP
#define HASH_HPP

#include <cstdint>
#include <cstddef>

#include <string>

constexpr uint32_t FNV_OFFSET_BASIS_32 = 2166136261u;
constexpr uint64_t FNV_OFFSET_BASIS_64 = 14695981039346656037ull;
constexpr uint32_t FNV_PRIME_32        = 16777619u;
constexpr uint64_t FNV_PRIME_64        = 1099511628211ull;

namespace mtrs::math
{

template<typename T>
constexpr T fnv1a(const char *data, size_t size, T seed, T prime)
{
    for (size_t i = 0; i < size; i++)
    {
        seed ^= data[i];
        seed *= prime;
    }
    return seed;
}

constexpr uint32_t hash32(const void *data, size_t size, uint32_t seed = FNV_OFFSET_BASIS_32)
{
    return fnv1a<uint32_t>(reinterpret_cast<const char*>(data), size, seed, FNV_PRIME_32);
}

constexpr uint64_t hash64(const void *data, size_t size, uint64_t seed = FNV_PRIME_64)
{
    return fnv1a<uint64_t>(reinterpret_cast<const char*>(data), size, seed, FNV_PRIME_64);
}

constexpr uint32_t hash32(const char *str, uint32_t seed = FNV_OFFSET_BASIS_32)
{
    int i = 0;
    while (str[i]) i++;
    return fnv1a<uint32_t>(str, i, seed, FNV_PRIME_32);
}

constexpr uint64_t hash64(const char *str, uint64_t seed = FNV_PRIME_64)
{
    int i = 0;
    while (str[i]) i++;
    return fnv1a<uint64_t>(str, i, seed, FNV_PRIME_64);
}

inline uint32_t hash32(const std::string& str, uint32_t seed = FNV_OFFSET_BASIS_32)
{
    return fnv1a<uint32_t>(str.data(), str.size(), seed, FNV_PRIME_32);
}

inline uint64_t hash64(const std::string& str, uint64_t seed = FNV_PRIME_64)
{
    return fnv1a<uint64_t>(str.data(), str.size(), seed, FNV_PRIME_64);
}

}

#endif
