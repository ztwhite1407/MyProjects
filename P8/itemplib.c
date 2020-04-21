/* 
 * File: itemplib.c
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


int import_items_node(char const filename[], item_node_type *head_node) {
    FILE *input;
    // int index;
    int is_head_node;
    item_node_type *current_node;
    char line[ line_length_max ];
    char chunks[ chunk_count_max ][ chunk_length_max ];
    int count;
   
    
    count = 0;
    is_head_node = 1;
    input = fopen("items.csv", "r");
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
                
                strcpy( current_node->item_id, chunks[ 0 ] );
                strcpy( current_node->item_description, chunks[ 1 ] );
                strcpy( current_node->item_price, chunks[ 2 ] );
                strcpy( current_node->item_quantity_ideal, chunks[ 3 ] );
                strcpy( current_node->item_quantity_actual, chunks[ 4 ] );
                strcpy( current_node->item_status, chunks[ 5 ] );
                
                
                current_node->next_item_node = NULL;
                
                is_head_node = 0;
                count = 1;
                
                
        } else {
            
                current_node->next_item_node = (item_node_type *) malloc(sizeof(item_node_type ));
                
                current_node = current_node->next_item_node;
                strcpy( current_node->item_id, chunks[ 0 ] );
                strcpy( current_node->item_description, chunks[ 1 ] );
                strcpy( current_node->item_price, chunks[ 2 ] );
                strcpy( current_node->item_quantity_ideal, chunks[ 3 ] );
                strcpy( current_node->item_quantity_actual, chunks[ 4 ] );
                strcpy( current_node->item_status, chunks[ 5 ] );
                
                
                current_node->next_item_node = NULL;
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
int display_items_node(item_node_type *head_node) {
    
}
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
