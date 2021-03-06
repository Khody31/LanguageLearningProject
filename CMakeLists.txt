cmake_minimum_required(VERSION 3.17)
project(language_learning)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_PREFIX_PATH "~/Qt/5.15.2/gcc_64/lib/cmake")
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

set(QT_VERSION 5)
set(REQUIRED_LIBS Core Gui Widgets Multimedia)
set(REQUIRED_LIBS_QUALIFIED Qt5::Core Qt5::Gui Qt5::Widgets Qt5::Multimedia)

add_executable(${PROJECT_NAME} main.cpp main_menu.cpp main_menu.h translation_exercise_widget.cpp translation_exercise_widget.h translation_exercise.cpp translation_exercise.h exercise.cpp exercise.h grammar_exercise.cpp grammar_exercise.h grammar_exercise_widget.cpp grammar_exercise_widget.h main_window.cpp main_window.h result_widget.cpp result_widget.h statistics.cpp statistics.h model.cpp model.h exercise_widget.cpp exercise_widget.h help_widget.cpp help_widget.h user_records.cpp user_records.h enums.h records_widget.cpp records_widget.h)

if (NOT CMAKE_PREFIX_PATH)
    message(WARNING "CMAKE_PREFIX_PATH is not defined, you may need to set it "
            "(-DCMAKE_PREFIX_PATH=\"path/to/Qt/lib/cmake\" or -DCMAKE_PREFIX_PATH=/usr/include/{host}/qt{version}/ on Ubuntu)")
endif ()

find_package(Qt${QT_VERSION} COMPONENTS ${REQUIRED_LIBS} REQUIRED)
target_link_libraries(${PROJECT_NAME} ${REQUIRED_LIBS_QUALIFIED})
