add_library(gaem gaem.cpp)
add_library(check_win_condition check_win_condition.cpp)

target_include_directories(gaem
        INTERFACE ${CMAKE_CURRENT_SOURCE_DIR}
        )
target_include_directories(check_win_condition
        INTERFACE ${CMAKE_CURRENT_SOURCE_DIR}
        )


