<?php

include '../include/config.inc.php';

if(isset($_POST["item_id"])){ 
    // Fetch city data based on the specific state 
    $query = "SELECT unit_price FROM objects WHERE item_id = ".$_POST['item_id']." ORDER BY item_number ASC"; 
    $result = $conn->query($query); 
     
    // Generate HTML of city options list 
    if($result->num_rows > 0){
        while($row = $result->fetch_assoc()){
    echo $row['unit_price'];
        }
    }
}