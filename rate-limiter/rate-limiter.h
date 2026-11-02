#ifndef RATE_LIMITER_H
#define RATE_LIMITER_H

#include <string>
#include "../ttlcache/ttlcache.h"

struct Request {
    std::string ip;
};

class RateLimiter {
private:
    TTLCache cache;

public:
    bool addNewRequest(Request req);
    bool isAtLimit(std::string_view ip);
    RateLimiter();
};

#endif
