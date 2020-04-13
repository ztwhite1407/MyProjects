<?php

include '../include/config.inc.php';

if(isset($_POST["item_number"])){

    $query = "SELECT quantity FROM objects WHERE item_number = ".$_POST['item_number']."";
    $result = $conn->query($query);


    if($result->num_rows>0){
        while($row = $result->fetch_assoc()){
            echo $row['quantity'];
        }
    }
}

?>