#include "hello_world.h"
#include <gtest/gtest.h>

TEST(HelloWorldTest, SaysHelloWorld)
{
    ASSERT_EQ(42, 42);
    EXPECT_EQ("Hello, World!", hello_world::hello());
}

int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}