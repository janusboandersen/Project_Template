/**
 * @file ProjectLib.h
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2023-05-07
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#pragma once
#include <string>

class Foo {
public:
    explicit Foo(const int value) : member{value} {};
    int twoTimesMember() const;
    std::string json_version() const;
    std::string fmt_version() const;

private:
    int member;
};