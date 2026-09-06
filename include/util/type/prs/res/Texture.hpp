#ifndef PRS_TEXTURE_HPP
#define PRS_TEXTURE_HPP

#include "util/type/prs/deferred_field.hpp"

namespace mtrs::prs
{

struct Texture
{
    DEFERRED_FIELDS(path);
    uint64_t max_instances;
};

}

#endif
