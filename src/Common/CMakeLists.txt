set(
    PROJECT_NAME 
    Common
)

string(TOUPPER "${PROJECT_NAME}" PROJECT)

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

set(
    SOURCE_FILES
    Camera
    #d3dApp
    #d3dUtil
    DDSTextureLoader
    GameTimer
    GeometryGenerator
    MathHelper
)

foreach(SOURCE ${SOURCE_FILES})
    add_library(${SOURCE} STATIC ${SOURCE}.cxx)
    install(TARGETS ${SOURCE}
        ARCHIVE DESTINATION lib
        LIBRARY DESTINATION lib
    )
    target_include_directories(${SOURCE} PUBLIC include)
endforeach(SOURCE ${SOURCE_FILES})

add_library(${PROJECT_NAME} STATIC ${PROJECT_NAME}.cxx)

target_include_directories(${PROJECT_NAME} PUBLIC include)

set_target_properties(${PROJECT_NAME} PROPERTIES
    VERSION ${PROJECT_VERSION}
    SOVERSION ${PROJECT_VERSION_MAJOR}
)

install(TARGETS ${PROJECT_NAME}
    ARCHIVE DESTINATION lib
    LIBRARY DESTINATION lib
)
install(DIRECTORY include/ DESTINATION include)
