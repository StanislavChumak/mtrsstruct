#ifndef JSON_HPP
#define JSON_HPP

#include "simdjson.h"

#include <array>
#include <vector>

#include "util/fun/msg/mtrs_message.hpp"
#include "util/fun/str/demangle.hpp"

namespace mtrs::prs
{

template<typename T, typename R>
T get_result_json(R result)
{
    if(result.error())
    {
        msg::mtrs_error("Failed to get ", mtrs::str::demangle<T>()," from json\n",
            "Error: ", simdjson::error_message(result.error()));
    }
    return result.value();
}

template<typename T, typename J>
T get_value_json(J json)
{
    return get_result_json<T>(json.template get<T>());
}

template<typename T, typename D, typename S>
void set_json_to_var(D &dest, S &source, std::string field)
{
    auto result = source[field].template get<T>();
    if(result.error())
    {
        msg::mtrs_error("Failed to get ", mtrs::str::demangle<T>()," from ", field,
            "\nError: ", simdjson::error_message(result.error()));
        return;
    }
    dest = result.value();
}

template<typename T, typename D, typename S>
void set_json_to_var(D &dest, S &source, std::string field, T value)
{
    auto result = source[field].template get<T>();
    dest = result.error() ? value : static_cast<D>(std::move(result.value()));
}

template<typename T, typename D, typename S>
void set_json_to_array(std::vector<D> &dest, S &source, std::string field)
{
    dest.clear();
    auto result = source[field].template get<simdjson::ondemand::array>();
    if(result.error())
    {
        msg::mtrs_error("Failed to get array from ", field,
            "\nError: ", simdjson::error_message(result.error()));
        return;
    }

    auto array = result.value();
    dest.reserve(array.count_elements());
    simdjson::simdjson_result<T> iter_result;
    for(auto iter : array)
    {
        iter_result = iter.template get<T>();
        if(iter_result.error())
        {
            msg::mtrs_error("Failed to get ", mtrs::str::demangle<T>()," from array ", field,
                "\nError: ", simdjson::error_message(result.error()));
            return;
        }

        dest.push_back(get_value_json<T>(iter));
    }
    
}

template<typename T, typename D, typename S>
void set_json_to_array(std::vector<D> &dest, S &source, std::string field, std::vector<D> value)
{
    dest.clear();
    auto result = source[field].template get<simdjson::ondemand::array>();
    if(result.error())
    {
        dest = std::move(value);
        return;
    }

    auto array = result.value();
    dest.reserve(array.count_elements());
    for(auto iter : array)
    {
        dest.push_back(get_value_json<T>(iter));
    }
}

template<typename T, typename D, size_t N, typename S>
void set_json_to_array_of_array(std::vector<std::array<D, N>> &dest, S &source, std::string field)
{
    dest.clear();
    auto result = source[field].template get<simdjson::ondemand::array>();
    if(result.error())
    {
        msg::mtrs_error("Failed to get array of array from ", field,
            "\nError: ", simdjson::error_message(result.error()));
        return;
    }
    
    auto arr_arr = result.value();
    dest.reserve(arr_arr.count_elements());
    simdjson::simdjson_result<simdjson::ondemand::array> arr_result;
    simdjson::simdjson_result<T> element_result;
    std::array<D, N> array;
    size_t i;
    for(auto iter_array : arr_arr)
    {
        arr_result = iter_array.template get<simdjson::ondemand::array>();
        if(arr_result.error())
        {
            msg::mtrs_error("Failed to get array from array of array ", field,
                "\nError: ", simdjson::error_message(result.error()));
            return;
        }
        
        i = 0;
        for(auto iter : arr_result.value())
        {
            element_result = iter.template get<T>();
            if(element_result.error())
            {
                msg::mtrs_error("Failed to get ",mtrs::str::demangle<T>()," from array of array ", field,
                "\nError: ", simdjson::error_message(result.error()));
                return;
            }
            array[i++] = element_result.value();
        }

        dest.push_back(std::move(array));
    }
}

}

#endif
