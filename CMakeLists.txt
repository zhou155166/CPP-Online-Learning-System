cmake_minimum_required(VERSION 3.26)
project(PieceOfShitok)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_EXE_LINKER_FLAGS "-static-libgcc -static-libstdc++")
add_executable(PieceOfShitok main.cpp
        login.cpp

        autojump.cpp

        check_all_course.cpp


        Course.cpp

        Assistant.cpp

        Teacher.cpp

        User.cpp

        worker.cpp

        Student.cpp

        notice.cpp
        homework.h
        student_score.h

)
