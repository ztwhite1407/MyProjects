<?php

include 'include/config.inc.php';

$query = "SELECT * FROM orders ORDER BY id desc";
$result = mysqli_query($conn, $query);


?>



<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <meta http-equiv="X-UA-Compatible" content="ie=edge">
    <title>Order History</title>
    <link href="https://fonts.googleapis.com/css?family=Noto+Serif+TC&display=swap" rel="stylesheet">
    <link rel="stylesheet" href="stylesheet/summary.css">
    <link rel="stylesheet" href="https://stackpath.bootstrapcdn.com/bootstrap/4.4.1/css/bootstrap.min.css" integrity="sha384-Vkoo8x4CGsO3+Hhxv8T/Q5PaXtkKtu6ug5TOeNV6gBiFeWPGFN9MuhOf23Q9Ifjh" crossorigin="anonymous">
    <link rel="stylesheet" href="stylesheet/inventory_out.css">
    <script src="https://ajax.googleapis.com/ajax/libs/jquery/3.4.1/jquery.min.js"></script>
    
    <script>
        $(document).ready(function(){
            $('.dateFilter').datepicker({
                dateFormat: "yy-mm-dd"
            });
        });
    </script>


  
<center>
    <!--Search filter-->
    <form method="POST" action="">
        Start Date <input type="date" class="dateFilter" name="fromDate" value="<?php if(isset($_POST["fromDate"])) echo $_POST['fromDate']; ?>">
        
        End Date <input type='date' class='dateFilter' name='endDate' value='<?php if(isset($_POST['endDate'])) echo $_POST['endDate']; ?>'>

        <input type='submit' name='but_search' value='Search'>
    </form>

<!-- Orders List -->
<div style='height: 80%; overflow: auto;' >
 
 <table border='1' width='100%' style='border-collapse: collapse;margin-top: 20px;'>
   <tr>
     <th>Job Number</th>
     <th>Date Ordered</th>
     <th>Item Number</th>
     <th>Quantity</th>

   </tr>

   <?php
   $order_query = "SELECT * FROM orders WHERE 1 ";

   // Date filter
   if(isset($_POST['but_search'])){
      $fromDate = $_POST['fromDate'];
      $endDate = $_POST['endDate'];

      if(!empty($fromDate) && !empty($endDate)){
         $order_query .= " and date_added 
                      between '".$fromDate."' and '".$endDate."' ";
      }
    }
    

    // Sort
    $order_query .= " ORDER BY date_added DESC";
    $orderRecords = mysqli_query($conn,$order_query);

    // Check records found or not
    if(mysqli_num_rows($orderRecords) > 0){
      while($ordRecord = mysqli_fetch_assoc($orderRecords)){
        $id = $ordRecord['id'];
        $jobNumber = $ordRecord['job_number'];
        $date_add = $ordRecord['date_added'];
        $itemNumber = $ordRecord['item_number'];
        $Quantity = $ordRecord['quantity'];
  

    
        echo "<tr>";
        echo "<td> <center>". $jobNumber ."</center> </td>";
        echo "<td> <center>". $date_add ."</center> </td>";
        echo "<td> <center>". $itemNumber ."</center> </td>";
        echo "<td> <center>". $Quantity ."</center> </td>";
  
        echo "</tr>";
      }
    }else{
      echo "<tr>";
      echo "<td colspan='4'>No record found.</td>";
      echo "</tr>";
    }
     
    ?>
  
  </table>
  </center>
</div>

<div class="menu">
    <a class="footer-link" href="index.php">Main Page</a>
    <a class="footer-link" href="inventory_in.php">Inventory In Page</a>
    <a class="footer-link" href="inventory_out.php">Inventory Out Page</a>
</div>

</body>
</html>



