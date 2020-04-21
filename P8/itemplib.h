/* 
 * File: itemplib.h
 * Copy: Copyright (c) 2018 Gregory C. Myers
 * BlazerID: gmyers
 * Vers: 1.0.0 04/15/2019 GCM - Original Coding
 * Desc: Header file for aggregating data functions using pointers
 */



typedef enum {
    item_active, item_inactive
} item_status_enum;

typedef enum {
    item_id, item_price, item_quantity_actual, item_status
} item_field_enum;

typedef struct item_node {
    unsigned long item_id;
    char item_description[50];
    double item_price;
    int item_quantity_ideal;
    int item_quantity_actual;
    item_status_enum item_status;
    struct item_node *next_item_node;
    struct item_node *prev_item_node;
} item_node_type; 

int import_items_node(char const filename[], item_node_type *head_node);
int display_items_node(item_node_type *head_node);
int examine_items_node(item_node_type *head_node );
int display_item_node(item_node_type *item_node );
int export_items_node(char const filename[], item_node_type *head_node);

int add_item_node(item_node_type *head_node,  item_node_type *item_node);
int remove_item_node(item_node_type *head_node, item_node_type *item_node);

int isa_item_all_fields_list(item_node_type *head_node, item_node_type *item_node);
int isa_item_node(item_node_type *head_node, unsigned long item_id);

int get_item_all_fields_list(item_node_type *head_node, item_node_type *item_node);
int get_item_node(item_node_type *head_node, char item_id[], item_node_type *item_node);

int compare_item_node(item_node_type *first_item_node, item_node_type *second_item_node);
int copy_item_node(item_node_type *destination_node, item_node_type *source_node);

int sort_items_node(item_node_type *head_node, item_field_enum field_name, order_type order);
