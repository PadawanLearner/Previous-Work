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


$page_title = 'Add Inventory';

// Require the database connection:
require("../../includes/db_connection.php");
$item_id = $_GET['id'];
// Check for a form submission:
if ($_GET['id']) {	

	echo "Yes";
	echo "
	<form method='post' enctype='multipart/form-data'>
	
		<table align='center' width='750' border='2' bgcolor='FFCCFF'>
			
			
			<tr>
				<td colspan ='7'><h2>Update Inventory</h2></td>
			</tr>
			
			
	
			
			<tr>
				<td align='right'><b>Inventory:</b> </td>
				<td><input type='text' name='inventory' required /></td>
			</tr>
			
			
			<tr align ='center'>
				<td colspan='7'><input type='submit' name='update_inventory' value ='Update Inventory' /></td>
			</tr>
				
		</table>
</form> ";

	if(isset($_POST['update_inventory'])){
		$inventory = $_POST['inventory'];
		$q="UPDATE items SET inventory = $inventory WHERE item_id=$item_id";
		$result =mysqli_query($connection, $q);
		
		if($result){
			echo "You successfully updated inventory";
		}
		
	}
		
}
?>


