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

  //geocode (convert an address to longitude and latitude)
  //$geolookup = $factual->geocode("425 Sherman Ave, Palo Alto, CA, USA");
  //print_r($geolookup);

  // if latitude and longitude are found use these values
  if (isset($geolookup['latitude']) && $geolookup['latitude'] && isset($geolookup['longitude']) && $geolookup['longitude']) {
    $user_lat = $geolookup['latitude'];
    $user_lon = $geolookup['longitude'];
  }
  
}

// set circle radius
if (isset($_GET['circle']['value']) && is_numeric($_GET['circle']['value'])) {
  $radius = $_GET['circle']['value'];
}
else {
  $radius =  20;
}

$circle_radius = gozulla_directory_miles_to_meters($radius);

$limit = 20;

$factual = new Factual($factual_key,$factual_secret); //2-legged OAUTH

$shops = '';

switch ($sport) {

  case 'bike':
    //start building search
    $query = new FactualQuery;
    $query->_or(array(
      $query->field("name")->search("bicycle"),
      $query->field("name")->search("bike"))
    );
    $query->limit($limit);
    $query->within(new FactualCircle($user_lat, $user_lon, $circle_radius));
    $result = $factual->fetch("places", $query);
    break;

  case 'boat':
    //start building search
    $category = 'Category Legal & Financial > Banking & Financing';
    $query = new FactualQuery;
    $query->_or(array(
      $query->field("name")->search("canoe"),
      $query->field("name")->search("kayak"),
      $query->field("name")->search("raft"))
    );
    // $query->_and(array(
    //   $query->field("name")->search("Category Legal & Financial > Banking & Financing"))
    // );


    
    $query->limit($limit);
    $query->within(new FactualCircle($user_lat, $user_lon, $circle_radius));
    //$query->field("category")->notequal($category);
    $result = $factual->fetch("places", $query);
    break;  

  case 'climb':
    //start building search
    $query = new FactualQuery;
    $query->_or(array(
      $query->field("name")->search("climbing"))
    );
    $query->limit($limit);
    $query->within(new FactualCircle($user_lat, $user_lon, $circle_radius));
    //$query->field("category")->equal($category);
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

  case 'skate':
    //start building search
    $query = new FactualQuery;
    $query->_or(array(
      $query->field("name")->search("skateboard"),
      $query->field("name")->search("skate shop"))
    );
    $query->limit($limit);
    $query->within(new FactualCircle($user_lat, $user_lon, $circle_radius));
    $result = $factual->fetch("places", $query);
    break;

  case 'snow':
    //start building search
    $query = new FactualQuery;
    $query->_or(array(
      $query->field("name")->search("ski shop"),
      $query->field("name")->search("snowboard"))
    );
    $query->limit($limit);
    $query->within(new FactualCircle($user_lat, $user_lon, $circle_radius));
    //$query->field("category")->equal($category);
    $result = $factual->fetch("places", $query);
    break; 
  
  case 'surf':
    //start building search
    $query = new FactualQuery;
    $query->_or(array(
      $query->field("name")->search("surf shop"),
      $query->field("name")->search("surfboard"))
    );
    $query->limit($limit);
    $query->within(new FactualCircle($user_lat, $user_lon, $circle_radius));
    $result = $factual->fetch("places", $query);
    break;
      
  case 'lodging':
    //start building search
    $query = new FactualQuery;
    $query->limit($limit);
    $query->within(new FactualCircle($user_lat, $user_lon, $circle_radius));
    
    $query->_or(array(
        $query->field("category")->equal("Travel & Tourism > Lodging > Hotels & Motels"),
       )
    );

    $result = $factual->fetch("places", $query);
    break;
      
  
}

//change view name
// $view = views_get_view('gozulla_directory')
// ->set_display('defaults');
// ->set_items_per_page(0);
// ->execute();
// $results = $view->result;

// dpm($results);
//foreach ($results as $result) {
//$options[] = $result->term_data_name;
//}


// set var for showing debug info
global $user;
$show_debug = 0;

if (in_array('administrator', array_values($user->roles)) || in_array('site manager', array_values($user->roles)))  {
  $show_debug = 1;
}



$shops = '';
$previoustitle = '';
$thistitle = '';
$isduplicate = FALSE;
//dpm($result->getData());
if ($result->getData()) {
//dpm($result->getData());
  foreach ($result->getData() as $value) {

    if ($value['status'] == 1) {
      
     // don't output record if the title is a duplicate
      $thistitle = $value['name'];
      
      if ($thistitle != $previoustitle) {
        
        $shops .= '<div class="places-row">';
      
        $shops .= '<h3 class="places-shop">' . $value['name'] . '</h3>';
        if (isset($value['address'])) { 
          $shops .= '<div class="places-detail">' . $value['address'] . '</div>';
        }
        if (isset($value['locality']) && isset($value['region']) && isset($value['postcode'])) { 
          $shops .= '<div class="places-detail">' . $value['locality'] . ' ' . $value['region'] . ' ' . $value['postcode'] . '</div>';
         }
        if (isset($value['tel']) && $show_debug) { 
          $shops .= '<div class="places-detail debug-view">Phone: ' . $value['tel'] . '</div>';
        }
        //$shops .= '<div class="">United States</div>';
        $shops .= '<div class="places-distance"> ' . gozulla_directory_meters_to_miles($value['$distance']) . ' mi </div>';
        // if (isset($value['website'])) { 
        //     $shops .= '<div class="places-detail"><a target="_blank" href= ' . $value['website'] . '> ' . $value['website'] . '</a></div>';
        //   }
        if (isset($value['category']) && $show_debug) { 
           $shops .= '<div class="places-detail debug-view">Category ' . $value['category'] . '</div>';
         }

        if ($show_debug) { 
          $shops .= '<div class="places-detail debug-view">Factual ID: ' . $value['factual_id'] . '</div>';
        }
       
        $shops .= '</div>';

      }

     $previoustitle = $value['name'];

    }
       
  }

}
else {
  $sport = '';
  $shops .= '<div class="places-row last"><h3 class="places-shop">no ' . $sport . ' shops found</h3><div class="places-detail">Try increasing the miles and/or changing the location.</div></div>';
}
