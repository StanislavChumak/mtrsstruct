#ifndef DEMANGLE_HPP
#define DEMANGLE_HPP

#include <string>
#include <string_view>

namespace mtrs::str
{

template<typename T>
std::string_view demangle() {
#if defined(__clang__) || defined(__GNUC__)
    std::string_view name = __PRETTY_FUNCTION__;
    auto start = name.find("T = ") + 4;
    auto end = name.find(']', start);
    return name.substr(start, end - start);
#elif defined(_MSC_VER)
    // "class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char> > __cdecl type_name<int>(void)"
    std::string_view name = __FUNCSIG__;
    auto start = name.rfind('<') + 1;
    auto end = name.rfind('>');
    return name.substr(start, end - start);
#else
    return typeid(T).name();
#endif
}

}

#endif
