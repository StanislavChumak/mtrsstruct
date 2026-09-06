#ifndef PRS_SPRITE_HPP
#define PRS_SPRITE_HPP

#include "util/type/prs/deferred_field.hpp"

namespace mtrs::prs
{

struct Sprite
{
    DEFERRED_FIELDS(shader, texture, atlas);
    uint32_t size_x, size_y;
    float layer;
    uint32_t color;
    bool visibility;
};

}

#endif
