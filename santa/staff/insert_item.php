<?php require_once("../../includes/db_connection.php"); 
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
<meta name ="description" content ="Sweets Complete">
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
			<a href="../logout.php" >Logout</a> 
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
		
	<div class="content">
		
	<div class="product-list">
		
		
		
		<!--Script for the text area box-->
<script src="//tinymce.cachefly.net/4.1/tinymce.min.js"></script>
<script>tinymce.init({selector:'textarea'});</script>

<form action="insert_item.php" method="post" enctype="multipart/form-data">
	
		<table align="center" width="750" border="2" bgcolor="FFCCFF">
			
			<!-- Insert new Items by admins-->
			<tr align="center">
				<td colspan ="7"><h2>Insert New Item Here</h2></td>
			</tr>
			
			
			<tr>
				<td align="right"><b>Item Name: </b> </td>
				<td><input type="text" name="item_name" size ="60" required/></td>
			</tr>
			
			<tr>
				<td align="right"><b>Category: </b> </td>
				<td><select name="item_category">
					<option value="">- Select -</option>
					<option value="Toys">Toys</option>
					<option value="Games">Games</option>
				</select></td>
				
				

			</tr>
			
			<tr>
				<td align="right"><b>Item image: </b> </td>
				<td><input type="file" name="item_image" required /></td>
			</tr>
			
			<tr>
				<td align="right"><b>Price:</b> </td>
				<td><input type="text" name="item_price" required /></td>
			</tr>
			
			<tr>
				<td align="right"><b>Inventory:</b> </td>
				<td><input type="text" name="inventory" required /></td>
			</tr>
			
			
			<tr>
				<td align="right"><b>Description:</b> </td>
				<td><textarea name="item_description" cols="20" rows="10"></textarea></td>
			</tr>
			
			
			
			<tr align ="center">
				<td colspan="7"><input type="submit" name="insert_post" value ="Insert Item Now" /></td>
			</tr>
				
		</table>
	</form>


<?php
	/* If the submit (a insert) button is clicked
	*/
	if(isset($_POST['insert_post'])){
		
		/*Getting the text data from the fields*/
		$item_name = $_POST['item_name'];
		$item_category = $_POST['item_category'];
		
		$item_price = $_POST['item_price'];
		$item_inventory=$_POST['inventory'];
		$item_description = $_POST['item_description'];
		
		/*Getting the image from the field*/
		$item_image = $_FILES['item_image']['name'];
		$item_image_tmp=$_FILES['item_image']['tmp_name'];
		
		/*Upload the file to the admin_area's item_images folder*/
		move_uploaded_file($item_image_tmp, "http://www.cs.uky.edu/~ylu236/santa/item_images/$item_image");
		
		/*Insert the new information into the database*/
		$insert_item = "insert into items (item_name,item_category,item_price,item_description,item_image,inventory) values ('$item_name','$item_category','$item_price','$item_description','$item_image', '$item_inventory')";	
		
		$insert_pro=mysqli_query($connection, $insert_item);
		
		if($insert_pro){
			echo "<script>alert('Item Has Been Inserted')</script>";
			echo "<script>window.open('insert_item.php','_self')</script>";
		}
		
	}
?>
		
		
		
		
		
		
		
		
		
	</div><!-- product-list -->
	
	<br class="clear-all"/>
</div><!-- content -->
	
	</div><!-- maincontent -->

	<div id="footer">
	
	</div><!-- footer -->
	
</div><!-- wrapper -->

</body>
</html>
