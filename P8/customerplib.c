/* 
 * File: customerplib.c
 * Copy: Copyright (c) 2018 Gregory C. Myers
 * BlazerID: gmyers
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


int import_customers_node(char const filename[], customer_node_type *head_node ) {
    FILE *input;
    // int index;
    int is_head_node;
    customer_node_type *current_node;
    char line[ line_length_max ];
    char chunks[ chunk_count_max ][ chunk_length_max ];
    int count;
   
    
    count = 0;
    is_head_node = 1;
    input = fopen("customers.csv", "r");
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
                
                strcpy( current_node->customer_id, chunks[ 0 ] );
                strcpy( current_node->customer_last_name, chunks[ 1 ] );
                strcpy( current_node->customer_first_name, chunks[ 2 ] );
                strcpy( current_node->customer_address, chunks[ 3 ] );
                strcpy( current_node->customer_city, chunks[ 4 ] );
                strcpy( current_node->customer_state, chunks[ 5 ] );
                strcpy( current_node->customer_zip, chunks[ 6 ] );
                strcpy( current_node->customer_status, chunks[ 7 ] );
                
                current_node->next_customer_node = NULL;
                
                is_head_node = 0;
                count = 1;
                
                
        } else {
            
                current_node->next_customer_node = (customer_node_type *) malloc(sizeof(customer_node_type ));
                
                current_node = current_node->next_customer_node;
                strcpy( current_node->customer_id, chunks[ 0 ] );
                strcpy( current_node->customer_last_name, chunks[ 1 ] );
                strcpy( current_node->customer_first_name, chunks[ 2 ] );
                strcpy( current_node->customer_address, chunks[ 3 ] );
                strcpy( current_node->customer_city, chunks[ 4 ] );
                strcpy( current_node->customer_state, chunks[ 5 ] );
                strcpy( current_node->customer_zip, chunks[ 6 ] );
                strcpy( current_node->customer_status, chunks[ 7 ] );
                
                current_node->next_customer_node = NULL;
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

int display_customers_node(customer_node_type *head_node ) {
    // loop through your linked list looking for what?
    // current_node->next_student_node == NULL
    customer_node_type *current_node;
    int count; 
    
    count = 0;
    if (head_node == NULL) {
        // no valid linked list...
        printf("Warning: No valid linked list.\n");
    } else if (head_node ->next_customer_node == head_node) {
        // it points to itself...
        printf("Warning: No valid linked list.\n");
    } else {
        current_node = head_node;
        while (current_node != NULL) {
            display_customer_node( current_node);
            current_node = current_node->next_customer_node; // moves to the next 
            // element in the linked list...
            count++;
        }
    }
    return( count );       
      
}

int examine_customers_node(customer_node_type *head_node ) {
    customer_node_type *current_node;

    current_node = head_node;
    
    printf("Description                                 Value\n");
    printf("===============================================================\n");
    printf("Address of head_node                            %p\n", head_node);    
    printf("head_node.customer_id                            %s\n", head_node->customer_id);
    printf("head_node.customer_last_name                        %s\n", head_node->customer_last_name);
    printf("head_node.customer_first_name                             %s\n", head_node->customer_first_name);
    printf("head_node.customer_address                             %s\n", head_node->customer_address);
    printf("head_node.customer_city                             %s\n", head_node->customer_city);
    printf("head_node.customer_state                             %s\n", head_node->customer_state);
    printf("head_node.customer_zip                             %s\n", head_node->customer_zip);
    printf("head_node.customer_status                             %s\n", head_node->customer_status);


    
    printf("Address of head_node.customer_id                 %p\n", &(head_node->customer_id));
    printf("Address of head_node.customer_last_name             %p\n", &(head_node->customer_last_name));
    printf("Address of head_node.customer_first_name                  %p\n", &(head_node->customer_first_name));
    printf("Address of head_node.customer_address                  %p\n", &(head_node->customer_address));
    printf("Address of head_node.customer_city                  %p\n", &(head_node->customer_city));
    printf("Address of head_node.customer_state                  %p\n", &(head_node->customer_state));
    printf("Address of head_node.customer_zip                  %p\n", &(head_node->customer_zip));
    printf("Address of head_node.customer_status                  %p\n", &(head_node->customer_status));
    printf("Address of head_node.next_customer_node          %p\n", head_node->next_customer_node);
    printf("===============================================================\n");
    
    while (current_node != NULL) {
        printf("Address of current_node                         %p\n", current_node);    
        printf("current_node.customer_id                         %s\n", current_node->customer_id);
        printf("current_node.customer_last_name                     %s\n", current_node->customer_last_name);
        printf("current_node.customer_first_name                          %s\n", current_node->customer_first_name);
        printf("current_node.customer_address                          %s\n", current_node->customer_address);           
        printf("current_node.customer_city                         %s\n", current_node->customer_city);
        printf("current_node.customer_state                     %s\n", current_node->customer_state);
        printf("current_node.customer_zip                          %s\n", current_node->customer_zip);
        printf("current_node.customer_status                          %s\n", current_node->customer_status);
        
        
        
        
        printf("Address of current_node.customer_id              %p\n", &(current_node->customer_id));
        printf("Address of current_node.customer_last_name          %p\n", &(current_node->customer_last_name));
        printf("Address of current_node.customer_first_name               %p\n", &(current_node->customer_first_name));
        printf("Address of current_node.customer_address               %p\n", &(current_node->customer_address));
        printf("Address of current_node.customer_city              %p\n", &(current_node->customer_city));
        printf("Address of current_node.customer_state          %p\n", &(current_node->customer_state));
        printf("Address of current_node.customer_zip               %p\n", &(current_node->customer_zip));
        printf("Address of current_node.customer_status               %p\n", &(current_node->customer_status));
        printf("Address of current_node.next_customer_node       %p\n", current_node->next_customer_node);
        
        current_node = current_node->next_customer_node;
    }
    printf("===============================================================\n");
    return( 0 );    
}


int display_customer_node(customer_node_type *head_node ) {
    
    customer_node_type *current_node;
    int count;
    
    count = 0;
    if ( head_node == NULL ) {
        // No valid linked list...
        printf("Warning: No valid linked list.\n");
    } else if (head_node ->next_customer_node == head_node) {
        // it points to itself...
        printf("Warning: No valid linked list.\n");
    } else {
        current_node = head_node;
        while (current_node != NULL) {
            display_customer_node( current_node );
            current_node = current_node->next_customer_node; // moves to the next element.
            count++;
        }
    }   
    return( 0 );
}

int export_customers(char const filename[], customer_node_type *head_node ) {
    FILE *output;
    customer_node_type *current_node;
    
    output = fopen( "customers.csv", "w");
    if (head_node == NULL) {
        // no valid linked list...
        printf("Warning: No valid linked list.\n");
    } else if (head_node->next_customer_node == head_node) {
        // it points to itself...
        printf("Warning: No valid linked list.\n");
    } else {
        current_node = head_node;
        while (current_node != NULL) {
            // display_student_node( current_node);
            fprintf(output, "%s, %s, %s, %s, %s, %s, %s\n", current_node-> customer_id,
                    current_node-> customer_last_name,
                    current_node-> customer_first_name,
                    current_node-> customer_address, 
                    current_node-> customer_city, 
                    current_node-> customer_state,
                    current_node-> customer_zip,
                    current_node-> customer_status);
            
            current_node = current_node->next_customer_node; // moves to the next 
            // element in the linked list...
            count++;
        }
    }
    
    fclose(output);
}
int add_customer_node(customer_node_type *head_node,  customer_node_type *customer_node) {
    
    // validate the properties of the student as well as checking that the pointer 
    // is not NULL.
    // enumerate through our linked list...
    //  comparing to see if the student already exists.
    //  if no existing student is found...
    //      add them. 
    
    int found;
    customer_node_type *current_node;
    found = 0;
    
    if (head_node == NULL) {
        // we have an invalid linked list...
    } else if (head_node->next_customer_node == head_node ) {
        copy_customer_node(head_node, customer_node);
        head_node->next_customer_node == NULL; // Consider handling this inside/outside
    } else {
        current_node = head_node;
        while ((current_node->next_customer_node != NULL) && (found == 0)) {
            if (compare_customer_node(current_node, customer_node) == 0) {
                found = 1;
            } else {
                current_node = current_node->next_customer_node;
            }
        }
    }
   
    if(found == 1) {
   
    } else if (compare_customer_node(current_node, customer_node) == 1) {
        current_node->next_customer_node = (customer_node_type *) malloc(sizeof(customer_node_type ));
        copy_customer_node( current_node->next_customer_node, customer_node );
    }
    
    return(found);
}

int remove_customer_node(customer_node_type *head_node, customer_node_type *customer_node) {
    
    
    
    return( 0 );
}

int compare_customer_node(customer_node_type *first_customer_node, customer_node_type *second_customer_node) {
    int results;
    
    // (1 == 1)
    
    results = (((string_compare( first_customer_node->customer_id, second_customer_node->customer_id, case_sensitive) == 0) && 
                string_compare(first_customer_node->customer_last_name, second_customer_node->customer_last_name, case_sensitive) == 0 &&
                string_compare(first_customer_node->customer_first_name, second_customer_node->customer_first_name, case_sensitive) == 0 &&
                string_compare(first_customer_node->customer_address, second_customer_node->customer_address, case_sensitive) == 0 &&
                string_compare(first_customer_node->customer_city, second_customer_node->customer_city, case_sensitive) == 0 &&
                string_compare(first_customer_node->customer_state, second_customer_node->customer_state, case_sensitive) == 0 &&
                string_compare(first_customer_node->customer_zip, second_customer_node->customer_zip, case_sensitive) == 0 &&
                string_compare(first_customer_node->customer_status, second_customer_node->customer_status, case_sensitive) == 0));
    
    return( !results );
            
}
int copy_customer_node(customer_node_type *destination_node, customer_node_type *source_node) {
    strcpy( destination_node->customer_id, source_node->customer_id);
    strcpy( destination_node->customer_last_name, source_node->customer_last_name);
    strcpy( destination_node->customer_first_name, source_node->customer_first_name);
    strcpy( destination_node->customer_address, source_node->customer_address);
    strcpy( destination_node->customer_city, source_node->customer_city);
    strcpy( destination_node->customer_state, source_node->customer_state);
    strcpy( destination_node->customer_zip, source_node->customer_zip);
    strcpy( destination_node->customer_status, source_node->customer_status);

    
    
    
    // we may not want to copy the node pointers.
    destination_node->next_customer_node = NULL;
    
    return( 0 );
    }

int isa_student_all_fields_list(customer_node_type *head_node, customer_node_type *student_node) {
    // return true or false...j
    int found;
    customer_node_type *current_node;
    found = 0;
    
    if (head_node == NULL) {
        found = 0;
    } else if (head_node->next_customer_node == head_node) {
        found - 0;
    } else {
        current_node = head_node;
        while (current_node != NULL ) {
            if (compare_customer_node(current_node, customer_node) == 0) {
                found = 1;
                break;
            }
            current_node = current_node->next_customer_node;
        }
    }
    
    return(found);
}

int isa_customer_node(customer_node_type *head_node, char customer_id[]) {
    
}

int get_customer_all_fields_list(customer_node_type *head_node, customer_node_type *customer_node) {
    
}

int get_customer_node(customer_node_type *head_node, char customer_id[], customer_node_type *customer_node) {
    
}
    
int sort_customers_node(customer_node_type *head_node, customer_field_enum field_name, order_type order) {
    
}
