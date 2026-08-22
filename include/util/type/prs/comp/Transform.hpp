#ifndef PRS_TRANSFORM_HPP
#define PRS_TRANSFORM_HPP

#include <cstdint>

namespace mtrs::prs
{

struct Transform
{
    int64_t pos_x, pos_y;
    float scale_size_x, scale_size_y;
    float rotation;
};

}

#endif
