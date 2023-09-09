find_package(raylib QUIET)
if (NOT raylib_FOUND)
    include(FetchContent)

    set(LIB_NAME "raylib")
    message("Fetch Content: " ${LIB_NAME})

    FetchContent_Declare(
        ${LIB_NAME}
        GIT_REPOSITORY  https://github.com/raysan5/raylib.git
        GIT_TAG         4.5.0
        GIT_PROGRESS    TRUE
    )

    FetchContent_MakeAvailable(${LIB_NAME})
endif()