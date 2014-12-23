<?php
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
			<a href="staff.php"><img src="../images/logo.png" alt="SweetsComplete.Com"/></a>
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
	</div>
</div>
</body>
</html>




<?php

// This file allows the administrator to view every order.


// Set the page title and include the header:
$page_title = 'View All Orders';

// The header file begins the session.

// Require the database connection:
//require(MYSQL);
require("../../includes/db_connection.php");
echo '<h3>View Orders</h3><table border="0" width="100%" cellspacing="4" cellpadding="4" id="orders">
<thead>
	<tr>
	
    <th align="center">Order ID</th>
	
    <th align="center">Total</th>

    <th align="center">Shipping Address</th>
	<th align="center">Billing Address</th>
	<th align="center">Ship this Order</a></th>
  
  </tr></thead>
<tbody>';

// Make the query:
$q = 'SELECT O.order_id, O.total_price, O.order_date, O.shipping_address, O.billing_address FROM orders as O WHERE O.shipped =0';

$r = mysqli_query($connection, $q);
while ($row = mysqli_fetch_array ($r, MYSQLI_ASSOC)) {
	echo '<tr>
	
    <td align="center"><a href="view_order.php?id=' . $row['order_id'] . '">' . $row['order_id'] . '</a></td>
	
	
	
    <td align="center">$' . $row['total_price'] .'</td>
   
    
    <td align="center">' . $row['shipping_address'] .'</td>
    <td align="center">' . $row['billing_address'] .'</td>
    
	<td align="center"><a href="ship.php?id=' . $row['order_id'] . '">Ship</a></td>
  </tr>';
 
}

echo '</tbody></table>';


?>

<script src="/js/jquery.dataTables.min.js" type="text/javascript" charset="utf-8"></script>
<script type="text/javascript"> 
// Enable Datatables:
$(function() { 
    $("#orders").dataTable();

}); 
</script>
