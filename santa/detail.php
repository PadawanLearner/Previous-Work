<?php require_once("../includes/db_connection.php"); ?>
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
			<b>
			</b>
			<br />
		</div>
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
	<br/>

<?php

		session_start();
		
		//First check to see if the user is logged in such that he/she can in fact add to a cart
		

		/* get product id selected by the customer
		and match to the item_id in the database. Display 
		the item_discription (which was not displayed on the home page*/	
		if(isset($_GET['pro_id'])){
			$product_id = $_GET['pro_id'];
			
			$get_pro="
				SELECT * 
				FROM items
				WHERE item_id = '$product_id'";
				
				
			//executing the query
			$run_pro=mysqli_query($connection, $get_pro);
		
		
		while($row_pro= mysqli_fetch_array($run_pro)){
			$item_id = $row_pro['item_id'];
			$item_name = $row_pro['item_name'];
			
			$item_price = $row_pro['item_price'];
			$item_image = $row_pro['item_image'];
			$item_description = $row_pro['item_description'];
		
			echo "
				<div id='single_item'>
					
						<h3>$item_name</h3>
						
						<img src='item_images/$item_image' width ='400' height ='300' />
						
						<p><b> $$item_price </b></p>
						
						
						<p>$item_description</p>
						
						";
						
						if (isset($_SESSION['user_level']) && $_SESSION['user_level'] == 1){
						
						echo"
							<a href='".$_SERVER['HTTP_REFERER']."' style ='float:left;'>Go Back</a>
						
							<a href='added.php?pro_id=$item_id'><button style='float:right'/>Add to Cart</a>  
							";
						}
						else{
							echo"
							<a href='".$_SERVER['HTTP_REFERER']."' style ='float:left;'>Go Back</a>
						
							<a href='login.php'><button style='float:right'/>Add to Cart</a>  
							";
						}
				
				
				echo
				"</div>";
			
			
			 			
		}//end while
		}//end if
		
	
//Product Recommendation
echo '<table border="0" width="100%" cellspacing="4" cellpadding="4" id="orders">
<thead>
	<h2 align="center"><strong>Customer Who Bought This Also Bought</strong></h2>
  </thead>
<tbody>';
// Make the query: This query total revenue
$q = "SELECT c2.item_id, i.item_image FROM contains c1 JOIN contains c2 ON c1.order_id = c2.order_id JOIN items i ON c2.item_id = i.item_id WHERE c1.item_id = $product_id AND c2.item_id !=$product_id GROUP BY c2.item_id ORDER BY COUNT(c2.item_id) DESC limit 5";
$r = mysqli_query($connection, $q);
while ($row = mysqli_fetch_array ($r, MYSQLI_ASSOC)) {

		$item_image1 = $row['item_image'];
		$item_id1=$row['item_id'];
		
		echo "<a href='detail.php?pro_id=$item_id1'><img src='item_images/$item_image1' width ='150' height ='150' /></a>";
	
	
 
}
echo '</tbody></table>';

	?>
	
<br class="clear-all"/>
</div><!-- content -->
	
	</div><!-- maincontent -->

	<div id="footer">
		
	</div><!-- footer -->
	
</div><!-- wrapper -->

</body>
</html>

