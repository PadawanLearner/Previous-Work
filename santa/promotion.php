<?php require_once("../includes/db_connection.php"); ?>
<!DOCTYPE HTML>
<html>
<head>
<title>Santa's Black Market| Home</title>
<meta http-equiv="Content-Type" content="text/html; charset=utf-8">
<meta name ="description" content ="Santa's Black Market">
<meta name="keywords" content="">
<link rel="stylesheet" href="../css/main.css" type="text/css">
<link rel="shortcut icon" href="../images/favicon.ico?v=2" type="image/x-icon" />
</head>
<body>
<div id="wrapper">
	<div id="maincontent">		
	<div id="header">
		<div id="logo" class="left">
			<a href="index.php"><img src="../images/logo.png" alt="SweetsComplete.Com"/></a>
		</div>
		<div class="right marT10">
			<b>
			<a href="index.php" >Log out</a> 
			</b>
		</div>
		<ul class="topmenu">
		<li><a href="staff.php">Home</a></li>
		<li><a href="products.php">Products</a></li>
		<li><a href="insert_item.php">Insert </a></li>	
		<li><a href="promotion.php">Promote Item </a></li>			
		</ul>
		<br>
		<div class="banner"><p></p></div>
		<br class="clear"/>
	</div> <!-- header -->
		
	<div class="content">
		
	
	
	<h2>Hello Staff Member,</h2>
	<br>
	<h4>New promotion:</h4>
	<br>
	<form method="post" action='promotion.php' >
   	 <p>Please enter item id to promote:</p>     
   	 <input type="text" name="itemId">
		<br>
    	<br>
   	 <p>Please enter the duration in number of days of this promotion:</p>
    	<input type="text" name="duration">
		<br>
		<br>
   	  <p>Please enter promotion rate:</p>
   	 <input type="text" name="rate">
    	<br>
   	    <br>

    <input type="submit" name="submitPromotion"> 
	</form>

	
	
	
	
	
	
	
	
	
</div><!-- content -->
	
	</div><!-- maincontent -->

	<div id="footer">
	
	</div><!-- footer -->
	
</div><!-- wrapper -->

</body>
</html>
<?php

//Did the admin enter the data which is required to promote an item?
if(isset($_POST["submitPromotion"])
&& isset($_POST["itemId"]) && $_POST["itemId"] !=''
&& isset($_POST["duration"])&& $_POST["duration"] !=''
&& isset($_POST["rate"])&& $_POST["rate"] !=''
){ 

	/*
	if he||she did, then get those values. use filter to typecast them as 
	an integer for the item id, then an integer for the number of days for
	the duration of the promotion.  Once we have the total number of days that
	the promotion will run, we can create a UNIX style timestamp with it
	by simply adding the duration(int) to the current day (today).  this will
	be our end date of the promotion. lastly, we type the rate itself into 
	a float so that sql can recognize it as a decimal.
	*/
	
	$itemId = filter_input(INPUT_POST, 'itemId', FILTER_VALIDATE_INT);
	$duration = filter_input(INPUT_POST, 'duration', FILTER_VALIDATE_INT);
	//the start date is today
	//$startDate = mktime(0, 0, 0, date("m")  , date("d"), date("Y"));
	$startDate= date('Y-m-d h:i:s', (mktime(0, 0, 0, date("m")  , date("d"), date("Y"))));
	//the end date is the today + number of days it will run (see above)
	$endDate = date('Y-m-d h:i:s', (mktime(0, 0, 0, date("m")  , date("d")+$duration, date("Y"))));
	//float/decimal
	$rate = filter_input(INPUT_POST, 'rate', FILTER_VALIDATE_FLOAT);
	
	
	
	//query items 1st, does the item id exist? is there anymore in stock?
	
	
	
	//send these values into our promotion rate table in our database
	$promoteItem = "insert into promotion (item_id,start_date,end_date,promotion_rate) 
									values('$itemId','$startDate','$endDate','$rate')";
									
	$promoteItemQuery = mysqli_query($connection, $promoteItem);
	
	//now check to make sure the item was stored into the database
	if ($promoteItemQuery){
		echo "<br>";
		echo "Item successfully promoted!";
		echo "<br>";
		
		
		$getResults = "
		SELECT * 
		FROM promotion 
		WHERE item_id = '$itemId'";
		
		$test = mysqli_query($connection, $getResults);
			while($row_test= mysqli_fetch_array($test)){
			
			$myItemId = $row_test['item_id'];
			$myEndDate = $row_test['end_date'];
			$myRate = $row_test['promotion_rate'];
			
			echo "<br>";
			echo "The item id: ".$myItemId;
			echo "<br>";
			echo "has a promotion rate of :".$myRate;
			echo "<br>";
			echo "which will end on: ".$myEndDate;
			echo "<br>";
			}
	}
	else{
		echo "<br>";
		echo "Item unsuccessfully promoted, try again.";
		echo "<br>";		
	}
	

}

?>