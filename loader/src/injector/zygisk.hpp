#pragma once

#include <jni.h>

extern void *start_addr;
extern size_t block_size;

void hook_functions();

void clean_trace(const char* path);

void revert_unmount_ksu();

void revert_unmount_magisk();

void revert_unmount_apatch();
