#include "util/type/prs/DeferredData.hpp"

namespace mtrs::prs
{

DeferredData::DeferredData(DeferredData &&other)
{
    field = other.field;
    other.field = nullptr;
    data = other.data;
    other.data = nullptr;
}

DeferredData &DeferredData::operator=(DeferredData &&other)
{
    if(this != &other)
    {
        field = other.field;
        other.field = nullptr;
        data = other.data;
        other.data = nullptr;
    }
    return *this;
}

DeferredData::~DeferredData()
{
    delete[] data;
};

}