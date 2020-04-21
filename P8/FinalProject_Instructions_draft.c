/*
 * Name: P8.c (a.k.a. FinalProject)
 * Description: Utilizing functions, build a command line utility that will 
 * model a small company's ordering system including tracking inventory, 
 * customers and sales information.  The system must allow for:
 *  addition of new inventory items
 *  removal of old inventory items (class discussion)
 *  update of inventory quantity
 *  addition of new customer
 *  removal of old customer (class discussion)
 *  update of customer information
 *  purchase of an existing item by an existing customer
 *  return of an existing item by an existing customer (class discussion)
 *  shipment of all ordered items
 *  feedback on an existing item by an existing customer
 * 
 * Input and Output files will be utilized as well as command line switches to 
 * control behavior.
 */

/* Problem{01}: Utilizing notes starting with Class_18, build a command line 
 * tool that will accept three hard coded csv files representing/containing  the
 * following information:
 * 
 * Item (in order)
 *  item_id (unsigned long)
 *  item_description (char)
 *  item_price (double)
 *  item_quantity_ideal (int)
 *  item_quantity_actual (int)
 *  item_status (enum active, inactive)
 * 
 * Customer (in order)
 *  customer_id (char)
 *  customer_last_name (char)
 *  customer first_name (char)
 *  customer_address (char)
 *  customer_city (char)
 *  customer_state (char)
 *  customer_zip (char)
 *  customer_status (enum active, inactive)
 * 
 * Order (in order)
 *  order_id (char)
 *  customer_id (char)
 *  item_id (unsigned long)
 * `quantity (unsigned short)
 *  ship_id (char)
 *  ship_date (char, ANSI C)
 *  order_status (enum shipped, back_ordered, returned )
 *  feedback (char)
 * 
 * All information and options must be provided from the command line based on 
 * the following switches/tiers and order:
 * Arguments:
 *  argv[1]: table options are /customer /item /order
 *  argv[2]: action options are /add /remove /sort /display /export
 *  argv[3]: add options are based on table
 *              /customer /add <customer_id> <first_name> <middle_initial> <last_name> <address> <city> <state> <zip>
 *              /item /add <item_id> <item_description> <item_price> <item_quantity_ideal> <item_quantity_actual>
 *              /order /add <item_id> <customer_id> <order_id>
 *  argv[3]: remove options are based on table
 *              /customer /remove <customer_id> --> active goes to inactive
 *              /item /remove <item_id> --> active goes to inactive
 *              /order /remove <item_id> <customer_id> <order_id> --> remove if not shipped, set as returned if shipped
 *  argv[3]: sort options are based on table
 *              /customer /sort <any field> /ascending or /descending>
 *              /item /sort <any field> /ascending or /descending>
 *              /order /sort <any field> /ascending or /descending>
 *  argv[3]: display options are based on table
 *              /customer requires /customer_id <customer_id>
 *              /item requires /item_id <item_id>
 *              /order can utilize
 *                  /item_id <item_id> /customer_id <customer_id>
 *                  /order_id <order_id> 
 *                  /customer_id <customer_id>
 *           export options are based on table
 *              /customer /export /customer_id <customer_id>
 *              /item /export /item_id <item_id> 
 *              /order /export /customer_id <customer_id>
 *              /order /export /item_id <item_id>             
 * 
 */

