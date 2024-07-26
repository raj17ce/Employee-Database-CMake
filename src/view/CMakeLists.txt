# Add all source files in src/view
file(GLOB VIEW_SOURCES
    ${CMAKE_SOURCE_DIR}/src/view/*.cpp
)

# Add all header files in include/view
file(GLOB VIEW_HEADERS
    ${CMAKE_SOURCE_DIR}/include/view/*.h
)

# Create the View library
add_library(View STATIC
    ${VIEW_SOURCES}
    ${VIEW_HEADERS}
)

# Include the header files in the library target
target_include_directories(View PUBLIC ${CMAKE_SOURCE_DIR}/include/view)

target_link_libraries(View PUBLIC Controller Shared)