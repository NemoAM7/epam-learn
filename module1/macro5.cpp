// logger.h
#ifndef LOGGER_H
#define LOGGER_H

#include <iostream>

// Default LOG_LEVEL if not provided
#ifndef LOG_LEVEL
#define LOG_LEVEL 3 // Default to INFO
#endif

// Macro with arguments: only print if msg_level <= LOG_LEVEL
#if LOG_LEVEL >= 4
#define LOG(level, msg) if(level <= LOG_LEVEL) printf("[DEBUG] %s\n", msg)
#elif LOG_LEVEL >= 3
#define LOG(level, msg) if(level <= LOG_LEVEL && level < 4) printf("[INFO] %s\n", msg)
#elif LOG_LEVEL >= 2
#define LOG(level, msg) if(level <= LOG_LEVEL && level < 3) printf("[WARN] %s\n", msg)
#else
#define LOG(level, msg) if(level == 1) printf("[ERROR] %s\n", msg)
#endif

// with single define
#define LOG(level, msg) \
    do { \
        if (level <= LOG_LEVEL) { \
            if (level == 1) printf("[ERROR] " msg "\n"); \
            else if (level == 2) printf("[WARN] " msg "\n"); \
            else if (level == 3) printf("[INFO] " msg "\n"); \
            else if (level == 4) printf("[DEBUG] " msg "\n"); \
        } \
    } while (0)

#endif