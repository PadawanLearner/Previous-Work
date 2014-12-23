<?php
	session_start();
	
	//Redirect to login if user is not logged in
	if ( isset($_SESSION['user_level']) && ($_SESSION['user_level'] === 1)){
		echo "Logged In";
	}
	else{
		header("Location: http://www.cs.uky.edu/~ylu236/santa/login.php"); 
	}
?>

<!DOCTYPE HTML>
<!-- this file has the overall look and feel of the website -->
<html>
<head>
<title>Santa's Black Market | Members</title>
<meta http-equiv="Content-Type" content="text/html; charset=utf-8">
<meta name ="description" content ="Sweets Complete">
<meta name="keywords" content="">
<link rel="stylesheet" href="css/main.css" type="text/css">
<link rel="shortcut icon" href="images/favicon.ico?v=2" type="image/x-icon" />
</head>
<body>
<?php include "security.php" ?>
<div id="wrapper">
	<div id="maincontent">
		
	<div id="header">
		<div id="logo" class="left">
			<a href="member_products.php"><img src="images/logo.png" alt="SweetsComplete.Com"/></a>
		</div>
		<div class="right marT10">
			<b>
			<a href="logout.php" >Log out</a> |<a href="members.php" class="active.php" >Our Members</a> |<a href="cart.php" >Shopping Cart</a>
			</b>
			<br />
			Welcome Guest		</div>
		<ul class="topmenu">
		<li><a href="member_products.php">Home</a></li>
		<li><a href="member_products.php">Products</a></li>
	
		</ul>
		<br>
		<div class="banner"><p></p></div>
		<br class="clear"/>
	</div> <!-- header -->
		
	<div class="content">

<br/>
<div class="product-list">
	<h2>Our Members</h2>
	<br/>
		<form name="search" method="get" action="members.php" id="search">
			<input type="text" value="keywords" name="keyword" class="s0" />
			<input type="submit" name="search" value="Search Members" class="button marL10" />
			<input type="hidden" name="page" value="members" />
		</form>
	<br/><br/>
	<a class="pages" href="members.php">&lt;prev</a>
	&nbsp;|&nbsp;
	<a class="pages" href="members.php">next&gt;</a>
	<table>
		<tr>
			<th>Member ID</th><th>Name</th>
		</tr>
				<tr>
			<td>00000062</td>
			<td><img src="images/m.gif" /> Aileen Duncan</td>
			
		</tr>
				<tr>
			<td>00000047</td>
			<td><img src="images/m.gif" /> Alonzo Sullivan</td>
		
		</tr>
				<tr>
			<td>00000009</td>
			<td><img src="images/m.gif" /> Armando Barlow</td>
			
		</tr>
				<tr>
			<td>00000078</td>
			<td><img src="images/m.gif" /> Blanca Le</td>
			
		</tr>
				<tr>
			<td>00000008</td>
			<td><img src="images/m.gif" /> Brian Crawford</td>
			
		</tr>
				<tr>
			<td>00000035</td>
			<td><img src="images/m.gif" /> Camille Perez</td>
			
		</tr>
				<tr>
			<td>00000024</td>
			<td><img src="images/m.gif" /> Cecelia Case</td>
			
		</tr>
				<tr>
			<td>00000038</td>
			<td><img src="images/m.gif" /> Celeste Justice</td>
			
		</tr>
				<tr>
			<td>00000053</td>
			<td><img src="images/m.gif" /> Chris Bradley</td>
			
		</tr>
				<tr>
			<td>00000022</td>
			<td><img src="images/m.gif" /> Coleen Walker</td>
			<
		</tr>
				<tr>
			<td>00000001</td>
			<td><img src="images/m.gif" /> Conrad Perry</td>
		
		</tr>
				<tr>
			<td>00000003</td>
			<td><img src="images/m.gif" /> Darrel Roman</td>
			
		</tr>
			</table>
	<br/>
	<a href="register.php" class="abutton">&nbsp;&nbsp;&nbsp;Member Sign Up&nbsp;&nbsp;&nbsp;</a>

</div>
<br class="clear-all"/>
</div><!-- content -->
	
	</div><!-- maincontent -->

	<div id="footer">
		
	</div><!-- footer -->
	
</div><!-- wrapper -->

</body>
</html>

