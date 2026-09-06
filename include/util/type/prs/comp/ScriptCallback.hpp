#ifndef PRS_SCRIPT_CALLBACK_HPP
#define PRS_SCRIPT_CALLBACK_HPP

#include "util/type/prs/deferred_field.hpp"

namespace mtrs::prs
{

struct ScriptCallback
{
    DEFERRED_FIELDS(script_file);
};

}

#endif
