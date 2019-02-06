include_directories(${CMAKE_SOURCE_DIR}/quantum/gate/ir/instructions)
include_directories(${CMAKE_SOURCE_DIR}/quantum/gate/utils)
include_directories(${CMAKE_SOURCE_DIR}/quantum/gate/ir)

add_subdirectory(compiler)

if(XACC_BUILD_TESTS)
   include_directories(${CMAKE_CURRENT_SOURCE_DIR}/compiler)
   add_subdirectory(tests)
endif()