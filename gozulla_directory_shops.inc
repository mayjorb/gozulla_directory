<?php

/**
 * @file
 * gozulla_directory_shops.inc
 *
 * builds factual shop directories
*/

try {

// factual driver files
require_once('factual-php-driver/Factual.php');

// set api key for oauth
$factual_key = variable_get('gozulla_directory_factual_key',0);
$factual_secret = variable_get('gozulla_directory_factual_secret',0);
$exclude = explode(",", variable_get('gozulla_directory_bad_factual_ids',''));


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
  $factual->debug();
  
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
  $radius =  50;
}

$circle_radius = gozulla_directory_miles_to_meters($radius);

$limit = 10;
$offset = 0;


$factual = new Factual($factual_key,$factual_secret); //2-legged OAUTH

$shops = '';

switch ($sport) {

  case 'bike':
    //start building search
    // $query = new FactualQuery;
    // // $query->_or(array(
    // //   $query->field("name")->search("bicycle"),
    // //   $query->field("name")->search("bike"),
    // //   $query->field("name")->search("cyclery"),
    // //   $query->field("name")->search("REI"))
    // // );
    // // $query->_and(array(
    // //   $query->field("category")->notBeginsWith("Legal & Financial"),
    // //   $query->field("category")->notBeginsWith("Food & Beverage"),
    // //   $query->field("category")->notBeginsWith("Real Estate & Home Improvement"),
    // //   $query->field("factual_id")->notIn($exclude))
    // // );

    // $query->_or(array(
    //   $query->field("name")->search("bicycle"),
    //   $query->field("name")->search("bike"),
    //   $query->field("name")->search("cyclery"),
    //   $query->field("name")->search("REI"))
    // );
    // $query->_and(array(
    //   //$query->field("category")->notBeginsWith("Legal & Financial"),
    //   $query->field("category_ids")->notEqual("77")
    //   //$query->field("category")->notBeginsWith("Real Estate & Home Improvement"),
    //   //$query->field("factual_id")->notIn($exclude)
    //   )
    // );

    // $query->limit($limit);
    // $query->within(new FactualCircle($user_lat, $user_lon, $circle_radius));
    // $result = $factual->fetch("places", $query);
    break;

  case 'boat':
    //start building search
    //$category = 'Category Legal & Financial > Banking & Financing';
    // $query = new FactualQuery;
    // $query->_or(array(
    //   $query->field("name")->search("canoe"),
    //   $query->field("name")->search("kayak"),
    //   $query->field("name")->search("raft"),
    //   $query->field("name")->search("paddle"),
    //   $query->field("name")->search("REI"))
    // );
    // // $query->_and(array(
    // //   $query->field("category")->notBeginsWith("Legal & Financial"),
    // //   $query->field("category")->notBeginsWith("Food & Beverage"),
    // //   $query->field("category")->notBeginsWith("Health & Medicine"),
    // //   $query->field("category")->notBeginsWith("Business & Professional Services"),
    // //   $query->field("category")->notBeginsWith("Real Estate & Home Improvement"),
    // //   $query->field("factual_id")->notIn($exclude))
    // // );
    // $query->_and(array(
    //   //$query->field("category")->notBeginsWith("Legal & Financial"),
    //   //$query->field("category")->notBeginsWith("Food & Beverage"),
    //   //$query->field("category")->notBeginsWith("Health & Medicine"),
    //   //$query->field("category")->notBeginsWith("Business & Professional Services"),
    //   //$query->field("category")->notBeginsWith("Real Estate & Home Improvement"),
    //   //$query->field("factual_id")->notIn($exclude)
    //   $query->field("category_ids")->notEqual("221"),
    //   $query->field("category_ids")->notEqual("189")
    //   )
    // );


    // $query->limit($limit);
    // $query->within(new FactualCircle($user_lat, $user_lon, $circle_radius));
    // //$query->field("category")->notequal($category);
    // $result = $factual->fetch("places", $query);
    break;  

  case 'climb':
    //start building search
    // $query = new FactualQuery;
    // $query->_or(array(
    //   $query->field("name")->search("climbing"),
    //   $query->field("name")->search("REI"),
    //   $query->field("name")->search("climbing gear"))
    // );
    // $query->_and(array(
    //   $query->field("category")->notBeginsWith("Legal & Financial"),
    //   $query->field("category")->notBeginsWith("Food & Beverage"),
    //   $query->field("category")->notBeginsWith("Real Estate & Home Improvement"),
    //   $query->field("category")->notBeginsWith("Health & Medicine"),
    //   $query->field("category")->notBeginsWith("Business & Professional Services") )
    //   //$query->field("factual_id")->notIn($exclude))
    // );

    // $query->limit($limit);
    // $query->within(new FactualCircle($user_lat, $user_lon, $circle_radius));
    // //$query->field("category")->equal($category);
    // $result = $factual->fetch("places", $query);
    break;
  
  case 'golf':
    //start building search
    // $query = new FactualQuery;
    // $category = 'Sports & Recreation > Outdoor Recreation > Golf';
    // $query->limit($limit);
    // $query->within(new FactualCircle($user_lat, $user_lon, $circle_radius));
    // $query->field("category")->equal($category);
    // $result = $factual->fetch("places", $query);
    break; 

  case 'skate':
    //start building search
    // $query = new FactualQuery;
    // $query->_or(array(
    //   $query->field("name")->search("skateboard"),
    //   $query->field("name")->search("skate shop"))
    // );
    // $query->_and(array(
    //   $query->field("category")->notBeginsWith("Legal & Financial"),
    //   $query->field("category")->notBeginsWith("Food & Beverage"),
    //   $query->field("category")->notBeginsWith("Real Estate & Home Improvement"),
    //   $query->field("category")->notBeginsWith("Business & Professional Services") )
    //   // $query->field("factual_id")->notIn($exclude))
    // );
    // $query->limit($limit);
    // $query->within(new FactualCircle($user_lat, $user_lon, $circle_radius));
    // $result = $factual->fetch("places", $query);
    break;

  case 'snow':
    //start building search
    // $query = new FactualQuery;
    // $query->_or(array(
    //   $query->field("name")->search("ski shop"),
    //   $query->field("name")->search("snowboard"))
    // );

    // // $thisexclude = '';
    // // foreach ($exclude as $factual_id) {
    // //     $thisexclude .= '$query->field("factual_id")->notEqual("' . $factual_id . '"),';
    // //   }
    // //   $thisexclude .= '$query->field("category")->notBeginsWith("Legal & Financial"),
    // //   $query->field("category")->notBeginsWith("Food & Beverage"),
    // //   $query->field("category")->notBeginsWith("Real Estate & Home Improvement"),
      
    // //   $query->field("category")->notBeginsWith("test") )';
    //   // $thisexclude .= ');';

    //   //dpm($thisexclude, 'this exclude');

    // $query->_and(array(
    //   $query->field("category")->notBeginsWith("Legal & Financial"),
    //   $query->field("category")->notBeginsWith("Food & Beverage"),
    //   $query->field("category")->notBeginsWith("Real Estate & Home Improvement") )
    // );
    // $query->limit($limit);
    // $query->within(new FactualCircle($user_lat, $user_lon, $circle_radius));
    // //$query->field("category")->equal($category);
    // $result = $factual->fetch("places", $query);
    break; 
  
  case 'surf':
    //start building search
    // $query = new FactualQuery;
    // $query->_or(array(
    //   $query->field("name")->search("surf shop"),
    //   $query->field("name")->search("surfboard"))
    // );
    // $query->_and(array(
    //   $query->field("category")->notBeginsWith("Legal & Financial"),
    //   $query->field("category")->notBeginsWith("Food & Beverage"),
    //   $query->field("category")->notBeginsWith("Real Estate & Home Improvement"),
    //   $query->field("category")->notBeginsWith("Personal Care & Services") )
    //   //$query->field("factual_id")->notIn($exclude))
    // );
    // $query->limit($limit);
    // $query->within(new FactualCircle($user_lat, $user_lon, $circle_radius));
    // $result = $factual->fetch("places", $query);
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

// set var for showing debug info
global $user;
$show_debug = 0;

if (in_array('administrator', array_values($user->roles)) || in_array('site manager', array_values($user->roles)))  {
  $show_debug = 1;
}

if ($result->getData() && $sport == 'lodging') {
//dpm($result->getData(), 'result get data');

  foreach ($result->getData() as $value) {  

    if ($value['status'] == 1) {

      //foreach ($shopresults as $record) { // remove subscribed shops from factual list

        // if ($record->field_factual_id_value != $value['factual_id']) {

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

            if (isset($value['tel'])) { 
              $shops .= '<div class="places-detail">Phone: ' . $value['tel'] . '</div>';
            }

            //$shops .= '<div class="">United States</div>';
            $shops .= '<div class="places-distance"> ' . gozulla_directory_meters_to_miles($value['$distance']) . ' mi </div>';

            if (isset($value['website']) && $show_debug) { 
              $shops .= '<div class="places-detail debug-view"><a target="_blank" href= ' . $value['website'] . '> ' . $value['website'] . '</a></div>';
            }

            if (isset($value['category']) && $show_debug) { 
              $shops .= '<div class="places-detail debug-view">Category ' . $value['category'] . '</div>';
            }

            if (isset($value['category_ids']) && $show_debug) { 
              $shops .= '<div class="places-detail debug-view">Categories ' . $value['category_ids'] . '</div>';
            }


            if (isset($value['category_ids']) && $show_debug) { 
              $shops .= '<div class="places-detail debug-view">Latitude ' . $value['latitude'] . '</div>';
            }

             if (isset($value['category_ids']) && $show_debug) { 
              $shops .= '<div class="places-detail debug-view">Longitude ' . $value['longitude'] . '</div>';
            }

            //dpm($value['category_ids'][0]);
            //dpm($value['category_labels'][0]);

            if (isset($value['category_labels']) && $show_debug) { 
              $shops .= '<div class="places-detail debug-view">Category Labels ' . $value['category_ids'] . '</div>';
            }

            if ($show_debug) { 
              $shops .= '<div class="places-detail debug-view">Factual ID: ' . $value['factual_id'] . '</div>';
            }
        
            $shops .= '</div>';

          }

          $previoustitle = $value['name'];

        //}

      //}
       
    }
  }

}

else {

  $sport = '';
  $shops .= '<div class="places-row last"><h3 class="places-shop">no ' . $sport . ' shops found</h3><div class="places-detail">Try increasing the miles and/or changing the location.</div></div>';
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
// global $user;
// $show_debug = 0;

// if (in_array('administrator', array_values($user->roles)) || in_array('site manager', array_values($user->roles)))  {
//   $show_debug = 1;
// }

// get list of subscribed shops factual_id
// $query = db_select('field_data_field_factual_id', 'f');
// $query->join('node', 'n', 'f.entity_id = n.nid');
// $query->fields('f', array('field_factual_id_value'))
// ->condition('n.status', '1', '=');
// $shopresults = $query->execute()
// ->fetchAll();

// $shopcount = count($shopresults);

// $shops = '';
// $previoustitle = '';
// $thistitle = '';
// $isduplicate = FALSE;

//dpm($shopresults, 'shop results');


} catch (FactualApiException $e) {


  global $user;
  if (in_array('administrator', array_values($user->roles))){
    print '<pre>'; 
    print_r($e->debug()) ;
    print '</pre>';
  }

  $factual_error = $e->debug();

  $errormessage = 'Factual api error: <pre>' . print_r($factual_error, TRUE) .'</pre>';
  
  // $message_body = $errormessage;
  $message_body = 'check watchdog messages for details, e.g. drush wd-show';

  $server_script = $_SERVER['SERVER_NAME'] . $_SERVER['REQUEST_URI'];
  $subject = 'Factual api error: ' . $server_script;

  $message_subject = $subject;
  _custom_simple_mail($message_subject, $message_body);


  watchdog('gozulla_directory', 'Factual api error: <pre>'. print_r($factual_error, TRUE) .'</pre>');


  drupal_set_message(t('<p>Focus Action Sport\'s database isn\'t happy. We are are in the process of correcting the problem, please check back soon. </p>'), 'warning') ;

}
