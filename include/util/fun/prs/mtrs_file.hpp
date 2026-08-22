#ifndef MTRS_FILE_HPP
#define MTRS_FILE_HPP

#include <string>
#include <cstdint>

#include <fstream>

namespace mtrs::prs
{

template<typename T>
void set_mtrs_to_var(std::ifstream &file, T& dest, uint32_t offset, uint32_t size)
{
    std::streampos pos_buffer = file.tellg();

    file.seekg(offset, std::ios::beg);

    dest.resize(size / sizeof(dest[0]));
    file.read(reinterpret_cast<char*>(dest.data()), size);

    file.seekg(pos_buffer, std::ios::beg);
}

}

#endif
