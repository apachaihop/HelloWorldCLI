#include <gtest/gtest.h>
#include "lib.hpp"
#include "version.hpp"
TEST(HelloTest,BundleTest)
{
    EXPECT_STREQ(VERSION,"0.0.1");
}