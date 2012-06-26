<?php
/**
 * @file
 * gozulla_directory.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function gozulla_directory_views_default_views() {
  $export = array();

  $view = new view;
  $view->name = 'gozulla_directory';
  $view->description = 'displays the closest shops to a users location';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'gozulla directory';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'gozulla directory';
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['query']['options']['query_comment'] = FALSE;
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['exposed_form']['options']['autosubmit'] = 0;
  $handler->display->display_options['exposed_form']['options']['autosubmit_hide'] = 1;
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '1';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['pager']['options']['id'] = '0';
  $handler->display->display_options['pager']['options']['expose']['items_per_page_options_all'] = 0;
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['title']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['title']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['title']['alter']['external'] = 0;
  $handler->display->display_options['fields']['title']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['title']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['title']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = 0;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = 0;
  $handler->display->display_options['fields']['title']['alter']['more_link'] = 0;
  $handler->display->display_options['fields']['title']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['title']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['title']['alter']['html'] = 0;
  $handler->display->display_options['fields']['title']['element_type'] = 'h3';
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['title']['hide_empty'] = 0;
  $handler->display->display_options['fields']['title']['empty_zero'] = 0;
  $handler->display->display_options['fields']['title']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['title']['link_to_node'] = 1;
  /* Field: Field: Address */
  $handler->display->display_options['fields']['field_address']['id'] = 'field_address';
  $handler->display->display_options['fields']['field_address']['table'] = 'field_data_field_address';
  $handler->display->display_options['fields']['field_address']['field'] = 'field_address';
  $handler->display->display_options['fields']['field_address']['label'] = '';
  $handler->display->display_options['fields']['field_address']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_address']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_address']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_address']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_address']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_address']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_address']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_address']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_address']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_address']['alter']['more_link'] = 0;
  $handler->display->display_options['fields']['field_address']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_address']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_address']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_address']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_address']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_address']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_address']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_address']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['field_address']['click_sort_column'] = 'country';
  $handler->display->display_options['fields']['field_address']['settings'] = array(
    'use_widget_handlers' => 1,
    'format_handlers' => array(
      'address' => 'address',
    ),
  );
  $handler->display->display_options['fields']['field_address']['field_api_classes'] = 0;
  /* Field: Proximity: Distance */
  $handler->display->display_options['fields']['distance']['id'] = 'distance';
  $handler->display->display_options['fields']['distance']['table'] = 'openlayers_proximity';
  $handler->display->display_options['fields']['distance']['field'] = 'distance';
  $handler->display->display_options['fields']['distance']['label'] = '';
  $handler->display->display_options['fields']['distance']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['distance']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['distance']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['distance']['alter']['external'] = 0;
  $handler->display->display_options['fields']['distance']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['distance']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['distance']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['distance']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['distance']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['distance']['alter']['more_link'] = 0;
  $handler->display->display_options['fields']['distance']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['distance']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['distance']['alter']['html'] = 0;
  $handler->display->display_options['fields']['distance']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['distance']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['distance']['hide_empty'] = 1;
  $handler->display->display_options['fields']['distance']['empty_zero'] = 0;
  $handler->display->display_options['fields']['distance']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['distance']['set_precision'] = 1;
  $handler->display->display_options['fields']['distance']['precision'] = '2';
  $handler->display->display_options['fields']['distance']['format_plural'] = 0;
  $handler->display->display_options['fields']['distance']['prefix'] = '~';
  $handler->display->display_options['fields']['distance']['suffix'] = 'miles';
  $handler->display->display_options['fields']['distance']['location_provider'] = 'circle';
  /* Field: Field: User Geofield */
  $handler->display->display_options['fields']['field_geofield_1']['id'] = 'field_geofield_1';
  $handler->display->display_options['fields']['field_geofield_1']['table'] = 'field_data_field_geofield';
  $handler->display->display_options['fields']['field_geofield_1']['field'] = 'field_geofield';
  $handler->display->display_options['fields']['field_geofield_1']['label'] = 'Geofield';
  $handler->display->display_options['fields']['field_geofield_1']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_geofield_1']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_geofield_1']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_geofield_1']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_geofield_1']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_geofield_1']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_geofield_1']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_geofield_1']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_geofield_1']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_geofield_1']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_geofield_1']['alter']['more_link'] = 0;
  $handler->display->display_options['fields']['field_geofield_1']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_geofield_1']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_geofield_1']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_geofield_1']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['field_geofield_1']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_geofield_1']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_geofield_1']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_geofield_1']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['field_geofield_1']['click_sort_column'] = 'wkt';
  $handler->display->display_options['fields']['field_geofield_1']['type'] = 'geofield_latlon';
  $handler->display->display_options['fields']['field_geofield_1']['settings'] = array(
    'data' => 'full',
    'format' => 'decimal_degrees',
    'labels' => 1,
  );
  $handler->display->display_options['fields']['field_geofield_1']['field_api_classes'] = 0;
  /* Field: Global: Custom text */
  $handler->display->display_options['fields']['nothing']['id'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['table'] = 'views';
  $handler->display->display_options['fields']['nothing']['field'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['label'] = '';
  $handler->display->display_options['fields']['nothing']['alter']['text'] = '&nbsp;';
  $handler->display->display_options['fields']['nothing']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['nothing']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['nothing']['alter']['external'] = 0;
  $handler->display->display_options['fields']['nothing']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['nothing']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['nothing']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['nothing']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['nothing']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['nothing']['alter']['more_link'] = 0;
  $handler->display->display_options['fields']['nothing']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['nothing']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['nothing']['alter']['html'] = 0;
  $handler->display->display_options['fields']['nothing']['element_class'] = 'clearfix';
  $handler->display->display_options['fields']['nothing']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['nothing']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['nothing']['hide_empty'] = 0;
  $handler->display->display_options['fields']['nothing']['empty_zero'] = 0;
  $handler->display->display_options['fields']['nothing']['hide_alter_empty'] = 0;
  /* Field: Node: Edit link */
  $handler->display->display_options['fields']['edit_node']['id'] = 'edit_node';
  $handler->display->display_options['fields']['edit_node']['table'] = 'views_entity_node';
  $handler->display->display_options['fields']['edit_node']['field'] = 'edit_node';
  $handler->display->display_options['fields']['edit_node']['label'] = '';
  $handler->display->display_options['fields']['edit_node']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['edit_node']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['edit_node']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['edit_node']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['edit_node']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['edit_node']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['edit_node']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['edit_node']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['edit_node']['alter']['more_link'] = 0;
  $handler->display->display_options['fields']['edit_node']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['edit_node']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['edit_node']['alter']['html'] = 0;
  $handler->display->display_options['fields']['edit_node']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['edit_node']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['edit_node']['hide_empty'] = 0;
  $handler->display->display_options['fields']['edit_node']['empty_zero'] = 0;
  $handler->display->display_options['fields']['edit_node']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['edit_node']['text'] = '[ edit ]';
  /* Sort criterion: Proximity: Distance */
  $handler->display->display_options['sorts']['distance']['id'] = 'distance';
  $handler->display->display_options['sorts']['distance']['table'] = 'openlayers_proximity';
  $handler->display->display_options['sorts']['distance']['field'] = 'distance';
  $handler->display->display_options['sorts']['distance']['location_provider'] = 'circle';
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'gozulla_location' => 'gozulla_location',
  );
  /* Filter criterion: Proximity: Great-circle */
  $handler->display->display_options['filters']['circle']['id'] = 'circle';
  $handler->display->display_options['filters']['circle']['table'] = 'openlayers_proximity';
  $handler->display->display_options['filters']['circle']['field'] = 'circle';
  $handler->display->display_options['filters']['circle']['value']['value'] = '20';
  $handler->display->display_options['filters']['circle']['value']['location'] = 'Newport, OR';
  $handler->display->display_options['filters']['circle']['value']['node'] = '1630';
  $handler->display->display_options['filters']['circle']['exposed'] = TRUE;
  $handler->display->display_options['filters']['circle']['expose']['operator_id'] = 'circle_op';
  $handler->display->display_options['filters']['circle']['expose']['operator'] = 'circle_op';
  $handler->display->display_options['filters']['circle']['expose']['identifier'] = 'circle';
  $handler->display->display_options['filters']['circle']['expose']['multiple'] = FALSE;
  $handler->display->display_options['filters']['circle']['expose']['use_unit'] = 0;
  $handler->display->display_options['filters']['circle']['expose']['use_location'] = 1;
  $handler->display->display_options['filters']['circle']['expose']['use_node'] = 0;
  /* Filter criterion: Content: Sports (field_sport_type) */
  $handler->display->display_options['filters']['field_sport_type_tid']['id'] = 'field_sport_type_tid';
  $handler->display->display_options['filters']['field_sport_type_tid']['table'] = 'field_data_field_sport_type';
  $handler->display->display_options['filters']['field_sport_type_tid']['field'] = 'field_sport_type_tid';
  $handler->display->display_options['filters']['field_sport_type_tid']['value'] = array(
    0 => '26',
  );
  $handler->display->display_options['filters']['field_sport_type_tid']['reduce_duplicates'] = 0;
  $handler->display->display_options['filters']['field_sport_type_tid']['vocabulary'] = 'gozulla_sport';

  /* Display: surf */
  $handler = $view->new_display('page', 'surf', 'page_1');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'surf directory';
  $handler->display->display_options['display_description'] = 'gozulla surf directory';
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'gozulla_location' => 'gozulla_location',
  );
  /* Filter criterion: Proximity: Great-circle */
  $handler->display->display_options['filters']['circle']['id'] = 'circle';
  $handler->display->display_options['filters']['circle']['table'] = 'openlayers_proximity';
  $handler->display->display_options['filters']['circle']['field'] = 'circle';
  $handler->display->display_options['filters']['circle']['value']['value'] = '20';
  $handler->display->display_options['filters']['circle']['value']['location'] = 'Newport, OR';
  $handler->display->display_options['filters']['circle']['value']['node'] = '1630';
  $handler->display->display_options['filters']['circle']['exposed'] = TRUE;
  $handler->display->display_options['filters']['circle']['expose']['operator_id'] = 'circle_op';
  $handler->display->display_options['filters']['circle']['expose']['operator'] = 'circle_op';
  $handler->display->display_options['filters']['circle']['expose']['identifier'] = 'circle';
  $handler->display->display_options['filters']['circle']['expose']['multiple'] = FALSE;
  $handler->display->display_options['filters']['circle']['expose']['use_unit'] = 0;
  $handler->display->display_options['filters']['circle']['expose']['use_location'] = 1;
  $handler->display->display_options['filters']['circle']['expose']['use_node'] = 0;
  /* Filter criterion: Content: Sports (field_sport_type) */
  $handler->display->display_options['filters']['field_sport_type_tid']['id'] = 'field_sport_type_tid';
  $handler->display->display_options['filters']['field_sport_type_tid']['table'] = 'field_data_field_sport_type';
  $handler->display->display_options['filters']['field_sport_type_tid']['field'] = 'field_sport_type_tid';
  $handler->display->display_options['filters']['field_sport_type_tid']['value'] = array(
    0 => '22',
  );
  $handler->display->display_options['filters']['field_sport_type_tid']['reduce_duplicates'] = 0;
  $handler->display->display_options['filters']['field_sport_type_tid']['vocabulary'] = 'gozulla_sport';
  $handler->display->display_options['path'] = 'surf';

  /* Display: skate */
  $handler = $view->new_display('page', 'skate', 'page_2');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'skate directory';
  $handler->display->display_options['display_description'] = 'gozulla skate directory';
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'gozulla_location' => 'gozulla_location',
  );
  /* Filter criterion: Proximity: Great-circle */
  $handler->display->display_options['filters']['circle']['id'] = 'circle';
  $handler->display->display_options['filters']['circle']['table'] = 'openlayers_proximity';
  $handler->display->display_options['filters']['circle']['field'] = 'circle';
  $handler->display->display_options['filters']['circle']['value']['value'] = '20';
  $handler->display->display_options['filters']['circle']['value']['location'] = 'Newport, OR';
  $handler->display->display_options['filters']['circle']['value']['node'] = '1630';
  $handler->display->display_options['filters']['circle']['exposed'] = TRUE;
  $handler->display->display_options['filters']['circle']['expose']['operator_id'] = 'circle_op';
  $handler->display->display_options['filters']['circle']['expose']['operator'] = 'circle_op';
  $handler->display->display_options['filters']['circle']['expose']['identifier'] = 'circle';
  $handler->display->display_options['filters']['circle']['expose']['multiple'] = FALSE;
  $handler->display->display_options['filters']['circle']['expose']['use_unit'] = 0;
  $handler->display->display_options['filters']['circle']['expose']['use_location'] = 1;
  $handler->display->display_options['filters']['circle']['expose']['use_node'] = 0;
  /* Filter criterion: Content: Sports (field_sport_type) */
  $handler->display->display_options['filters']['field_sport_type_tid']['id'] = 'field_sport_type_tid';
  $handler->display->display_options['filters']['field_sport_type_tid']['table'] = 'field_data_field_sport_type';
  $handler->display->display_options['filters']['field_sport_type_tid']['field'] = 'field_sport_type_tid';
  $handler->display->display_options['filters']['field_sport_type_tid']['value'] = array(
    0 => '23',
  );
  $handler->display->display_options['filters']['field_sport_type_tid']['reduce_duplicates'] = 0;
  $handler->display->display_options['filters']['field_sport_type_tid']['vocabulary'] = 'gozulla_sport';
  $handler->display->display_options['path'] = 'skate';

  /* Display: geofield map */
  $handler = $view->new_display('attachment', 'geofield map', 'geofield_map');
  $handler->display->display_options['enabled'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'geofield_map_map';
  $handler->display->display_options['style_options']['data_source'] = 'field_geofield_1';
  $handler->display->display_options['style_options']['popup_source'] = 'field_address';
  $handler->display->display_options['style_options']['geofield_map_zoom'] = '12';
  $handler->display->display_options['style_options']['geofield_map_mtc'] = 'menu';
  $handler->display->display_options['style_options']['geofield_map_maptype'] = 'physical';
  $handler->display->display_options['style_options']['geofield_map_baselayers_physical'] = 1;
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['title']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['title']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['title']['alter']['external'] = 0;
  $handler->display->display_options['fields']['title']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['title']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['title']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = 0;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = 0;
  $handler->display->display_options['fields']['title']['alter']['more_link'] = 0;
  $handler->display->display_options['fields']['title']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['title']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['title']['alter']['html'] = 0;
  $handler->display->display_options['fields']['title']['element_type'] = 'h3';
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['title']['hide_empty'] = 0;
  $handler->display->display_options['fields']['title']['empty_zero'] = 0;
  $handler->display->display_options['fields']['title']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['title']['link_to_node'] = 1;
  /* Field: Field: Address */
  $handler->display->display_options['fields']['field_address']['id'] = 'field_address';
  $handler->display->display_options['fields']['field_address']['table'] = 'field_data_field_address';
  $handler->display->display_options['fields']['field_address']['field'] = 'field_address';
  $handler->display->display_options['fields']['field_address']['label'] = '';
  $handler->display->display_options['fields']['field_address']['alter']['alter_text'] = 1;
  $handler->display->display_options['fields']['field_address']['alter']['text'] = '[title] 
[field_address]';
  $handler->display->display_options['fields']['field_address']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_address']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_address']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_address']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_address']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_address']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_address']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_address']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_address']['alter']['more_link'] = 0;
  $handler->display->display_options['fields']['field_address']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_address']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_address']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_address']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_address']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_address']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_address']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_address']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['field_address']['click_sort_column'] = 'country';
  $handler->display->display_options['fields']['field_address']['settings'] = array(
    'use_widget_handlers' => 1,
    'format_handlers' => array(
      'address' => 'address',
    ),
  );
  $handler->display->display_options['fields']['field_address']['field_api_classes'] = 0;
  /* Field: Proximity: Distance */
  $handler->display->display_options['fields']['distance']['id'] = 'distance';
  $handler->display->display_options['fields']['distance']['table'] = 'openlayers_proximity';
  $handler->display->display_options['fields']['distance']['field'] = 'distance';
  $handler->display->display_options['fields']['distance']['label'] = '';
  $handler->display->display_options['fields']['distance']['exclude'] = TRUE;
  $handler->display->display_options['fields']['distance']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['distance']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['distance']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['distance']['alter']['external'] = 0;
  $handler->display->display_options['fields']['distance']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['distance']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['distance']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['distance']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['distance']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['distance']['alter']['more_link'] = 0;
  $handler->display->display_options['fields']['distance']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['distance']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['distance']['alter']['html'] = 0;
  $handler->display->display_options['fields']['distance']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['distance']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['distance']['hide_empty'] = 1;
  $handler->display->display_options['fields']['distance']['empty_zero'] = 0;
  $handler->display->display_options['fields']['distance']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['distance']['set_precision'] = 1;
  $handler->display->display_options['fields']['distance']['precision'] = '2';
  $handler->display->display_options['fields']['distance']['format_plural'] = 0;
  $handler->display->display_options['fields']['distance']['prefix'] = '~';
  $handler->display->display_options['fields']['distance']['suffix'] = 'miles';
  $handler->display->display_options['fields']['distance']['location_provider'] = 'circle';
  /* Field: Field: User Geofield */
  $handler->display->display_options['fields']['field_geofield_1']['id'] = 'field_geofield_1';
  $handler->display->display_options['fields']['field_geofield_1']['table'] = 'field_data_field_geofield';
  $handler->display->display_options['fields']['field_geofield_1']['field'] = 'field_geofield';
  $handler->display->display_options['fields']['field_geofield_1']['label'] = 'Geofield';
  $handler->display->display_options['fields']['field_geofield_1']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_geofield_1']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_geofield_1']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_geofield_1']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_geofield_1']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_geofield_1']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_geofield_1']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_geofield_1']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_geofield_1']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_geofield_1']['alter']['more_link'] = 0;
  $handler->display->display_options['fields']['field_geofield_1']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_geofield_1']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_geofield_1']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_geofield_1']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['field_geofield_1']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_geofield_1']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_geofield_1']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_geofield_1']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['field_geofield_1']['click_sort_column'] = 'wkt';
  $handler->display->display_options['fields']['field_geofield_1']['type'] = 'geofield_latlon';
  $handler->display->display_options['fields']['field_geofield_1']['settings'] = array(
    'data' => 'full',
    'format' => 'decimal_degrees',
    'labels' => 1,
  );
  $handler->display->display_options['fields']['field_geofield_1']['field_api_classes'] = 0;
  $handler->display->display_options['displays'] = array(
    'page_1' => 'page_1',
    'default' => 0,
    'block' => 0,
    'page_2' => 0,
  );
  $handler->display->display_options['inherit_exposed_filters'] = 1;

  /* Display: featured shop */
  $handler = $view->new_display('block', 'featured shop', 'featured_shop');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'one hot shop';
  $handler->display->display_options['display_description'] = 'Displays random gozulla location';
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '1';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Nid */
  $handler->display->display_options['fields']['nid']['id'] = 'nid';
  $handler->display->display_options['fields']['nid']['table'] = 'node';
  $handler->display->display_options['fields']['nid']['field'] = 'nid';
  $handler->display->display_options['fields']['nid']['label'] = '';
  $handler->display->display_options['fields']['nid']['exclude'] = TRUE;
  $handler->display->display_options['fields']['nid']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['nid']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['nid']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['nid']['alter']['external'] = 0;
  $handler->display->display_options['fields']['nid']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['nid']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['nid']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['nid']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['nid']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['nid']['alter']['more_link'] = 0;
  $handler->display->display_options['fields']['nid']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['nid']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['nid']['alter']['html'] = 0;
  $handler->display->display_options['fields']['nid']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['nid']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['nid']['hide_empty'] = 0;
  $handler->display->display_options['fields']['nid']['empty_zero'] = 0;
  $handler->display->display_options['fields']['nid']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['nid']['link_to_node'] = 0;
  /* Field: Content: Shop Logo */
  $handler->display->display_options['fields']['field_location_logo']['id'] = 'field_location_logo';
  $handler->display->display_options['fields']['field_location_logo']['table'] = 'field_data_field_location_logo';
  $handler->display->display_options['fields']['field_location_logo']['field'] = 'field_location_logo';
  $handler->display->display_options['fields']['field_location_logo']['label'] = '';
  $handler->display->display_options['fields']['field_location_logo']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_location_logo']['alter']['make_link'] = 1;
  $handler->display->display_options['fields']['field_location_logo']['alter']['path'] = 'node/[nid]';
  $handler->display->display_options['fields']['field_location_logo']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_location_logo']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_location_logo']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_location_logo']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_location_logo']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_location_logo']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_location_logo']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_location_logo']['alter']['more_link'] = 0;
  $handler->display->display_options['fields']['field_location_logo']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_location_logo']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_location_logo']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_location_logo']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_location_logo']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_location_logo']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_location_logo']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_location_logo']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['field_location_logo']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_location_logo']['type'] = 'colorbox';
  $handler->display->display_options['fields']['field_location_logo']['settings'] = array(
    'colorbox_node_style' => 'gozulla_client_logo',
    'colorbox_image_style' => 'colorbox_image',
    'colorbox_gallery' => 'post',
    'colorbox_gallery_custom' => '',
    'colorbox_caption' => 'auto',
    'colorbox_caption_custom' => '',
  );
  $handler->display->display_options['fields']['field_location_logo']['field_api_classes'] = 0;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['title']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['title']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['title']['alter']['external'] = 0;
  $handler->display->display_options['fields']['title']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['title']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['title']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = 0;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = 0;
  $handler->display->display_options['fields']['title']['alter']['more_link'] = 0;
  $handler->display->display_options['fields']['title']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['title']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['title']['alter']['html'] = 0;
  $handler->display->display_options['fields']['title']['element_type'] = 'h3';
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['title']['hide_empty'] = 0;
  $handler->display->display_options['fields']['title']['empty_zero'] = 0;
  $handler->display->display_options['fields']['title']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['title']['link_to_node'] = 1;
  /* Field: Field: Address */
  $handler->display->display_options['fields']['field_address']['id'] = 'field_address';
  $handler->display->display_options['fields']['field_address']['table'] = 'field_data_field_address';
  $handler->display->display_options['fields']['field_address']['field'] = 'field_address';
  $handler->display->display_options['fields']['field_address']['label'] = '';
  $handler->display->display_options['fields']['field_address']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_address']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_address']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_address']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_address']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_address']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_address']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_address']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_address']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_address']['alter']['more_link'] = 0;
  $handler->display->display_options['fields']['field_address']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_address']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_address']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_address']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_address']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_address']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_address']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_address']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['field_address']['click_sort_column'] = 'country';
  $handler->display->display_options['fields']['field_address']['settings'] = array(
    'use_widget_handlers' => 1,
    'format_handlers' => array(
      'address' => 'address',
    ),
  );
  $handler->display->display_options['fields']['field_address']['field_api_classes'] = 0;
  /* Field: Content: Shop website */
  $handler->display->display_options['fields']['field_website']['id'] = 'field_website';
  $handler->display->display_options['fields']['field_website']['table'] = 'field_data_field_website';
  $handler->display->display_options['fields']['field_website']['field'] = 'field_website';
  $handler->display->display_options['fields']['field_website']['label'] = '';
  $handler->display->display_options['fields']['field_website']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_website']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_website']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_website']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_website']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_website']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_website']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_website']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_website']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_website']['alter']['more_link'] = 0;
  $handler->display->display_options['fields']['field_website']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_website']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_website']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_website']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_website']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_website']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_website']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_website']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['field_website']['click_sort_column'] = 'url';
  $handler->display->display_options['fields']['field_website']['type'] = 'link_url';
  $handler->display->display_options['fields']['field_website']['field_api_classes'] = 0;
  /* Field: Node: Edit link */
  $handler->display->display_options['fields']['edit_node']['id'] = 'edit_node';
  $handler->display->display_options['fields']['edit_node']['table'] = 'views_entity_node';
  $handler->display->display_options['fields']['edit_node']['field'] = 'edit_node';
  $handler->display->display_options['fields']['edit_node']['label'] = '';
  $handler->display->display_options['fields']['edit_node']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['edit_node']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['edit_node']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['edit_node']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['edit_node']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['edit_node']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['edit_node']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['edit_node']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['edit_node']['alter']['more_link'] = 0;
  $handler->display->display_options['fields']['edit_node']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['edit_node']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['edit_node']['alter']['html'] = 0;
  $handler->display->display_options['fields']['edit_node']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['edit_node']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['edit_node']['hide_empty'] = 0;
  $handler->display->display_options['fields']['edit_node']['empty_zero'] = 0;
  $handler->display->display_options['fields']['edit_node']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['edit_node']['text'] = '[ edit ]';
  $handler->display->display_options['defaults']['sorts'] = FALSE;
  /* Sort criterion: Global: Random */
  $handler->display->display_options['sorts']['random']['id'] = 'random';
  $handler->display->display_options['sorts']['random']['table'] = 'views';
  $handler->display->display_options['sorts']['random']['field'] = 'random';
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'gozulla_location' => 'gozulla_location',
  );
  /* Filter criterion: Content: Active Subscription (field_gozulla_subscription) */
  $handler->display->display_options['filters']['field_gozulla_subscription_value']['id'] = 'field_gozulla_subscription_value';
  $handler->display->display_options['filters']['field_gozulla_subscription_value']['table'] = 'field_data_field_gozulla_subscription';
  $handler->display->display_options['filters']['field_gozulla_subscription_value']['field'] = 'field_gozulla_subscription_value';
  $handler->display->display_options['filters']['field_gozulla_subscription_value']['value'] = array(
    1 => '1',
  );

  /* Display: snow */
  $handler = $view->new_display('page', 'snow', 'page_3');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'snow directory';
  $handler->display->display_options['display_description'] = 'gozulla snow directory';
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'gozulla_location' => 'gozulla_location',
  );
  /* Filter criterion: Proximity: Great-circle */
  $handler->display->display_options['filters']['circle']['id'] = 'circle';
  $handler->display->display_options['filters']['circle']['table'] = 'openlayers_proximity';
  $handler->display->display_options['filters']['circle']['field'] = 'circle';
  $handler->display->display_options['filters']['circle']['value']['value'] = '50';
  $handler->display->display_options['filters']['circle']['value']['location'] = 'Newport, OR';
  $handler->display->display_options['filters']['circle']['value']['node'] = '1630';
  $handler->display->display_options['filters']['circle']['exposed'] = TRUE;
  $handler->display->display_options['filters']['circle']['expose']['operator_id'] = 'circle_op';
  $handler->display->display_options['filters']['circle']['expose']['operator'] = 'circle_op';
  $handler->display->display_options['filters']['circle']['expose']['identifier'] = 'circle';
  $handler->display->display_options['filters']['circle']['expose']['multiple'] = FALSE;
  $handler->display->display_options['filters']['circle']['expose']['use_unit'] = 0;
  $handler->display->display_options['filters']['circle']['expose']['use_location'] = 1;
  $handler->display->display_options['filters']['circle']['expose']['use_node'] = 0;
  /* Filter criterion: Content: Sports (field_sport_type) */
  $handler->display->display_options['filters']['field_sport_type_tid']['id'] = 'field_sport_type_tid';
  $handler->display->display_options['filters']['field_sport_type_tid']['table'] = 'field_data_field_sport_type';
  $handler->display->display_options['filters']['field_sport_type_tid']['field'] = 'field_sport_type_tid';
  $handler->display->display_options['filters']['field_sport_type_tid']['value'] = array(
    0 => '24',
  );
  $handler->display->display_options['filters']['field_sport_type_tid']['reduce_duplicates'] = 0;
  $handler->display->display_options['filters']['field_sport_type_tid']['vocabulary'] = 'gozulla_sport';
  $handler->display->display_options['path'] = 'snow';

  /* Display: bike */
  $handler = $view->new_display('page', 'bike', 'page_4');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'bike directory';
  $handler->display->display_options['display_description'] = 'gozulla bike directory';
  $handler->display->display_options['path'] = 'bike';

  /* Display: climb */
  $handler = $view->new_display('page', 'climb', 'page_5');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'climb directory';
  $handler->display->display_options['display_description'] = 'gozulla climb directory';
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'gozulla_location' => 'gozulla_location',
  );
  /* Filter criterion: Proximity: Great-circle */
  $handler->display->display_options['filters']['circle']['id'] = 'circle';
  $handler->display->display_options['filters']['circle']['table'] = 'openlayers_proximity';
  $handler->display->display_options['filters']['circle']['field'] = 'circle';
  $handler->display->display_options['filters']['circle']['value']['value'] = '20';
  $handler->display->display_options['filters']['circle']['value']['location'] = 'Newport, OR';
  $handler->display->display_options['filters']['circle']['value']['node'] = '1630';
  $handler->display->display_options['filters']['circle']['exposed'] = TRUE;
  $handler->display->display_options['filters']['circle']['expose']['operator_id'] = 'circle_op';
  $handler->display->display_options['filters']['circle']['expose']['operator'] = 'circle_op';
  $handler->display->display_options['filters']['circle']['expose']['identifier'] = 'circle';
  $handler->display->display_options['filters']['circle']['expose']['multiple'] = FALSE;
  $handler->display->display_options['filters']['circle']['expose']['use_unit'] = 0;
  $handler->display->display_options['filters']['circle']['expose']['use_location'] = 1;
  $handler->display->display_options['filters']['circle']['expose']['use_node'] = 0;
  /* Filter criterion: Content: Sports (field_sport_type) */
  $handler->display->display_options['filters']['field_sport_type_tid']['id'] = 'field_sport_type_tid';
  $handler->display->display_options['filters']['field_sport_type_tid']['table'] = 'field_data_field_sport_type';
  $handler->display->display_options['filters']['field_sport_type_tid']['field'] = 'field_sport_type_tid';
  $handler->display->display_options['filters']['field_sport_type_tid']['value'] = array(
    0 => '27',
  );
  $handler->display->display_options['filters']['field_sport_type_tid']['reduce_duplicates'] = 0;
  $handler->display->display_options['filters']['field_sport_type_tid']['vocabulary'] = 'gozulla_sport';
  $handler->display->display_options['path'] = 'climb';

  /* Display: boat */
  $handler = $view->new_display('page', 'boat', 'page_6');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'boat directory';
  $handler->display->display_options['display_description'] = 'gozulla boat directory';
  $handler->display->display_options['path'] = 'boat';

  /* Display: golf */
  $handler = $view->new_display('page', 'golf', 'page_7');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'golf directory';
  $handler->display->display_options['display_description'] = 'gozulla golf directory';
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'gozulla_location' => 'gozulla_location',
  );
  /* Filter criterion: Proximity: Great-circle */
  $handler->display->display_options['filters']['circle']['id'] = 'circle';
  $handler->display->display_options['filters']['circle']['table'] = 'openlayers_proximity';
  $handler->display->display_options['filters']['circle']['field'] = 'circle';
  $handler->display->display_options['filters']['circle']['value']['value'] = '20';
  $handler->display->display_options['filters']['circle']['value']['location'] = 'Newport, OR';
  $handler->display->display_options['filters']['circle']['value']['node'] = '1630';
  $handler->display->display_options['filters']['circle']['exposed'] = TRUE;
  $handler->display->display_options['filters']['circle']['expose']['operator_id'] = 'circle_op';
  $handler->display->display_options['filters']['circle']['expose']['operator'] = 'circle_op';
  $handler->display->display_options['filters']['circle']['expose']['identifier'] = 'circle';
  $handler->display->display_options['filters']['circle']['expose']['multiple'] = FALSE;
  $handler->display->display_options['filters']['circle']['expose']['use_unit'] = 0;
  $handler->display->display_options['filters']['circle']['expose']['use_location'] = 1;
  $handler->display->display_options['filters']['circle']['expose']['use_node'] = 0;
  /* Filter criterion: Content: Sports (field_sport_type) */
  $handler->display->display_options['filters']['field_sport_type_tid']['id'] = 'field_sport_type_tid';
  $handler->display->display_options['filters']['field_sport_type_tid']['table'] = 'field_data_field_sport_type';
  $handler->display->display_options['filters']['field_sport_type_tid']['field'] = 'field_sport_type_tid';
  $handler->display->display_options['filters']['field_sport_type_tid']['value'] = array(
    0 => '28',
  );
  $handler->display->display_options['filters']['field_sport_type_tid']['reduce_duplicates'] = 0;
  $handler->display->display_options['filters']['field_sport_type_tid']['vocabulary'] = 'gozulla_sport';
  $handler->display->display_options['path'] = 'golf';
  $translatables['gozulla_directory'] = array(
    t('Master'),
    t('gozulla directory'),
    t('more'),
    t('Apply'),
    t('Reset'),
    t('Sort by'),
    t('Asc'),
    t('Desc'),
    t('Items per page'),
    t('- All -'),
    t('Offset'),
    t('.'),
    t(','),
    t('~'),
    t('miles'),
    t('Geofield'),
    t('&nbsp;'),
    t('[ edit ]'),
    t('surf'),
    t('surf directory'),
    t('gozulla surf directory'),
    t('skate'),
    t('skate directory'),
    t('gozulla skate directory'),
    t('geofield map'),
    t('[title] 
[field_address]'),
    t('featured shop'),
    t('one hot shop'),
    t('Displays random gozulla location'),
    t('node/[nid]'),
    t('snow'),
    t('snow directory'),
    t('gozulla snow directory'),
    t('bike'),
    t('bike directory'),
    t('gozulla bike directory'),
    t('climb'),
    t('climb directory'),
    t('gozulla climb directory'),
    t('boat'),
    t('boat directory'),
    t('gozulla boat directory'),
    t('golf'),
    t('golf directory'),
    t('gozulla golf directory'),
  );
  $export['gozulla_directory'] = $view;

  return $export;
}
