<?php
$server_name = "localhost:3307";
$user_name = "root";
$password = "root";
$database = "testgraph";

$conn = mysqli_connect($server_name, $user_name, $password, $database);
$query = "TRUNCATE table graphtest";
if(mysqli_multi_query($conn, $query)){
    echo "Succes";
    header("Location: index2.php");
}else{
    echo "Error: " . mysqli_error($conn);
}

mysqli_close($conn);

?>