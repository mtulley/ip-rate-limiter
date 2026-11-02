# TTL Cache

## Overview

This is an implementation of a time-to-live cache. A time-to-live cache is an in memory key-value store where each key-value pair is initialized with a lifespan. When the key-value pair has been in the cache for longer than its lifespan, it is removed. 

## Implementation details

### Lazy removal

When a key-value pair is accessed via the get method and it's lifespan is up, it is removed. The other type of removal is eager removal where key-value pairs are actively removed when they expire rather than only when they are accessed by the user program.

### Types

The keys are strings and the values are integers. The insert method also takes a integer seconds which is the lifespan in seconds of the item. 

This is because the first use case I want to test is an IP rate limiter where keys are IP adresses (string) and values are the number of requests made (int). Of course, in the future I would like to make the TTLCache a class template to allow more types. 

## Warning

This is a learning project, not meant for use in critical systems. 
