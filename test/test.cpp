#include <stdio.h>
#include <assert.h>

#include <lib.hpp>

void testBasic()
{
    assert(getMessage().size() > 0);
}

int main() {
    testBasic();
}
