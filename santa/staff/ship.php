<?php 
session_start();
require("../../includes/db_connection.php");

/*if (!isset($_GET['id1']) || !isset($GET['id2']))
{
    echo 'No ID was given...';
    exit;
}
*/
$order_id = (int)($_GET['id']);
echo "order ID = " . $order_id;


//Beginning of the transaction
mysqli_autocommit($connection, FALSE);

$update_orders = "UPDATE orders SET shipped = 1 WHERE order_id=$order_id";
mysqli_query($connection, $update_orders);

//get all the items from a order
$ordered_items = "SELECT item_id, quantity FROM contains WHERE order_id =$order_id";
$result = mysqli_query($connection, $ordered_items);
//decrement inventory values from items
while ($row = mysqli_fetch_array ($result, MYSQLI_ASSOC)){

	$item_id = $row['item_id'];
	$quantity = $row['quantity'];
	
	$update_invetory="UPDATE items SET inventory = inventory - $quantity WHERE item_id = $item_id";
	$query = mysqli_query($connection, $update_invetory);
}

if(!mysqli_commit($connection)){
	print("Commit failed");
}
else{
	print("Success");
	}
			//end of transaction



$connection->close();

?>
