cmake_minimum_required (VERSION 3.8)

project(GUI) 

#头文件变量:GLFW、 IMGUI、 glad、Lua
set(GUIEXTRA_INCLUDE 
    ${CMAKE_SOURCE_DIR}/lib/GLFW/include 

    ${CMAKE_SOURCE_DIR}/lib/imgui 

    ${CMAKE_SOURCE_DIR}/lib/glad/include
    ${CMAKE_SOURCE_DIR}/lib/glad/include/glad

    ${CMAKE_SOURCE_DIR}/lib/lua/include 
)
  
#源文件变量: IMGUI、 glad
set(GUIEXTRA_SOURCES_IMGUI  
    ${CMAKE_SOURCE_DIR}/lib/imgui/imgui.cpp 
    ${CMAKE_SOURCE_DIR}/lib/imgui/imgui_draw.cpp 
    ${CMAKE_SOURCE_DIR}/lib/imgui/imgui_impl_glfw.cpp 
    ${CMAKE_SOURCE_DIR}/lib/imgui/imgui_impl_opengl3.cpp 
    ${CMAKE_SOURCE_DIR}/lib/imgui/imgui_impl_win32.cpp 
    ${CMAKE_SOURCE_DIR}/lib/imgui/imgui_tables.cpp 
    ${CMAKE_SOURCE_DIR}/lib/imgui/imgui_widgets.cpp 

    ${CMAKE_SOURCE_DIR}/lib/glad/src/glad.c 
)

set(GUIEXTRA_SOURCES_GLAD ${CMAKE_SOURCE_DIR}/lib/glad/src/glad.c)

#子项目本身的源文件
set(GUI_SOURCES
    src/MainWindow.cpp
)

#静态库变量：GLFW、Lua
set(EXTRA_LIBS
    ${CMAKE_SOURCE_DIR}/lib/GLFW/lib-vc2022/glfw3.lib

    ${CMAKE_SOURCE_DIR}/lib/lua/lua54.lib
)


#生成静态库，STATIC：静态
add_library(imgui STATIC ${GUIEXTRA_SOURCES_IMGUI})
add_library(glad STATIC ${GUIEXTRA_SOURCES_GLAD})
add_library(gui STATIC ${GUI_SOURCES})

#设置库的生成路径  如果想将lib生成到项目根目录的lib下，CMAKE_BINARY_DIR改成CMAKE_SOURCE_DIR
set_target_properties(imgui PROPERTIES ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set_target_properties(glad PROPERTIES ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set_target_properties(gui PROPERTIES ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)

#导入头文件
target_include_directories(gui PUBLIC include)
target_include_directories(gui PUBLIC ${GUIEXTRA_INCLUDE})
target_include_directories(imgui PRIVATE ${GUIEXTRA_INCLUDE})
target_include_directories(glad PRIVATE ${GUIEXTRA_INCLUDE})

target_link_libraries(gui PRIVATE ${EXTRA_LIBS})
target_link_libraries(gui PRIVATE imgui)
target_link_libraries(gui PRIVATE glad)