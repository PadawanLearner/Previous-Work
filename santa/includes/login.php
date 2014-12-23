
<?php
session_start();
$email = $_POST["username"];
$password = $_POST["password"];


//did they enter the pswd and email?
if($email&&$password){

//if so, connect
//include 'sqlConnect.php';
require_once("../../includes/db_connection.php"); 

//query their email/username
$query = mysqli_query($connection, "SELECT * FROM user WHERE 
email='$email'"); // AND password='$password'");


$numrows = mysqli_num_rows($query);


//check for log in status, perform check on the the row [status]
if ($numrows!=0)
{
	$row = mysqli_fetch_array($query);
	
	//check to see if user entered in correct password:
	if ($row['password'] == $password){

		/*
		hey judy if you read this, here i used a delay on purpose so that the user has some sort of confirmation that his/her log-in was successful.  
		going straight to the new user page was almost instantaneous, and leaves the user wondering if the login was successful, so i put a delay in on purpose.
		*/

		//if admin, then redirect to admin home screen:
		if((int)$row['user_level'] == 2){
		
		$_SESSION['previous'] = basename($_SERVER['PHP_SELF']);
		$_SESSION['type'] = 'manager';
		header('Refresh: 2; URL=http://cs.uky.edu/~ylu236/santa/manager/manager.php');
		//header("location: /SantasBlackMarket/pages/manager.php");
		echo "Manager log in successful. Redirecting...";
		}
		
		//if staff, then redirect to staff home screen:
		if( (int)$row['user_level'] == 1){
		$_SESSION['previous'] = basename($_SERVER['PHP_SELF']);
		$_SESSION['type'] = 'staff';
		//header('Refresh: 2; URL=http://localhost/SantasBlackMarket/pages/staff.php');
		header("location: http://cs.uky.edu/~ylu236/santa/staff/staff.php");
		echo "Log in successful. Redirecting...";
		}	
		
		//if user, then redirect to users home screen:
		if((int)$row['user_level'] === 0){
		$_SESSION['previous'] = basename($_SERVER['PHP_SELF']);
		header("location: http://cs.uky.edu/~ylu236/santa/members.php");
		exit();
		}
	}
	//user in our system, but entered in wrong password:
	else{
		header('Refresh: 5; URL=http://cs.uky.edu/~ylu236/santa/login.php');
		echo "LOG IN FAILED.  Incorrect password.  Please re-enter your email and password. Redirecting to login screen in 5 seconds...";
	}
} 
//otherwise there was no user with the specified log in info, or the user entered his email name incorrectly
else{
	header("Location: http://cs.uky.edu/~ylu236/santas_black_market/pages/error.php");
	exit();
}
}
else{
	header("Location: http://cs.uky.edu/~ylu236/santas_black_market/pages/error.php");
	exit();
}



?>