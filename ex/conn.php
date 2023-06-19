<?php
$servername = "localhost:3307";
$username = "root";
$password = "root";
$dbname = "testgraph";
// Database Connection Code
	$conn = new mysqli($servername, $username, $password, $dbname );
	// Check connection
		if ($conn->connect_error) {
			die("Connection failed: " . $conn->connect_error); // in case of error
	 	}
?>