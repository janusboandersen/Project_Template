/**
 * @file Testfile_Template.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2023-05-08
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include <iostream>
#include <ProjectLib.h>

using namespace testing;

class LibTestFixture: public Test {
public:
    int test_value {3};
    Foo test_foo = Foo {test_value};

};

TEST_F(LibTestFixture, FooMethodTwiceReturnsDoubledValue) {
    ASSERT_THAT(test_foo.twoTimesMember(), Eq(2*test_value));
}
