<!DOCTYPE html>
<html>
<head>
<title>Remote LED Control</title>
<style>
		body {
			background-color:black;
					}
</style>
</head>

<body>
<?php
$onoroff = $_GET["state"]; // Declares the request from index.html as a variable
$textfile = "ledstat.txt"; // Declares the name and location of the .txt file
 
$fileLocation = "$textfile";
$fh = fopen($fileLocation, 'w   ') or die("Something went wrong!"); // Opens up the .txt file for writing and replaces any previous content
$stringToWrite = "$onoroff"; // Write either 1 or 0 depending on request from index.html
fwrite($fh, $stringToWrite); // Writes it to the .txt file
fclose($fh); 
echo "<script language=javascript>window.close();</script>";
?>
</body>
</html>