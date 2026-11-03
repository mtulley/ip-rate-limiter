# IP Rate Limiter

## Overview
This is a fixed window IP rate limiter.

## Implementation Details

### Fixed Window
When a new request occurs, the systems either start a 60 second window or add to the request count if a window is already open for the incoming IP address. If the IP address sends more than 5 requests in the 60 second window, their new requests will be ignored. 
