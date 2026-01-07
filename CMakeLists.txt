cmake_minimum_required(VERSION 3.26)
project(Jeu_Coree_2024 C)

set(CMAKE_C_STANDARD 99)

add_executable(Jeu_Coree_2024
        code/fin.c
        code/grotte.c
        code/main.c
        code/maison.c
        code/sous_main.c
        code/menu.h)


# On lie Allegro 4
target_link_libraries(Jeu_Coree_2024 -lmingw32 -lalleg44 )
