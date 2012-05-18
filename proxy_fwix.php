<?php
  if ($_GET['lat'] && $_GET['lng']) {
    $lat = $_GET['lat'];
    $lng = $_GET['lng'];
    $fwixurl =    'http://geoapi.fwix.com/location.json?lat=' . $lat . '&lng=' . $lng . '&api_key=0514d0c66030&callback=?';
    $session = curl_init($fwixurl);
    curl_setopt($session, CURLOPT_FOLLOWLOCATION, true);
    curl_setopt($session, CURLOPT_HEADER, false);
    curl_setopt($session, CURLOPT_RETURNTRANSFER, true);
    $response = curl_exec($session);
    $json = $_GET['callback'].'('.$response.')';

    //header('Content-type: application/json');
    print $json;
    curl_close($session);
  }
?>