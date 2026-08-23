#ifndef DEMANGLE_HPP
#define DEMANGLE_HPP

#include <typeinfo>
#include <cxxabi.h>
#include <memory>

template<typename T>
std::string demangle() {
    int status;
    std::unique_ptr<char, void(*)(void*)> demangled(
        abi::__cxa_demangle(typeid(T).name(), nullptr, nullptr, &status),
        std::free
    );
    return status == 0 ? demangled.get() : typeid(T).name();
}

#endif
