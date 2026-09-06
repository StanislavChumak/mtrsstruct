#ifndef READ_HPP
#define READ_HPP

#include <cstring>

template<typename T>
void read(T &dest, char *source, size_t &cur)
{
    std::memcpy(&dest, source + cur, sizeof(T));
    cur += sizeof(T);
}

#endif
