#include "util/type/prs/DeferredData.hpp"

namespace mtrs::prs
{

DeferredData::DeferredData(std::string str, uint32_t &offset, uint32_t &size)
: offset(&offset)
{
    this->size = size = static_cast<uint32_t>(str.size());
    data = new char[size];
    std::copy(str.begin(), str.end(), data);
}

}