<?php
include("conn.php"); 
?>

<!DOCTYPE html>
<html>
<head>
<title>ESP32 data</title>

 <link rel="stylesheet" href="style.css">
<link rel="stylesheet" href="https://cdn.jsdelivr.net/npm/bootstrap@4.0.0/dist/css/bootstrap.min.css" integrity="sha384-Gn5384xqQ1aoWXA+058RXPxPg6fy4IWvTNh0E263XmFcJlSAwiGgFAW/dAiS6JXm" crossorigin="anonymous">

  <script src="https://maxcdn.bootstrapcdn.com/bootstrap/3.3.7/js/bootstrap.min.js"></script>
</head>
<style type="text/css">
  .button {
  background-color: #B0E0E6; /* Green */
  color: black;
  padding: 20px 32px;
  text-align: center;
  text-decoration: none;
  display: inline-block;
  font-size: 16px;
  border: 2px solid #87CEEB; /* Green */
  
}  
</style>
    <!-- Content Header (Page header) -->
    <!-- Main content -->
          <div class="col-md-12">
            <!-- general form elements -->
         <div class="card card-success">
              <div class="card-header">
                <h2 style = "text-align: center; padding: 20px; background-color: #A4D8F9; color: #fff; font-weight: bold;">ESP32 DATA</h2>
                <!-- <h3 class="card-title">Display, Copy, Print and extract data in Excel and PDF From MySQL Database Using PHP, jQuery and DataTable </h3> -->
              </div>
              <!-- /.card-header -->
              <!-- form start -->
                <div class="card-body">
                  <div class="row">
                     <div class="col-md-12">
                <table id="table" class="table table-bordered table-hover">
                    <thead style="background:#A4D8F9;">
          <tr>
                            <td>ID</td>
                            <td>Detak Jantung</td>
                            <td>Saturasi Oksigen</td>
                            <td>Keringat</td>
                            <td>Klasifikasi</td>
                            <td>Tanggal</td> 
                
                        </tr>
                    </thead>
                    <tbody>
                        <?php

$sql = "SELECT id, heartrate, oxygen, handresistant, klasifikasi,tanggal FROM graphtest ORDER BY id DESC";
if ($result = $conn->query($sql)) {
    while ($row = $result->fetch_assoc()) {
        $row_id = $row["id"];
        $row_heartrate = $row["heartrate"];
        $row_oxygen = $row["oxygen"];
        $row_handresistant = $row["handresistant"];
        $row_klasifikasi = $row["klasifikasi"];
        $row_tanggal = $row["tanggal"]; 
        // Uncomment to set timezone to - 1 hour (you can change 1 to any number)
        //$row_reading_time = date("Y-m-d H:i:s", strtotime("$row_reading_time - 1 hours"));
      
        // Uncomment to set timezone to + 4 hours (you can change 4 to any number)
        //$row_reading_time = date("Y-m-d H:i:s", strtotime("$row_reading_time + 4 hours"));
      
        echo '<tr> 
                <td>' . $row_id . '</td> 
                <td>' . $row_heartrate . '</td> 
                <td>' . $row_oxygen . '</td> 
                <td>' . $row_handresistant . '</td> 
                <td>' . $row_klasifikasi . '</td> 
                <td>' . $row_tanggal . '</td>

              </tr>';
    }
    $result->free();
}

$conn->close();
?> 

                    </tbody>
                </table>

                    <a href="index2.php" class="button" style="color: darkblue; font-weight: bold; font-family: sans-serif;">
                        Home
                    </a>

            </div>
              </div>       
                </div>
              <!-- /.card-body -->
            </div>
    <!-- /.content -->
  </div>
<link href="https://fonts.googleapis.com/css?family=Source+Sans+Pro:300,400,400i,700" rel="stylesheet">
  <link rel="stylesheet" type="text/css" href="https://cdn.datatables.net/1.10.16/css/jquery.dataTables.min.css">
  <link rel="stylesheet" type="text/css" href="https://cdn.datatables.net/buttons/1.5.1/css/buttons.dataTables.min.css">
  <script src="https://maxcdn.bootstrapcdn.com/bootstrap/3.3.7/js/bootstrap.min.js"></script>

<script type="text/javascript" src="https://code.jquery.com/jquery-1.12.4.js"></script>
<script type="text/javascript" src="https://cdn.datatables.net/1.10.16/js/jquery.dataTables.min.js"></script>
<script type="text/javascript" src="https://cdn.datatables.net/buttons/1.5.1/js/buttons.print.min.js"></script>
<script type="text/javascript" src="https://cdnjs.cloudflare.com/ajax/libs/pdfmake/0.1.32/pdfmake.min.js"></script>
<script type="text/javascript" src="https://cdn.datatables.net/buttons/1.5.1/js/buttons.flash.min.js"></script>
<script type="text/javascript" src="https://cdn.datatables.net/buttons/1.5.1/js/dataTables.buttons.min.js"></script>
<script type="text/javascript" src="https://cdn.datatables.net/buttons/1.5.1/js/buttons.html5.min.js"></script>
    <script type="text/javascript">
        $(document).ready(function() {
            $('#table').DataTable({
               dom: 'Bfrtip',
buttons: [ 'copy', 'csv', 'excel', 'print']

            });
        });
    </script>
</body>
</html> 
