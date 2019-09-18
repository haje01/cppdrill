#
# PyBind11
#
set(PYBIND11_CPP_STANDARD -std=c++14)
# set(PYBIND11_PYTHON_VERSION=3.7)
# Prevent `cmake __create_def` error for Visual Studio Release DLL
set(PYBIND11_LTO_CXX_FLAGS "")
add_subdirectory(${EXTERNAL_DIR}/pybind11
    ../build/externals/pybind11
)


#
# Catch2
#
set(CATCH_DIR "${EXTERNAL_DIR}/Catch2")
add_subdirectory(${CATCH_DIR} ../build/externals/Catch2)


#
# nlohmann JSON
#
set(JSON_BuildTests OFF CACHE INTERNAL "")
add_subdirectory(${EXTERNAL_DIR}/json ../build/externals/json)


#
# TBB
#
add_subdirectory(${EXTERNAL_DIR}/tbb ../build/externals/tbb)
