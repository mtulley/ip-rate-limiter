#include "./rate-limiter/rate-limiter.h"
#include <string>
#include <iostream>
#include <chrono>
#include <thread>

int main() {
    RateLimiter limiter{};

    std::string ip = "0.0.0.0";
    Request req1 { ip };

    for (int i = 0; i < 3; i++) {
        limiter.addNewRequest(req1);
    }

    std::cout << (limiter.isAtLimit(ip) ? "true" : "false") << std::endl;

    limiter.addNewRequest(req1);
    limiter.addNewRequest(req1);

    std::cout << (limiter.isAtLimit(ip) ? "true" : "false") << std::endl;

    std::this_thread::sleep_for(std::chrono::seconds(61));

    std::cout << (limiter.isAtLimit(ip) ? "true" : "false") << std::endl;
}
