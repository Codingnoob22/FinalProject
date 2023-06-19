<?php
	include("conn.php");

	$date = mysqli_query($conn, "select tanggal from graphtest order by id asc");
	$heartrate = mysqli_query($conn, "select heartrate from graphtest order by id asc");
	$oxygen = mysqli_query($conn, "select oxygen from graphtest order by id asc");
	$handresistant = mysqli_query($conn, "select handresistant from graphtest order by id asc");
?>

<!-- gambar grafik -->
<div class="panel panel-primary" >
	<div class="panel-heading" style="background-color: lightblue;">
		Grafik Sensor
	</div>

	<div class="panel-body">
		<!-- menggunakan canvas untuk visualisasi grafik -->
		<canvas id="myChart"></canvas>


		<script type="text/javascript">
			// pembacaan untuk id canvas
			var canvas = document.getElementById('myChart');
			// tambahkan tanggal
			var data = {
				labels: [
					<?php

						while($data_date = mysqli_fetch_array($date))
						{
							echo '"'.$data_date['tanggal'].'",';
						} 
					?>
		],
		datasets : [
		{
			label :"BPM",
			fill: true,
			
			borderColor: "rgba(249,198,207)",
			lineTension: 0.5,
			pointRadius: 5, 
			data : [
					<?php
						while($data_heartrate = mysqli_fetch_array($heartrate))
						{
							echo $data_heartrate['heartrate'].',';
						}
					?>
				]
			},
		{
			label :"Oxygen",
			fill: true,
			
			borderColor: "rgba(173,216,230)",
			lineTension: 0.5,
			pointRadius: 5, 
			data : [
					<?php
						while($data_oxygen = mysqli_fetch_array($oxygen))
						{
							echo $data_oxygen['oxygen'].',';
						}
					?>
				]
			},
		{
			label :"GSR",
			fill: true,
			
			borderColor: "rgba(255,255,128)",
			lineTension: 0.5,
			pointRadius: 5, 
			data : [
					<?php
						while($data_gsr = mysqli_fetch_array($handresistant))
						{
							echo $data_gsr['handresistant'].',';
						}
					?>
				]
			}
			]
		};

		//visualisasi grafik
		var option = {
			showLines : true,
			animation : {duration : 0}
		};

		var myLineChart = Chart.Line(canvas, {
			data : data,
			options : option
		});
		
		</script>
	</div>
</div>