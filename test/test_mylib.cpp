#include <stdio.h>

#define CATCH_CONFIG_MAIN
#include <catch2/catch.hpp>

#include <lib.hpp>

TEST_CASE("MyLib test.", "Test1") {
    SECTION("sa") {
        REQUIRE( getMessage().size() > 0 );
    }
}
