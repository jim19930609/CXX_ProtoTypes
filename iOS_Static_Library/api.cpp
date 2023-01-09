#include "api.hpp"
#include "deps/impl.hpp"

void* ti_create_runtime() {
    float res = compute_result(5);
    void* ret = (void*) &res;

    return ret;
}

void ti_destroy_runtime(void* runtime) {
    
}
