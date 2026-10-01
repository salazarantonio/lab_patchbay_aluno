cmake_minimum_required(VERSION 3.25)
project(patchbay LANGUAGES CXX VERSION 0.3.0)

set(CMAKE_CXX_STANDARD 17) #PADRAO C++17
set(CMAKE_CXX_STANDARD_REQUIRED ON) #NAO MUDA C++
set(CMAKE_CXX_EXTENSIONS OFF)

if (NOT CMAKE_BUILD_TYPE AND NOT CMAKE_CONFIGURATION_TYPES)
    set(CMAKE_BUILD_TYPE Debug CACHE STRING "" FORCE)
endif()

add_library(patch_nucleo
    src/ponto.cpp
    src/painel.cpp
    src/conectar.cpp
)
target_include_directories(patch_nucleo PUBLIC include)

target_compile_options(patch_nucle PRIVATE
    -Wall -Wextra -Wpedantic -Wshadow -Wnon-virtual-dtor -Wold-style-cast
    -Wcast-align -Wunused -Woverloaded-virtual -Wconversion -Wsign-conversion
    -Wdouble-promotion -Wformat=2 -Werror
)

option(PROJETO_TESTES "Compilar os testes (Catch2)" ON)

if (PROJETO_TESTES)
    include(FetchContent)
    FetchContent_Declare(Catch2
        GIT_REPOSITORY https://github.com/catchorg/Catch2.git
        GIT_TAG v5.0.0
        GIT_SHALLOW TRUE
        SYSTEM
    )
    FetchContent_MakeAvailable(Catch2)
    
    enable_testing()
    add_executable(testes testes/test_a.cpp)
    target_link_libraries(testes PRIVATE
        projeto_nucleo Catch2::Catch2WithMain)
    add_test(NAME testes COMMAND testes)
endif()