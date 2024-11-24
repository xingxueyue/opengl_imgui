# CMakeList.txt: 顶层 CMake 项目文件，在此处执行全局配置
# 并包含子项目。
#
cmake_minimum_required (VERSION 3.8)

project ("imguiDemo")

#编译主程序
add_executable(IMGUIDemo main.cpp)

# 包含子项目。
add_subdirectory ("GUI")

target_include_directories(IMGUIDemo PRIVATE GUI/include)

target_link_libraries(IMGUIDemo PRIVATE gui)
