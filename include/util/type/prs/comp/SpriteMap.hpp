#ifndef PRS_SPRITE_MAP_HPP
#define PRS_SPRITE_MAP_HPP

#include "util/type/prs/deferred_field.hpp"

namespace mtrs::prs
{

struct SpriteMap
{
    DEFERRED_FIELDS(shader, texture, atlas, cell_types, cell_map);
    float layer;
    uint32_t cell_size_x, cell_size_y;
    uint32_t color;
    bool visibility;
    struct MapCell
    {
        uint32_t type;
        int32_t cord_x, cord_y;
    };
};

}

#endif
