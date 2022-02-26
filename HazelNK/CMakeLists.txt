project(HazelNuK)

set(GLFW_BUILD_DOCS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_TESTS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_EXAMPLES OFF CACHE BOOL "" FORCE)

add_compile_definitions(
    $<$<CONFIG:Debug>:NK_DEBUG>
    $<$<CONFIG:RelWithDebInfo>:NK_RELEASE>
    $<$<CONFIG:Release>:NK_DIST>
    NK_BUILD_DLL
)

if (CMAKE_SYSTEM_NAME STREQUAL "Windows")
    add_compile_definitions(
        NK_PLATFORM_WINDOWS
    )
endif()

add_subdirectory(vendor/fmt)
add_subdirectory(vendor/spdlog)
add_subdirectory(vendor/eventpp)
add_subdirectory(vendor/GLFW)
add_subdirectory(vendor/glad)
add_subdirectory(vendor/ImGui)

file(GLOB SOURCES CMAKE_CONFIGURE_DEPENDS
    src/*.cpp
    src/*.h
    src/Hazel/*.cpp
    src/Hazel/*.h
    src/Hazel/Events/*.cpp
    src/Hazel/Events/*.h
    src/Hazel/ImGui/*.cpp
    src/Hazel/ImGui/*.h
    src/Platform/OpenGL/*.cpp
    src/Platform/OpenGL/*.h
    src/Platform/Windows/*.cpp
    src/Platform/Windows/*.h
)

add_library(HazelNuK SHARED ${SOURCES})

#find_package(OpenGL REQUIRED)

target_link_libraries(HazelNuK PUBLIC
    fmt::fmt
    spdlog
    glfw
    glad
    ImGui
    #OpenGL::GL
)

target_precompile_headers(HazelNuK PUBLIC src/nkpch.h)

target_include_directories(HazelNuK
PUBLIC
    src
    src/Hazel
    src/Platform

    vendor/fmt/include
    vendor/spdlog/include
    vendor/eventpp/include
    vendor/ImGui/imgui
PRIVATE
    vendor/GLFW/include
    vendor/glad/include
)

target_include_directories(spdlog
PRIVATE
    vendor/fmt/include
)
