cmake_minimum_required(VERSION 3.23)
project(Seminar2_GestiuneMelodii_AlocareDinamica C)

set(CMAKE_C_STANDARD 11)

include_directories(Seminar2_GestiuneMelodii_AlocareDinamica)

add_executable(Seminar2_GestiuneMelodii_AlocareDinamica
        Seminar2_GestiuneMelodii_AlocareDinamica/Masina.c
        Seminar2_GestiuneMelodii_AlocareDinamica/Masina.h
        Seminar2_GestiuneMelodii_AlocareDinamica/my_utils.c
        Seminar2_GestiuneMelodii_AlocareDinamica/my_utils.h
        Seminar2_GestiuneMelodii_AlocareDinamica/MyList.c
        Seminar2_GestiuneMelodii_AlocareDinamica/MyList.h
        Seminar2_GestiuneMelodii_AlocareDinamica/service.c
        Seminar2_GestiuneMelodii_AlocareDinamica/service.h
        Seminar2_GestiuneMelodii_AlocareDinamica/ui.c)
