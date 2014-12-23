<?php require_once("../../includes/db_connection.php"); ?>

<!DOCTYPE HTML>
<html>
<head>
<title>Santa's Black Market | Products</title>
<meta http-equiv="Content-Type" content="text/html; charset=utf-8">
<meta name ="description" content ="Santas Black Market">
<meta name="keywords" content="">
<link rel="stylesheet" href="../css/main.css" type="text/css">
<link rel="shortcut icon" href="../images/favicon.ico?v=2" type="image/x-icon" />
</head>
<body>
<div id="wrapper">
	<div id="maincontent">
		
	<div id="header">
		<div id="logo" class="left">
			<a href="staff.php"><img src="../images/logo.png" alt="SweetsComplete.Com"/></a>
		</div>
		<div class="right marT10">
			<b>
			<a href="login.php" >Login</a> |<a href="members.php" >Our Members</a>
			</b>
			<br />
			Welcome Guest		</div>
		<ul class="topmenu">
		<li><a href="../index.php">Home</a></li>
		
		</ul>
		<br>
		<div class="banner"><p></p></div>
		<br class="clear"/>
	</div> <!-- header -->
		
	<div class="content">

<div id="leftnav">
	<div class="search">

		<form name="search" method="get" action="search.php" id="search">
			<input type="text" value="keywords" name="keyword" class="s0" />
			<br />
			<select name="title" class="s2">
			<option value="00000019"> Toys</option><option value="00000034">Games</option></select>
			<br />
			<input type="submit" name="search" value="Search Products" class="button marT5" />
			<input type="hidden" name="page" value="search" />
		</form>
		<br /><br />
		
		<h3>About Us</h3><br/>
		<p class="width180">
		
		<h1>Santa actually does not sell his stuff</h1>
		</p>
	</div>
</div><!-- leftnav -->


<div id="rightnav">

	<div class="product-list">
		<h2>Our Products</h2>
		<a class="pages" href="products.php">&lt;prev</a>
		&nbsp;|&nbsp;
		<a class="pages" href="products.php">next&gt;</a>
			<ul>
				<li>
					<div class="image">
						<a href="detail.php">
						<img src="images/167_2835774.scale_20.JPG" alt=" Ambrosia Salad" width="190" height="130"/>
						</a>
					</div>
					<div class="detail">
						<p class="name"><a href="detail.php"> Ambrosia Salad</a></p>
						<p class="view"><a href="detail.php">purchase</a> | <a href="detail.php">view details >></a></p>
					</div>
				</li>
				<li>
					<div class="image">
						<a href="detail.php">
						<img src="images/167_2835774.scale_20.JPG" alt=" Apple Pie a la Mode" width="190" height="130"/>
						</a>
					</div>
					<div class="detail">
						<p class="name"><a href="detail.php"> Apple Pie a la Mode</a></p>
						<p class="view"><a href="detail.php">purchase</a> | <a href="detail.php">view details >></a></p>
					</div>
				</li>
				<li>
					<div class="image">
						<a href="detail.php">
						<img src="images/430_3151480.scale_20.JPG" alt=" Apple Turnover" width="190" height="130"/>
						</a>
					</div>
					<div class="detail">
						<p class="name"><a href="detail.php"> Apple Turnover</a></p>
						<p class="view"><a href="detail.php">purchase</a> | <a href="detail.php">view details >></a></p>
					</div>
				</li>
				<li>
					<div class="image">
						<a href="detail.php">
						<img src="images/430_3150132.scale_20.JPG" alt=" Baked Alaska" width="190" height="130"/>
						</a>
					</div>
					<div class="detail">
						<p class="name"><a href="detail.php"> Baked Alaska</a></p>
						<p class="view"><a href="detail.php">purchase</a> | <a href="detail.php">view details >></a></p>
					</div>
				</li>
				<li>
					<div class="image">
						<a href="detail.php">
						<img src="images/700_3473780.scale_20.JPG" alt=" Baklava" width="190" height="130"/>
						</a>
					</div>
					<div class="detail">
						<p class="name"><a href="detail.php"> Baklava</a></p>
						<p class="view"><a href="detail.php">purchase</a> | <a href="detail.php">view details >></a></p>
					</div>
				</li>
				<li>
					<div class="image">
						<a href="detail.php">
						<img src="images/430_3151480.scale_20.JPG" alt=" Banana Bread" width="190" height="130"/>
						</a>
					</div>
					<div class="detail">
						<p class="name"><a href="detail.php"> Banana Bread</a></p>
						<p class="view"><a href="detail.php">purchase</a> | <a href="detail.php">view details >></a></p>
					</div>
				</li>
				<li>
					<div class="image">
						<a href="detail.php">
						<img src="images/430_3150132.scale_20.JPG" alt=" Banana Pudding" width="190" height="130"/>
						</a>
					</div>
					<div class="detail">
						<p class="name"><a href="detail.php"> Banana Pudding</a></p>
						<p class="view"><a href="detail.php">purchase</a> | <a href="detail.php">view details >></a></p>
					</div>
				</li>
				<li>
					<div class="image">
						<a href="detail.php">
						<img src="images/167_2835774.scale_20.JPG" alt=" Banana Split" width="190" height="130"/>
						</a>
					</div>
					<div class="detail">
						<p class="name"><a href="detail.php"> Banana Split</a></p>
						<p class="view"><a href="detail.php">purchase</a> | <a href="detail.php">view details >></a></p>
					</div>
				</li>
				<li>
					<div class="image">
						<a href="detail.php">
						<img src="images/167_2835774.scale_20.JPG" alt=" Black Forest Cake" width="190" height="130"/>
						</a>
					</div>
					<div class="detail">
						<p class="name"><a href="detail.php"> Black Forest Cake</a></p>
						<p class="view"><a href="detail.php">purchase</a> | <a href="detail.php">view details >></a></p>
					</div>
				</li>
		</ul>
	</div><!-- product-list -->
	
	
</div><!-- rightnav -->

<br class="clear-all"/>
</div><!-- content -->
	
	</div><!-- maincontent -->

	<div id="footer">
		
	</div><!-- footer -->
	
</div><!-- wrapper -->

</body>
</html>

