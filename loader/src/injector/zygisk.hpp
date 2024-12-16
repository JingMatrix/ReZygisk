#pragma once

#include <jni.h>

extern void *start_addr;
extern size_t block_size;

void hook_functions();

void clean_trace(const char* path, size_t load = 1, size_t unload = 0, bool spoof_maps = false);

void revert_unmount_ksu();

void revert_unmount_magisk();

void revert_unmount_apatch();
