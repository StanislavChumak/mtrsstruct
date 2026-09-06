#ifndef PRS_SCRIPT_UPDATE_HPP
#define PRS_SCRIPT_UPDATE_HPP

#include "util/type/prs/deferred_field.hpp"

namespace mtrs::prs
{

struct ScriptUpdate
{
    DEFERRED_FIELDS(script_file);
};

}

#endif
