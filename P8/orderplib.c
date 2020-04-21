/* 
 * File: oderplib.c
 * Copy: Copyright (c) 2018 Gregory C. Myers
 * BlazerID: ztwhite
 * Vers: 2.0.0 04/09/2018 GCM - Presented Spring 2018
 * Vers: 1.0.0 04/09/2018 GCM - Original Coding
 * Desc: Code file for implementing datalib.h
 */

#include <stdio.h>
#include <stdlib.h> 
#include <string.h>
#include "customerplib.h"
#include "coreinv.h"
#include "dataplib.h"
#include "itemplib.h"
#include "corelib.h"


int import_orders_node(char const filename[], order_node_type *head_node) {
    FILE *input;
    // int index;
    int is_head_node;
    order_node_type *current_node;
    char line[ line_length_max ];
    char chunks[ chunk_count_max ][ chunk_length_max ];
    int count;
   
    
    count = 0;
    is_head_node = 1;
    input = fopen("orders.csv", "r");
    // we could check for an open file, or we could rely on our file_read_line.
    //either,,,
    //  max the array size via a constant in the .h file
    //  or use dynamic memory allocation and continue if and only if
    //  memory was successfully allocated. 
    
    while (file_read_line(input, line ) > 0 ) {
        // we at least have some data (we have no idea if it is valid)
        // we know it is a valid line of data if we can split it into 4 chunks.
        if (string_split( line, ',' , chunks ) == 4) {
            // then we know that our line of data had four columns
            // before you blindly accept a value, 
            // check the length...
            // validate your data...
            if (is_head_node == 1) {
                current_node = head_node;
                
                strcpy( current_node->order_id, chunks[ 0 ] );
                strcpy( current_node->customer_id, chunks[ 1 ] );
                strcpy( current_node->item_id, chunks[ 2 ] );
                strcpy( current_node->quantity, chunks[ 3 ] );
                strcpy( current_node->shipped_id, chunks[ 4 ] );
                strcpy( current_node->shipped_date, chunks[ 5 ] );
                strcpy( current_node->feedback, chunks[ 6 ] );
                strcpy( current_node->order_status, chunks[ 7 ] );
                
                current_node->next_order_node = NULL;
                
                is_head_node = 0;
                count = 1;
                
                
        } else {
            
                current_node->next_order_node = (customer_node_type *) malloc(sizeof(customer_node_type ));
                
                current_node = current_node->next_order_node;
                strcpy( current_node->order_id, chunks[ 0 ] );
                strcpy( current_node->customer_id, chunks[ 1 ] );
                strcpy( current_node->item_id, chunks[ 2 ] );
                strcpy( current_node->quantity, chunks[ 3 ] );
                strcpy( current_node->shipped_id, chunks[ 4 ] );
                strcpy( current_node->shipped_date chunks[ 5 ] );
                strcpy( current_node->feedback, chunks[ 6 ] );
                strcpy( current_node->order_status, chunks[ 7 ] );
                
                current_node->next_order_node = NULL;
                count = count + 1;
                
                
            }
        } else {
            
        }
    }
    
    fclose( input );   
    // update the count using the count variable...
    // return( *count > 0 );
    return( count ); // return success or failure.


}
    

int display_orders_node(order_node_type *head_node) {
    // loop through your linked list looking for what?
    // current_node->next_student_node == NULL
    order_node_type *current_node;
    int count; 
    
    count = 0;
    if (head_node == NULL) {
        // no valid linked list...
        printf("Warning: No valid linked list.\n");
    } else if (head_node ->next_order_node == head_node) {
        // it points to itself...
        printf("Warning: No valid linked list.\n");
    } else {
        current_node = head_node;
        while (current_node != NULL) {
            display_order_node( current_node);
            current_node = current_node->next_order_node; // moves to the next 
            // element in the linked list...
            count++;
        }
    }
    return( count );   
}
int examine_orders_node(order_node_type *head_node ){
    order_node_type *current_node;

    current_node = head_node;
    
    printf("Description                                 Value\n");
    printf("===============================================================\n");
    printf("Address of head_node                            %p\n", head_node);    
    printf("head_node.order_id                           %s\n", head_node->order_id);
    printf("head_node.customer_id                        %s\n", head_node->customer_id);
    printf("head_node.item_id                             %ld\n", head_node->item_id);
    printf("head_node.quantity                             %ld\n", head_node->quantity);
    printf("head_node.shipped_id                             %s\n", head_node->shipped_id);
    printf("head_node.shipped_date                             %s\n", head_node->shipped_date);
    printf("head_node.feedback                             %s\n", head_node->feedback);
    printf("head_node.order_status                             %s\n", head_node->order_status);


    
    printf("Address of head_node.order_id                 %p\n", &(head_node->order_id));
    printf("Address of head_node.customer_id             %p\n", &(head_node->customer_id));
    printf("Address of head_node.item_id                  %p\n", &(head_node->item_id));
    printf("Address of head_node.quantity                  %p\n", &(head_node->quantity));
    printf("Address of head_node.shipped_id                  %p\n", &(head_node->shipped_id));
    printf("Address of head_node.shipped_date                  %p\n", &(head_node->shipped_date));
    printf("Address of head_node.feedback                  %p\n", &(head_node->feedback));
    printf("Address of head_node.order_status                  %p\n", &(head_node->order_status));
    printf("Address of head_node.next_order_node          %p\n", head_node->next_order_node);
    printf("===============================================================\n");
    
    while (current_node != NULL) {
        printf("Address of current_node                         %p\n", current_node);    
        printf("current_node.order_id                         %s\n", current_node->order_id);
        printf("current_node.customer_id                     %s\n", current_node->customer_id);
        printf("current_node.item_id                          %ld\n", current_node->item_id);
        printf("current_node.quantity                          %ld\n", current_node->quantity);           
        printf("current_node.shipped_id                         %s\n", current_node->shipped_id);
        printf("current_node.shipped_date                     %s\n", current_node->shipped_date);
        printf("current_node.feedback                          %s\n", current_node->feedback);
        printf("current_node.order_status                          %s\n", current_node->order_status);
        
        
        
        
        printf("Address of current_node.order_id              %p\n", &(current_node->order_id));
        printf("Address of current_node.customer_id          %p\n", &(current_node->customer_id));
        printf("Address of current_node.item_id               %p\n", &(current_node->item_id));
        printf("Address of current_node.quantity               %p\n", &(current_node->quantity));
        printf("Address of current_node.shipped_id              %p\n", &(current_node->shipped_id));
        printf("Address of current_node.shipped_date          %p\n", &(current_node->shipped_date));
        printf("Address of current_node.feedback               %p\n", &(current_node->feedback));
        printf("Address of current_node.order_status               %p\n", &(current_node->order_status));
        printf("Address of current_node.next_order_node       %p\n", current_node->next_order_node);
        
        current_node = current_node->next_order_node;
    }
    printf("===============================================================\n");
    return( 0 );    
}
int display_order_node(order_node_type *order_node ) {
    // loop through your linked list looking for what?
    // current_node->next_student_node == NULL
    order_node_type *current_node;
    int count; 
    
    count = 0;
    if (order_node == NULL) {
        // no valid linked list...
        printf("Warning: No valid linked list.\n");
    } else if (order_node ->next_order_node == order_node) {
        // it points to itself...
        printf("Warning: No valid linked list.\n");
    } else {
        current_node = order_node;
        while (current_node != NULL) {
            display_order_node( current_node);
            current_node = current_node->next_order_node; // moves to the next 
            // element in the linked list...
            count++;
        }
    }
    return( count );       
   
}
int export_orders_node(char const filename[], order_node_type *head_node) {
    FILE *output;
    order_node_type *current_node;
    
    output = fopen( "orders.csv", "w");
    if (head_node == NULL) {
        // no valid linked list...
        printf("Warning: No valid linked list.\n");
    } else if (head_node->next_order_node == head_node) {
        // it points to itself...
        printf("Warning: No valid linked list.\n");
    } else {
        current_node = head_node;
        while (current_node != NULL) {
            // display_student_node( current_node);
            fprintf(output, "%s, %s, %s, %s, %s, %s, %s\n", current_node-> customer_id,
                    current_node-> order_id,
                    current_node-> customer_id,
                    current_node-> item_id, 
                    current_node-> quantity, 
                    current_node-> shipped_id,
                    current_node-> shipped_date,
                    current_node-> order_status);
            
            current_node = current_node->next_order_node; // moves to the next 
            // element in the linked list...
            count++;
        }
    }
    
    fclose(output);
}

int add_order_node(order_node_type *head_node,  order_node_type *order_node) {
    // validate the properties of the student as well as checking that the pointer 
    // is not NULL.
    // enumerate through our linked list...
    //  comparing to see if the student already exists.
    //  if no existing student is found...
    //      add them. 
    
    int found;
    order_node_type *current_node;
    found = 0;
    
    if (head_node == NULL) {
        // we have an invalid linked list...
    } else if (head_node->next_order_node == head_node ) {
        copy_order_node(head_node, customer_node);
        head_node->next_order_node == NULL; // Consider handling this inside/outside
    } else {
        current_node = head_node;
        while ((current_node->next_order_node != NULL) && (found == 0)) {
            if (compare_order_node(current_node, customer_node) == 0) {
                found = 1;
            } else {
                current_node = current_node->next_order_node;
            }
        }
    }
   
    if(found == 1) {
   
    } else if (compare_order_node(current_node, customer_node) == 1) {
        current_node->next_order_node = (order_node_type *) malloc(sizeof(order_node_type ));
        copy_order_node( current_node->next_order_node, order_node );
    }
    
    return(found);
    
}
int remove_order_node(order_node_type *head_node, order_node_type *order_node);

int isa_order_all_fields_list(order_node_type *head_node, order_node_type *order_node) {
    // return true or false...j
    int found;
    order_node_type *current_node;
    found = 0;
    
    if (head_node == NULL) {
        found = 0;
    } else if (head_node->next_order_node == head_node) {
        found - 0;
    } else {
        current_node = head_node;
        while (current_node != NULL ) {
            if (compare_order_node(current_node, order_node) == 0) {
                found = 1;
                break;
            }
            current_node = current_node->next_order_node;
        }
    }
    
    return(found);
}
int isa_order_node(order_node_type *head_node, char order_id[]);

int get_order_all_fields_list(order_node_type *head_node, order_node_type *order_node);
int get_order_node(order_node_type *head_node, char order_id[], order_node_type *order_node);

int compare_order_node(order_node_type *first_order_node, order_node_type *second_order_node) {
    int results;
    
    // (1 == 1)
    
    results = (((string_compare( first_order_node->order_id, second_order_node->order_id, case_sensitive) == 0) && 
                string_compare(first_order_node->customer_id, second_order_node->customer_id, case_sensitive) == 0 &&
                string_compare(first_order_node->item_id, second_order_node->item_id, case_sensitive) == 0 &&
                string_compare(first_order_node->quantity, second_order_node->quantity, case_sensitive) == 0 &&
                string_compare(first_order_node->shipped_id, second_order_node->shipped_id, case_sensitive) == 0 &&
                string_compare(first_order_node->shipped_date, second_order_node->shipped_id, case_sensitive) == 0 &&
                string_compare(first_order_node->feedback, second_order_node->feedback, case_sensitive) == 0 &&
                string_compare(first_order_node->order_status, second_order_node->order_status, case_sensitive) == 0));
    
    return( !results );
}
int copy_order_node(order_node_type *destination_node, order_node_type *source_node) {
    strcpy( destination_node->order_id, source_node->order_id);
    strcpy( destination_node->customer_id, source_node->customer_id);
    strcpy( destination_node->item_id, source_node->item_id);
    strcpy( destination_node->quantity, source_node->quantity);
    strcpy( destination_node->shipped_id, source_node->shipped_id);
    strcpy( destination_node->shipped_date, source_node->shipped_date);
    strcpy( destination_node->feedback, source_node->feedback);
    strcpy( destination_node->order_status, source_node->order_status);

    
    
    
    // we may not want to copy the node pointers.
    destination_node->next_customer_node = NULL;
    
    return( 0 );
}

int sort_orders_node(order_node_type *head_node, order_field_enum field_name, order_type order );

// add a ship function.
int ship_orders_node(order_node_type *head_node, char output_filename[]);
