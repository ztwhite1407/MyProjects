/* 
 * File: dataplib.h
 * Copy: Copyright (c) 2018 Gregory C. Myers
 * BlazerID: gmyers
 * Vers: 2.0.1 11/27/2018 GCM - Presented Fall 2018
 * Vers: 2.0.0 04/11/2018 GCM - Presented Spring 2018
 * Vers: 1.0.0 04/11/2018 GCM - Original Coding
 * Desc: Header file for aggregating data functions using pointers
 */

typedef struct student_node {
    char first_name[10];
    char middle_initial[2];
    char last_name[10];
    char blazer_id[10];
    struct student_node *next_student_node;
} student_node_type; 

int import_students_node(char const filename[], student_node_type *head_node);
int display_students_node(student_node_type *head_node);
int examine_students_node(student_node_type *head_node );
int display_student_node(student_node_type *student_node );
int export_students_node(char const filename[], student_node_type *head_node);

int add_student_node(student_node_type *head_node,  student_node_type *student_node);
int remove_student_node(student_node_type *head_node, student_node_type *student_node);

int isa_student_all_fields_list(student_node_type *head_node, student_node_type *student_node);
int isa_student_node(student_node_type *head_node, char blazer_id[]);

int get_student_all_fields_list(student_node_type *head_node, student_node_type *student_node);
int get_student_node(student_node_type *head_node, char blazer_id[], student_node_type *student_node);

int compare_student_node(student_node_type *first_student_node, student_node_type *second_student_node);
int copy_student_node(student_node_type *destination_node, student_node_type *source_node);

