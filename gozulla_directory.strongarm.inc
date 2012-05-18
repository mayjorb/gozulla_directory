<?php
/**
 * @file
 * gozulla_directory.strongarm.inc
 */

/**
 * Implements hook_strongarm().
 */
function gozulla_directory_strongarm() {
  $export = array();

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'menu_options_gozulla_location';
  $strongarm->value = array(
    0 => 'main-menu',
  );
  $export['menu_options_gozulla_location'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'menu_parent_gozulla_location';
  $strongarm->value = 'main-menu:0';
  $export['menu_parent_gozulla_location'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_options_gozulla_location';
  $strongarm->value = array(
    0 => 'status',
  );
  $export['node_options_gozulla_location'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_preview_gozulla_location';
  $strongarm->value = '0';
  $export['node_preview_gozulla_location'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_submitted_gozulla_location';
  $strongarm->value = 0;
  $export['node_submitted_gozulla_location'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'pathauto_node_gozulla_location_pattern';
  $strongarm->value = '';
  $export['pathauto_node_gozulla_location_pattern'] = $strongarm;

  return $export;
}
