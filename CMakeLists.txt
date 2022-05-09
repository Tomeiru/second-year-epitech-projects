cmake_minimum_required(VERSION 3.12)

project(plazza CXX)

add_executable(plazza
    "src/main.cpp"
    "src/thread/CThread.cpp"
    "src/mutex/CMutex.cpp"
    "src/process/CProcess.cpp"
    "src/com/NamedPipes.cpp"
)

target_include_directories(plazza PRIVATE "${CMAKE_SOURCE_DIR}/include")
set_target_properties(plazza PROPERTIES RUNTIME_OUTPUT_DIRECTORY "${CMAKE_SOURCE_DIR}/")
