	
<?php
require_once("../includes/db_connection.php"); ?>
<!DOCTYPE HTML>
<html>
<head>
<title>Santa's Black Market| Home</title>
<meta http-equiv="Content-Type" content="text/html; charset=utf-8">
<meta name ="description" content ="Sweets Complete">
<meta name="keywords" content="">
<link rel="stylesheet" href="css/main.css" type="text/css">
<link rel="shortcut icon" href="images/favicon.ico?v=2" type="image/x-icon" />
</head>
<body>

<div id="wrapper">
	<div id="maincontent">		
	<div id="header">
		<div id="logo" class="left">
			<a href="member_products.php"><img src="images/logo.png" alt="SweetsComplete.Com"/></a>
		</div>
		<div class="right marT10">
			<b>
			<a href="logout.php" >Log Out</a> |<a href="view_user_order.php" >View Order</a> |<a href="cart.php" >Shopping Cart</a>
			</b>
		</div>
		<ul class="topmenu">
		<li><a href="member_products.php">Home</a></li>
		<li><a href="member_products.php">Products</a></li>
		</ul>
		<br>
		<div class="banner"><p></p></div>
		<br class="clear"/>
	</div> <!-- header -->
		
	<div class="content">
	
	<div class="search left">
			<form name="search" method="get" action="search.php" id="search" enctype="multipart/form-data">
			<input type="text" value="" name="user_query" class="s0" />
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
