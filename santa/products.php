<?php include 'includes/header_home.php'?>	


		<h2>Our Products</h2>
		
		<div id="item_box">
		
		<?php 
		//Display all the products in the item table
		$get_product="
		SELECT * 
		FROM items";
		//executing the query
		$run_pro=mysqli_query($connection, $get_product);
		
		/*
		The temporary variables are connected to the field name
		in the table items. The name inside of the [] is the field name
		From the table items
		*/
		while($row_pro= mysqli_fetch_array($run_pro)){
			$item_id = $row_pro['item_id'];
			$item_name = $row_pro['item_name'];
			$item_category = $row_pro['item_category'];
			$item_price = $row_pro['item_price'];
			$item_image = $row_pro['item_image'];
		
			/*
			Displays the table onto the page by include html code inside the 
			php code using quotes
			*/
			echo "
				<div id='single_item'>
					
						<h3>$item_name</h3>
						
						<img src='item_images/$item_image' width ='180' height ='180' />
						
						<p><b> $$item_price </b></p>
						
						
						<a href='detail.php?pro_id=$item_id'>Details</a>
						
						
						
				
				</div>";			

		//<a href='added.php?pro_id=$item_id'><button/>Add to Cart</a> //line 47
	}//end while
		
		
		?>
		
		</div>
		
		
	
	

<br class="clear-all"/>
</div><!-- content -->
	
	</div><!-- maincontent -->

	<div id="footer">
		
	</div><!-- footer -->
	
</div><!-- wrapper -->

</body>
</html>

