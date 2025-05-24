set(TTTU_Headers
    utils.hpp
    )

set(TTTU_Impl
    utils.cpp   
    )

add_library(TTTU_Objects OBJECT
    ${TTTU_Headers}    
    ${TTTU_Impl}
    )

target_include_directories(TTTU_Objects
    PUBLIC
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/..>
    $<INSTALL_INTERFACE:include>    
    )

add_library(TTTU $<TARGET_OBJECTS:TTTU_Objects>)

add_library(TTTU::TTTU ALIAS TTTU)

set_target_properties(TTTU PROPERTIES
    CXX_EXTENSIONS NO
    CXX_STANDARD 23
    CXX_STANDARD_REQUIRED YES
    COMPILE_OPTIONS "-O3 -Wall -Wextra -Wpedantic -Werror -std=c++23"
    PUBLIC_HEADER "${TTTU_Headers}"
    )

target_compile_options(TTTU PRIVATE "-std=c++23")

include(GNUInstallDirs)

install(TARGETS TTTU TTTU_Objects
    EXPORT TTTU_Targets
    RUNTIME DESTINATION ${CMAKE_INSTAL_BINDIR}
    LIBRARY DESTINATION ${CMAKE_INSTAL_LIBDIR}
    ARCHIVE DESTINATION ${CMAKE_INSTAL_LIBDIR}
    PUBLIC_HEADER DESTINATION ${CMAKE_INSTAL_INCLUDEDIR}/src
    )

install(EXPORT TTTU_Targets
    FILE TTTU_Targets.cmake
    NAMESPACE TTTU::
    DESTINATION ${CMAKE_INSTAL_LIBDIR}/cmake/src
    )