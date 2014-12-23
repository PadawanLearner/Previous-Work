<?php
session_start();
include 'includes/header_home.php'
?>



<?php 
// Determine whether the form been submitted
if ($_SERVER['REQUEST_METHOD'] == 'POST') {
//connect to database
	require ('../includes/db_connection.php');
// Was the email address entered?
	if (!empty($_POST['email'])) {
			$e = mysqli_real_escape_string($connection, $_POST['email']);
	} else {
	$e = FALSE;
		echo '<p class="error">You forgot to enter your email address.</p>';
	}
// Was the password entered?
	if (!empty($_POST['password'])) {
			$p = mysqli_real_escape_string($connection, $_POST['password']);
	} else {
	$p = FALSE;
		echo '<p class="error">You forgot to enter your password.</p>';
	}
	if ($e && $p){//if no problem was encountered
// Select the user_id, first_name and user_level for that email/password combination
		$q = "SELECT user_id, name, user_level FROM user WHERE (email='$e' AND password='$p')";		
		$result = mysqli_query ($connection, $q); 
		// Check the result
		if (@mysqli_num_rows($result) == 1) {//The user input matched the database record
		// Start the session, fetch the record and insert the three values in an array
		
		
		//$_SESSION["checked"]=true;
		session_start();
		
		$_SESSION = mysqli_fetch_array ($result, MYSQLI_ASSOC);
		
		
$_SESSION['user_level'] = (int) $_SESSION['user_level']; // Ensure the user level is an integer
$_SESSION['user_id'] = (int) $_SESSION['user_id'];
// The login page redirects the user either to the admin page or the users search page
// Use a ternary operation to set the URL
if(($_SESSION['user_level'] === 51)){
$url = './staff/staff.php';
}
else if($_SESSION['user_level'] === 22){
$url = './staff/staff.php';
}
else{

$url = 'member_products.php';
}

//$url = ($_SESSION['user_level'] === 51) ? './manager/manager.php' : 'member_products.php';
//$url = ($_SESSION['user_level'] === 22) ? './staff/staff.php' : 'member_products.php';
header('Location: ' . $url); // The user is directed to the appropriate page
exit(); // Cancel the rest of the script
	mysqli_free_result($result);
	mysqli_close($connection);
	} else { // If no match was found
	
	echo '<p class="error">The email address and password entered do not match our records.<br>Perhaps you need to register, click the Register button on the header menu</p>';
	}
	} else { // If there was a problem
		echo '<p class="error">Please try again.</p>';
	}
	mysqli_close($connection);
	} // End of submit conditional
?>




	<br/>
	<div class="product-list">
		
		<h2>Login</h2>
		<br/>
		
		<b>Please enter your information. If you do not have an account with us, please </b> <u><a href="http://www.cs.uky.edu/~ylu236/santa/register.php">register.</a></u><br/><br/>
		<form  method="POST">
			<p>
				<label>Email: </label>
				<input type="text" name="email" />
			<p>
			<p>
				<label>Password: </label>
				<input type="password" name="password" />
			<p>
			<p>
				<input type="reset" name="data[clear]" value="Clear" class="button"/>
				<input type="submit" name="submit" value="Log In" class="button marL10"/>
			<p>
		</form>
	</div><!-- product-list -->
</div>
	
	</div><!-- maincontent -->

	<div id="footer">
	
	</div><!-- footer -->
	
</div><!-- wrapper -->

</body>
</html>

