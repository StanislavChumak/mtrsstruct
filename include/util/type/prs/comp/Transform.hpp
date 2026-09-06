#ifndef PRS_TRANSFORM_HPP
#define PRS_TRANSFORM_HPP

#include "util/type/prs/deferred_field.hpp"

namespace mtrs::prs
{

struct Transform
{
    auto get_deferred_fields() { return std::array<uint64_t*, 0>{}; }
    int64_t pos_x, pos_y;
    float scale_size_x, scale_size_y;
    float rotation;
};

}

#endif
