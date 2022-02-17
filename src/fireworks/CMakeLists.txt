include_directories(${PROJECT_SOURCE_DIR}/src)

add_library(fireworks STATIC
    fireworks.cpp particle.cpp
)

target_link_libraries(fireworks PRIVATE sfml-system sfml-graphics sfml-window)

target_include_directories(fireworks PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}
)