#ifndef PRS_SHADER_HPP
#define PRS_SHADER_HPP

#include "util/type/prs/deferred_field.hpp"

namespace mtrs::prs
{

struct Shader
{
    DEFERRED_FIELD(vertex);
    DEFERRED_FIELD(fragment);
};

}

#endif
