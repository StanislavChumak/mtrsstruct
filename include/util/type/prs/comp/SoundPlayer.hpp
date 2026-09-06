#ifndef PRS_SOUND_PLAYER_HPP
#define PRS_SOUND_PLAYER_HPP

#include "util/type/prs/deferred_field.hpp"

namespace mtrs::prs
{

struct SoundPlayer
{
    DEFERRED_FIELDS(sound);
    float volume;
};

}

#endif
