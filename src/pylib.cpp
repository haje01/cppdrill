#include <pybind11/pybind11.h>
#include <lib.hpp>

namespace py = pybind11;

PYBIND11_MODULE(pymylib, m) {
    m.doc() = "My Python Lib.";
    m.def("get_message", &getMessage, "Get message.");
}