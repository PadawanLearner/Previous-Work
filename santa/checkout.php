<?php 
	session_start();
	//Redirect to login if user is not logged in
	if ( isset($_SESSION['user_level']) && ($_SESSION['user_level'] == 1)){
		echo "Logged In";
	}
	else{
		header("Location: http://www.cs.uky.edu/~ylu236/santa/login.php"); 
	}
?>
<!DOCTYPE HTML>
<html>
<head>
<title>Santa's Black Market| Checkout</title>
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

<?php
	//make db connection
	require ('../includes/db_connection.php');


//Is the user visiting the checkout page for the first time, i.e. they are coming from cart.php
if (!( $_SERVER['REQUEST_METHOD'] == 'POST' )){	
	//Acquire user information for the order:
	echo "Your total is ".$_SESSION['checkout_total']."<br>";
	echo '<form action="checkout.php" method="post" >'.'<br>';
	echo "Please enter your email";
	echo "<input type='text' name='email'>"."<br>";
	echo "Please enter your billing address";
	echo "<input type='text' name='billing_address'>"."<br>";
	echo "Please enter your shipping address";
	echo "<input type='text' name='shipping_address'>"."<br>";
	echo '<input type="submit" name="make_order">'."<br>";
	echo "</form>";
	
	//the query has not been made yet:
	$_SESSION['flag'] = false;
}

//Did the user already input ALL their info on checkout.php? Then report the order detials and put the info into sql, i.e. make the order:
else if ( $_SERVER['REQUEST_METHOD'] == 'POST' 
&& isset($_POST['email']) && ($_POST['email'] != '') 
&& isset($_POST['billing_address']) && ($_POST['billing_address'] != '')
&& isset($_POST['shipping_address']) && ($_POST['shipping_address'] != '')
)
{

	//check if user is valid i.e is the user in the db
	$temp = $_POST['email'];	
	$is_user_in_db_query = mysqli_query($connection, "SELECT * FROM user WHERE email = '$temp'");
	$user_info = mysqli_fetch_array($is_user_in_db_query);
	$successful_row_result = mysqli_num_rows($is_user_in_db_query);
	
	if($successful_row_result)
	{
	
		/*t0-do: guard against sql injection*/
		
		//get price into float format:
		$order_price = (float)($_SESSION['checkout_total']);
		echo "Price ".$order_price;
		//get string value for the addresses:
		$order_bill_addr = (string)($_POST['billing_address']);
		$order_ship_addr = (string)($_POST['shipping_address']);
		
		
		//get the item_id and qty from the cart.php
		$item_id = (int)($_SESSION['item_id']);
		$qty = (int)($_SESSION['quantity']);
		
		
		
		echo "qty = ".$qty;

		

		
		//insert the order if it hasn't already been made (flag)
		if (!$_SESSION['flag']){
			
			//Beginning of the transaction
			mysqli_autocommit($connection, FALSE);
			
			//now we are ready to create the order in sql:
			$order_query = "INSERT into orders (total_price,shipping_address,billing_address) 
						values ('$order_price','$order_ship_addr','$order_bill_addr')";
			
			$order_to_sql = mysqli_query($connection, $order_query);
			
			//Retrieve the order_id for this checkout
			$order_id = mysqli_insert_id($connection);
			
			
			  $q = "SELECT * FROM items WHERE item_id IN (";
			  foreach ($_SESSION['cart'] as $id => $value) { $q .= $id . ','; }
			  $q = substr( $q, 0, -1 ) . ') ORDER BY item_id ASC';
  
			$result = mysqli_query ($connection, $q);
			
			//Insert associated order into places table
			while($row = mysqli_fetch_array($result, MYSQLI_ASSOC)){
			
				
				$item_id = (int)($row['item_id']);
				$item_qty=(int)($_SESSION['cart'][$row['item_id']]['quantity']);
				
				echo "Item ID = ".$item_id." Quantity = ". $item_qty;
				$query = "INSERT INTO contains ( order_id, item_id, quantity ) VALUES ($order_id, $item_id, $item_qty)";
				$insert_to_contains = mysqli_query($connection,$query);
			}
			//Get user id from email submitted
			$result = mysqli_query($connection, "SELECT user_id FROM user WHERE email = '$temp'");
			$row = mysqli_fetch_assoc($result);
			$user_id = (int)($row['user_id']);
			
			//insert into places table
			$places_query="INSERT INTO places (user_id, order_id) VALUES ('$user_id','$order_id')";
			$places_to_sql = mysqli_query($connection, $places_query);
			
			if(!mysqli_commit($connection)){
				print("Commit failed");
			}
			else{
				print("Success");
			}
			//end of transaction
			
		}
		
		//did the query go through? then lets check and output the results:
		if ($order_to_sql){
			//We must do the following, otherwise if the user refreshes the page, it will produces another identical order in the db. This flag will stop the else-if conditional above
			$_SESSION['flag'] = true;
			
			
			
			// REPORT THE USERS ORDER INFORMATION BACK TO THEM 
			//find the orders that are being shipped to the users house:
			$check_order = "SELECT * 
							FROM orders
							WHERE shipping_address = '$order_ship_addr'";
			$get_order = mysqli_query($connection, $check_order);
			//Tell the user which orders are being shipped to his house (including the one he/she just ordered!)
			
			
			
			
			
			
			
			
			
			//number of orders being shipped to the same address:
			$order_info_rows = mysqli_num_rows($get_order);
			$ctr = 0;
			while ($order_info= mysqli_fetch_array($get_order)){
				
				if ($ctr == $order_info_rows-1){
					echo "<br>"."The amount of $".$order_info['total_price']." will be billed to ".$order_info['billing_address']."<br>";
					echo "<br>"."Your order will be shipped to ".$order_info['shipping_address'].'<br>';
					echo "<br>"."Your order confirmation number is ".$order_info['order_id']."<br>";
					
					//insert the order into places using the unique keys that we now have
					$places_user_id = $user_info['user_id']; 
					$places_order_id = $order_info['order_id'];
					$places_query = "INSERT into places (user_id, order_id) values ('$places_user_id','$places_order_id')";
					$places_to_sql = mysqli_query($connection, $places_query);
				}
				$ctr++;
			}
			
		
			
			
			//places
			//$places_user_id = $user_info['user_id']; 
			//$places_order_id = $order_info['order_id'];
			//$places_query = "INSERT into places (user_id, order_id) values ('$places_user_id','$places_order_id')";
			//$places_to_sql = mysqli_query($connection, $places_query);
			
			//contains
			//$contains_query = "";
					
			//$contains_to_sql = mysqli_query($connection, $contains_query);
			
		
		}
		
		
		//The user clicked refresh on the page after his order is already shipped
		else if($_SESSION['flag']){
			echo "
			<br><h3>The shopping cart has been emptied ready for your next 
			transaction.</h3><br>Your order has been registered. Please check your user account. Thank you!<br>";
		}
		//failure of query (This should never happen but contingency is a good thing)
		else{
			echo mysqli_error($connection) . ": " . mysqli_error($connection)."\n";
			echo "<br>Your order has not been registered, please try again.<br>";
		}
		
	}
	//They entered an invalid email address
	else{
		echo "<br>You did not enter a valid email address that is linked to your account with us.  Please re-enter your information. Thank you.<br>";
		//Acquire user information for the order:
		echo "Your total is ".$_SESSION['checkout_total']."<br>";
		echo '<form action="checkout.php" method="post" >'.'<br>';
		echo "Please enter your email";
		echo "<input type='text' name='email'>"."<br>";
		echo "Please enter your billing address";
		echo "<input type='text' name='billing_address'>"."<br>";
		echo "Please enter your shipping address";
		echo "<input type='text' name='shipping_address'>"."<br>";
		echo '<input type="submit" name="make_order">'."<br>";
		echo "</form>";
		$_SESSION['flag'] = false;
	}

}

//They did not fill out all fields
else{
	echo "<br>You did not enter all of your information.<br>Please re-enter your information. Thank you.<br>";
	//Acquire user information for the order:
	echo "Your total is ".$_SESSION['checkout_total']."<br>";
	echo '<form action="checkout.php" method="post" >'.'<br>';
	echo "Please enter your email";
	echo "<input type='text' name='email'>"."<br>";
	echo "Please enter your billing address";
	echo "<input type='text' name='billing_address'>"."<br>";
	echo "Please enter your shipping address";
	echo "<input type='text' name='shipping_address'>"."<br>";
	echo '<input type="submit" name="make_order">'."<br>";
	echo "</form>";
	$_SESSION['flag'] = false;
}

/*

*/

	/* CONTAINS */
	
	//get product(s) from last page
	//get their quantities
	
	//send to sql

?>
	

</div><!-- content -->
	
	</div><!-- maincontent -->

	<div id="footer">
		
	</div><!-- footer -->
	
</div><!-- wrapper -->

</body>
</html>
