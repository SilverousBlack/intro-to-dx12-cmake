cmake_minimum_required(VERSION 3.10)

set(
    OWNER
    "Frank D. Luna"
    "Vasilios Magriplis @yottaawesome"
    "Julian Caleb Segundo @SilverousBlack [juliancalebsegundo@gmail.com]"
)

set(
    WORKSPACE_NAME
    "intro-to-dx12-cmake"
)

string(TOUPPER "${WORKSPACE_NAME}" WORKSPACE)
string(REGEX REPLACE "[\.\-]" "_" WORKSPACE ${WORKSPACE})

set(
    ${WORKSPACE_NAME}_VERSION_MAJOR
    0 # TODO: Version major
)

set(
    ${WORKSPACE_NAME}_VERSION_MINOR
    0 # TODO: Version minor
)

set(
    ${WORKSPACE_NAME}_VERSION_PATCH
    0 # TODO: Version patch
)

# auto-generated semantic version
set(
    ${WORKSPACE_NAME}_VERSION
    ${${WORKSPACE_NAME}_VERSION_MAJOR}.${${WORKSPACE_NAME}_VERSION_MINOR}.${${WORKSPACE_NAME}_VERSION_PATCH}
)

project(${WORKSPACE_NAME} VERSION ${${WORKSPACE_NAME}_VERSION})

# always use at least C++17
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

if(MSVC)
    add_definitions(-DUNICODE -D_UNICODE)

    add_compile_options(/D_UNICODE /DUNICODE)
endif()

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/out/${CMAKE_SYSTEM_PROCESSOR})
set(CMAKE)

configure_file(${CMAKE_SOURCE_DIR}/src/info/info_template.hxx.in ${CMAKE_SOURCE_DIR}/src/info/info.hxx.in)
configure_file(${CMAKE_SOURCE_DIR}/src/info/info.hxx.in ${CMAKE_SOURCE_DIR}/src/info/info.hxx)

set(D3D12SDK_INCLUDE "${PROJECT_SOURCE_DIR}/ext/d3d/build/native/include")
set(D3D12SDK_LIBRARY "${PROJECT_SOURCE_DIR}/ext/d3d/build/native/bin/${CMAKE_SYSTEM_PROCESSOR}")

include_directories(src)
include_directories(src/info)

set(
    EXECUTABLES
    "ch1.vector_algebra.init"
    "ch1.vector_algebra.tol"
    "ch1.vector_algebra.vector_ops"
    "ch1.vector_algebra.xmvec3"
    "ch2.matrix_algebra.xmmatrix"
    "ch4.direct3d_init.init"
    "ch6.drawing_in_d3d.box"
    "ch7.drawing_in_d3d_2.shapes"
)

set(
    LIBRARIES
    "Common"
)

foreach(EXECUTABLE ${EXECUTABLES})
    add_subdirectory(src/${EXECUTABLE})
endforeach()

foreach(LIBRARY ${LIBRARIES})
    add_subdirectory(src/${LIBRARY})
endforeach()

foreach(SHARED_LIBRARY ${SHARED_LIBRARIES})
    add_subdirectory(src/${SHARED_LIBRARY})
endforeach()

add_custom_target(
    clean-all
    COMMAND ${CMAKE_COMMAND} --build ${CMAKE_BINARY_DIR} --target clean
)

add_custom_target(build-all)

foreach(config ${CMAKE_CONFIGURATION_TYPES})
    add_custom_command(
        TARGET build-all
        COMMAND ${CMAKE_COMMAND} --build ${CMAKE_BINARY_DIR} --config ${config}
        COMMENT "Building ${config} configuration"
    )
endforeach()

# Globally enable SSE support 
set(
    CMAKE_CXX_FLAGS 
    "${CMAKE_CXX_FLAGS} -msse -msse2 -msse3"
)

include_directories(${CMAKE_SOURCE_DIR}/include)
