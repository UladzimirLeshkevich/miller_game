cmake_minimum_required(VERSION 3.14)
project(miller)

add_executable(miller game.cxx game_geometry.hxx stb_image.h)

target_compile_features(miller PUBLIC cxx_std_17)

if (MINGW)
    target_link_libraries(miller
               -lmingw32 
               -lSDL2main 
               -lSDL2
               -mwindows
               -lopengl32
               )
elseif(UNIX)
    target_link_libraries(miller
               -lSDL2
               -lGL
               )
endif()

file(GLOB resources "res/*")
file(COPY ${resources} DESTINATION ${CMAKE_CURRENT_BINARY_DIR}/res)









