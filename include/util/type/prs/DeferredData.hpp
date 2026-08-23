#ifndef DEFERRED_DATA_HPP
#define DEFERRED_DATA_HPP

#include "util/fun/msg/mtrs_message.hpp"

#include <cstdint>
#include <vector>
#include <array>
#include <string>
#include <type_traits>
#include <cstring>

namespace mtrs::prs
{

struct DeferredData
{
private:
    template<typename T>
    struct is_std_array : std::false_type {};
    
    template<typename U, size_t N>
    struct is_std_array<std::array<U, N>> : std::true_type {};

    template<typename T>
    static constexpr bool is_std_array_v = is_std_array<T>::value;

public:
    uint32_t *offset;
    uint32_t size;
    char *data;

    DeferredData() = delete;

    DeferredData(std::string str, uint32_t &offset, uint32_t &size);

    template<typename T>
    DeferredData(std::vector<T> array, uint32_t &offset, uint32_t &size,
        std::enable_if_t<!is_std_array_v<T>>* = nullptr)
    : offset(&offset)
    {
        this->size = size = static_cast<uint32_t>(sizeof(T) * array.size());

        data = new char[size];
        std::memcpy(data, array.data(), size);
    }

    template<typename T, size_t N>
    DeferredData(std::vector<std::array<T, N>> arr_arr, uint32_t &offset, uint32_t &size)
    : offset(&offset)
    {
        this->size = size = static_cast<uint32_t>(sizeof(T) * arr_arr.size() * N);

        data = new char[size];
        std::memcpy(data, arr_arr.data(), size);
    }
};

}

#endif
