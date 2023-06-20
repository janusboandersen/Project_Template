/**
 * @file ProjectLib.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2023-05-07
 * 
 * @copyright Copyright (c) 2023
 * 
 */


#include <sstream>
#include <nlohmann/json.hpp>
#include <fmt/format.h>
#include <ProjectLib.h>

/**
 * @brief Descriptive description
 * 
 * @return int 
 */
int Foo::twoTimesMember() const {
    return this->member * 2;
}


std::string Foo::json_version() const {
    std::stringstream s;
    s <<
        NLOHMANN_JSON_VERSION_MAJOR << "." <<
        NLOHMANN_JSON_VERSION_MINOR << "." <<
        NLOHMANN_JSON_VERSION_PATCH;
    return s.str();
}


std::string Foo::fmt_version() const {
    std::stringstream s;
    s << FMT_VERSION;
    return s.str();
}