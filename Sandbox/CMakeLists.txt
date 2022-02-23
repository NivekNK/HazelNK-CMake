project(Sandbox)

add_executable(Sandbox src/SandboxApp.cpp)

target_compile_definitions(Sandbox PRIVATE
    $<$<CONFIG:Debug>:NK_DEBUG>
    $<$<CONFIG:RelWithDebInfo>:NK_RELEASE>
    $<$<CONFIG:Release>:NK_DIST>
)

if (CMAKE_SYSTEM_NAME STREQUAL "Windows")
    target_compile_definitions(Sandbox PRIVATE
        NK_PLATFORM_WINDOWS
    )
endif()

target_link_libraries(Sandbox PRIVATE HazelNuK)
