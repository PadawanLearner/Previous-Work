<?php
	session_start();

	//Redirect to login if user is not logged in
	if ( isset($_SESSION['user_level'])){
		echo "Logged In";
	}
	else{
		header("Location: http://www.cs.uky.edu/~ylu236/santa/login.php"); 
	}

?>
<!DOCTYPE HTML>

<html>


<head>
<title>Santa's Black Market | Cart</title>
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
			<a href="logout.php" >Log out</a> |<a href="cart.php" >Shopping Cart</a>
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
		<h2>Shopping Basket</h2>


		
<?php
if ( $_SERVER['REQUEST_METHOD'] == 'POST' )
{
// If the user changes the quantity then Update the cart
  foreach ( $_POST['qty'] as $item_id => $item_qty )
  {
// Ensure that the id and the quantity are integers
    $id = (int) $item_id;
    $qty = (int) $item_qty;
// If the quantity is set to zero clear the session or else store the changed quantity
    if ( $qty == 0 ) { unset ($_SESSION['cart'][$id]); } 
    elseif ( $qty > 0 ) { $_SESSION['cart'][$id]['quantity'] = $qty; }
  }
}
// Set an initial variable for the total cost
$total = 0; 

// Display the cart contents
if (!empty($_SESSION['cart']))
{
// Connect to the database.
  require ('../includes/db_connection.php');
// Get the items from the art table and insert them into the cart
  $q = "SELECT * FROM items WHERE item_id IN (";
  foreach ($_SESSION['cart'] as $id => $value) { $q .= $id . ','; }
  $q = substr( $q, 0, -1 ) . ') ORDER BY item_id ASC';
  
  $result = mysqli_query ($connection, $q);
// Create a form and a table
  echo '<form action="cart.php" method="post">
  <table><tr>';
  while ($row = mysqli_fetch_array ($result, MYSQLI_ASSOC))
  {
// Calculate the subtotals and the grand total
    $subtotal = $_SESSION['cart'][$row['item_id']]['quantity'] * $_SESSION['cart'][$row['item_id']]['price'];
    $total += $subtotal;
// Display the table
    echo "<tr> <td>{$row['item_name']}</td><td>Product(s)</td> 
    <td><input type=\"text\" size=\"3\" name=\"qty[{$row['item_id']}]\" value=\"{$_SESSION['cart'][$row['item_id']]['quantity']}\"></td>
    <td>at {$row['item_price']} each </td> <td style=\"text-align:right\">".number_format ($subtotal, 2)."</td></tr>";
  }
  
  
  
  //Calculate how much promotion to reduce from the total price
   $q = "SELECT I.item_id, P.promotion_rate, P.start_date, P.end_date FROM items AS I, promotion AS P WHERE P.end_date < NOW() I.item_id = P.item_id AND I.item_id IN (";
  foreach ($_SESSION['cart'] as $id => $value) { $q .= $id . ','; }
  $q = substr( $q, 0, -1 ) . ') ORDER BY I.item_id ASC';
  
  $result = mysqli_query ($connection, $q);
// Create a form and a table
  echo '<form action="cart.php" method="post">
  <table><tr>';
  while ($row = mysqli_fetch_array ($result, MYSQLI_ASSOC))
  {
	echo "Hey";
	 $subtotal = $_SESSION['cart'][$row['item_id']]['quantity'] * $_SESSION['cart'][$row['item_id']]['price'];
	 $subtotal = $subtotal * $row['promotion_rate'];
	 $p += $subtotal;
	echo "Promotion ".$p;
	
  }
  
  
  $total = $total - $p;
    
  
  
  
// Close the database connection
  mysqli_close($connection); 
// Display the total
  echo ' <tr><td colspan="5" style="text-align:right">Applied promotion' .number_format($p, 2).'</td><td colspan="5" style="text-align:right">Total = '.number_format($total,2).'</td></tr>
  </table>
  <input id="submit" type="submit" name="submit" value="Update My Cart"></form>';
  
  
  //Prepare total for checkout page:
  $_SESSION['checkout_total'] = $total;
  $_SESSION['quantity']=$qty;
  $_SESSION['item_id']=$id;
  
  
}
else
// Or display a message
{ echo '<p>Your cart is currently empty.</p>' ; }


// Create some links


	echo '<p><a href="member_products.php">Continue Shopping</a> | <a href="checkout.php">Checkout</a>';
?>
	</div>

</div><!-- content -->
	
	</div><!-- maincontent -->

	<div id="footer">
		<div class="footer">
	
	</div><!-- footer -->
	
</div><!-- wrapper -->

</body>
</html>

