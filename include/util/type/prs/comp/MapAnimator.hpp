#ifndef PRS_MAP_ANIMATOR_HPP
#define PRS_MAP_ANIMATOR_HPP

#include "util/type/prs/deferred_field.hpp"

namespace mtrs::prs
{

struct MapAnimator
{
    DEFERRED_FIELDS(durations, cell_animators);
    struct CellAnimator{uint32_t frame_offset, count_frame;};
};

}

#endif
