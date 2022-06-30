cmake_minimum_required(VERSION 3.0.0)
project(Fireworks VERSION 0.1.0)

# locate sfml
set(SFML_DIR "D:/Programs/SFML-2.5.1/lib/cmake/SFML")
set(SFML_STATIC_LIBRARIES TRUE)
find_package(SFML COMPONENTS graphics window system)

# head directory
include_directories("./include")
# .cpp files
aux_source_directory("./src" cppfiles)
# add exe
add_executable(fireworks main.cpp ${cppfiles})
# link to libraries
target_link_libraries(fireworks
  sfml-system 
  sfml-graphics 
  sfml-window
)