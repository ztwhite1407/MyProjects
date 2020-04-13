<?php

include 'include/config.inc.php';

if(isset($_POST["from_date"], $_POST["to_date"])) {
    $output = '';
    $query = 'SELECT * FROM orders WHERE date_added BETWEEN "'.$_POST["from_date"].'" AND "'.$_POST["to_date"].'"'; 
    $result = mysqli_query($conn, $query);
    if(mysqli_num_rows($result) > 0){
        while($row=mysqli_fetch_array($result)){
            echo $row['job_number'];
        }
    }
}

?>