include_directories(${CMAKE_SOURCE_DIR}/plugins/ibm/utils)
include_directories(${CMAKE_SOURCE_DIR}/quantum/gate/ir/instructions)
include_directories(${CMAKE_SOURCE_DIR}/quantum/gate/utils)
include_directories(${CMAKE_SOURCE_DIR}/quantum/gate/ir)

add_subdirectory(compiler)
add_subdirectory(accelerator)

if(XACC_BUILD_TESTS)
   include_directories(${CMAKE_CURRENT_SOURCE_DIR}/accelerator)
   include_directories(${CMAKE_CURRENT_SOURCE_DIR}/utils)
   add_subdirectory(tests)
endif()