//
// Created by adminu on 01.03.2020.
//

#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include "utils.h"

typedef enum resource_type {
    MACHINES_AND_MECHANISMS,
    RAW_MATERIALS,
    WORK,
    RESOURCE_TYPE_COUNT
} resource_type;

typedef enum units {
    TONS,
    KILOGRAMS,
    LITRES,
    THING,
    MAN_HOUR,
    MACHINE_HOUR,
    METRES,
    CUBIC_METRES,
    UNITS_COUNT
} units;

struct resource {
    char *cipher;
    char *name;
    size_t quantity;
    enum units unit;
    enum resource_type resourceType;
};

struct resource_node {
    resource *current_resource;
    resource_node *previous_node;
};


int get_resource_input(resource *resource) {

    return 0;
}

int collect_resources_data(resource **resource_array) {
    return 0;
}

resource_node ***create_resource_store() {
    resource_node ***resource_store = (resource_node ***) calloc(RESOURCE_TYPE_COUNT, sizeof(resource_node **));
    if (!resource_store) { return NULL; }
    for (size_t i = 0; i < RESOURCE_TYPE_COUNT; i++) {
        resource_store[i] = (resource_node **) calloc(UNITS_COUNT, sizeof(resource_node *));
        if (!resource_store[i]) {
            free_resource_store(resource_store);
            return NULL;
        }
    }
    return resource_store;
}

void free_resource_store(resource_node ***resource_store) {
    if (!resource_store) { return; }
    for (size_t i = 0; i < RESOURCE_TYPE_COUNT; ++i) {
        if (!resource_store[i]) { continue; }
        for (size_t j = 0; j < UNITS_COUNT; ++j) {
            if (!resource_store[i][j]) { continue; }
            free_resource_node(resource_store[i][j]);
        }
        free(resource_store[i]);
    }
    free(resource_store);
}

resource_node *create_resource_node() {
    resource_node *node = (resource_node*) calloc(1, sizeof(resource_node));
    return node;
}

void free_resource_node(resource_node *node_to_free) {
    resource_node* next = NULL;
    while(node_to_free) {
        next = node_to_free->previous_node;
        free_resource(node_to_free->current_resource);
        free(node_to_free);
        node_to_free = next;
    }
}
