#ifndef PREPROCESS_JSON_HPP
#define PREPROCESS_JSON_HPP

#include <string>
#include <unordered_map>

namespace mtrs::str
{

std::string preprocess_json(const std::string& path,
    std::unordered_map<std::string, std::string>& defines);

}

#endif
