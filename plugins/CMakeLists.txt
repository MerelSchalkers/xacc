
set (XACC_INCLUDE_DIRS "${CMAKE_BINARY_DIR};${CMAKE_SOURCE_DIR}/xacc/program;${CMAKE_SOURCE_DIR}/xacc/ir;${CMAKE_SOURCE_DIR}/xacc/compiler;${CMAKE_SOURCE_DIR}/xacc/accelerator;${CMAKE_SOURCE_DIR}/xacc/accelerator/remote;${CMAKE_SOURCE_DIR}/xacc/utils;${CMAKE_SOURCE_DIR}/tpls/antlr/runtime/src;${CMAKE_SOURCE_DIR}/xacc;${CMAKE_SOURCE_DIR}/quantum/gate;${CMAKE_SOURCE_DIR}/quantum/aqc;${CMAKE_SOURCE_DIR}/tpls/spdlog;${CMAKE_SOURCE_DIR}/tpls/exprtk;${CMAKE_SOURCE_DIR}/tpls/eigen;${CMAKE_SOURCE_DIR}/tpls/rapidjson/include;${CMAKE_SOURCE_DIR}/tpls/cpr/opt/googletest/include")
set (XACC_LIBRARIES "xacc;xacc-quantum-gate;xacc-quantum-aqc;antlr4-runtime;CppMicroServices;boost_system;boost_filesystem;boost_regex;boost_graph;boost_program_options")

include_directories(${CMAKE_SOURCE_DIR}/tpls/boost-cmake/boost/boost_1_64_0)
include_directories(${CMAKE_BINARY_DIR}/tpls/cppmicroservices/framework/include)

include_directories(${CMAKE_BINARY_DIR}/tpls/cppmicroservices/include)
include_directories(${CMAKE_SOURCE_DIR}/tpls/cppmicroservices/framework/include)

include_directories(${XACC_INCLUDE_DIRS})
add_subdirectory(ibm)
add_subdirectory(rigetti)
add_subdirectory(vqe)
add_subdirectory(dwave)