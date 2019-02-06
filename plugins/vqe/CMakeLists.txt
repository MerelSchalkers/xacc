set(VQE_TOP_LEVEL "${CMAKE_CURRENT_SOURCE_DIR}")
include_directories(${CMAKE_SOURCE_DIR}/quantum/gate/ir/instructions)
include_directories(${CMAKE_SOURCE_DIR}/quantum/gate/utils)
include_directories(${CMAKE_SOURCE_DIR}/quantum/gate/ir)
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/tpls/cppnumericalsolvers/cppoptlib)

add_subdirectory(mpi)
add_subdirectory(ir)
add_subdirectory(transformations)
add_subdirectory(compiler)
add_subdirectory(task)
add_subdirectory(decorators)

if(PYTHON_INCLUDE_DIR)
   include_directories(${PYTHON_INCLUDE_DIR})
   add_subdirectory(python)
endif()

#add_executable(xacc-vqe xacc-vqe.cpp)
#target_link_libraries(xacc-vqe xacc-vqe-ir xacc-vqe-tasks ${XACC_LIBRARIES} pthread) # petsc)
#if(APPLE)
#   set_target_properties(xacc-vqe PROPERTIES INSTALL_RPATH "@loader_path/../lib;@loader_path/../plugins")
#else()
#   set_target_properties(xacc-vqe PROPERTIES INSTALL_RPATH "$ORIGIN/../lib:$ORIGIN/../plugins")
#endif()

#install(TARGETS xacc-vqe DESTINATION ${CMAKE_INSTALL_PREFIX}/bin)

file(GLOB BENCHMARK ${CMAKE_CURRENT_SOURCE_DIR}/benchmark/*.py)
install(FILES ${BENCHMARK} DESTINATION ${CMAKE_INSTALL_PREFIX}/py-plugins)

file(GLOB PYDECORATORS ${CMAKE_CURRENT_SOURCE_DIR}/python/decorators/*.py)
install(FILES ${PYDECORATORS} DESTINATION ${CMAKE_INSTALL_PREFIX}/py-plugins)

#configure_file("${CMAKE_SOURCE_DIR}/cmake/xaccvqe-config.cmake.in" "${CMAKE_BINARY_DIR}/xaccvqe-config.cmake" @ONLY)
#install(FILES "${CMAKE_BINARY_DIR}/xaccvqe-config.cmake" DESTINATION ${CMAKE_INSTALL_PREFIX})
#install( DIRECTORY "${CMAKE_SOURCE_DIR}/tpls/cppnumericalsolvers/cppoptlib" DESTINATION ${CMAKE_INSTALL_PREFIX}/include )
