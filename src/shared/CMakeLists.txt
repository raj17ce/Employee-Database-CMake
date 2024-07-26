# Add all source files in src/shared
file(GLOB SHARED_SOURCES
    ${CMAKE_SOURCE_DIR}/src/shared/*.cpp
)

# Add all header files in include/shared
file(GLOB SHARED_HEADERS
    ${CMAKE_SOURCE_DIR}/include/shared/*.h
)

# Create the Shared library
add_library(Shared STATIC
    ${SHARED_SOURCES}
    ${SHARED_HEADERS}
)

find_package(unofficial-sqlite3 REQUIRED)

if (NOT unofficial-sqlite3_FOUND)
    message(FATAL_ERROR "Could not find sqlite3")
endif()

# Include the header files in the library target
target_include_directories(Shared PUBLIC ${CMAKE_SOURCE_DIR}/include/shared)

target_link_libraries(Shared PUBLIC Controller unofficial::sqlite3::sqlite3 logician View)