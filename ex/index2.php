<!doctype html>
<html lang="en">
  <head>
    <title>Grafik sensor</title>

    <link rel="stylesheet" type="text/css" href="assets/css/bootstrap.min.css">
    <script type="text/javascript" src="assets/js/jquery-3.4.0.min.js"></script>
    <script type="text/javascript" src="assets/js/mdb.min.js"></script>
    <script type="text/javascript" src="jquery-latest.js"></script>


    <!-- Bootstrap CSS -->
    <link rel="stylesheet" href="https://cdn.jsdelivr.net/npm/bootstrap@4.0.0/dist/css/bootstrap.min.css" integrity="sha384-Gn5384xqQ1aoWXA+058RXPxPg6fy4IWvTNh0E263XmFcJlSAwiGgFAW/dAiS6JXm" crossorigin="anonymous">

    <link rel="stylesheet" type="text/css" href="assets/css/bootstrap.min.css">
    <script type="text/javascript" src="assets/js/jquery-3.4.0.min.js"></script>
    <script type="text/javascript" src="assets/js/mdb.min.js"></script>
    <script type="text/javascript" src="jquery-latest.js"></script>

    <script src="https://code.jquery.com/jquery-3.4.0.js"></script>
    <link rel="stylesheet" href="//cdnjs.cloudflare.com/ajax/libs/morris.js/0.5.1/morris.css">
    <script src="//cdnjs.cloudflare.com/ajax/libs/raphael/2.1.0/raphael-min.js"></script>
    <script src="//cdnjs.cloudflare.com/ajax/libs/morris.js/0.5.1/morris.min.js"></script>

    <!-- jav untuk memangil data grafik -->
    <script type="text/javascript">
      var refreshid = setInterval(function(){
        $('#responsecontainer').load('data.php');
      }, 1000);
    </script>

    <script type="text/javascript">
        $(document).ready(function() {

            setInterval( function() {
                $("#heartrate").load("heartrate.php");
                $("#oxygen").load("oxygen.php");
                $("#handresistant").load("handresistant.php");
                $("#klasifikasi").load("klasifikasi.php");
                $("#tanggal").load("tanggal.php");
            }, 1000);

        });
    </script>


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
<body>
    <div class="card card-success">
        <div class="card-header">
                <h2 style = "text-align: center; padding: 20px; background-color: #A4D8F9; color: #fff; font-weight: bold;">Monitoring Pasien</h2>
                <!-- <h3 class="card-title">Display, Copy, Print and extract data in Excel and PDF From MySQL Database Using PHP, jQuery and DataTable </h3> -->
        </div>
    </div>

  <!-- tampilan untuk grafik -->
  <br>
  <div class="container" style="text-align: center;">
  <!-- div untuk grafik -->
      <div class="container">

          <div class="container" id="responsecontainer" style="width: 80%; text-align: center;"></div>

      </div>
  </div>


  <div class="container">
        <div class="row">
            <div class="col-lg-4 mb-4">
                <div class="card">
                    <img class="card-img-top" src="" alt="">
  
                    <div class="card-body" style="background-color: #f9c6cf ;">
                        <h5 class="card-header" style="text-align: center; background-color: indianred; font-weight: bold; color: white;">Detak Jantung</h5>
                        <p class="card-text">
                            <center>
                            <h1><span id="heartrate"></span></h1>
                            </center>
                        </p>
                    </div>
                </div>
            </div>
            <div class="col-lg-4 mb-4">
                <div class="card">
                    <img class="card-img-top" src="" alt="">
  
                    <div class="card-body" style=" background-color: #add8e6;">
                        <h5 class="card-header" style="text-align: center; background-color: deepskyblue; font-weight: bold; color: white;">Oxygen</h5>
                        <p class="card-text">
                            <center>
                            <h1><span id="oxygen"></span></h1>
                            </center>
                        </p>
                    </div>
                </div>
            </div>
            <div class="col-lg-4 mb-4">
                <div class="card"> 
                    <div class="card-body" style="background-color: #ffff80;">
                        <h5 class="card-header" style="text-align: center; background-color: #e5e619; font-weight: bold; color: white;">GSR</h5>
                        <p class="card-text">
                            <center>
                            <h1><span id="handresistant"></span></h1>
                            </center>
                        </p>
                    </div>
                </div>
            </div>
        </div>
    </div>

        <div class="container">
            <div class="card text-center" style="background-color: #EFEFEF;">
              <div class="card-header text-muted" style="text-align: center; background-color: #CDF0EA; font-weight: bold; color:white; font-size: medium;">
                Klasifikasi
              </div>
              <div class="card-body">
                <p class="card-text text-center" style="font-size: medium; font-weight: bold; color:#B1D7B4;"><h1><span id="klasifikasi"></span></h1></p>
              </div>
              <div class="card-footer text-muted" style="background-color: #CDF0EA;font-size: small;">
                <h1><span id="tanggal"></span></h1></p>
              </div>
            </div>
        </div>

 
        <footer class="page-footer font-small cyan darken-3">

          <!-- Footer Elements -->
            <div class="container">

                <!-- Grid row-->
                <div class="row">
                    <div class="col-md-12 py-5">
                        <div class="mb-5 flex-center">
                            <a href="reset.php" class="button" style="color: darkblue; font-weight: bold; font-family: sans-serif;">
                                Reset
                            </a>
                            <a href="tables.php" class="button" style="color: darkblue; font-weight: bold; font-family: sans-serif;">
                                Table
                            </a>
                        </div>
                    </div>
                <br>
                </div>
            </div>

        </footer>


  <script type="text/javascript" src="assets/js/jquery.min.js"></script>
  <script type="text/javascript" src="assets/js/bootstrap.min.js"></script>
  <script src="https://cdn.jsdelivr.net/npm/popper.js@1.12.9/dist/umd/popper.min.js" integrity="sha384-ApNbgh9B+Y1QKtv3Rn7W3mgPxhU9K/ScQsAP7hUibX39j7fakFPskvXusvfa0b4Q" crossorigin="anonymous"></script>
  <script src="https://cdn.jsdelivr.net/npm/bootstrap@4.0.0/dist/js/bootstrap.min.js" integrity="sha384-JZR6Spejh4U02d8jOt6vLEHfe/JQGiRRSQQxSfFWpi1MquVdAyjUar5+76PVCmYl" crossorigin="anonymous"></script>


</body>
</html>
