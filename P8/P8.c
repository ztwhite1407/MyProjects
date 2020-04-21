/*
 * File: P5.c
 * Copy: Copyright (c) 2019 Zachary T. White
 * BlazerID: ztwhite
 * Vers: 1.0.0 03/15/2019 ZTW - Original Coding
 * Vers: 1.0.1 03/18/2019 ZTW - 
 * Vers: 1.0.2 03/24/2019 ZTW
 * Desc: A program designed to display the integral of defined functions by either the left_rectangle, right_rectangle, mid_rectangle or trapezoidal method.  These method is
 * chosen by the user.  The compare function can then be ran to analyze which method is more efficient.  
 */




#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <float.h>
#include "coreinv.h"
#include "customerplib.h"
#include "itemplib.h"
#include "orderplib.h"





// Function Prototype
int help(void);

int main(int argc, char** argv) {
 int i;

    
 // argc - number of arguments
 // argv - arguments themselves
    
 printf("Number of Arguments: %i\n", argc); // Number of input arguments
 printf("Value of first Arguments: %s\n", argv[0]); // zero (0) based index
    // starts with the number 0  
    
 printf("Value of all Arguments:\n");
    // Sample from Netbeans, modified - GCM
    for (i = 0; i < argc; i++) {
        printf("\t%i: %s\n", i, argv[i]);        
    }  if (argc < 2) {
   
        // help implicitly called.
        help();
    } else {
        // argc >= 2
        /* Start parsing tier-one arguments.  Assume argument number 2 is a tier 
         * 1 option.  Argument number 3 is a tier 2 option.  Tier 1 options 
         * override tier 3 options (for this example).  For example, calling 
         * help will ignore other parameters.
         */
        if (strcmp( argv[1], "/h" ) == 0) {
            // help explicitly called
            help();
        } else if (strcmp( argv[1], "/customer" ) == 0 ) { 

            printf("Customer\n");
                
 // Add               
            if (( strcmp( argv[2], "/add") == 0) && (argc == 3 )) {
                
               

            }
       
 // Remove 
            else if ((strcmp( argv[2], "/remove") == 0) && (argc == 3 )) {

                
                
            } 
                        
 // Sort             
            else if ((strcmp( argv[2], "/sort") == 0) && (argc == 3)) {
                
                
                
            }
            
 // Display            
            else if ((strcmp( argv[2], "/display") == 0) && (argc == 3)) {

                
                
                
            } else {
                
                // call help
                int help();
            }
                   
        return(EXIT_SUCCESS);
        
        

        } else if (strcmp( argv[1], "/item" ) == 0) { 
        
            printf("Items\n");
            
 // Add               
            if (( strcmp( argv[2], "/add") == 0) && (argc == 3 )) {
                
               

            }
       
 // Remove 
            else if ((strcmp( argv[2], "/remove") == 0) && (argc == 3 )) {

                
                
            } 
                        
 // Sort             
            else if ((strcmp( argv[2], "/sort") == 0) && (argc == 3)) {
                
                
                
            }
            
 // Display            
            else if ((strcmp( argv[2], "/display") == 0) && (argc == 3)) {

                
                
                
            } else {
                
                // call help
                int help();
            }
                   
        return(EXIT_SUCCESS);
        
        
        } else if (strcmp( argv[1], "/order" ) == 0) { 
        
            printf("Items\n");
            
 // Add               
            if (( strcmp( argv[2], "/add") == 0) && (argc == 3 )) {
                
               

            }
       
 // Remove 
            else if ((strcmp( argv[2], "/remove") == 0) && (argc == 3 )) {

                
                
            } 
                        
 // Sort             
            else if ((strcmp( argv[2], "/sort") == 0) && (argc == 3)) {
                
                
                
            }
            
 // Display            
            else if ((strcmp( argv[2], "/display") == 0) && (argc == 3)) {

                
                
                
            } else {
                
                // call help
                int help();
            }
                   
        return(EXIT_SUCCESS);
        
        
        
} else {
        
 // help implicitly called
        printf("Unhandled mode\n");
        help();            
        }
    
 return (EXIT_SUCCESS);

}
        
            
 
                
                 
     

    


/*
 * Name: int help(void)
 * Desc: Brings Help Menu for user.  
 */
int help(void) {
    printf("========================================\n");
    printf("File: P8.exe\n");
    printf("Copy: Copyright (c) 2019 Zachary White\n");
    printf("Vers: 1.0.0 04/18/2018 ZW - \n");
    printf("Desc: Inventory System\n");
    printf("========================================\n");
    printf("Usage:\n");
    printf("    /customer - Customer\n");
    printf("        /add - Adds customers\n");
    printf("        /remove - Removes customers\n");
    printf("        /sort - Sorts customers\n");
    printf("        /display - Displays list of customers\n");
    printf("    /item - Item\n");
    printf("        /add - Adds item\n");
    printf("        /remove - Removes item\n");
    printf("        /sort - Sorts items\n");
    printf("        /display - Displays list of items\n");
    printf("    /order - Order\n");
    printf("        /add - Adds order\n");
    printf("        /remove - Removes an order\n");
    printf("        /sort - Sorts orders\n");
    printf("        /display - Displays order\n");
    printf("    /h - Help\n");
    printf("========================================\n");
    printf("Examples:\n");
      
        
    return (EXIT_SUCCESS);
    
}
}
