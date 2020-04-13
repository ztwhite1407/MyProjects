<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <meta http-equiv="X-UA-Compatible" content="ie=edge">
    <title>Inventory Out</title>
    <link rel="stylesheet" href="stylesheet/inventory_out.css">
    <script src="https://ajax.googleapis.com/ajax/libs/jquery/3.4.1/jquery.min.js"></script>

    <script>
    $(document).ready(function(){
        $('#category').on('change', function(){
            var categoryID = $(this).val();
            if(categoryID){
                $.ajax({
                    type: 'POST',
                    url: 'ajax/ajaxData.php',
                    data: 'cat_id='+categoryID,
                    success: function(html){
                        $('#item').html(html);
                    }
                });
            }else{
                $('#item').html('<option value="">Select Category First</option>');
                $('#itemnum').html('<input value="">Select Item First>');
            }
        });

        $('#item').on('change', function(){
            var itemID = $(this).val();
            if(itemID){
                $.ajax({
                    type:'POST',
                    url:'ajax/ajaxData.php',
                    data:'item_id='+itemID,
                    success:function(data){
                        $('#itemnum').val(data);
                       
                    }
                }); 
            }else{
                $('#itemnum').val('<input value="">Item Number>');               
            }
        });

        $('#item').on('change', function(){
            var itemID = $(this).val();
            if(itemID){
                $.ajax({
                    type:'POST',
                    url:'ajax/getUnitPrice.php',
                    data:'item_id='+itemID,
                    success:function(data){
                        $('#unitprice').val(data);
                    }
                }); 
            }else{
                $('#unitprice').val('<input value="">Unit Price>');
            }
        });
        $('#item').on('change', function(){
            var itemID = $(this).val();
            if(itemID){
                $.ajax({
                    type:'POST',
                    url:'ajax/getQuantity.php',
                    data:'item_id='+itemID,
                    success:function(data){
                        $('#stockquantity').val(data);
                    }
                });
            }else{
                $('#stockquantity').val('<input value="">Quantity>');
            }
        });
        

    });

    </script>

</head>
<body>
<?php
    session_start();
?>
<h2 id="username"><?php echo "Hello" . "<br>" .  htmlspecialchars($_SESSION["username"]);?></h2>
    <center>
    <h1>Add to Job</h1>
    </center>
<?php

include 'include/config.inc.php';


$query = "SELECT * FROM category ORDER BY cat_name ASC";
$result = $conn->query($query);
?>
<center>

<form action="update.php" method="POST" id="outform">

<!-- Category Dropdown -->
<div id="catbox">
    <label for="Category">Category</label> <br>
<select id="category" name="cAt" class="CATEGORY"> 
    <option value="" id="cats" >Select Category</option> 
    <?php
    if($result->num_rows > 0) {
        while($row = $result->fetch_assoc()) {
            echo '<option value="'.$row['cat_id'].'">'.$row['cat_name'].'</option>';
        }
    } else {
        echo '<option value="">Category not available</option>';
    }
    ?>
</select>
</div>
<br>
<br>
<br>

<!-- Item Name Dropdown -->
<div id="itembox">
   <label for="Item_Name">Item Description</label> <br>
<select name="ITEM_NAME" id="item">
    <option value="">Select Category First</option> 
</select>
</div>
<br>
<br>
<br>

<!-- Item Number -->
<label for="itemnum">Item Number</label> <br>
<input type="text" id="itemnum" name="item_num">
<br>
<br>
<br>
<label for="unitprice">Unit Price</label> <br>
<input type="text" id="unitprice" name="unitPrice" value="">
<br>
<br>
<br>
<label for="stockquantity">Quantity in Stock</label> <br>
<input type="text" id="stockquantity" name="StockQuantity" value="">
<br>
<br>
<br>
<label for="jobnumber">Job Number</label> <br>
<input type="text" id="jobnumber" name="JobNumber">
<br>
<br>
<br>
<label for="quantity">Quantity Scanning Out</label> <br>
<input type="text" id="quantity" name="Quantity">
<br>
<br>
<br>
<input type="submit" id="submit" value="submit" style="cursor:pointer" >
</form>

</center>
</body>
</html>