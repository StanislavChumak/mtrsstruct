#ifndef PRS_TEXTURE_ATLAS_HPP
#define PRS_TEXTURE_ATLAS_HPP

#include "util/type/prs/deferred_field.hpp"

namespace mtrs::prs
{

struct TextureAtlas
{
    DEFERRED_FIELD(texture);
    uint64_t sub_width;
    uint64_t sub_height;
    bool spirality;
};

}

#endif
