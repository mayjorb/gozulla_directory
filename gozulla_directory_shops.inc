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
  $user_lat = '44.6367836'; // newport, oregon
  $user_lon = '-124.0534505';
}

// dpm($user_lat);
// dpm($user_lon);

if (isset($_GET['circle']['location']) && $_GET['circle']['location']) {

  // geocode (convert an address to longitude and latitude) if submitted in form
  $factual = new Factual($factual_key,$factual_secret); //2-legged OAUTH
  
  $location = $_GET['circle']['location'];
  
  $geolookup = $factual->geocode($location);
  //dpm($geolookup);
  
  // if latitude and longitude are found use these values
  if (isset($geolookup['latitude']) && $geolookup['latitude'] && isset($geolookup['longitude']) && $geolookup['longitude']) {
    $user_lat = $geolookup['latitude'];
    $user_lon = $geolookup['longitude'];
  }
  
}

// set circle radius
if (isset($_GET['circle']['value']) && $_GET['circle']['value']) {
  $radius = $_GET['circle']['value'];
}
else {
  $radius =  20;
}

$circle_radius = gozulla_directory_miles_to_meters($radius);

$limit = 30;

$factual = new Factual($factual_key,$factual_secret); //2-legged OAUTH

$shops = '';

switch ($sport) {

  case 'bike':
    //start building search
    $query = new FactualQuery;
    $query->limit($limit);
    $query->within(new FactualCircle($user_lat, $user_lon, $circle_radius));

    $query->_or(array(
       //$query->field("category")->equal("Sports & Recreation > Bicycle Rentals"),
        //$query->field("category")->equal("Shopping > Bicycle Sales & Service"),
        $query->field("name")->search("bicycle"),
        $query->field("name")->search("bike"),
        //$query->field("name")->search("bike shop")
       )
    );
    
    $result = $factual->fetch("places", $query);
    break;
    
  case 'skate':
    //start building search
    $query = new FactualQuery;
    $query->limit($limit);
    $query->within(new FactualCircle($user_lat, $user_lon, $circle_radius));

    $query->field("name")->search("skate");
    $query->field("name")->notEqual("Fuel Surf Skate Moto");
    $query->field("category")->notBeginsWith("Arts, Entertainment & Nightlife");
    $query->field("category")->notBeginsWith("Sports & Recreation > Ice Skating");
    $query->field("category")->notBeginsWith("Business & Professional Services > Advertising & Marketing");
    
    $result = $factual->fetch("places", $query);
    break;
   
  case 'snow':
    //start building search
    $query = new FactualQuery;
    $query->limit($limit);
    $query->within(new FactualCircle($user_lat, $user_lon, $circle_radius));

    $query->_or(array(
        $query->field("category")->equal("Sports & Recreation > Outdoor Recreation > Ski & Snowboard"),
        //$query->field("name")->search("ski"),
        //$query->field("name")->search("snowboard"),
        //$query->field("name")->search("snow")
       )
    );

    $result = $factual->fetch("places", $query);
    break;
      
  case 'surf':
    //start building search
    $query = new FactualQuery;
    $query->limit($limit);
    $query->within(new FactualCircle($user_lat, $user_lon, $circle_radius));
   
    $query->field("name")->search("surf");
    $query->field("name")->notEqual("Fuel Surf Skate Moto");
    $query->field("category")->notBeginsWith("Travel & Tourism");
    $query->field("category")->notBeginsWith("Food & Beverage");
    $query->field("category")->notBeginsWith("Real Estate & Home Improvement");
    $query->field("category")->notBeginsWith("Shopping > Music");
    $query->field("category")->notBeginsWith("Personal Care & Services");
    $query->field("category")->notBeginsWith("Business & Professional Services");
    $query->field("category")->notBeginsWith("Shopping > Department Stores");
    $query->field("category")->notBeginsWith("Community & Government");
    $query->field("category")->notBeginsWith("Sports & Recreation > Outdoor Recreation > Campgrounds & RV Parks");
    $query->field("category")->notBeginsWith("Shopping > Computers & Electronics");
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
    $category = 'Sports & Recreation > Outdoor Recreation > Canoes & Kayaks';
    $query->limit($limit);
    $query->within(new FactualCircle($user_lat, $user_lon, $circle_radius));
    $query->field("category")->equal($category);
    $result = $factual->fetch("places", $query);
    break;

  case 'climb':
    //start building search
    $query = new FactualQuery;
    $query->limit($limit);
    $query->within(new FactualCircle($user_lat, $user_lon, $circle_radius));
    
    $query->_or(array(
        $query->field("category")->equal("Sports & Recreation > Outdoor Recreation > Rock Climbing"),
        //$query->field("name")->search("climb"),
        //$query->field("name")->search("rock"),
        //$query->field("name")->search("mountain")
       )
    );
    
  case 'lodging':
    //start building search
    $query = new FactualQuery;
    $query->limit($limit);
    $query->within(new FactualCircle($user_lat, $user_lon, $circle_radius));
    
    $query->_or(array(
        $query->field("category")->equal("Travel & Tourism > Lodging > Hotels & Motels"),
        //$query->field("name")->search("climb"),
        //$query->field("name")->search("rock"),
        //$query->field("name")->search("mountain")
       )
    );

    $result = $factual->fetch("places", $query);
    break;
      
  default:
    # code ...
}

$shops = '';
//dpm($result->getData());
if ($result->getData()) {
//dpm($result->getData());
  foreach ($result->getData() as $value) {

    if ($value['status'] == 1) {
      
      $shops .= '<div class="places-row">';
      
       $shops .= '<h3 class="places-shop">' . $value['name'] . '</h3>';
       if (isset($value['address'])) { 
         $shops .= '<div class="places-detail">' . $value['address'] . '</div>';
       }
       if (isset($value['locality']) && isset($value['region']) && isset($value['postcode'])) { 
         $shops .= '<div class="places-detail">' . $value['locality'] . ' ' . $value['region'] . ' ' . $value['postcode'] . '</div>';
       }
       if (isset($value['tel'])) { 
          $shops .= '<div class="places-detail">Phone: ' . $value['tel'] . '</div>';
        }
       //$shops .= '<div class="">United States</div>';
       $shops .= '<div class="places-distance"> ' . gozulla_directory_meters_to_miles($value['$distance']) . ' mi </div>';
       //$shops .= '<div class="">Factual ID: ' . $value['factual_id'] . '</div>';
      //if (isset($value['website'])) { 
          //$shops .= '<div class=""><a target="_blank" href= ' . $value['website'] . '> ' . $value['website'] . '</a></div>';
        //}
        //if (isset($value['category'])) { 
          //$shops .= '<div class="">Category ' . $value['category'] . '</div>';
        //}
       
      $shops .= '</div>';

     }
       
  }

}
else {
  $shops .= '<div class="places-row last"><h3 class="places-shop">no ' . $sport . ' shops found</h3><div class="places-detail">Try increasing the miles and/or changing the location.</div></div>';
}
