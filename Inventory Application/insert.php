<?php

include 'include/config.inc.php';

$category = mysqli_real_escape_string($conn, $_REQUEST['cAt']);
$items = mysqli_real_escape_string($conn, $_REQUEST['itemName']);
$quantity = mysqli_real_escape_string($conn, $_REQUEST['Quantity']);
$unitprice = mysqli_real_escape_string($conn, $_REQUEST['unitPrice']);




$sql = "INSERT INTO items (cat_id, item_name) VALUES ('$category', '$items')"; 

    if(mysqli_query($conn, $sql)){
    echo "Success!";
    
    $itemid = mysqli_insert_id($conn);
    $sql = "INSERT INTO objects (cat_id, item_id, unit_price, quantity) VALUES ('$category','$itemid','$unitprice','$quantity')";
    mysqli_query($conn,$sql);
    }else{
    echo "ERROR: Could not execute $sql. " . mysqli_error($conn);
    }


header("Location:index.php");
// Close connection
mysqli_close($conn);
?>

