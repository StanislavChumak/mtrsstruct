#ifndef JSON_PARSING_HPP
#define JSON_PARSING_HPP

#include "simdjson.h"

#include <string>
#include <vector>
#include <unordered_map>

#include "util/fun/msg/mtrs_message.hpp"

namespace mtrs::prs
{

simdjson::padded_string preprocess_json(const std::string& path,
    std::unordered_map<std::string, std::string>& defines);

template<typename T, typename R>
T get_result_json(R result)
{
    if(result.error())
    {
        msg::mtrs_error("Failed to get ", typeid(T).name()," from json\n",
            "Error: ", simdjson::error_message(result.error()));
    }
    return result.value();
}

template<typename T, typename S>
T get_value_json(S source)
{
    return get_result_json<T>(source.template get<T>());
}

template<typename T, typename D, typename S>
void set_json_to_var(D &dest, S source)
{
    dest = static_cast<D>(get_value_json<T>(std::move(source)));
}

template<typename T, typename D, typename S>
void set_json_to_var(D &dest, S source, T value)
{
    auto result = source.template get<T>();
    dest = result.error() ? value : static_cast<D>(std::move(result.value()));
}

template<typename T, typename D, typename S>
void set_json_to_array(std::vector<D> &dest, S source)
{
    auto array = get_value_json<simdjson::ondemand::array>(source);
    dest.clear();
    dest.reserve(array.count_elements());
    for(auto iter : array)
    {
        dest.push_back(get_value_json<T>(iter));
    }
}

template<typename T, typename D, typename S>
void set_json_to_array(std::vector<D> &dest, S source, std::vector<D> value)
{
    dest.clear();
    auto result = source.template get<simdjson::ondemand::array>();
    if(result.error())
    {
        dest = std::move(value);
    }
    else
    {
        auto array = result.value();
        dest.reserve(array.count_elements());
        for(auto iter : array)
        {
            dest.push_back(get_value_json<T>(iter));
        }
    }
}

template<typename T, size_t C, typename D, typename S>
void set_json_to_array_of_array(std::vector<D[C]> &dest, S source)
{
    auto array_of_array = get_value_json<simdjson::ondemand::array>(source);
    dest.clear();
    dest.reserve(array_of_array.count_elements());

    D array[C];
    size_t i;
    for(auto iter_array : array_of_array)
    {
        i = 0;
        for(auto iter : get_value_json<simdjson::ondemand::array>(iter_array))
        {
            array[i++] = get_value_json<T>(iter);
            if(i >= C)
            {
                msg::mtrs_warning("In JSON, the number of elements in the array of arrays"
                    " exceeded the value C(max count)");
                break;
            }
        }
        dest.push_back(std::move(array));
    }
}

}

#endif
