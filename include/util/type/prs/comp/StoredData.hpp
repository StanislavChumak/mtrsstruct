#ifndef PRS_STORED_DATA_HPP
#define PRS_STORED_DATA_HPP

#include "util/type/prs/deferred_field.hpp"

namespace mtrs::prs
{

struct StoredData
{
    DEFERRED_FIELDS(data);
};

}

#endif
