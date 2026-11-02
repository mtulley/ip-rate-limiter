cmake_minimum_required(VERSION 3.20)

project(ip-rate-limiter LANGUAGES CXX)

add_executable(ip-rate-limiter
    main.cpp
    rate-limiter/rate-limiter.cpp
    ttlcache/ttlcache.cpp
)

target_compile_features(ip-rate-limiter PRIVATE cxx_std_20)
