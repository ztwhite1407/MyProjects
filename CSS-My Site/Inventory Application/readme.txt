Zachary White's Web App Files:

**All files are located in the path--> C:\Users\user\Desktop\xampp\htdocs\www\webapp 



*PHP FILES*

include/config.inc.php: Page that makes the connection to the database. 

index.php: Main page that includes links to choose from Inventory Out or Inventory In.

inventory_out.php: Page containing the form for checking items out of inventory and assigning them to a job. 

ajaxData.php: Page that is called from ajax commands in inventory_out.php and collects the dropbox data for Item Description.

getQuantity.php: Page that is called from ajax command in inventory_out.php and displays the quantity of item chosen. 

getUnitPrice.php: Page that is called from ajax command in inventory_out.php and displays the unit price for the item chosen. 

update.php: Page that updates the quantity in the main database, and records the order history of items checked out, as well as to what job is went to and the date ordered. 

inventory_in.php: Page containing the form for adding new items into Inventory database. 

insert.php: Page that is called from inventory_in when form is submitted that adds new items, quantities and unitprice to the database. 


*Javascript Files*

js/script.js: Contains the jQuery library. 



*CSS Style Sheet*
stylesheet/style.css: Contains the css styling for my entire web app. 




