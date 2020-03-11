#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include "module.h"

#define RESOURCE_FIELD_COUNT 5
#define RESOURCE_TYPE_COUNT 3
#define UNITS_COUNT 8

#if (defined _TESTING)
#include "moc.hpp"
#define printf moc_printf
#define scanf moc_scanf
#endif

struct resource {
    char *cipher;
    char *name;
    size_t quantity;
    size_t unit;
    size_t resource_type;
};

struct resource_node {
    resource *current_resource;
    resource_node *previous_node;
};

resource_node ***create_resource_store() {
    resource_node ***const resource_store = (resource_node ***) calloc(RESOURCE_TYPE_COUNT, sizeof(resource_node **));
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

void free_resource_store(resource_node ***const resource_store) {
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
    return (resource_node *) calloc(1, sizeof(resource_node));
}

void free_resource_node(resource_node *node_to_free) {
    resource_node *next = NULL;
    while (node_to_free) {
        next = node_to_free->previous_node;
        free_resource(node_to_free->current_resource);
        free(node_to_free);
        node_to_free = next;
    }
}

resource *create_resource() {
    return (resource *) calloc(1, sizeof(resource));
}

void free_resource(resource *const resource) {
    free(resource->name);
    free(resource->cipher);
    free(resource);
}

resource_node ***collect_resources_data() {
    resource_node ***const resource_store = create_resource_store();
    if (!resource_store) {
        return NULL;
    }
    resource_node *node = NULL;
    while ((node = get_resource_node_from_input())) {
        node->previous_node = resource_store[node->current_resource->resource_type][node->current_resource->unit];
        resource_store[node->current_resource->resource_type][node->current_resource->unit] = node;
    }
    return resource_store;
}

resource_node *get_resource_node_from_input() {
    resource_node *node = NULL;
    node = create_resource_node();
    if (!node) {
        return NULL;
    }
    node->current_resource = create_resource();
    if (!node->current_resource) {
        return NULL;
    }
    if ((scanf("%ms %ms %lu %lu %lu", &node->current_resource->cipher, &node->current_resource->name,
               &node->current_resource->quantity, &node->current_resource->resource_type,
               &node->current_resource->unit) != RESOURCE_FIELD_COUNT) ||
        node->current_resource->resource_type >= RESOURCE_TYPE_COUNT ||
        node->current_resource->unit >= UNITS_COUNT) {
        free_resource_node(node);
        return NULL;
    }
    return node;
}

size_t **get_resources_information_from_resource_store(const resource_node ***const resource_store) {
    if (!resource_store) {
        return NULL;
    }
    size_t **information = create_resource_information();
    if (!information) {
        return NULL;
    }
    for (size_t i = 0; i < RESOURCE_TYPE_COUNT; ++i) {
        for (size_t j = 0; j < UNITS_COUNT; ++j) {
            const resource_node *researchable_node = resource_store[i][j];
            while (researchable_node) {
                information[i][j] += researchable_node->current_resource->quantity;
                researchable_node = researchable_node->previous_node;
            }
        }
    }
    return information;
}

void print_resource_information(const size_t **const information) {
    static const char *units_names[] = {"TONS",
                                        "KILOGRAMS",
                                        "LITRES",
                                        "THING",
                                        "MAN_HOUR",
                                        "MACHINE_HOUR",
                                        "METRES",
                                        "CUBIC_METRES"};

    static const char *types_names[] = {"MACHINES_AND_MECHANISMS",
                                        "RAW_MATERIALS",
                                        "WORK"};

    if (!information) {
        return;
    }
    for (size_t i = 0; i < RESOURCE_TYPE_COUNT; ++i) {
        printf("%s:\n", types_names[i]);
        for (size_t j = 0; j < UNITS_COUNT; ++j) {
            printf("\t%s = %lu\n", units_names[j], information[i][j]);
        }
    }
}

size_t **create_resource_information() {
    size_t **information = (size_t **) calloc(RESOURCE_TYPE_COUNT, sizeof(size_t *));
    if (!information) { return NULL; }
    for (size_t i = 0; i < RESOURCE_TYPE_COUNT; i++) {
        information[i] = (size_t *) calloc(UNITS_COUNT, sizeof(size_t));
        if (!information[i]) {
            free_resource_information(information);
            return NULL;
        }
    }
    return information;
}

void free_resource_information(size_t **const information) {
    if (!information) { return; }
    for (size_t i = 0; i < RESOURCE_TYPE_COUNT; ++i) {
        free(information[i]);
    }
    free(information);
}
