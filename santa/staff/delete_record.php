<?php 
session_start();
require("../../includes/db_connection.php");

/*if (!isset($_GET['id1']) || !isset($GET['id2']))
{
    echo 'No ID was given...';
    exit;
}
*/
$item_id = (int)($_SESSION['to_be_deleted_item_id']);
echo "Item ID = " . $item_id;


/*$connection = new mysqli($db_host, $db_user, $db_pass, $db_name);
if ($connection->connect_error)
{
    die('Connect Error (' . $connection->connect_errno . ') ' . $connection->connect_error);
}

$sql = "DELETE FROM recetas_galletas WHERE id = ?";
if (!$result = $connection->prepare($sql))
{
    die('Query failed: (' . $connection->errno . ') ' . $connection->error);
}

if (!$result->bind_param('i', $_GET['id']))
{
    die('Binding parameters failed: (' . $result->errno . ') ' . $result->error);
}

if (!$result->execute())
{
    die('Execute failed: (' . $result->errno . ') ' . $result->error);
}

if ($result->affected_rows > 0)
{
    echo "The ID was deleted with success.";
}
else
{
    echo "Couldn't delete the ID.";
}
$result->close();
$connection->close();
*/
?>