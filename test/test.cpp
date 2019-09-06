#include <stdio.h>
#include <lib.hpp>

#define CATCH_CONFIG_MAIN
#include <catch2/catch.hpp>


TEST_CASE("Basic test.", "Test1") {
    SECTION("sa") {
        REQUIRE( getMessage().size() > 0 );
    }
}
