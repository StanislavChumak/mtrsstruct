#ifndef DEFERRED_DATA_HPP
#define DEFERRED_DATA_HPP

#include "util/fun/msg/mtrs_message.hpp"

#include <cstdint>
#include <vector>
#include <string>

namespace mtrs::prs
{

struct DeferredData
{
    uint32_t *offset;
    uint32_t size;
    char *data;

    DeferredData() = delete;

    DeferredData(std::string str, uint32_t &offset, uint32_t &size);

    template<typename T>
    DeferredData(std::vector<T> &array, uint32_t &offset, uint32_t &size)
    : offset(&offset)
    {
        this->size = size = static_cast<uint32_t>(sizeof(T) * array.size());

        data = new char[size];
        data = reinterpret_cast<char*>(std::move(array.data()));
    }

    template<typename T, size_t C>
    DeferredData(std::vector<T[C]> arr_arr, uint32_t &offset, uint32_t &size)
    : offset(&offset)
    {
        this->size = size = static_cast<uint32_t>(sizeof(T) * arr_arr.size() * C);

        data = new char[size];
        data = reinterpret_cast<char*>(std::move(arr_arr.data()));
    }
};

}

#endif
