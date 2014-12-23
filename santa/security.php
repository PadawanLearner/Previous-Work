<?php 
session_start();

/*

Hey Yu,

Only referred "logged in" pages are allowed to be accessed by the user

DO NOT create a session on an unsecure page such as index.php or
registerScreen.php!!!!! The security logic of redirect and security
will fail!!!!

Also we need to restrict accesss for the folders on the website
with .htaccess
Will implement this later if we need, but it doesn't seem important 
right now.

*/


	echo basename($_SERVER['HTTP_REFERER']);
	//header("location: http://www.cs.uky.edu/~ylu236/santa/login.php");
	//exit();		



//basic user access to certain pages:
if( basename($_SERVER['HTTP_REFERER']) == "login.php" or 
	   basename($_SERVER['HTTP_REFERER']) == "login.php" or 
		 basename($_SERVER['HTTP_REFERER']) == "members.php" or 
		  basename($_SERVER['HTTP_REFERER']) == "cart.php" or 
		   basename($_SERVER['HTTP_REFERER']) == "member_products.php" or 
		   basename($_SERVER['HTTP_REFERER']) == "register.php" or 
		    basename($_SERVER['HTTP_REFERER']) == "myAccount.php" 
			){
				echo "Logged In";
			}


else{
	header("location: http://www.cs.uky.edu/~ylu236/santa/login.php");
	exit();		

}

?>