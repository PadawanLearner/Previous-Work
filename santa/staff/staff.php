<?php require_once("../../includes/db_connection.php"); 

	session_start();
	//Redirect to login if user is not logged in
	if ( isset($_SESSION['user_level']) && ($_SESSION['user_level'] == 22)){
		echo "Staff Logged In";
	}
	elseif(isset($_SESSION['user_level']) && ($_SESSION['user_level'] == 51)){
		echo "Manager Logged In";
	}
	else{
		header("Location: http://www.cs.uky.edu/~ylu236/santa/login.php"); 
	}
?>
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
			<a href="../logout.php" >Log out</a> 
			</b>
		</div>
		<ul class="topmenu">
		<li><a href="staff.php">Home</a></li>	
		<li><a href="insert_item.php">Insert</a></li>
		<li><a href ="view_items.php">View Inventory</a></li>
		<li><a href ="view_orders.php">View Orders</a></li>
		<br>
		<li><a href ="view_stats.php">Stats-Admin Only</a></li>
		</ul>
		<br>
		<div class="banner"><p></p></div>
		<br class="clear"/>
	</div> <!-- header -->
		
	<div class="content">
	
	<div class="search left">
		<form name="search" method="get" action="search.php" id="search">
			<input type="text" value="keywords" name="keyword" class="s0" />
			<br />
			<select name="title" class="s2">
			<option value="00000019">Toys</option><option value="00000044"> Games</option></select>
			<br />
			<input type="submit" name="search" value="Search Products" class="button marT5" />
			<input type="hidden" name="page" value="search" />
		</form>
		<br /><br />
	</div>
	
	<div class="intro left">
	  <h3>About Us</h3><br/>
	  <p><h2>This is Santa's Black Market. He atually does not sell anything. </h2>
	  </p>
	</div>
	<br class="clear"/>
	<br/>
		
	<div class="product-list">
		<h2>Some Specials</h2>
		
		<ul class="specials">
				<li>
					<div class="image">
						<a href="detail.php">
						<img src="../images/430_3150132.scale_20.JPG" alt=" Chocolate Angelfood Cupcakes" width="190" height="130"/>
						</a>
					</div>
					<div class="detail">
						<p class="name"><a href="detail.php"> Bird</a></p>
						<p class="view"><a href="detail.php">purchase</a> | <a href="detail.php">view details >></a></p>
					</div>
				</li>
				<li>
					<div class="image">
						<a href="detail.php">
						<img src="../images/167_2835774.scale_20.JPG" alt=" Fruit Salad" width="190" height="130"/>
						</a>
					</div>
					<div class="detail">
						<p class="name"><a href="detail.php"> Play</a></p>
						<p class="view"><a href="detail.php">purchase</a> | <a href="detail.php">view details >></a></p>
					</div>
				</li>
				<li>
					<div class="image">
						<a href="detail.php">
						<img src="../images/95_2542284.scale_20.JPG" alt=" Fudge" width="190" height="130"/>
						</a>
					</div>
					<div class="detail">
						<p class="name"><a href="detail.php"> Robot</a></p>
						<p class="view"><a href="detail.php">purchase</a> | <a href="detail.php">view details >></a></p>
					</div>
				</li>
			</ul>
	</div><!-- product-list -->
	
	<br class="clear-all"/>
</div><!-- content -->
	
	</div><!-- maincontent -->

	<div id="footer">
	
	</div><!-- footer -->
	
</div><!-- wrapper -->

</body>
</html>
