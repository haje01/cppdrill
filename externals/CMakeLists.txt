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
set (TBB_ROOT "${EXTERNAL_DIR}/tbb")
set (TBB_DIR "${TBB_ROOT}/cmake")
include(${TBB_DIR}/TBBBuild.cmake)
tbb_build(TBB_ROOT ${TBB_ROOT} CONFIG_DIR TBB_DIR)
find_package(TBB REQUIRED tbb tbbmalloc)

# list(APPEND CMAKE_MODULE_PATH ${TBB_DIR})
# list(APPEND CMAKE_PREFIX_PATH TBB)
# set(TBB_ROOT ${EXTERNAL_DIR}/tbb/)
# set(TBB_ROOT ${TBB_ROOT} PARENT_SCOPE)
# message("TBB_ROOT ${TBB_ROOT}")
# include(${TBB_ROOT}/cmake/TBBBuild.cmake)
# tbb_build(
#     TBB_ROOT ${TBB_ROOT}
#     MAKE_ARGS tbb_build_dir=${CMAKE_CURRENT_BINARY_DIR}/tbb/
#     CONFIG_DIR TBB_DIR)
# set(TBB_DIR ${TBB_DIR} PARENT_SCOPE)
# list(APPEND CMAKE_MODULE_PATH ${TBB_DIR})
# message("CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH}")

