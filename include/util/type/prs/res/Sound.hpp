#ifndef PRS_SOUND_HPP
#define PRS_SOUND_HPP

#include "util/type/prs/deferred_field.hpp"

namespace mtrs::prs
{

struct Sound
{
    DEFERRED_FIELD(path);
    uint32_t flag;
    uint16_t count, max_distance;
};

}

#endif
