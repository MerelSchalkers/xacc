include_directories(${CMAKE_SOURCE_DIR}/quantum/aqc/ir)
include_directories(${CMAKE_SOURCE_DIR}/quantum/aqc/compiler)
include_directories(${CMAKE_SOURCE_DIR}/quantum/aqc)

add_subdirectory(tpls/xacc-cmr)
add_subdirectory(compiler)
add_subdirectory(accelerator)

if(XACC_BUILD_TESTS)
   include_directories(${CMAKE_CURRENT_SOURCE_DIR}/accelerator)
   include_directories(${CMAKE_CURRENT_SOURCE_DIR}/utils)
   add_subdirectory(tests)
endif()