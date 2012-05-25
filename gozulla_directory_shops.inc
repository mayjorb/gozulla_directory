<?php

/**
 * @file
 * gozulla_directory_shops.inc
 *
 * builds factual shop directories
*/

// factual driver files
require_once('factual-php-driver/Factual.php');

// set api key for oauth
$factual_key = variable_get('gozulla_directory_factual_key',0);
$factual_secret = variable_get('gozulla_directory_factual_secret',0);

function gozulla_directory_miles_to_meters($miles) {
  $meters = round($miles * 1609.344);
  return $meters;
}

function gozulla_directory_meters_to_miles($meters) {
  $miles = $meters * 0.000621371192 * 10 / 10;
  $miles = round($miles, 1);
  return $miles;
}
  
if (isset($_SESSION['ip_geoloc']['location']['latitude']) && isset($_SESSION['ip_geoloc']['location']['longitude'])) {
  $user_lat = $_SESSION['ip_geoloc']['location']['latitude'];
  $user_lon = $_SESSION['ip_geoloc']['location']['longitude'];
}
else {
  $user_lat = '45.8817737'; // cannon beach, oregon
  $user_lon = '-123.9643052';
}

$radius =  100;

$circle_radius = gozulla_directory_miles_to_meters($radius);

$limit = 20;

$factual = new Factual($factual_key,$factual_secret); //2-legged OAUTH
$shops = '';

switch ($sport) {
  case 'bike':
    //start building search
    $query = new FactualQuery;
    $category = 'Shopping > Bicycle Sales & Service';
    $query->limit($limit);
    $query->within(new FactualCircle($user_lat, $user_lon, $circle_radius));
    $query->field("category")->equal($category);
    $result = $factual->fetch("places", $query);
    break;
    
    case 'skate':
      //start building search
      $query = new FactualQuery;
      $category = '';
      $query->limit($limit);
      $query->within(new FactualCircle($user_lat, $user_lon, $circle_radius));
      $query->field("category")->equal($category);
      $result = $factual->fetch("places", $query);
      break;
    
    case 'snow':
      //start building search
      $query = new FactualQuery;
      $category = 'Sports & Recreation > Outdoor Recreation > Ski & Snowboard';
      $query->limit($limit);
      $query->within(new FactualCircle($user_lat, $user_lon, $circle_radius));
      $query->field("category")->equal($category);
      $result = $factual->fetch("places", $query);
      break;
      
    case 'surf':
      //start building search
      $query = new FactualQuery;
      $category = '';
      $query->limit($limit);
      $query->within(new FactualCircle($user_lat, $user_lon, $circle_radius));
      $query->field("category")->equal($category);
      $result = $factual->fetch("places", $query);
      break;
      
    case 'golf':
      //start building search
      $query = new FactualQuery;
      $category = 'Sports & Recreation > Outdoor Recreation > Golf';
      $query->limit($limit);
      $query->within(new FactualCircle($user_lat, $user_lon, $circle_radius));
      $query->field("category")->equal($category);
      $result = $factual->fetch("places", $query);
      break;

    case 'boat':
      //start building search
      $query = new FactualQuery;
      $category = '';
      $query->limit($limit);
      $query->within(new FactualCircle($user_lat, $user_lon, $circle_radius));
      $query->field("category")->equal($category);
      $result = $factual->fetch("places", $query);
      break;

    case 'climb':
      //start building search
      $query = new FactualQuery;
      $category = '';
      $query->limit($limit);
      $query->within(new FactualCircle($user_lat, $user_lon, $circle_radius));
      $query->field("category")->equal($category);
      $result = $factual->fetch("places", $query);
      break;
      
  default:
    # code ...
}

$shops = '';

if ($result->getData()) {

  foreach ($result->getData() as $value) {

    if ($value['status'] == 1) {
       $shops .= '<h3 class="">' . $value['name'] . '</h3>';
       $shops .= '<div class="">' . $value['address'] . '</div>';
       $shops .= '<div class="">' . $value['locality'] . ' ' . $value['region'] . ' ' . $value['postcode'] . '</div>';
       $shops .= '<div class="">United States</div>';
       $shops .= '<div class="">~ ' . gozulla_directory_meters_to_miles($value['$distance']) . ' miles</div>';
     }
       
  }

}
else {
  $shops .= '<h3>no shops found</h3>';
}