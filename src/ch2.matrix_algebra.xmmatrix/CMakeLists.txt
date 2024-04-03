set(
    PROJECT_NAME
    "ch2.matrix_algebra.xmmatrix"
)

string(TOUPPER "${PROJECT_NAME}" PROJECT)
string(REGEX REPLACE "[\.\-]" "_" PROJECT ${PROJECT})

set(
    ${PROJECT_NAME}_VERSION_MAJOR
    0 # TODO: Version major
)

set(
    ${PROJECT_NAME}_VERSION_MINOR
    0 # TODO: Version minor
)

set(
    ${PROJECT_NAME}_VERSION_PATCH
    0 # TODO: Version patch
)

# auto-generated semantic version
set(
    ${PROJECT_NAME}_VERSION
    ${${PROJECT_NAME}_VERSION_MAJOR}.${${PROJECT_NAME}_VERSION_MINOR}.${${PROJECT_NAME}_VERSION_PATCH}
)

configure_file(${CMAKE_SOURCE_DIR}/src/${PROJECT_NAME}/info_template.hxx.in ${CMAKE_SOURCE_DIR}/src/${PROJECT_NAME}/info.hxx.in)
configure_file(${CMAKE_SOURCE_DIR}/src/${PROJECT_NAME}/info.hxx.in ${CMAKE_SOURCE_DIR}/src/${PROJECT_NAME}/info.hxx)

add_executable(${PROJECT_NAME} xmmatrix.cxx)
set_target_properties(
    ${PROJECT_NAME} PROPERTIES
    VERSION ${${PROJECT_NAME}_VERSION}
)

set(
    TARGET_LINK_LIBRARIES,
)

foreach(TARGET_LINK_LIBRARY ${TARGET_LINK_LIBRARIES})
    target_link_libraries(${PROJECT_NAME} PRIVATE ${TARGET_LINK_LIBRARY})
endforeach(TARGET_LINK_LIBRARY ${TARGET_LINK_LIBRARIES})
