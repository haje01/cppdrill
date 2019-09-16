#include <iostream>
#include <catch2/catch.hpp>
#include <tbb/tbb.h>

using namespace tbb;

float power( float a) {
    return a * a;
}

class ApplyPower {
    float * const my_a;
public:
    void operator()( const blocked_range<size_t> & r) const {
        float * a = my_a;
        for(size_t i= r.begin(); i != r.end(); ++i) 
            power(a[i]);
    }
    ApplyPower( float a[] ) : my_a(a) {}
};


TEST_CASE("TBB test.", "Test1") {
    SECTION("sa") {
        float a[] = {0.0, 1.0, 2.0, 3.0, 4.0, 5.0};
        parallel_for(blocked_range<size_t>(0, 5), ApplyPower(a));
    }
}
