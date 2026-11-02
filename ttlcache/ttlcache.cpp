#include "ttlcache.h"
#include <stdexcept>

void TTLCache::insert(std::string_view key, int val, int lifespan) {
    CacheEntry entry{val, std::chrono::steady_clock::now(), std::chrono::seconds(lifespan)};
    map.insert_or_assign(std::string(key), entry);
}

int TTLCache::get(std::string_view key) {
    auto it = map.find(std::string(key));
    if (it == map.end()) {
        throw std::out_of_range("TTLCache key not found");
    }

    if (isExpired(it->second)) {
        map.erase(it);
        return 0;
    }

    return it->second.val;
}

bool TTLCache::contains(std::string_view key) {
    auto it = map.find(std::string(key));
    if (it == map.end()) {
        return false;
    }

    if (isExpired(it->second)) {
        map.erase(it);
        return false;
    }

    return true;
}

void TTLCache::update(std::string_view key, int newVal) {
    auto it = map.find(std::string(key));
    if (it == map.end()) {
        return;
    }

    if (isExpired(it->second)) {
        map.erase(it);
        return;
    }

    it->second.val = newVal;
}

TTLCache::TTLCache() : map{} {}

bool TTLCache::isExpired(const CacheEntry& entry) const {
    return std::chrono::steady_clock::now() - entry.timeOfInsertion >= entry.lifespan;
}
