# Add all source files in src/controller
file(GLOB CONTROLLER_SOURCES
    ${CMAKE_SOURCE_DIR}/src/controller/*.cpp
)

# Add all header files in include/controller
file(GLOB CONTROLLER_HEADERS
    ${CMAKE_SOURCE_DIR}/include/controller/*.h
)

# Create the Controller library
add_library(Controller STATIC
    ${CONTROLLER_SOURCES}
    ${CONTROLLER_HEADERS}
)

# Include the header files in the library target
target_include_directories(Controller PUBLIC ${CMAKE_SOURCE_DIR}/include/controller)

target_link_libraries(Controller PUBLIC Model Shared)