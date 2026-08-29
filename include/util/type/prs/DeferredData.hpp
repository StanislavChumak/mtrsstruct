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
    uint32_t *offset;
    uint32_t size;
    char *data;

    DeferredData() = delete;

    template<typename T>
    DeferredData(T array, uint32_t &offset, uint32_t &size)
    : offset(&offset)
    {
        this->size = size = static_cast<uint32_t>(sizeof(array[0]) * array.size());

        data = new char[size];
        std::memcpy(data, array.data(), size);
    }
};

}

#endif
