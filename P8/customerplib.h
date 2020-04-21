/* 
 * File: customerplib.h
 * Copy: Copyright (c) 2018 Gregory C. Myers
 * BlazerID: gmyers
 * Vers: 1.0.0 04/15/2019 GCM - Original Coding
 * Desc: Header file for aggregating data functions using pointers
 */

typedef enum {
    customer_active, customer_inactive
} customer_status_enum;

typedef enum {
    customer_id, customer_last_name, customer_state
} customer_field_enum;

typedef struct customer_node {
    char customer_id[10]; // blazer id
    char customer_last_name[20];
    char customer_first_name[20];
    char customer_address[50];
    char customer_city[20];
    char customer_state[3];
    char customer_zip[10];
    customer_status_enum customer_status;
    struct customer_node *next_customer_node;
    struct customer_node *prev_customer_node;
} customer_node_type; 

int import_customers_node(char const filename[], customer_node_type *head_node);
int display_customers_node(customer_node_type *head_node);
int examine_customers_node(customer_node_type *head_node );
int display_customer_node(customer_node_type *customer_node );
int export_customers_node(char const filename[], customer_node_type *head_node);

int add_customer_node(customer_node_type *head_node,  customer_node_type *customer_node);
int remove_customer_node(customer_node_type *head_node, customer_node_type *customer_node);

int isa_customer_all_fields_list(customer_node_type *head_node, customer_node_type *customer_node);
int isa_customer_node(customer_node_type *head_node, char customer_id[]);

int get_customer_all_fields_list(customer_node_type *head_node, customer_node_type *customer_node);
int get_customer_node(customer_node_type *head_node, char customer_id[], customer_node_type *customer_node);

int compare_customer_node(customer_node_type *first_customer_node, customer_node_type *second_customer_node);
int copy_customer_node(customer_node_type *destination_node, customer_node_type *source_node);

int sort_customers_node(customer_node_type *head_node, customer_field_enum field_name, order_type order);