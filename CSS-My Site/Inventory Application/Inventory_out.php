<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <meta http-equiv="X-UA-Compatible" content="ie=edge">
    <title>Inventory Out</title>
    <link href="https://fonts.googleapis.com/css?family=Noto+Serif+TC&display=swap" rel="stylesheet">
    <link rel="stylesheet" href="https://stackpath.bootstrapcdn.com/bootstrap/4.4.1/css/bootstrap.min.css" integrity="sha384-Vkoo8x4CGsO3+Hhxv8T/Q5PaXtkKtu6ug5TOeNV6gBiFeWPGFN9MuhOf23Q9Ifjh" crossorigin="anonymous">
    <link rel="stylesheet" href="stylesheet/inventory_out.css">
    <script src="https://ajax.googleapis.com/ajax/libs/jquery/3.4.1/jquery.min.js"></script>
    <script src="https://stackpath.bootstrapcdn.com/bootstrap/4.4.1/js/bootstrap.min.js" integrity="sha384-wfSDF2E50Y2D1uUdj0O3uMBJnjuUD4Ih7YwaYd1iqfktj0Uod8GCExl3Og8ifwB6" crossorigin="anonymous"></script>


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

    <center>
    <h1 id="header">Add to Job</h1>
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
    <label for="Category" id="catlabel">Category</label> <br>
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
   <label for="Item_Name" id="itemlabel">Item Description</label> <br>
<select name="ITEM_NAME" id="item">
    <option value="">Select Category First</option> 
</select>
</div>
<br>
<br>
<br>

<!-- Item Number -->
<div id="itemnumbox">
<label for="itemnum" id="itemnumlabel">Item Number</label> <br>
<input type="text" id="itemnum" name="item_num">
</div>
<br>
<br>
<br>
<div id="unitbox">
<label for="unitprice" id="unitlabel">Unit Price</label> <br>
<input type="text" id="unitprice" name="unitPrice" value="">
</div>
<br>
<br>
<br>
<div id="stockbox">
<label for="stockquantity" id="quantitylabel">Quantity in Stock</label> <br>
<input type="text" id="stockquantity" name="StockQuantity" value="">
</div>
<br>
<br>
<br>
<div id="jobbox">
<label for="jobnumber" id="joblabel">Job Number</label> <br>
<input type="text" id="jobnumber" name="JobNumber">
</div>
<br>
<br>
<br>
<div id="quantitybox">
<label for="quantity" id="quantitylabel">Quantity Scanning Out</label> <br>
<input type="text" id="quantity" name="Quantity">
</div>
<br>
<br>
<br>
<input type="submit" id="submit" value="submit" style="cursor:pointer" >
</form>
<div class="menu">
    <a class="footer-link" href="index.php">Main Page</a>
    <a class="footer-link" href="inventory_in.php">Inventory In Page</a>
    <a class="footer-link" href="inventory_out.php">Inventory Out Page</a>
</div>
</center>
</body>
</html>