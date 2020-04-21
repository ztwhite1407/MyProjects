/* 
 * File: orderplib.h
 * Copy: Copyright (c) 2018 Gregory C. Myers
 * BlazerID: gmyers
 * Vers: 1.0.0 04/15/2019 GCM - Original Coding
 * Desc: Header file for aggregating data functions using pointers
 */

typedef enum {
    order_shipped, order_back_ordered, order_returned
} order_status_enum;

typedef enum {
    order_id, order_customer_id, order_item_id, order_shipped_id
} order_field_enum;

typedef struct order_node {
    char order_id[10]; // 1st column
    char customer_id[20]; // 2nd column
    unsigned long item_id; // 3rd column
    unsigned short quantity; // 4th column
    char shipped_id[10]; // gets assigned after item is shipped....5th column
    char shipped_date[30]; // 6th column
    char feedback[50];
    order_status_enum order_status; // 
    struct order_node *next_order_node;
    struct order_node *prev_order_node;
} order_node_type; 

int import_orders_node(char const filename[], order_node_type *head_node);
int display_orders_node(order_node_type *head_node);
int examine_orders_node(order_node_type *head_node );
int display_order_node(order_node_type *order_node );
int export_orders_node(char const filename[], order_node_type *head_node);

int add_order_node(order_node_type *head_node,  order_node_type *order_node);
int remove_order_node(order_node_type *head_node, order_node_type *order_node);

int isa_order_all_fields_list(order_node_type *head_node, order_node_type *order_node);
int isa_order_node(order_node_type *head_node, char order_id[]);

int get_order_all_fields_list(order_node_type *head_node, order_node_type *order_node);
int get_order_node(order_node_type *head_node, char order_id[], order_node_type *order_node);

int compare_order_node(order_node_type *first_order_node, order_node_type *second_order_node);
int copy_order_node(order_node_type *destination_node, order_node_type *source_node);

int sort_orders_node(order_node_type *head_node, order_field_enum field_name, order_type order );

// add a ship function.
int ship_orders_node(order_node_type *head_node, char output_filename[]);
