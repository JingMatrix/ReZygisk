#include "daemon.h"
#include "logging.h"
#include "zygisk.hpp"

using namespace std;

void *start_addr = nullptr;
size_t block_size = 0;

extern "C" [[gnu::visibility("default")]]
void entry(void* addr, size_t size, const char* path) {
    LOGI("Zygisk library injected, version %s", ZKSU_VERSION);
    start_addr = addr;
    block_size = size;
    zygiskd::Init(path);

    if (!zygiskd::PingHeartbeat()) {
        LOGE("Zygisk daemon is not running");
        return;
    }

#ifdef NDEBUG
    logging::setfd(zygiskd::RequestLogcatFd());
#endif

    LOGI("Start hooking, call %p", hook_functions);
    hook_functions();
    clean_trace(path);
}
