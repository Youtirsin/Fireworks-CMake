include_directories(${PROJECT_SOURCE_DIR}/src)

add_executable(main main.cpp)

target_link_libraries(main PRIVATE fireworks)
target_link_libraries(main PRIVATE sfml-system sfml-graphics sfml-window)

install (TARGETS main
    RUNTIME DESTINATION bin
)

