cmake_minimum_required(VERSION 3.10)
project(TicTacToeCLI VERSION 1.0 LANGUAGES CXX)
add_executable(TicTacToeCLI main.cpp)
set(CMAKE_CXX_STANDARD_REQUIRED 11)
set(CMAKE_CXX_STANDARD_REQUIRED true)
set(EXTRA_LIBS)
set(EXTRA_INCLUDES)
configure_file(tic-tac-toe_info.h.in tic-tac-toe_info.h)
option(USE_GAMELIBS "Use provided game libraries" ON)

if(USE_GAMELIBS)
        add_subdirectory(GameLibs)
        list(APPEND EXTRA_LIBS gaem check_win_condition)
endif()

target_link_libraries(TicTacToeCLI PUBLIC ${EXTRA_LIBS})
target_include_directories(TicTacToeCLI PUBLIC 
		"${PROJECT_BINARY_DIR}"
)
