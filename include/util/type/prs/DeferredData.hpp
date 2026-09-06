#ifndef DEFERRED_DATA_HPP
#define DEFERRED_DATA_HPP

#include "util/fun/msg/mtrs_message.hpp"

#include <cstdint>
#include <cstring>

namespace mtrs::prs
{

struct DeferredData
{
    uint32_t *field;
    char *data;

    DeferredData() : field(nullptr), data(nullptr) {}
    DeferredData(const DeferredData&) = delete;
    DeferredData &operator=(const DeferredData&) = delete;
    DeferredData(DeferredData &&other);
    DeferredData &operator=(DeferredData &&other);
    ~DeferredData();

    template<typename T>
    DeferredData(T array, uint64_t &field)
    : field(reinterpret_cast<uint32_t*>(&field))
    {
        this->field[1] = static_cast<uint32_t>(sizeof(array[0]) * array.size());

        data = new char[this->field[1]];
        std::memcpy(data, array.data(), this->field[1]);
    }
};

}

#endif
