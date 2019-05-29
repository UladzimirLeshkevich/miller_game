cmake_minimum_required(VERSION 3.14)
project(miller)

add_executable(miller game.cxx
               game_geometry.hxx
               stb_image.h
               count_for_timer.hxx
               count_for_timer.cxx
               load_texture.hxx
               save_game_time.cxx
               save_game_time.hxx
               #load_texture.cxx
               )

target_compile_features(miller PUBLIC cxx_std_17)

find_library(SDL2_LIB NAMES libSDL2.a)

if(NOT SDL2_LIB)
    message(FATAL_ERROR "Error: find_library(...) did not find libSDL2.a")
endif()

if (MINGW)
    # find out what libraries are needed for staticaly linking with libSDL.a
    # using mingw64 cross-compiler

    #$> $ /usr/x86_64-w64-mingw32/sys-root/mingw/bin/sdl2-config --static-libs
    #-L/usr/x86_64-w64-mingw32/sys-root/mingw/lib -lmingw32 -lSDL2main
    #-lSDL2 -mwindows -Wl,--no-undefined -lm -ldinput8 -ldxguid -ldxerr8 -luser32
    #-lgdi32 -lwinmm -limm32 -lole32 -loleaut32 -lshell32 -lversion -luuid
    #-static-libgcc

    target_link_libraries(${PROJECT_NAME}
               #SDL2::SDL2-static
               #SDL2::SDL2main
               -lmingw32
               -lSDL2main
               -lSDL2
               ${SDL2_LIB} # full path to libSDL2.a force to staticaly link with it
               -mwindows
               -Wl,--no-undefined
               -lm
               -ldinput8
               -ldxguid
               -ldxerr8
               -luser32
               -lgdi32
               -lwinmm
               -limm32
               -lole32
               -loleaut32
               -lshell32
               -lversion
               -luuid
               -static-libgcc
               -lopengl32
               )
elseif(UNIX)
    target_link_libraries(miller
               ${SDL2_LIB}
               -lSDL2
               -lGL

               -lm
               -ldl
               -lpthread
               -lrt
               )
endif()

file(GLOB resources "res/*")
file(COPY ${resources} DESTINATION ${CMAKE_CURRENT_BINARY_DIR}/res)









