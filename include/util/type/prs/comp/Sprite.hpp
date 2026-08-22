#ifndef PRS_SPRITE_HPP
#define PRS_SPRITE_HPP

#include "util/type/prs/deferred_field.hpp"

namespace mtrs::prs
{

struct Sprite
{
    DEFERRED_FIELD(shader);
    DEFERRED_FIELD(texture);
    DEFERRED_FIELD(atlas);
    float layer;
    uint32_t size_x, size_y;
    uint32_t color;
};

}

#endif
