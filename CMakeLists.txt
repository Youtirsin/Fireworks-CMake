cmake_minimum_required(VERSION 3.0.0)
project(Fireworks VERSION 0.1.0)

include(CTest)
enable_testing()

set(CMAKE_CXX_STANDARD 11)

find_package(SFML COMPONENTS system window graphics CONFIG REQUIRED)

install(IMPORTED_RUNTIME_ARTIFACTS system window graphics
    LIBRARY DESTINATION lib
    LIBRARY DESTINATION lib
    LIBRARY DESTINATION lib
)

add_subdirectory(src/fireworks)
add_subdirectory(src)

include(InstallRequiredSystemLibraries)
set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
