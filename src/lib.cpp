#include "lib.hpp"

using namespace std::string_literals;

std::string getMessage() {
    auto msg = R"({
    "name": "KJJ",
    "score": 100
}
)";
    return msg;
}
