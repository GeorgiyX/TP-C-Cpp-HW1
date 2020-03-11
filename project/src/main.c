#include <stdio.h>
#include "module.h"

int main() {
    printf("Type resources information:\n");
    resource_node ***const resource_store = collect_resources_data();
    if (!resource_store) {
        return -1;
    }

    size_t **const resource_information = get_resources_information_from_resource_store(
            (const resource_node ***) resource_store);
    if (!resource_information) {
        free_resource_store(resource_store);
        return -1;
    }

    print_resource_information((const size_t **) resource_information);
    free_resource_store(resource_store);
    free_resource_information(resource_information);
    return 0;
}
