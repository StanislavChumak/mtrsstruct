#include "util/fun/prs/mtrs_file.hpp"

namespace mtrs::prs
{

void set_mtrs_to_string(std::ifstream &file, std::string &dest, uint32_t offset, uint32_t size)
{
    std::streampos buffer = file.tellg();
    
    file.seekg(offset, std::ios::beg);

    dest.resize(size);
    file.read(dest.data(), size);
    
    file.seekg(buffer, std::ios::beg);
}

}