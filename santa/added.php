<?php 
	session_start();
	//Redirect to login if user is not logged in
	if ( isset($_SESSION['user_level']) && ($_SESSION['user_level'] == 1)){
		echo "Member Logged In";
	}
	else{
		header("Location: http://www.cs.uky.edu/~ylu236/santa/login.php"); 
	}

?>
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
			<a href="index.php" >Log out</a> |<a href="cart.php" >Shopping Cart</a>
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

<?php



	//Redirect to login if user is not logged in
	if ( isset($_SESSION['user_level']) && ($_SESSION['user_level'] == 1)){
		echo "Member Logged In";
	}
	else{
		header("Location: http://www.cs.uky.edu/~ylu236/santa/login.php"); 
	}




//This pro_id is coming from the products.php or member_products.php, where
//there is a line of code added.php?pro_id=$item_id
if ( isset( $_GET['pro_id'] ) ) $id = $_GET['pro_id'] ; 
// Connect to the database
require ( '../includes/db_connection.php' ) ;

$q = "SELECT * FROM items WHERE item_id = $id" ;
$result = mysqli_query( $connection, $q ) ;
if ( mysqli_num_rows( $result ) == 1 )
{
  $row = mysqli_fetch_array( $result, MYSQLI_ASSOC );
 // If the cart already contains one of those products
  if ( isset( $_SESSION['cart'][$id] ) )
  { 
    // Add another one of the products
    $_SESSION['cart'][$id]['quantity']++; 
    echo '<h3>Another one of those products has been added to your cart</h3>';
  } 
  else
  {
    // Add a different product
    $_SESSION['cart'][$id]= array ( 'quantity' => 1, 'price' => $row['item_price'] ) ;
    echo '<h3>A product has been added to your cart</h3>' ;
  }
}
// Close the database connection
mysqli_close($connection);
// Insert links



echo '<p><a href="member_products.php">Continue Shopping</a> | <a href="cart.php">View my Cart</a></p>' ;
?>
	
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

