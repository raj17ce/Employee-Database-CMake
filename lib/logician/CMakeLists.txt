# Add all logician files
file(GLOB LOGICIAN_FILES
    ${CMAKE_SOURCE_DIR}/lib/logician/*.h ${CMAKE_SOURCE_DIR}/lib/logician/*.cpp
)

# Create the View library
add_library(logician STATIC
    ${LOGICIAN_FILES}
)

# Include the header files in the library target
target_include_directories(logician PUBLIC ${CMAKE_SOURCE_DIR}/lib/logician)