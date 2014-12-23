<!DOCTYPE HTML>
<html>
<head>
<title>Santa's Black Market | Detail</title>
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
			<a href="index.php"><img src="images/logo.png" alt="SweetsComplete.Com"/></a>
		</div>
		<div class="right marT10">
			<b>
			<a href="index.php" >Log out</a> |<a href="members.php" class="active.php" >Our Members</a> |<a href="cart.php" >Shopping Cart</a>
			</b>
			<br />
			Welcome Guest		</div>
		<ul class="topmenu">
		<li><a href="members.php">Home</a></li>
		<li><a href="member_products.php">Products</a></li>
	
		</ul>
		<br>
		<div class="banner"><p></p></div>
		<br class="clear"/>
	</div> <!-- header -->
		
	<div class="content">	
	<br/>
	<div class="product-list">
		<h2>Product Details</h2>
		<br/>
		<div class="images">
			<a href="#">
				<img src="images/430_3150132.scale_20.JPG" alt=" Chocolate Angelfood Cupcakes" width="350" />
			</a>
		</div>
		<div class="details">
			<h3>SKU:  C3000</h3><br/>
			<h1 class="name"><b> Bird</b></h1><br/>
			<p class="desc">This is a bird
			</p>
			<br/>
			<p class="view"><b>Price: $0.30</b></p><br/>
			<form action="purchase.php" method="POST" name="to_cart">
			<p class="view">
				<label>Qty:</label> <input type="text" value="1" name="qty" class="s0" size="2" />
				<input type="submit" name="purchase" value="Buy this item" class="button"/>
				<input type="hidden" name="price" value="0.30" />
				<input type="hidden" name="productID" value="3" />
			</p>
			
			</form>
			<br />
			<b>Added to the cart, thanks!</b>
		</div>
	</div><!-- product-list -->
<br class="clear-all"/>
</div><!-- content -->
	
	</div><!-- maincontent -->

	<div id="footer">
		
	</div><!-- footer -->
	
</div><!-- wrapper 
<input type="submit" name="to_cart">
-->

</body>
</html>

<?php

if (isset($_POST["purchase"])){

	echo "test two";
}






?>
