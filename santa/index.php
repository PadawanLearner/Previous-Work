<?php include 'includes/header_home.php'?>		
	<div class="product-list">
		
	</div><!-- product-list -->
	
	<h1><font size="55" color="red">Online Specials: Checkout these amazing deals!</font></h1>
	<br>
	
<?php 
$q="SELECT item_id, item_image FROM items";

$r = mysqli_query($connection, $q);

while ($row = mysqli_fetch_array ($r, MYSQLI_ASSOC)) {

		$item_image1 = $row['item_image'];
		$item_id1=$row['item_id'];
		
		echo "<a href='detail.php?pro_id=$item_id1'><img src='item_images/$item_image1' width ='380' height ='380' /></a>";
	
	
 
}
?>
	<br class="clear-all"/>
</div><!-- content -->
	
	</div><!-- maincontent -->

	<div id="footer">
	
	</div><!-- footer -->
	
</div><!-- wrapper -->

</body>
</html>
