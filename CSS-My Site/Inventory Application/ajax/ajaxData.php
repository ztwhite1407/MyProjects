<?php

include '../include/config.inc.php';



if(!empty($_POST['cat_id'])) {
    $query = "SELECT * FROM items WHERE cat_id = ". $_POST['cat_id'] ." ORDER BY item_name ASC";
    $result = $conn->query($query);

    if($result->num_rows > 0){
        echo '<option value="">Select Item</option>';
        while($row = $result->fetch_assoc()){
            echo '<option value="'.$row['item_id'].'">'.$row['item_name'].'</option>';
        }
    } else {
        echo '<option value="">Item Not Available</option>';
    }
} elseif(!empty($_POST["item_id"])){ 
    // Fetch city data based on the specific state 
    $query = "SELECT item_number FROM objects WHERE item_id = ".$_POST['item_id']." "; 
    $result = $conn->query($query); 
     
    // Generate HTML of city options list 
    if($result->num_rows > 0){
        while($row = $result->fetch_assoc()){
        
            echo $row['item_number'];
    
        }  
    } 
} 

?>