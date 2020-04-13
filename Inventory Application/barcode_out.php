<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <meta http-equiv="X-UA-Compatible" content="ie=edge">
    <title>Scanner Out</title>
    <link rel="stylesheet" href="stylesheet/style.css">
    <script src="https://ajax.googleapis.com/ajax/libs/jquery/3.4.1/jquery.min.js"></script>

    <script>
    $(document).ready(function(){
        $('#barcode').on('change', function(){
            var barcodeID = $(this).val();
            if(barcodeID){
                $.ajax({
                    type: 'POST',
                    url: 'ajax/barcodeOutAjax.php',
                    data: 'item_number='+barcodeID,
                    success: function(data){
                        $('#quantity').val(data);
                    }
                });
            } else {
                $('#quantity').val('<input value="">Quantity>');
            }
        });

        $('#barcode').on('change', function(){
            var barcodeID = $(this).val();
            if(barcodeID){
                $.ajax({
                    type: 'POST',
                    url: 'ajax/barcodeOut2Ajax.php',
                    data: 'item_number='+barcodeID,
                    success: function(data){
                        $('#item_description').val(data);
                    }
                });
            } else {
                $('#item_description').val('<input value = "">Item_Name>');
            }
        });

    });
    
    </script>

</head>
<body>

<?php
include 'include/config.inc.php';


?>
<center>
<form action="outform.php" method="POST">
    <label for="barcode">Barcode Number</label>
    <input type="text" id="barcode" name="Barcode">
    <br>
    <br>
    <br>
    <label for="item_description">Item</label>
    <input type="text" id="item_description" name="item_desc">
    <br>
    <br>
    <br>
    <label for="Quantity">Quantity in Stock</label>
    <input type="text" id="quantity" name="Quantity">
    <br>
    <br>
    <br>
    <label for="JobNumber">Job Number</label>
    <input type="text" id="jobnumber" name="JOBnumber">
    <br>
    <br>
    <br>
    <label for="quantityout">Quantity Scanning Out</label>
    <input type="text" id="quantityout" name="Quantityout">
    <br>
    <br>
    <br>
    <input type="submit" id="submit" name="submit" style="cursor:pointer">

</form>
</center>
</body>
</html>