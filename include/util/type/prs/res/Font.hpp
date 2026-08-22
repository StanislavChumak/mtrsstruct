#ifndef PRS_FONT_HPP
#define PRS_FONT_HPP

#include "util/type/prs/deferred_field.hpp"

namespace mtrs::prs
{

struct Font
{
    DEFERRED_FIELD(texture);
    DEFERRED_FIELD(symbols);
    DEFERRED_FIELD(symbol_widths);
    struct SymbolWidth
    {
        uint32_t count;
        uint32_t value;
    };
    uint32_t symbol_height;
};

}

#endif
