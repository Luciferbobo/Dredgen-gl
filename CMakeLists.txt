cmake_minimum_required(VERSION 3.18)
# set vcpkg dir
#SET(CMAKE_TOOLCHAIN_FILE C:/vcpkg/scripts/buildsystems/vcpkg.cmake)

project(Dredgen-gl)

set(CMAKE_CXX_STANDARD 17)

file(GLOB SOURCES ${PROJECT_SOURCE_DIR}/Dredgen-gl/*.cpp ${PROJECT_SOURCE_DIR}/Dredgen-gl/*.h)

add_executable(${PROJECT_NAME} ${SOURCES})

target_include_directories(${PROJECT_NAME} PUBLIC
    ${PROJECT_SOURCE_DIR}/Dredgen-gl
)


