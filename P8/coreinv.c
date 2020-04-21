/* 
 * File: corelib.c
 * Copy: Copyright (c) 2018 Gregory C. Myers
 * BlazerID: gmyers
 * Vers: 2.0.1 11/15/2018 GCM - Presented Fall 2018
 * Vers: 2.0.0 04/11/2018 GCM - Presented Spring 2018
 * Vers: 1.0.0 04/11/2018 GCM - Original Coding
 * Desc: Code file for implementing corelib.h
 */


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "coreinv.h"

int file_read( char file_name[], char contents[] ) { 
    FILE *input;
    int index;
    char chunk;
    
    index = 0;
    input = fopen( file_name, "r");
    if (input != NULL) {
        while (fscanf(input, "%c", &contents[ index ]) != EOF) {
            // could include logic to strip out characters....
            contents[ index ] = chunk;
            index++;
        }
        fclose(input);      
    }
    
    contents[ index ] = '\0';
    return( index + 1 );
}


/* Name: int read_line( FILE *input, char line[] )
 * Desc: reads one line at a time from a file based on \n.  line[] will be a 
 * string with a \0.
 */
int file_read_line( FILE *input, char line[] ) {
    int index;
    char chunk;
    
    if (input != NULL) {
        while ((fscanf(input, "%c", &chunk) != EOF) && (chunk != '\n') && (index < line_length_max)) {
            line[ index ] = chunk;
        }
    } else {
        // we can't do anything with a null file pointer.
    }
    line[ index ] = '\0';
    return( index );
}

/* Name: int char_find( char contents[], int contents_length, char search, int locations[])
 * Desc: 
 */
int char_find( char contents[], int contents_length, char search, int locations[]) {
    // contents_length -> number of char in the contents because it is not a string!
    // search -> char to look for.
    // locations -> array of where you found the search char
    int index; // loop through the contents.
    int count; // how many matches we find...
    
    index = 0;
    count = 0;
    
    // n_max is arbitrarily set to 100
    while (( index < contents_length ) && ( count < n_max )) {
        if ( contents[index ] == search ) {
            // a match was found...
            locations[ count ] = index; // store where the char was found...
            count++;
        } else {
            
        }
        index++;
    }
    return( count );
}

/* Name: int string_find( char contents[], char search[], int locations[])
 * Desc: 
 */
int string_find( char contents[], char search[], int locations[]) {
    int contents_index;
    int search_index;
    int count;
    int contents_length; 
    int search_length;
    int matching; // flag
    
    
    contents_index = 0;
    search_index = 0;
    count = 0;
    matching = 0;
    
    contents_length = string_length(contents);
    search_length = string_length(search);
    
    if ((contents_length != 0) && (search_length != 0) && (search_length < contents_length)) {
        while ((contents_index < contents_length) && ( contents_index < (contents_length - search_length))) {
            matching = 1;
            while ((search_index < search_length) && (matching == 1 )) {
                if (contents[ contents_index + search_index ] == search[ search_index ]) {
                    // if those match keep looking...
                } else {
                    matching = 0;
                }
                search_index++;
            }
            if (matching == 1) {
                // store the location
                locations[count] = contents_index;
                count++;
            } else {
                // keep on looking
            }
            contents_index++; // moves to the next character.
        }
    } else {
        // we assume we have nothing to search...
    }
    
    return( count );
}

/* Name: int string_split( char contents[], char delimiter, char chunks[][chunk_length])
 * Desc: 
 */
int string_split( char contents[], char delimiter, char chunks[][chunk_length_max]) {
    int chunk_index; // row in the chunks
    int char_index; // column in a specific chunk
    int contents_index;
    
    
    chunk_index = 0;
    char_index = 0;
    contents_index = 0;
    
    // while not EOS, chunk_length_max, chunk_count_max
    while ((contents[contents_index] != '\0') && ((char_index < chunk_length_max) && (chunk_index < chunk_count_max))) {
        // look for our delimeter...
        // create a new chunk...
        if (contents[contents_index] == delimiter) {
            //start a new chunk
            chunks[ chunk_index ][ char_index ] = '\0';
            chunk_index++;
            char_index = 0;
        } else {
            //we want to keep the character in our existing chunks...
            chunks[ chunk_index ][ char_index ] = contents[ contents_index ];
            char_index++; // moves to the next column...
        }
        
        contents_index++;
    }
    chunks[ chunk_index ][ char_index ] = '\0';
    
    return( chunk_index +1 );
}

/* Name: int string_compare( char const first[], char const second[], case_sensitivity_type sensitivity )
 * Desc: 
 */
int string_compare( char const first[], char const second[], case_sensitivity_type sensitivity ) {
    return( 0 );
}

/* Name: int export_int2Darray(int array[n_max][m_max], int n, int m, char *filename, char *delimiter)
 * Desc: 
 */
int export_int2Darray(int array[n_max][m_max], int n, int m, char *filename, char *delimiter) {
   return( 0 );    
}

/* Name: int export_double2Darray(double array[n_max][m_max], int n, int m, char *filename, char *delimiter)
 * Desc: 
 */
int export_double2Darray(double array[n_max][m_max], int n, int m, char *filename, char *delimiter) {
   return( 0 );    
}

/* Name: int export_char2Darray(char array[n_max][m_max], int n, int m, char *filename, char *delimiter)
 * Desc: 
 */
int export_char2Darray(char array[n_max][m_max], int n, int m, char *filename, char *delimiter) {
    return( 0 );    
}

/* Name: int export_string2Darray(char array[n_max][m_max], int n, int m, char *filename, char *delimiter)
 * Desc: 
 */
int export_string2Darray(char array[n_max][m_max][chunk_length_max], int n, int m, char *filename, char *delimiter) {
    return( 0 );    
}
int string_length( char const source[] ) {
    int results; // the number of non-EOS characters
    int count;
 // the amount of characters in a vector 
    // look at each character... looking for the End of String character. "\o"
    // count the number of iterations of your loop...
    count = 0;
    while (source[ count ] != '\0' ) {
        count = count + 1;
        
    }
    
    return( count );
}

// return the upper case according to ASCII values...
int string_upper( char destination[], char const source[] ) {        
    /* Upper case: (A-Z) --> (65-90)
     * Lower case: (a-z) --> (97-122)
     */ 
    int index;
    int count;
    
    count = 0;
    index = 0;

    while (source[index] != '\0') {
        if ((source[index] >= 65 ) & (source[index] <= 90)) {
            // shift our character (subtract 32)
            destination[ index ] = source[ index ] + 32;
            count = count + 1;
	} else {
            // we keep the existing character
            destination[ index ] = source[ index ];
        }
        index = index + 1;
    }
    destination[ index ] = '\0';

    
    return( count );  
}

// return the lower case according to ASCII values
int string_lower( char destination[], char const source[] ) {
    /* Upper case: (A-Z) --> (65-90)
     * Lower case: (a-z) --> (97-122)
     */ 
    int index;
    int count;
    
    count = 0;
    index = 0;

    while (source[index] != '\0') {
        if ((source[index] >= 97 ) & (source[index] <= 122)) {
            // shift our character (subtract 32)
            destination[ index ] = source[ index ] - 32;
            count = count + 1;
	} else {
            // we keep the existing character
            destination[ index ] = source[ index ];
        }
        index = index + 1;
    }
    destination[ index ] = '\0';

    
    return( count );   
}


int string_compare_v2( char const first[], char const second[], case_sensitivity_type sensitivity ) {
    int first_length;
    int second_length;
    int shortest_length;
    int index;
    int results;
    char first_modified[ 20 ];
    char second_modified[ 20 ];   
    int validated;
    
    validated = 0;
    results = 0; // or some error code
    
    first_length = string_length( first );
    second_length = string_length( second );
    if (first_length <= second_length ) {
        shortest_length = first_length;
    } else {
        shortest_length = second_length;
    }
    
    
    // arbitrarily limited our array size to (ex. 20)
    string_upper( first_modified, first );
    string_upper( second_modified, second );
    
    // Note: this is the same algorithm as above just with _modified variables...
            
    return( results );
}


