#include <lib.hpp>
#include <nlohmann/json.hpp>

using namespace std::string_literals;
using json = nlohmann::json;

std::string getMessage() {
    auto msg = R"({
    "name": "KJJ",
    "score": 100
}
)";
    return msg;
}


std::string dumpJSON() {
    json j;
    j["pi"] = 3.141;
    j["name"]["first"] = "Niels";

    return j.dump();
}