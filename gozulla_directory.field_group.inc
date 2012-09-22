<?php
/**
 * @file
 * gozulla_directory.field_group.inc
 */

/**
 * Implements hook_field_group_info().
 */
function gozulla_directory_field_group_info() {
  $export = array();

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_address|node|gozullalocation|form';
  $field_group->group_name = 'group_address';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'gozullalocation';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Address',
    'weight' => '12',
    'children' => array(
      0 => 'field_address',
      1 => 'field_geofield',
    ),
    'format_type' => 'tab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'description' => '',
        'classes' => '',
        'required_fields' => 1,
      ),
    ),
  );
  $export['group_address|node|gozullalocation|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_places_id|node|gozullalocation|form';
  $field_group->group_name = 'group_places_id';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'gozullalocation';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'guids',
    'weight' => '13',
    'children' => array(
      0 => 'field_places_id',
      1 => 'field_gozulla_subscription',
      2 => 'field_factual_id',
    ),
    'format_type' => 'tab',
    'format_settings' => array(
      'label' => 'guids',
      'instance_settings' => array(
        'required_fields' => 0,
        'classes' => '',
        'description' => 'admin stuff',
      ),
      'formatter' => 'closed',
    ),
  );
  $export['group_places_id|node|gozullalocation|form'] = $field_group;

  return $export;
}
