cmake_minimum_required(VERSION 3.22)

project(iokit-usb-sandbox
   LANGUAGES CXX
   VERSION 0.1.0
   DESCRIPTION "IOKit USB sandbox for stupid stuff"
   HOMEPAGE_URL "https://github.com/jevinskie/naplink-ng"
)

option(IOKIT_USB_SANBOX_FORCE_COLORED_OUTPUT "Always produce ANSI-colored output (GNU/Clang only)." ON)

if(IOKIT_USB_SANBOX_FORCE_COLORED_OUTPUT)
    if("${CMAKE_CXX_COMPILER_ID}" STREQUAL "GNU")
       add_compile_options(-fdiagnostics-color=always)
    elseif("${CMAKE_CXX_COMPILER_ID}" STREQUAL "Clang" OR "${CMAKE_CXX_COMPILER_ID}" STREQUAL "AppleClang")
       add_compile_options(-fcolor-diagnostics)
    endif()
endif()

find_package(fmt REQUIRED)

add_executable(iokit-usb-sandbox iokit-usb-sandbox.cpp)
target_link_libraries(iokit-usb-sandbox PRIVATE fmt::fmt "-framework IOKit" "-framework CoreFoundation")
set_target_properties(iokit-usb-sandbox PROPERTIES
    CXX_STANDARD 20
    CXX_EXTENSIONS OFF
    CXX_STANDARD_REQUIRED ON
    CXX_VISIBILITY_PRESET hidden
    VISIBILITY_INLINES_HIDDEN ON
)

install(TARGETS iokit-usb-sandbox)
