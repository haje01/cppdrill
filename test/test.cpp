#include <iostream>

#define CATCH_CONFIG_MAIN
#include <catch2/catch.hpp>

#include <lib.hpp>

TEST_CASE("Basic test.", "Test1") {
    SECTION("sa") {
        REQUIRE( getMessage().size() > 0 );
    }
    SECTION("io") {
        std::cout << dumpJSON() << std::endl;
        REQUIRE( dumpJSON().size() > 0 );
    }
}
