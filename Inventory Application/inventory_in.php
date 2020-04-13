<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <meta http-equiv="X-UA-Compatible" content="ie=edge">
    <title>Inventory In</title>
    <link rel="stylesheet" href="stylesheet/inventory_in.css">
    
</head>
<body>
 <?php
    session_start();
    include 'include/config.inc.php';
    $query = "SELECT * FROM category ORDER BY cat_name ASC";
    $result = $conn->query($query);
 ?>
 <h1 id="header">Add to Inventory</h1>

 <h2 id="username"><?php echo "Hello" . "<br>" .  htmlspecialchars($_SESSION["username"]);?></h2>

<form action="insert.php" id="forminventoryin">
    <label for="Category">Category</label> <br>
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
<label for="itemname">Enter Item Description</label> <br>
<input type="text" id="itemname" name="itemName" value="">
<br>
<br>
<br>
<label for="unitprice">Enter Unit Price</label> <br>
<input type="text" id="unitprice" name="unitPrice" value=""> 
<br>
<br>
<br>
<label for="quantity">Enter Quantity</label> <br>
<input type="text" id="quantity" name="Quantity">
<br>
<br>
<br>
<input type="submit" id="submit" value="submit" style="cursor:pointer">
</form>


</body>
</html>