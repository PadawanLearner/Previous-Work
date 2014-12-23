<?php
session_start();

//Redirect to login if user is not logged in
if ( isset($_SESSION['user_level']) && ($_SESSION['user_level'] == 1)){
	echo "Logged In";
}
else{
	header("Location: http://www.cs.uky.edu/~ylu236/santa/login.php"); 
}




// This file allows the user to view a single order.

// Set the page title and include the header:
$page_title = 'View User Orders';

// The header file begins the session.

// Require the database connection:
//require(MYSQL);
require("../includes/db_connection.php");
echo '<h3>View Order</h3><table border="0" width="100%" cellspacing="4" cellpadding="4" id="orders">
<thead>
	<tr>
	<th align="center">Item ID</th>
    <th align="center">Order ID</th>
	<th align="center">Item Name</th>
	<th align="center">Quantity</th>
    <th align="center">Total</th>

    <th align="center">Shipping Address</th>
	<th align="center">Billing Address</th>
	<th align="center">Order Status</th>
  
  </tr></thead>
<tbody>';

//Get user id, as it is all we need for the query 
$userId = $_SESSION['user_id'];

// Make the query:
$q = "SELECT I.item_id, I.item_name, C.quantity, O.order_id, I.item_price,U.name,O.order_date, O.shipping_address, O.billing_address, O.shipped 
FROM user as U,  places as P, orders as O, contains as C, items as I 
WHERE U.user_id = P.user_id AND P.order_id = O.order_id AND C.order_id = O.order_id AND C.item_id = I.item_id AND U.user_id = $userId";

$r = mysqli_query($connection, $q);
while ($row = mysqli_fetch_array ($r, MYSQLI_ASSOC)) {
	echo '<tr>

	<td align="center">' . $row['item_id'] .'</td>
	<td align="center">' . $row['order_id'] .'</td>
	<td align="center">' . $row['item_name'] .'</td>
	<td align="center">' . $row['quantity'] .'</td>
	
    <td align="center">$' . $row['item_price']*$row['quantity'] .'</td>
   
    
    <td align="center">' . $row['shipping_address'] .'</td>
    <td align="center">' . $row['billing_address'] .'</td>
    <td align="center">'; 
	if ($row['shipped']){
		echo "Shipped";
	}
	else{
		echo "Pending";
	}
	  echo'</td>;
	
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
