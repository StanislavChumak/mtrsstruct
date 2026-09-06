#ifndef PRS_ANIMATOR_HPP
#define PRS_ANIMATOR_HPP

#include "util/type/prs/deferred_field.hpp"

namespace mtrs::prs
{

struct Animator
{
    DEFERRED_FIELDS(durations);
    uint32_t frame_offset, count_frame;
};

}

#endif
