cmake_minimum_required(VERSION 3.16)
project(ELSED)

#set(CMAKE_BUILD_TYPE Release)

find_package(PythonInterp)

if (PYTHONINTERP_FOUND)
    if (UNIX AND NOT APPLE)
        if (PYTHON_VERSION_MAJOR EQUAL 3)
            find_package(Boost COMPONENTS python${PYTHON_VERSION_SUFFIX} numpy)
            find_package(PythonInterp 3)
            find_package(PythonLibs 3 REQUIRED)
        else ()
            find_package(Boost COMPONENTS python numpy)
            find_package(PythonInterp)
            find_package(PythonLibs REQUIRED)
        endif ()
    else ()
        if (PYTHON_VERSION_MAJOR EQUAL 3)
            find_package(Boost COMPONENTS python${PYTHON_VERSION_MAJOR} ${PYTHON_VERSION_MINOR} numpy)
            find_package(PythonInterp 3)
            find_package(PythonLibs 3 REQUIRED)
        else ()
            find_package(Boost COMPONENTS python${PYTHON_VERSION_MAJOR} ${PYTHON_VERSION_MINOR} numpy)
            find_package(PythonInterp)
            find_package(PythonLibs REQUIRED)
        endif ()
    endif ()
else ()
    message("Python not found")
endif ()

find_package(OpenCV REQUIRED)

include_directories(
${PROJECT_SOURCE_DIR}/src
${OpenCV_INCLUDE_DIRS}
${Boost_INCLUDE_DIRS}
${PYTHON_INCLUDE_DIRS}
)

set(LIBRARY_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/lib)

PYTHON_ADD_MODULE(pyelsed
python/pyelsed.cc
src/EdgeDrawer.cpp
src/ELSED.cpp
src/FullSegmentInfo.cpp
)

target_link_libraries(pyelsed
${OpenCV_LIBS}
${Boost_LIBRARIES}
${PYTHON_LIBRARIES}
)