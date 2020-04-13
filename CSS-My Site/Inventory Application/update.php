<?php

include 'include/config.inc.php';


 
$jobnumber = mysqli_real_escape_string($conn, $_REQUEST['JobNumber']);
$Date = date("Y-m-d H:i:s");
$Quantity = mysqli_real_escape_string($conn, $_REQUEST['Quantity']);
$ItemNumber = mysqli_real_escape_string($conn, $_REQUEST['item_num']);
//$ItemID = mysqli_real_escape_string($conn, $_REQUEST['item_id']);
$StockQuantity = mysqli_real_escape_string($conn, $_REQUEST['StockQuantity']);
$QuantityAfterSubmit = $StockQuantity - $Quantity;


if(isset($_POST['item_num'])){
    $query = "UPDATE objects set quantity = '$QuantityAfterSubmit' WHERE item_number = ".$_POST['item_num']."";
    $result = mysqli_query($conn,$query);

    if($result->num_rows > 0){
        while($row = $result->fetch_assoc()){
            $myQuantity = $row['quantity'];
            echo $myQuantity;
        }
    }
}
echo $myQuantity;

// Attempt insert query execution
$sql = "INSERT INTO orders (job_number, quantity, date_added, item_number) VALUES 
('$jobnumber', '$Quantity', '$Date', '$ItemNumber')";
if(mysqli_query($conn, $sql)){
    echo "Success!";
} else{
    echo "ERROR: Could not execute $sql. " . mysqli_error($conn);
}

header("Location:index.php");
// Close connection
mysqli_close($conn);
?>