#ifndef MTRS_FILE_HPP
#define MTRS_FILE_HPP

#include "util/type/prs/DeferredData.hpp"

namespace mtrs::prs
{

template<typename T>
void set_mtrs_to_var(prs::DeferredData &ddata, T& dest)
{
    dest.resize(ddata.field[1] / sizeof(dest[0]));
    std::memcpy(dest.data(), ddata.data, ddata.field[1]);
}

}

#endif
