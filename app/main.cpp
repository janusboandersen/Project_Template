/**
 * @file main.cpp
 * @author Janus Bo Andersen
 * @brief A Template for a small C++ project with 
 *  - own library, 
 *  - unit-testing with GoogleTest, 
 *  - third-party dependency configuration, 
 *  - running in the CppDocker environment.
 * @version 0.1
 * @date Q2 2023
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#include <iostream>
#include <config.hpp>
#include <ProjectLib.h>

int main(void) {
    // Demo -Werror
    //int uninitialized_and_unused_var_should_raise_warning_error;

    // Demo -fsanitize=address
    // Out-of-bounds should be caught by sanitizer
    // int x[] {1, 2, 3};
    // std::cout << x[0] << std::endl;
    // x[3] = 123;  // overflowing into redzone on stack
    
    auto foo = Foo{21};
    std::cout << project_name << ": " << project_version << " (" << project_build_type << ")" << std::endl;
    std::cout << "Sample output: " << foo.twoTimesMember() << std::endl;
    std::cout << "JSON version: " << foo.json_version() << std::endl;
    std::cout << "FMT version: " << foo.fmt_version() << std::endl;
    std::cout << "New line added" << std::endl;
    return 0;
}
