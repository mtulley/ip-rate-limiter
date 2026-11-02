#include "rate-limiter.h"
#include <string>

RateLimiter::RateLimiter() : cache{} {};

bool RateLimiter::addNewRequest(Request req) {
    if (!cache.contains(req.ip)) {
        cache.insert(req.ip, 1, 60);
        return true;
    }

    int numRequests = cache.get(req.ip);
    if (numRequests == 0) {
        cache.insert(req.ip, 1, 60);
        return true;
    }

    if (numRequests >= 5) {
        return false;
    }

    cache.update(req.ip, numRequests + 1);
    return true;
}

bool RateLimiter::isAtLimit(std::string_view ip) {
    if (!cache.contains(ip)) {
        return false;
    }

    int numRequests = cache.get(ip);
    return numRequests >= 5;
}
