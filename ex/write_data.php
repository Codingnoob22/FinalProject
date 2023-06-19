<?php
 
$servername = 'localhost:3307';
$username	= 'root';
$password	= 'root';
$dbname	= 'testgraph';

$conn = mysqli_connect($servername, $username, $password, $dbname);


//check koneksi
if(!$conn){
	echo "Error: ".mysqli_connect_error();
	exit();
}
//jika sudah ok print
echo "Connection Success!!<br><br>";


//sql untuk mengirim data
$var1		= $_GET['data1'];
$var2 	= $_GET['data2'];
$var3  	= $_GET['data3'];
$var4  	= $_GET['data4'];

$result = mysqli_query($conn, "INSERT INTO graphtest (heartrate, oxygen, handresistant, klasifikasi) VALUES ('$var1', '$var2', '$var3', '$var4')");



//jika result gagal maka tidak akan disimpan ke mysql
if (!$result)
   {
	die('Query Invalid: '.mysqli_error($connect));
	echo "Connection Failed!!<br><br>";
   }
?>

