#ifndef PRS_LABEL_HPP
#define PRS_LABEL_HPP

#include "util/type/prs/deferred_field.hpp"

namespace mtrs::prs
{

struct Label
{
    DEFERRED_FIELD(shader);
    DEFERRED_FIELD(text);
    float layer;
    uint32_t size_x, size_y;
    uint32_t color;
};

}

#endif
