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
// This file allows the administrator to view every item and its quantity.


// Set the page title and include the header:
$page_title = 'View Item Inventory';

// The header file begins the session.

// Require the database connection:
//require(MYSQL);
require("../../includes/db_connection.php");
echo '<h3>View Item Inventory</h3><table border="0" width="100%" cellspacing="4" cellpadding="4" id="orders">
<thead>
	<tr>
	<th align="center">Item ID</th>
    <th align="center">Item Name</th>
	<th align="center">Item Category</th>
	<th align="center">Item Price</th>
	<th align="center">Inventory</th>
	<th align="center">Update Inventory</th>  
	<th align="center">Add Promotion</th>  
  </tr></thead>
<tbody>';

// Make the query:
$q = "SELECT * from items";

$r = mysqli_query($connection, $q);
while ($row = mysqli_fetch_array ($r, MYSQLI_ASSOC)) {
	echo '<tr>
	 <td align="center">'. $row['item_id'] . '</td>
   
	<td align="center">' . $row['item_name'] .'</td>
	<td align="center">' . $row['item_category'] .'</td>
	
    <td align="center">$' . $row['item_price'] .'</td>
   <td align="center">' . $row['inventory'] .'</td>
    <td align="center"><a href="update_inventory.php?id=' . $row['item_id'] . '">Update Inventory</a></td>
  
   <td align="center"><a href="promotion.php?id=' . $row['item_id'] . '">Add Promotion(manager only)</a></td>
  </tr>';
 
}

echo '</tbody></table>';
//Delete row with item_id and order id from contains table, 
//update item quantity in items table

?>

<script src="/js/jquery.dataTables.min.js" type="text/javascript" charset="utf-8"></script>
<script type="text/javascript"> 
// Enable Datatables:
$(function() { 
    $("#orders").dataTable();

}); 
</script>
