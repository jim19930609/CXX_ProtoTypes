#pragma once

extern "C" {
    void* ti_create_runtime();

    void ti_destroy_runtime(void* runtime);
}
