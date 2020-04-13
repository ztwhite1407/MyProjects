<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <meta http-equiv="X-UA-Compatible" content="ie=edge">
    <title>Inventory In</title>
    <link href="https://fonts.googleapis.com/css?family=Noto+Serif+TC&display=swap" rel="stylesheet">
    <link rel="stylesheet" href="https://stackpath.bootstrapcdn.com/bootstrap/4.4.1/css/bootstrap.min.css" integrity="sha384-Vkoo8x4CGsO3+Hhxv8T/Q5PaXtkKtu6ug5TOeNV6gBiFeWPGFN9MuhOf23Q9Ifjh" crossorigin="anonymous">
    <link rel="stylesheet" href="stylesheet/inventory_in.css">
    

    
</head>
<body>
 <?php

    include 'include/config.inc.php';
    $query = "SELECT * FROM category ORDER BY cat_name ASC";
    $result = $conn->query($query);
 ?>
 <h1 id="header">Add to Inventory</h1>


<form action="insert.php" id="forminventoryin">
    <label for="Category" id="catlabel">Category</label> <br>
    <select name="cAt" id="category">
        <option value="" id="cats">Select Category</option>
        <?php
            if($result->num_rows > 0) {
                while($row = $result->fetch_assoc()){
                    echo '<option value="'.$row['cat_id'].'">'.$row['cat_name'].'</option>';
                }
            } else {
                echo '<option value ="">Category not Available</option>';
            }
        ?>
    </select>
<br>
<br>
<br>

<!--Item Name-->
<label for="itemname" id="itemlabel">Enter Item Description</label> <br>
<input type="text" id="itemname" name="itemName" value="">
<br>
<br>
<br>
<label for="unitprice" id="unitlabel">Enter Unit Price</label> <br>
<input type="text" id="unitprice" name="unitPrice" value=""> 
<br>
<br>
<br>
<label for="quantity" id="quantitylabel">Enter Quantity</label> <br>
<input type="text" id="quantity" name="Quantity">
<br>
<br>
<br>
<input type="submit" id="submit" value="Add" style="cursor:pointer">
</form>


</body>
</html>