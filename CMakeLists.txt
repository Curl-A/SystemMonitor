cmake_minimum_required(VERSION 3.10)

project(SystemMonitor)

set(CMAKE_CXX_STANDARD 17)

add_executable(sysmon src/main.cpp src/monitor_memory.cpp src/monitor_cpu.cpp src/monitor_net.cpp src/metrics.cpp)

target_include_directories(sysmon PRIVATE include)
