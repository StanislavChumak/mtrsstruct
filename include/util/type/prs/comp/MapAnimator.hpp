#ifndef PRS_MAP_ANIMATOR_HPP
#define PRS_MAP_ANIMATOR_HPP

#include "util/type/prs/deferred_field.hpp"

namespace mtrs::prs
{

struct MapAnimator
{
    DEFERRED_FIELD(ranges);
    DEFERRED_FIELD(durations);
    struct Range{uint32_t offset, size;};
};

}

#endif
