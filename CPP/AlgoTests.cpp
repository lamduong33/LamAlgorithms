#define CATCH_CONFIG_RUNNER
#include <catch2/catch.hpp>
#include "Algorithms.hpp"

TEST_CASE("Johnson-Trotter Test")
{
    auto result = Algorithms::johnsonTrotter(4);
}

int main(int argc, char *argv[])
{
    int result = Catch::Session().run(argc, argv);
    return result;
}
