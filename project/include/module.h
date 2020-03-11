#ifndef TP_C_CPP_HW1_MODULE_H
#define TP_C_CPP_HW1_MODULE_H

typedef struct resource resource;
typedef struct resource_node resource_node;  // Stores pointer to resource and pointer to previous resource

resource_node ***collect_resources_data();
resource_node *get_resource_node_from_input();
size_t **get_resources_information_from_resource_store(const resource_node ***resource_store);
void print_resource_information(const size_t **information);

resource_node *create_resource_node();
void free_resource_node(resource_node *node_to_free);

resource_node ***create_resource_store();
void free_resource_store(resource_node ***resource_store);

resource *create_resource();
void free_resource(resource *resource);

size_t **create_resource_information();
void free_resource_information(size_t **information);

#endif //TP_C_CPP_HW1_MODULE_H
