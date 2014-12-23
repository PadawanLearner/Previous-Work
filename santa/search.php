<?php include '../includes/db_connection.php'; 

?>
<!DOCTYPE HTML>
<html>
<head>
<title>Santa's Black Market | Search</title>
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
		
		<?php
		session_start();
			if (isset($_SESSION['user_level']) && ($_SESSION['user_level'] == 1)){
				echo "<a href='member_products.php'><img src='images/logo.png' alt='SweetsComplete.Com'/></a>";
			}
			else{
				echo "<a href='index.php'><img src='images/logo.png' alt='SweetsComplete.Com'/></a>";
			}
		?>
		</div>
		<div class="right marT10">
			<br />
			Welcome Guest		</div>
		<ul class="topmenu">
		<?php
		session_start();
			if (isset($_SESSION['user_level']) && ($_SESSION['user_level'] == 1)){
				echo "<li><a href='member_products.php'>Home</a></li>";
			}
			else{
				echo "<li><a href='index.php'>Home</a></li>";
			}
		?>
		
	
		</ul>
		<br>
		<div class="banner"><p></p></div>
		<br class="clear"/>
	</div> <!-- header -->
		
	<div class="content">

<div id="rightnav">

	<div class="product-list">
		
		<!-- item box -->
	<div id="item_box">
  		<?php 
		
		if(isset($_GET['search'])){
		
		$search_query=$_GET['user_query'];
		
		
		$get_pro="
		SELECT * 
		FROM items WHERE item_name like '%$search_query%'";
		//executing the query
		$run_pro=mysqli_query($connection, $get_pro);
		
		
		while($row_pro= mysqli_fetch_array($run_pro)){
			$item_id = $row_pro['item_id'];
			$item_name = $row_pro['item_name'];
			$item_category = $row_pro['item_category'];
			$item_price = $row_pro['item_price'];
			$item_image = $row_pro['item_image'];
		
			echo "
				<div id='single_item'>
					
						<h3>$item_name</h3>
						
						<img src='http://cs.uky.edu/~ylu236/santa/item_images/$item_image' width ='180' height ='180' />
						
						<p><b> $$item_price </b></p>
						
						<a href='detail.php?pro_id=$item_id' style ='float:left;'>Details</a>
						
				
				</div>
			
			
			";
	}//end while
		
	}//end if
		?>

	 </div><!--end item box -->
		
		
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

