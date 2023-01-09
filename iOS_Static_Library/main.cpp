#include "c_api/api.hpp"

int main() {
    void* runtime = ti_create_runtime();

    ti_destroy_runtime(runtime);

    return 0;
}
