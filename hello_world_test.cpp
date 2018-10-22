#include "hello_world.h"
#include <gtest/gtest.h>
#include <fruit/fruit.h>

TEST(HelloWorldTest, SaysHelloWorld)
{
    fruit::Injector<hello_world::Greeter> injector(hello_world::getGreeterComponent);
    hello_world::Greeter* greeter = injector.get<hello_world::Greeter*>();
    ASSERT_EQ(42, 42);
    EXPECT_EQ("Hello, World!", greeter->greet());
}

int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}