//
// Created by adminu on 01.03.2020.
//

#ifndef TP_C_CPP_HW1_UTILS_H
#define TP_C_CPP_HW1_UTILS_H

typedef struct resource resource;
typedef struct resource_node resource_node;  // Stores pointer to resource and pointer to previous resource
typedef struct resource_information resource_information;  // Stores summary information for each type of resource

int get_resource_input(resource *resource);
int collect_resources_data(resource **resource_array);
void get_resources_information(resource **resource_array, resource_information *resource_information);

resource_node *create_resource_node();
void free_resource_node(resource_node *node_to_free);

resource_node ***create_resource_store();
void free_resource_store(resource_node ***resource_store);

resource *create_resource();
void free_resource(resource *resource);

int handel_error(int return_code);


#endif //TP_C_CPP_HW1_UTILS_H
