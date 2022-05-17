cmake_minimum_required(VERSION 3.12)

project(plazza CXX)

add_executable(plazza
    "src/main.cpp"
    "src/Reception.cpp"
    "src/com/NamedPipes.cpp"
    "src/cond/CCondVar.cpp"
    "src/kitchen/Kitchen.cpp"
    "src/kitchen/pizzas/APizza.cpp"
    "src/kitchen/pizzas/Serializer.cpp"
    "src/mutex/CMutex.cpp"
    "src/process/CProcess.cpp"
    "src/thread/CThread.cpp"
    "src/thread/ThreadPool.cpp"
    "src/thread/Jobs.cpp"
)

target_include_directories(plazza PRIVATE "${CMAKE_SOURCE_DIR}/include")
set_target_properties(plazza PROPERTIES RUNTIME_OUTPUT_DIRECTORY "${CMAKE_SOURCE_DIR}/")
