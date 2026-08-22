#ifndef PRS_STATE_ANIMATOR_HPP
#define PRS_STATE_ANIMATOR_HPP

#include "util/type/prs/deferred_field.hpp"

namespace mtrs::prs
{

struct StateAnimator
{
    DEFERRED_FIELD(states);
    struct State
    {
        uint32_t id;
        uint16_t offset;
        uint16_t count;
    };
};

}

#endif
