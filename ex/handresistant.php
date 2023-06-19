<?php
	//pembacaan tiap field yang akan dipanggil atau 
	//telah ditentukan 
	include("conn.php");

	//urutkan berdasarkan data terakhir yang tersimpan didatabase
	$sql = mysqli_query($conn, "select * from graphtest order by id desc");

	$data = mysqli_fetch_array($sql);
	if($data>0){
		echo ($handresistant = $data['handresistant']);
	}
	else{
		echo "0";
	}


	//print nilai suhu 
	//echo $handresistant;
?>