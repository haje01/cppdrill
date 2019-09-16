#
# PyBind11
#
set(PYBIND11_CPP_STANDARD -std=c++14)
set(PYBIND11_PYTHON_VERSION=3.7)
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
set(TBB_ROOT ${CMAKE_CURRENT_SOURCE_DIR}/tbb/)
set(TBB_ROOT ${TBB_ROOT} PARENT_SCOPE)
include(${TBB_ROOT}/cmake/TBBBuild.cmake)
tbb_build(
    TBB_ROOT ${TBB_ROOT}
    MAKE_ARGS tbb_build_dir=${CMAKE_CURRENT_BINARY_DIR}/tbb/
    CONFIG_DIR TBB_DIR)
set(TBB_DIR ${TBB_DIR} PARENT_SCOPE)

