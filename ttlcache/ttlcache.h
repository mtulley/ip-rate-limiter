#ifndef TTL_CACHE_H
#define TTL_CACHE_H

#include <string>
#include <string_view>
#include <unordered_map>
#include <chrono>

class TTLCache {
private:
    struct CacheEntry {
        int val {};
        std::chrono::time_point<std::chrono::steady_clock> timeOfInsertion {};
        std::chrono::seconds lifespan {};
    };

    std::unordered_map<std::string, CacheEntry> map;
    bool isExpired(const CacheEntry& entry) const;

public:
    void insert(std::string_view key, int val, int lifespan = 10);
    int get(std::string_view key);
    bool contains(std::string_view key);
    void update(std::string_view key, int newVal);
    TTLCache();
};

#endif
