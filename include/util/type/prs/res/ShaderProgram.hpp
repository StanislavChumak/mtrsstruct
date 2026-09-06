#ifndef PRS_SHADER_PROGRAM_HPP
#define PRS_SHADER_PROGRAM_HPP

#include "util/type/prs/deferred_field.hpp"

namespace mtrs::prs
{

struct ShaderProgram
{
    DEFERRED_FIELDS(vertex, fragment);
};

}

#endif
