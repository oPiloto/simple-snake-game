find_package(raylib_cpp QUIET)
if (NOT raylib_cpp_FOUND)
    include(FetchContent)

    set(LIB_NAME "raylib_cpp")
    message("Fetch Content: " ${LIB_NAME})

    FetchContent_Declare(
        ${LIB_NAME}
        GIT_REPOSITORY  https://github.com/RobLoach/raylib-cpp.git
        GIT_TAG         v4.5.1
        GIT_PROGRESS    TRUE
    )

    FetchContent_MakeAvailable(${LIB_NAME})
    set_property(TARGET ${LIB_NAME} PROPERTY CXX_STANDARD 11)
endif()