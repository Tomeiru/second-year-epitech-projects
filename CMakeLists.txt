cmake_minimum_required(VERSION 3.12)

project(plazza CXX)
set(CMAKE_BUILD_TYPE Debug)

add_executable(plazza
    "src/main.cpp"
    "src/ArgHandler.cpp"
    "src/Logistic.cpp"
    "src/Order.cpp"
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
set_target_properties(plazza
    PROPERTIES
        CXX_STANDARD 17
        CXX_STANDARD_REQUIRED ON
        CXX_EXTENSIONS OFF

        RUNTIME_OUTPUT_DIRECTORY "${CMAKE_SOURCE_DIR}/"
)