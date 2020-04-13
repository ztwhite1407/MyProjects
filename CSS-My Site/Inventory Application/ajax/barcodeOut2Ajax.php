<?php

include '../include/config.inc.php';

if(isset($_POST["item_number"])){

    $query = "SELECT item_id FROM objects WHERE item_number = ".$_POST['item_number']."";
    $result = $conn->query($query);


    if($result->num_rows>0){
        while($row = $result->fetch_assoc()){
            $itemid = $row['item_id'];
            $query = "SELECT item_name FROM items WHERE item_id = ".$itemid."";
            $result = $conn->query($query);
            if($result->num_rows>0){
                while($row = $result->fetch_assoc()){
                    echo $row['item_name'];
                }
            }
        }
    }
}

?>