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

  $view = new view();
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
  $handler->display->display_options['title'] = 'go sport';
  $handler->display->display_options['css_class'] = 'gozulla-directory';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['query']['options']['query_comment'] = FALSE;
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['exposed_form']['options']['reset_button_label'] = 'Find Me';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '10';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['pager']['options']['id'] = '0';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Header: common-links */
  $handler->display->display_options['header']['area']['id'] = 'area';
  $handler->display->display_options['header']['area']['table'] = 'views';
  $handler->display->display_options['header']['area']['field'] = 'area';
  $handler->display->display_options['header']['area']['ui_name'] = 'common-links';
  $handler->display->display_options['header']['area']['empty'] = TRUE;
  $handler->display->display_options['header']['area']['content'] = '<div id="common-links-container">
	<span class="common-links"><a id="shops-link" href="/" title="locate gozulla shops">shops</a>
		<span class"link-divider">|</span>
	</span> 
	<span class="common-links"><a id="lodging-link" href="/lodging" title="find gozulla lodging">lodging</a>
		<span class"link-divider">|</span> 
		</span> 
	<span class="common-links"><a id="deals-link" href="/deals/" title="find gozulla deals">deals</a></span>
</div>';
  $handler->display->display_options['header']['area']['format'] = 'full_html';
  /* Field: location nid */
  $handler->display->display_options['fields']['nid_1']['id'] = 'nid_1';
  $handler->display->display_options['fields']['nid_1']['table'] = 'node';
  $handler->display->display_options['fields']['nid_1']['field'] = 'nid';
  $handler->display->display_options['fields']['nid_1']['ui_name'] = 'location nid';
  $handler->display->display_options['fields']['nid_1']['label'] = '';
  $handler->display->display_options['fields']['nid_1']['exclude'] = TRUE;
  $handler->display->display_options['fields']['nid_1']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['nid_1']['node_in_colorbox_width'] = '600';
  $handler->display->display_options['fields']['nid_1']['node_in_colorbox_height'] = '600';
  /* Field: Content: Sports */
  $handler->display->display_options['fields']['field_sport_type']['id'] = 'field_sport_type';
  $handler->display->display_options['fields']['field_sport_type']['table'] = 'field_data_field_sport_type';
  $handler->display->display_options['fields']['field_sport_type']['field'] = 'field_sport_type';
  $handler->display->display_options['fields']['field_sport_type']['label'] = '';
  $handler->display->display_options['fields']['field_sport_type']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_sport_type']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_sport_type']['type'] = 'taxonomy_term_reference_plain';
  $handler->display->display_options['fields']['field_sport_type']['delta_offset'] = '0';
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['title']['element_type'] = 'h3';
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  /* Field: deal link */
  $handler->display->display_options['fields']['nid']['id'] = 'nid';
  $handler->display->display_options['fields']['nid']['table'] = 'node';
  $handler->display->display_options['fields']['nid']['field'] = 'nid';
  $handler->display->display_options['fields']['nid']['relationship'] = 'field_gozullalocation_nid';
  $handler->display->display_options['fields']['nid']['ui_name'] = 'deal link';
  $handler->display->display_options['fields']['nid']['label'] = '';
  $handler->display->display_options['fields']['nid']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['nid']['alter']['text'] = 'DEAL$';
  $handler->display->display_options['fields']['nid']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['nid']['alter']['path'] = 'node/[nid_1]';
  $handler->display->display_options['fields']['nid']['element_type'] = 'div';
  $handler->display->display_options['fields']['nid']['element_class'] = 'deal-link';
  $handler->display->display_options['fields']['nid']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['nid']['hide_alter_empty'] = FALSE;
  $handler->display->display_options['fields']['nid']['node_in_colorbox_width'] = '600';
  $handler->display->display_options['fields']['nid']['node_in_colorbox_height'] = '600';
  /* Field: Field: Address */
  $handler->display->display_options['fields']['field_address']['id'] = 'field_address';
  $handler->display->display_options['fields']['field_address']['table'] = 'field_data_field_address';
  $handler->display->display_options['fields']['field_address']['field'] = 'field_address';
  $handler->display->display_options['fields']['field_address']['label'] = '';
  $handler->display->display_options['fields']['field_address']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_address']['click_sort_column'] = 'country';
  $handler->display->display_options['fields']['field_address']['settings'] = array(
    'use_widget_handlers' => 1,
    'format_handlers' => array(
      'address' => 'address',
    ),
  );
  /* Field: Proximity: Distance */
  $handler->display->display_options['fields']['distance']['id'] = 'distance';
  $handler->display->display_options['fields']['distance']['table'] = 'openlayers_proximity';
  $handler->display->display_options['fields']['distance']['field'] = 'distance';
  $handler->display->display_options['fields']['distance']['label'] = '';
  $handler->display->display_options['fields']['distance']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['distance']['hide_empty'] = 1;
  $handler->display->display_options['fields']['distance']['set_precision'] = 1;
  $handler->display->display_options['fields']['distance']['precision'] = '1';
  $handler->display->display_options['fields']['distance']['location_provider'] = 'circle';
  /* Field: Content: Edit link */
  $handler->display->display_options['fields']['edit_node']['id'] = 'edit_node';
  $handler->display->display_options['fields']['edit_node']['table'] = 'views_entity_node';
  $handler->display->display_options['fields']['edit_node']['field'] = 'edit_node';
  $handler->display->display_options['fields']['edit_node']['label'] = '';
  $handler->display->display_options['fields']['edit_node']['exclude'] = TRUE;
  $handler->display->display_options['fields']['edit_node']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['edit_node']['text'] = '[ edit ]';
  /* Sort criterion: Proximity: Distance */
  $handler->display->display_options['sorts']['distance']['id'] = 'distance';
  $handler->display->display_options['sorts']['distance']['table'] = 'openlayers_proximity';
  $handler->display->display_options['sorts']['distance']['field'] = 'distance';
  $handler->display->display_options['sorts']['distance']['relationship'] = 'field_gozullalocation_nid';
  $handler->display->display_options['sorts']['distance']['location_provider'] = 'circle';
  /* Contextual filter: Content: Has taxonomy term ID */
  $handler->display->display_options['arguments']['tid']['id'] = 'tid';
  $handler->display->display_options['arguments']['tid']['table'] = 'taxonomy_index';
  $handler->display->display_options['arguments']['tid']['field'] = 'tid';
  $handler->display->display_options['arguments']['tid']['default_argument_type'] = 'node';
  $handler->display->display_options['arguments']['tid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['tid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['tid']['summary_options']['items_per_page'] = '25';
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
    'gozullalocation' => 'gozullalocation',
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
  $handler->display->display_options['filters']['circle']['expose']['use_unit'] = 0;
  $handler->display->display_options['filters']['circle']['expose']['use_location'] = 1;
  $handler->display->display_options['filters']['circle']['expose']['use_node'] = 0;

  /* Display: surf */
  $handler = $view->new_display('page', 'surf', 'surf');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'go surf';
  $handler->display->display_options['display_description'] = 'gozulla surf directory';
  $handler->display->display_options['defaults']['hide_admin_links'] = FALSE;
  $handler->display->display_options['exposed_block'] = TRUE;
  $handler->display->display_options['defaults']['header'] = FALSE;
  /* Header: common-links */
  $handler->display->display_options['header']['area']['id'] = 'area';
  $handler->display->display_options['header']['area']['table'] = 'views';
  $handler->display->display_options['header']['area']['field'] = 'area';
  $handler->display->display_options['header']['area']['ui_name'] = 'common-links';
  $handler->display->display_options['header']['area']['empty'] = TRUE;
  $handler->display->display_options['header']['area']['content'] = '<div id="common-links-container">
	<span class="common-links"><a id="shops-link" href="/surf" title="locate gozulla shops">shops</a>
		<span class"link-divider">|</span>
	</span> 
	<span class="common-links"><a id="lodging-link" href="/lodging" title="find gozulla lodging">lodging</a>
		<span class"link-divider">|</span> 
		</span> 
	<span class="common-links"><a id="deals-link" href="/deals/surf" title="find gozulla deals">deals</a></span>
</div>';
  $handler->display->display_options['header']['area']['format'] = 'full_html';
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
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
    'gozullalocation' => 'gozullalocation',
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
  $handler->display->display_options['filters']['circle']['expose']['use_unit'] = 0;
  $handler->display->display_options['filters']['circle']['expose']['use_location'] = 1;
  $handler->display->display_options['filters']['circle']['expose']['use_node'] = 0;
  /* Filter criterion: Content: Sports (field_sport_type) */
  $handler->display->display_options['filters']['field_sport_type_tid']['id'] = 'field_sport_type_tid';
  $handler->display->display_options['filters']['field_sport_type_tid']['table'] = 'field_data_field_sport_type';
  $handler->display->display_options['filters']['field_sport_type_tid']['field'] = 'field_sport_type_tid';
  $handler->display->display_options['filters']['field_sport_type_tid']['value'] = array(
    12 => '12',
  );
  $handler->display->display_options['filters']['field_sport_type_tid']['type'] = 'select';
  $handler->display->display_options['filters']['field_sport_type_tid']['vocabulary'] = 'gozulla_sport';
  $handler->display->display_options['path'] = 'surf';
  $handler->display->display_options['menu']['type'] = 'normal';
  $handler->display->display_options['menu']['title'] = 'surf';
  $handler->display->display_options['menu']['description'] = 'find surf shops near you';
  $handler->display->display_options['menu']['weight'] = '0';
  $handler->display->display_options['menu']['name'] = 'menu-sport-links';
  $handler->display->display_options['menu']['context'] = 0;

  /* Display: skate */
  $handler = $view->new_display('page', 'skate', 'skate');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'go skate';
  $handler->display->display_options['display_description'] = 'gozulla skate directory';
  $handler->display->display_options['defaults']['hide_admin_links'] = FALSE;
  $handler->display->display_options['exposed_block'] = TRUE;
  $handler->display->display_options['defaults']['header'] = FALSE;
  /* Header: common-links */
  $handler->display->display_options['header']['area']['id'] = 'area';
  $handler->display->display_options['header']['area']['table'] = 'views';
  $handler->display->display_options['header']['area']['field'] = 'area';
  $handler->display->display_options['header']['area']['ui_name'] = 'common-links';
  $handler->display->display_options['header']['area']['empty'] = TRUE;
  $handler->display->display_options['header']['area']['content'] = '<div id="common-links-container">
	<span class="common-links"><a id="shops-link" href="/skate" title="locate gozulla shops">shops</a>
		<span class"link-divider">|</span>
	</span> 
	<span class="common-links"><a id="lodging-link" href="/lodging" title="find gozulla lodging">lodging</a>
		<span class"link-divider">|</span> 
		</span> 
	<span class="common-links"><a id="deals-link" href="/deals/skate" title="find gozulla deals">deals</a></span>
</div>';
  $handler->display->display_options['header']['area']['format'] = 'full_html';
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
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
    'gozullalocation' => 'gozullalocation',
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
  $handler->display->display_options['filters']['circle']['expose']['use_unit'] = 0;
  $handler->display->display_options['filters']['circle']['expose']['use_location'] = 1;
  $handler->display->display_options['filters']['circle']['expose']['use_node'] = 0;
  /* Filter criterion: Content: Sports (field_sport_type) */
  $handler->display->display_options['filters']['field_sport_type_tid']['id'] = 'field_sport_type_tid';
  $handler->display->display_options['filters']['field_sport_type_tid']['table'] = 'field_data_field_sport_type';
  $handler->display->display_options['filters']['field_sport_type_tid']['field'] = 'field_sport_type_tid';
  $handler->display->display_options['filters']['field_sport_type_tid']['value'] = array(
    18 => '18',
  );
  $handler->display->display_options['filters']['field_sport_type_tid']['type'] = 'select';
  $handler->display->display_options['filters']['field_sport_type_tid']['vocabulary'] = 'gozulla_sport';
  $handler->display->display_options['path'] = 'skate';
  $handler->display->display_options['menu']['type'] = 'normal';
  $handler->display->display_options['menu']['title'] = 'skate';
  $handler->display->display_options['menu']['description'] = 'find skate shops near you';
  $handler->display->display_options['menu']['weight'] = '0';
  $handler->display->display_options['menu']['name'] = 'menu-sport-links';
  $handler->display->display_options['menu']['context'] = 0;

  /* Display: geofield map */
  $handler = $view->new_display('attachment', 'geofield map', 'geofield_map');
  $handler->display->display_options['enabled'] = FALSE;
  $handler->display->display_options['defaults']['hide_admin_links'] = FALSE;
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
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['title']['element_type'] = 'h3';
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  /* Field: Field: Address */
  $handler->display->display_options['fields']['field_address']['id'] = 'field_address';
  $handler->display->display_options['fields']['field_address']['table'] = 'field_data_field_address';
  $handler->display->display_options['fields']['field_address']['field'] = 'field_address';
  $handler->display->display_options['fields']['field_address']['label'] = '';
  $handler->display->display_options['fields']['field_address']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_address']['alter']['text'] = '[title] 
  [field_address]';
  $handler->display->display_options['fields']['field_address']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_address']['click_sort_column'] = 'country';
  $handler->display->display_options['fields']['field_address']['settings'] = array(
    'use_widget_handlers' => 1,
    'format_handlers' => array(
      'address' => 'address',
    ),
  );
  /* Field: Proximity: Distance */
  $handler->display->display_options['fields']['distance']['id'] = 'distance';
  $handler->display->display_options['fields']['distance']['table'] = 'openlayers_proximity';
  $handler->display->display_options['fields']['distance']['field'] = 'distance';
  $handler->display->display_options['fields']['distance']['label'] = '';
  $handler->display->display_options['fields']['distance']['exclude'] = TRUE;
  $handler->display->display_options['fields']['distance']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['distance']['hide_empty'] = 1;
  $handler->display->display_options['fields']['distance']['set_precision'] = 1;
  $handler->display->display_options['fields']['distance']['precision'] = '2';
  $handler->display->display_options['fields']['distance']['prefix'] = '~';
  $handler->display->display_options['fields']['distance']['suffix'] = 'miles';
  $handler->display->display_options['fields']['distance']['location_provider'] = 'circle';
  /* Field: Field: Geo Field */
  $handler->display->display_options['fields']['field_geofield_1']['id'] = 'field_geofield_1';
  $handler->display->display_options['fields']['field_geofield_1']['table'] = 'field_data_field_geofield';
  $handler->display->display_options['fields']['field_geofield_1']['field'] = 'field_geofield';
  $handler->display->display_options['fields']['field_geofield_1']['label'] = 'Geofield';
  $handler->display->display_options['fields']['field_geofield_1']['click_sort_column'] = 'wkt';
  $handler->display->display_options['fields']['field_geofield_1']['type'] = 'geofield_latlon';
  $handler->display->display_options['fields']['field_geofield_1']['settings'] = array(
    'data' => 'full',
    'format' => 'decimal_degrees',
    'labels' => 1,
  );
  $handler->display->display_options['displays'] = array(
    'page_1' => 'page_1',
    'default' => 0,
    'block' => 0,
    'page_2' => 0,
  );
  $handler->display->display_options['inherit_exposed_filters'] = TRUE;

  /* Display: featured shop */
  $handler = $view->new_display('block', 'featured shop', 'featured_shop');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'one hot shop';
  $handler->display->display_options['defaults']['css_class'] = FALSE;
  $handler->display->display_options['display_description'] = 'Displays random gozulla location';
  $handler->display->display_options['defaults']['hide_admin_links'] = FALSE;
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '1';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['defaults']['header'] = FALSE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Nid */
  $handler->display->display_options['fields']['nid']['id'] = 'nid';
  $handler->display->display_options['fields']['nid']['table'] = 'node';
  $handler->display->display_options['fields']['nid']['field'] = 'nid';
  $handler->display->display_options['fields']['nid']['label'] = '';
  $handler->display->display_options['fields']['nid']['exclude'] = TRUE;
  $handler->display->display_options['fields']['nid']['element_label_colon'] = FALSE;
  /* Field: Content: Business logo */
  $handler->display->display_options['fields']['field_location_logo']['id'] = 'field_location_logo';
  $handler->display->display_options['fields']['field_location_logo']['table'] = 'field_data_field_location_logo';
  $handler->display->display_options['fields']['field_location_logo']['field'] = 'field_location_logo';
  $handler->display->display_options['fields']['field_location_logo']['label'] = '';
  $handler->display->display_options['fields']['field_location_logo']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['field_location_logo']['alter']['path'] = 'node/[nid]';
  $handler->display->display_options['fields']['field_location_logo']['element_label_colon'] = FALSE;
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
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['title']['element_type'] = 'h3';
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  /* Field: Field: Address */
  $handler->display->display_options['fields']['field_address']['id'] = 'field_address';
  $handler->display->display_options['fields']['field_address']['table'] = 'field_data_field_address';
  $handler->display->display_options['fields']['field_address']['field'] = 'field_address';
  $handler->display->display_options['fields']['field_address']['label'] = '';
  $handler->display->display_options['fields']['field_address']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_address']['click_sort_column'] = 'country';
  $handler->display->display_options['fields']['field_address']['settings'] = array(
    'use_widget_handlers' => 1,
    'format_handlers' => array(
      'address' => 'address',
    ),
  );
  /* Field: Content: Business website */
  $handler->display->display_options['fields']['field_website']['id'] = 'field_website';
  $handler->display->display_options['fields']['field_website']['table'] = 'field_data_field_website';
  $handler->display->display_options['fields']['field_website']['field'] = 'field_website';
  $handler->display->display_options['fields']['field_website']['label'] = '';
  $handler->display->display_options['fields']['field_website']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_website']['click_sort_column'] = 'url';
  $handler->display->display_options['fields']['field_website']['type'] = 'link_url';
  /* Field: Content: Edit link */
  $handler->display->display_options['fields']['edit_node']['id'] = 'edit_node';
  $handler->display->display_options['fields']['edit_node']['table'] = 'views_entity_node';
  $handler->display->display_options['fields']['edit_node']['field'] = 'edit_node';
  $handler->display->display_options['fields']['edit_node']['label'] = '';
  $handler->display->display_options['fields']['edit_node']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['edit_node']['text'] = '[ edit ]';
  $handler->display->display_options['defaults']['sorts'] = FALSE;
  /* Sort criterion: Global: Random */
  $handler->display->display_options['sorts']['random']['id'] = 'random';
  $handler->display->display_options['sorts']['random']['table'] = 'views';
  $handler->display->display_options['sorts']['random']['field'] = 'random';
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
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
    'gozullalocation' => 'gozullalocation',
  );
  /* Filter criterion: Content: Active Subscription (field_gozulla_subscription) */
  $handler->display->display_options['filters']['field_gozulla_subscription_value']['id'] = 'field_gozulla_subscription_value';
  $handler->display->display_options['filters']['field_gozulla_subscription_value']['table'] = 'field_data_field_gozulla_subscription';
  $handler->display->display_options['filters']['field_gozulla_subscription_value']['field'] = 'field_gozulla_subscription_value';
  $handler->display->display_options['filters']['field_gozulla_subscription_value']['value'] = array(
    1 => '1',
  );

  /* Display: snow */
  $handler = $view->new_display('page', 'snow', 'snow');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'go snow';
  $handler->display->display_options['display_description'] = 'gozulla snow directory';
  $handler->display->display_options['defaults']['hide_admin_links'] = FALSE;
  $handler->display->display_options['exposed_block'] = TRUE;
  $handler->display->display_options['defaults']['header'] = FALSE;
  /* Header: common-links */
  $handler->display->display_options['header']['area']['id'] = 'area';
  $handler->display->display_options['header']['area']['table'] = 'views';
  $handler->display->display_options['header']['area']['field'] = 'area';
  $handler->display->display_options['header']['area']['ui_name'] = 'common-links';
  $handler->display->display_options['header']['area']['empty'] = TRUE;
  $handler->display->display_options['header']['area']['content'] = '<div id="common-links-container">
	<span class="common-links"><a id="shops-link" href="/snow" title="locate gozulla shops">shops</a>
		<span class"link-divider">|</span>
	</span> 
	<span class="common-links"><a id="lodging-link" href="/lodging" title="find gozulla lodging">lodging</a>
		<span class"link-divider">|</span> 
		</span> 
	<span class="common-links"><a id="deals-link" href="/deals/snow" title="find gozulla deals">deals</a></span>
</div>';
  $handler->display->display_options['header']['area']['format'] = 'full_html';
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
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
    'gozullalocation' => 'gozullalocation',
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
  $handler->display->display_options['filters']['circle']['expose']['use_unit'] = 0;
  $handler->display->display_options['filters']['circle']['expose']['use_location'] = 1;
  $handler->display->display_options['filters']['circle']['expose']['use_node'] = 0;
  /* Filter criterion: Content: Sports (field_sport_type) */
  $handler->display->display_options['filters']['field_sport_type_tid']['id'] = 'field_sport_type_tid';
  $handler->display->display_options['filters']['field_sport_type_tid']['table'] = 'field_data_field_sport_type';
  $handler->display->display_options['filters']['field_sport_type_tid']['field'] = 'field_sport_type_tid';
  $handler->display->display_options['filters']['field_sport_type_tid']['value'] = array(
    19 => '19',
  );
  $handler->display->display_options['filters']['field_sport_type_tid']['type'] = 'select';
  $handler->display->display_options['filters']['field_sport_type_tid']['vocabulary'] = 'gozulla_sport';
  $handler->display->display_options['path'] = 'snow';
  $handler->display->display_options['menu']['type'] = 'normal';
  $handler->display->display_options['menu']['title'] = 'snow';
  $handler->display->display_options['menu']['description'] = 'find snow shops near you';
  $handler->display->display_options['menu']['weight'] = '0';
  $handler->display->display_options['menu']['name'] = 'menu-sport-links';
  $handler->display->display_options['menu']['context'] = 0;

  /* Display: bike */
  $handler = $view->new_display('page', 'bike', 'bike');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'go bike';
  $handler->display->display_options['display_description'] = 'gozulla bike directory';
  $handler->display->display_options['defaults']['hide_admin_links'] = FALSE;
  $handler->display->display_options['exposed_block'] = TRUE;
  $handler->display->display_options['defaults']['header'] = FALSE;
  /* Header: common-links */
  $handler->display->display_options['header']['area']['id'] = 'area';
  $handler->display->display_options['header']['area']['table'] = 'views';
  $handler->display->display_options['header']['area']['field'] = 'area';
  $handler->display->display_options['header']['area']['ui_name'] = 'common-links';
  $handler->display->display_options['header']['area']['empty'] = TRUE;
  $handler->display->display_options['header']['area']['content'] = '<div id="common-links-container">
	<span class="common-links"><a id="shops-link" href="/bike" title="locate gozulla shops">shops</a>
		<span class"link-divider">|</span>
	</span> 
	<span class="common-links"><a id="lodging-link" href="/lodging" title="find gozulla lodging">lodging</a>
		<span class"link-divider">|</span> 
		</span> 
	<span class="common-links"><a id="deals-link" href="/deals/bike" title="find gozulla deals">deals</a></span>
</div>';
  $handler->display->display_options['header']['area']['format'] = 'full_html';
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
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
    'gozullalocation' => 'gozullalocation',
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
  $handler->display->display_options['filters']['circle']['expose']['use_unit'] = 0;
  $handler->display->display_options['filters']['circle']['expose']['use_location'] = 1;
  $handler->display->display_options['filters']['circle']['expose']['use_node'] = 0;
  /* Filter criterion: Content: Sports (field_sport_type) */
  $handler->display->display_options['filters']['field_sport_type_tid']['id'] = 'field_sport_type_tid';
  $handler->display->display_options['filters']['field_sport_type_tid']['table'] = 'field_data_field_sport_type';
  $handler->display->display_options['filters']['field_sport_type_tid']['field'] = 'field_sport_type_tid';
  $handler->display->display_options['filters']['field_sport_type_tid']['value'] = array(
    14 => '14',
  );
  $handler->display->display_options['filters']['field_sport_type_tid']['type'] = 'select';
  $handler->display->display_options['filters']['field_sport_type_tid']['vocabulary'] = 'gozulla_sport';
  $handler->display->display_options['path'] = 'bike';
  $handler->display->display_options['menu']['type'] = 'normal';
  $handler->display->display_options['menu']['title'] = 'bike';
  $handler->display->display_options['menu']['description'] = 'find bike shops near you';
  $handler->display->display_options['menu']['weight'] = '0';
  $handler->display->display_options['menu']['name'] = 'menu-sport-links';
  $handler->display->display_options['menu']['context'] = 0;

  /* Display: climb */
  $handler = $view->new_display('page', 'climb', 'climb');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'go climb';
  $handler->display->display_options['display_description'] = 'gozulla climb directory';
  $handler->display->display_options['defaults']['hide_admin_links'] = FALSE;
  $handler->display->display_options['exposed_block'] = TRUE;
  $handler->display->display_options['defaults']['header'] = FALSE;
  /* Header: common-links */
  $handler->display->display_options['header']['area']['id'] = 'area';
  $handler->display->display_options['header']['area']['table'] = 'views';
  $handler->display->display_options['header']['area']['field'] = 'area';
  $handler->display->display_options['header']['area']['ui_name'] = 'common-links';
  $handler->display->display_options['header']['area']['empty'] = TRUE;
  $handler->display->display_options['header']['area']['content'] = '<div id="common-links-container">
	<span class="common-links"><a id="shops-link" href="/climb" title="locate gozulla shops">shops</a>
		<span class"link-divider">|</span>
	</span> 
	<span class="common-links"><a id="lodging-link" href="/lodging" title="find gozulla lodging">lodging</a>
		<span class"link-divider">|</span> 
		</span> 
	<span class="common-links"><a id="deals-link" href="/deals/climb" title="find gozulla deals">deals</a></span>
</div>';
  $handler->display->display_options['header']['area']['format'] = 'full_html';
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
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
    'gozullalocation' => 'gozullalocation',
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
  $handler->display->display_options['filters']['circle']['expose']['use_unit'] = 0;
  $handler->display->display_options['filters']['circle']['expose']['use_location'] = 1;
  $handler->display->display_options['filters']['circle']['expose']['use_node'] = 0;
  /* Filter criterion: Content: Sports (field_sport_type) */
  $handler->display->display_options['filters']['field_sport_type_tid']['id'] = 'field_sport_type_tid';
  $handler->display->display_options['filters']['field_sport_type_tid']['table'] = 'field_data_field_sport_type';
  $handler->display->display_options['filters']['field_sport_type_tid']['field'] = 'field_sport_type_tid';
  $handler->display->display_options['filters']['field_sport_type_tid']['value'] = array(
    13 => '13',
  );
  $handler->display->display_options['filters']['field_sport_type_tid']['type'] = 'select';
  $handler->display->display_options['filters']['field_sport_type_tid']['vocabulary'] = 'gozulla_sport';
  $handler->display->display_options['path'] = 'climb';
  $handler->display->display_options['menu']['type'] = 'normal';
  $handler->display->display_options['menu']['title'] = 'climb';
  $handler->display->display_options['menu']['description'] = 'find climb shops near you';
  $handler->display->display_options['menu']['weight'] = '0';
  $handler->display->display_options['menu']['name'] = 'menu-sport-links';
  $handler->display->display_options['menu']['context'] = 0;

  /* Display: boat */
  $handler = $view->new_display('page', 'boat', 'boat');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'go boat';
  $handler->display->display_options['display_description'] = 'gozulla boat directory';
  $handler->display->display_options['defaults']['hide_admin_links'] = FALSE;
  $handler->display->display_options['exposed_block'] = TRUE;
  $handler->display->display_options['defaults']['header'] = FALSE;
  /* Header: common-links */
  $handler->display->display_options['header']['area']['id'] = 'area';
  $handler->display->display_options['header']['area']['table'] = 'views';
  $handler->display->display_options['header']['area']['field'] = 'area';
  $handler->display->display_options['header']['area']['ui_name'] = 'common-links';
  $handler->display->display_options['header']['area']['empty'] = TRUE;
  $handler->display->display_options['header']['area']['content'] = '<div id="common-links-container">
	<span class="common-links"><a id="shops-link" href="/boat" title="locate gozulla shops">shops</a>
		<span class"link-divider">|</span>
	</span> 
	<span class="common-links"><a id="lodging-link" href="/lodging" title="find gozulla lodging">lodging</a>
		<span class"link-divider">|</span> 
		</span> 
	<span class="common-links"><a id="deals-link" href="/deals/boat" title="find gozulla deals">deals</a></span>
</div>';
  $handler->display->display_options['header']['area']['format'] = 'full_html';
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
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
    'gozullalocation' => 'gozullalocation',
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
  $handler->display->display_options['filters']['circle']['expose']['use_unit'] = 0;
  $handler->display->display_options['filters']['circle']['expose']['use_location'] = 1;
  $handler->display->display_options['filters']['circle']['expose']['use_node'] = 0;
  /* Filter criterion: Content: Sports (field_sport_type) */
  $handler->display->display_options['filters']['field_sport_type_tid']['id'] = 'field_sport_type_tid';
  $handler->display->display_options['filters']['field_sport_type_tid']['table'] = 'field_data_field_sport_type';
  $handler->display->display_options['filters']['field_sport_type_tid']['field'] = 'field_sport_type_tid';
  $handler->display->display_options['filters']['field_sport_type_tid']['value'] = array(
    15 => '15',
  );
  $handler->display->display_options['filters']['field_sport_type_tid']['type'] = 'select';
  $handler->display->display_options['filters']['field_sport_type_tid']['vocabulary'] = 'gozulla_sport';
  $handler->display->display_options['path'] = 'boat';
  $handler->display->display_options['menu']['type'] = 'normal';
  $handler->display->display_options['menu']['title'] = 'boat';
  $handler->display->display_options['menu']['description'] = 'find boat shops near you';
  $handler->display->display_options['menu']['weight'] = '0';
  $handler->display->display_options['menu']['name'] = 'menu-sport-links';
  $handler->display->display_options['menu']['context'] = 0;

  /* Display: golf */
  $handler = $view->new_display('page', 'golf', 'golf');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'go golf';
  $handler->display->display_options['display_description'] = 'gozulla golf directory';
  $handler->display->display_options['defaults']['hide_admin_links'] = FALSE;
  $handler->display->display_options['exposed_block'] = TRUE;
  $handler->display->display_options['defaults']['header'] = FALSE;
  /* Header: common-links */
  $handler->display->display_options['header']['area']['id'] = 'area';
  $handler->display->display_options['header']['area']['table'] = 'views';
  $handler->display->display_options['header']['area']['field'] = 'area';
  $handler->display->display_options['header']['area']['ui_name'] = 'common-links';
  $handler->display->display_options['header']['area']['empty'] = TRUE;
  $handler->display->display_options['header']['area']['content'] = '<div id="common-links-container">
	<span class="common-links"><a id="shops-link" href="/golf" title="locate gozulla shops">shops</a>
		<span class"link-divider">|</span>
	</span> 
	<span class="common-links"><a id="lodging-link" href="/lodging" title="find gozulla lodging">lodging</a>
		<span class"link-divider">|</span> 
		</span> 
	<span class="common-links"><a id="deals-link" href="/deals/golf" title="find gozulla deals">deals</a></span>
</div>';
  $handler->display->display_options['header']['area']['format'] = 'full_html';
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
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
    'gozullalocation' => 'gozullalocation',
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
  $handler->display->display_options['filters']['circle']['expose']['use_unit'] = 0;
  $handler->display->display_options['filters']['circle']['expose']['use_location'] = 1;
  $handler->display->display_options['filters']['circle']['expose']['use_node'] = 0;
  /* Filter criterion: Content: Sports (field_sport_type) */
  $handler->display->display_options['filters']['field_sport_type_tid']['id'] = 'field_sport_type_tid';
  $handler->display->display_options['filters']['field_sport_type_tid']['table'] = 'field_data_field_sport_type';
  $handler->display->display_options['filters']['field_sport_type_tid']['field'] = 'field_sport_type_tid';
  $handler->display->display_options['filters']['field_sport_type_tid']['value'] = array(
    20 => '20',
  );
  $handler->display->display_options['filters']['field_sport_type_tid']['type'] = 'select';
  $handler->display->display_options['filters']['field_sport_type_tid']['vocabulary'] = 'gozulla_sport';
  $handler->display->display_options['path'] = 'golf';
  $handler->display->display_options['menu']['type'] = 'normal';
  $handler->display->display_options['menu']['title'] = 'golf';
  $handler->display->display_options['menu']['description'] = 'find golf shops near you';
  $handler->display->display_options['menu']['weight'] = '0';
  $handler->display->display_options['menu']['name'] = 'menu-sport-links';
  $handler->display->display_options['menu']['context'] = 0;

  /* Display: deals */
  $handler = $view->new_display('page', 'deals', 'deals');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'gozulla deals';
  $handler->display->display_options['display_description'] = 'displays gozulla deals by proximity and/or sports';
  $handler->display->display_options['defaults']['hide_admin_links'] = FALSE;
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['columns'] = array(
    'field_deal_photo' => 'field_deal_photo',
    'title_1' => 'field_deal_photo',
    'field_description' => 'field_deal_photo',
    'title' => 'title',
    'field_address' => 'title',
    'distance' => 'title',
    'nothing' => 'title',
    'edit_node' => 'title',
  );
  $handler->display->display_options['style_options']['default'] = '-1';
  $handler->display->display_options['style_options']['info'] = array(
    'field_deal_photo' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '<br />',
      'empty_column' => 0,
    ),
    'title_1' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_description' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'title' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '<br />',
      'empty_column' => 0,
    ),
    'field_address' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'distance' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'nothing' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'edit_node' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
  );
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['exposed_block'] = TRUE;
  $handler->display->display_options['defaults']['header'] = FALSE;
  $handler->display->display_options['defaults']['empty'] = FALSE;
  /* No results behavior: Global: Text area */
  $handler->display->display_options['empty']['area']['id'] = 'area';
  $handler->display->display_options['empty']['area']['table'] = 'views';
  $handler->display->display_options['empty']['area']['field'] = 'area';
  $handler->display->display_options['empty']['area']['content'] = '<h3>no deals found near your location</h3>

  <div>Try increasing the miles and/or changing the location.</div>
  ';
  $handler->display->display_options['empty']['area']['format'] = 'full_html';
  $handler->display->display_options['defaults']['relationships'] = FALSE;
  /* Relationship: Content: gozulla location (field_gozulla_location) - reverse */
  $handler->display->display_options['relationships']['reverse_field_gozulla_location_node']['id'] = 'reverse_field_gozulla_location_node';
  $handler->display->display_options['relationships']['reverse_field_gozulla_location_node']['table'] = 'node';
  $handler->display->display_options['relationships']['reverse_field_gozulla_location_node']['field'] = 'reverse_field_gozulla_location_node';
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title_2']['id'] = 'title_2';
  $handler->display->display_options['fields']['title_2']['table'] = 'node';
  $handler->display->display_options['fields']['title_2']['field'] = 'title';
  $handler->display->display_options['fields']['title_2']['label'] = '';
  $handler->display->display_options['fields']['title_2']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title_2']['node_in_colorbox_width'] = '600';
  $handler->display->display_options['fields']['title_2']['node_in_colorbox_height'] = '600';
  /* Field: Content: Details */
  $handler->display->display_options['fields']['field_description']['id'] = 'field_description';
  $handler->display->display_options['fields']['field_description']['table'] = 'field_data_field_description';
  $handler->display->display_options['fields']['field_description']['field'] = 'field_description';
  $handler->display->display_options['fields']['field_description']['label'] = '';
  $handler->display->display_options['fields']['field_description']['alter']['nl2br'] = TRUE;
  $handler->display->display_options['fields']['field_description']['element_label_colon'] = FALSE;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['title']['element_type'] = 'h3';
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  /* Field: Field: Address */
  $handler->display->display_options['fields']['field_address']['id'] = 'field_address';
  $handler->display->display_options['fields']['field_address']['table'] = 'field_data_field_address';
  $handler->display->display_options['fields']['field_address']['field'] = 'field_address';
  $handler->display->display_options['fields']['field_address']['label'] = '';
  $handler->display->display_options['fields']['field_address']['alter']['text'] = '[field_address-premise]';
  $handler->display->display_options['fields']['field_address']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_address']['click_sort_column'] = 'country';
  $handler->display->display_options['fields']['field_address']['settings'] = array(
    'use_widget_handlers' => 0,
    'format_handlers' => array(
      'address' => 'address',
      'address-hide-country' => 'address-hide-country',
    ),
  );
  /* Field: Proximity: Distance */
  $handler->display->display_options['fields']['distance']['id'] = 'distance';
  $handler->display->display_options['fields']['distance']['table'] = 'openlayers_proximity';
  $handler->display->display_options['fields']['distance']['field'] = 'distance';
  $handler->display->display_options['fields']['distance']['label'] = '';
  $handler->display->display_options['fields']['distance']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['distance']['hide_empty'] = 1;
  $handler->display->display_options['fields']['distance']['set_precision'] = 1;
  $handler->display->display_options['fields']['distance']['precision'] = '2';
  $handler->display->display_options['fields']['distance']['prefix'] = '~';
  $handler->display->display_options['fields']['distance']['suffix'] = 'miles';
  $handler->display->display_options['fields']['distance']['location_provider'] = 'circle';
  /* Field: Global: Custom text */
  $handler->display->display_options['fields']['nothing']['id'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['table'] = 'views';
  $handler->display->display_options['fields']['nothing']['field'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['label'] = '';
  $handler->display->display_options['fields']['nothing']['alter']['text'] = '&nbsp;';
  $handler->display->display_options['fields']['nothing']['element_class'] = 'clearfix';
  $handler->display->display_options['fields']['nothing']['element_label_colon'] = FALSE;
  /* Field: Content: Edit link */
  $handler->display->display_options['fields']['edit_node']['id'] = 'edit_node';
  $handler->display->display_options['fields']['edit_node']['table'] = 'views_entity_node';
  $handler->display->display_options['fields']['edit_node']['field'] = 'edit_node';
  $handler->display->display_options['fields']['edit_node']['label'] = '';
  $handler->display->display_options['fields']['edit_node']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['edit_node']['text'] = '[ edit deal ]';
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
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
    'gozullalocation' => 'gozullalocation',
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
  $handler->display->display_options['filters']['circle']['expose']['use_unit'] = 0;
  $handler->display->display_options['filters']['circle']['expose']['use_location'] = 1;
  $handler->display->display_options['filters']['circle']['expose']['use_node'] = 0;
  /* Filter criterion: Content: Deal active  (field_deal_active_) */
  $handler->display->display_options['filters']['field_deal_active__value']['id'] = 'field_deal_active__value';
  $handler->display->display_options['filters']['field_deal_active__value']['table'] = 'field_data_field_deal_active_';
  $handler->display->display_options['filters']['field_deal_active__value']['field'] = 'field_deal_active__value';
  $handler->display->display_options['filters']['field_deal_active__value']['relationship'] = 'reverse_field_gozullalocation_node';
  $handler->display->display_options['filters']['field_deal_active__value']['value'] = array(
    1 => '1',
  );
  $handler->display->display_options['path'] = 'deals';
  $handler->display->display_options['menu']['type'] = 'normal';
  $handler->display->display_options['menu']['title'] = 'deals';
  $handler->display->display_options['menu']['description'] = 'find gozulla deals near you';
  $handler->display->display_options['menu']['weight'] = '10';
  $handler->display->display_options['menu']['name'] = 'menu-sport-links';
  $handler->display->display_options['menu']['context'] = 0;

  /* Display: deals by sport */
  $handler = $view->new_display('page', 'deals by sport', 'deals_by_sport');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'gozulla deals';
  $handler->display->display_options['display_description'] = 'displays gozulla deals by proximity and sport';
  $handler->display->display_options['defaults']['hide_admin_links'] = FALSE;
  $handler->display->display_options['hide_admin_links'] = TRUE;
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'node';
  $handler->display->display_options['row_options']['links'] = FALSE;
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['exposed_block'] = TRUE;
  $handler->display->display_options['defaults']['header'] = FALSE;
  /* Header: Global: Text area */
  $handler->display->display_options['header']['area']['id'] = 'area';
  $handler->display->display_options['header']['area']['table'] = 'views';
  $handler->display->display_options['header']['area']['field'] = 'area';
  $handler->display->display_options['header']['area']['empty'] = TRUE;
  $handler->display->display_options['header']['area']['content'] = '<div id="common-links-container">
	<span class="common-links sport"><a id="shops-link" href="/%1" title="locate gozulla shops">shops</a>
		<span class"link-spander">|</span>
	</span> 
	<span class="common-links lodging">lodging
		<span class"link-spander">|</span> 
		</span> 
	<span class="common-links deal clearfix"><a id="deals-link" href="/deals/%1" title="find gozulla deals">deals</a></span>
</div>';
  $handler->display->display_options['header']['area']['format'] = 'full_html';
  $handler->display->display_options['header']['area']['tokenize'] = TRUE;
  $handler->display->display_options['defaults']['empty'] = FALSE;
  /* No results behavior: Global: Text area */
  $handler->display->display_options['empty']['area']['id'] = 'area';
  $handler->display->display_options['empty']['area']['table'] = 'views';
  $handler->display->display_options['empty']['area']['field'] = 'area';
  $handler->display->display_options['empty']['area']['content'] = '<h3>no deals found near your location</h3>

  <div>Try increasing the miles and/or changing the location.</div>
  ';
  $handler->display->display_options['empty']['area']['format'] = 'full_html';
  $handler->display->display_options['defaults']['relationships'] = FALSE;
  /* Relationship: Content: gozulla location (field_gozulla_location) */
  $handler->display->display_options['relationships']['field_gozulla_location_nid']['id'] = 'field_gozulla_location_nid';
  $handler->display->display_options['relationships']['field_gozulla_location_nid']['table'] = 'field_data_field_gozulla_location';
  $handler->display->display_options['relationships']['field_gozulla_location_nid']['field'] = 'field_gozulla_location_nid';
  $handler->display->display_options['relationships']['field_gozulla_location_nid']['delta'] = '0';
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title_2']['id'] = 'title_2';
  $handler->display->display_options['fields']['title_2']['table'] = 'node';
  $handler->display->display_options['fields']['title_2']['field'] = 'title';
  $handler->display->display_options['fields']['title_2']['relationship'] = 'reverse_field_gozullalocation_node';
  $handler->display->display_options['fields']['title_2']['label'] = '';
  $handler->display->display_options['fields']['title_2']['element_type'] = 'h2';
  $handler->display->display_options['fields']['title_2']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title_2']['link_to_node'] = FALSE;
  $handler->display->display_options['fields']['title_2']['node_in_colorbox_width'] = '600';
  $handler->display->display_options['fields']['title_2']['node_in_colorbox_height'] = '600';
  /* Field: Content: Details */
  $handler->display->display_options['fields']['field_description']['id'] = 'field_description';
  $handler->display->display_options['fields']['field_description']['table'] = 'field_data_field_description';
  $handler->display->display_options['fields']['field_description']['field'] = 'field_description';
  $handler->display->display_options['fields']['field_description']['relationship'] = 'reverse_field_gozullalocation_node';
  $handler->display->display_options['fields']['field_description']['label'] = '';
  $handler->display->display_options['fields']['field_description']['alter']['nl2br'] = TRUE;
  $handler->display->display_options['fields']['field_description']['element_label_colon'] = FALSE;
  /* Field: expiration date */
  $handler->display->display_options['fields']['field_deal_expiration_date']['id'] = 'field_deal_expiration_date';
  $handler->display->display_options['fields']['field_deal_expiration_date']['table'] = 'field_data_field_deal_expiration_date';
  $handler->display->display_options['fields']['field_deal_expiration_date']['field'] = 'field_deal_expiration_date';
  $handler->display->display_options['fields']['field_deal_expiration_date']['relationship'] = 'reverse_field_gozullalocation_node';
  $handler->display->display_options['fields']['field_deal_expiration_date']['ui_name'] = 'expiration date';
  $handler->display->display_options['fields']['field_deal_expiration_date']['label'] = '';
  $handler->display->display_options['fields']['field_deal_expiration_date']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_deal_expiration_date']['alter']['text'] = 'Expires: [field_deal_expiration_date]';
  $handler->display->display_options['fields']['field_deal_expiration_date']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_deal_expiration_date']['settings'] = array(
    'format_type' => 'm_d_y',
    'fromto' => 'value2',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
  );
  /* Field: Print link */
  $handler->display->display_options['fields']['nid']['id'] = 'nid';
  $handler->display->display_options['fields']['nid']['table'] = 'node';
  $handler->display->display_options['fields']['nid']['field'] = 'nid';
  $handler->display->display_options['fields']['nid']['relationship'] = 'reverse_field_gozullalocation_node';
  $handler->display->display_options['fields']['nid']['ui_name'] = 'Print link';
  $handler->display->display_options['fields']['nid']['label'] = '';
  $handler->display->display_options['fields']['nid']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['nid']['alter']['text'] = 'Print Deal';
  $handler->display->display_options['fields']['nid']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['nid']['alter']['path'] = 'node/[nid]';
  $handler->display->display_options['fields']['nid']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['nid']['node_in_colorbox_width'] = '600';
  $handler->display->display_options['fields']['nid']['node_in_colorbox_height'] = '600';
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['title']['element_type'] = 'h3';
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  /* Field: Field: Address */
  $handler->display->display_options['fields']['field_address']['id'] = 'field_address';
  $handler->display->display_options['fields']['field_address']['table'] = 'field_data_field_address';
  $handler->display->display_options['fields']['field_address']['field'] = 'field_address';
  $handler->display->display_options['fields']['field_address']['label'] = '';
  $handler->display->display_options['fields']['field_address']['alter']['text'] = '[field_address-premise]';
  $handler->display->display_options['fields']['field_address']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_address']['click_sort_column'] = 'country';
  $handler->display->display_options['fields']['field_address']['settings'] = array(
    'use_widget_handlers' => 0,
    'format_handlers' => array(
      'address' => 'address',
      'address-hide-country' => 'address-hide-country',
    ),
  );
  /* Field: Proximity: Distance */
  $handler->display->display_options['fields']['distance']['id'] = 'distance';
  $handler->display->display_options['fields']['distance']['table'] = 'openlayers_proximity';
  $handler->display->display_options['fields']['distance']['field'] = 'distance';
  $handler->display->display_options['fields']['distance']['label'] = '';
  $handler->display->display_options['fields']['distance']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['distance']['hide_empty'] = 1;
  $handler->display->display_options['fields']['distance']['set_precision'] = 1;
  $handler->display->display_options['fields']['distance']['precision'] = '2';
  $handler->display->display_options['fields']['distance']['prefix'] = '~';
  $handler->display->display_options['fields']['distance']['suffix'] = 'miles';
  $handler->display->display_options['fields']['distance']['location_provider'] = 'circle';
  /* Field: Global: Custom text */
  $handler->display->display_options['fields']['nothing']['id'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['table'] = 'views';
  $handler->display->display_options['fields']['nothing']['field'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['label'] = '';
  $handler->display->display_options['fields']['nothing']['alter']['text'] = '&nbsp;';
  $handler->display->display_options['fields']['nothing']['element_class'] = 'clearfix';
  $handler->display->display_options['fields']['nothing']['element_label_colon'] = FALSE;
  /* Field: Content: Edit link */
  $handler->display->display_options['fields']['edit_node']['id'] = 'edit_node';
  $handler->display->display_options['fields']['edit_node']['table'] = 'views_entity_node';
  $handler->display->display_options['fields']['edit_node']['field'] = 'edit_node';
  $handler->display->display_options['fields']['edit_node']['relationship'] = 'reverse_field_gozullalocation_node';
  $handler->display->display_options['fields']['edit_node']['label'] = '';
  $handler->display->display_options['fields']['edit_node']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['edit_node']['text'] = '[ edit deal ]';
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Contextual filter: Content: Sports (field_sport_type) */
  $handler->display->display_options['arguments']['field_sport_type_tid']['id'] = 'field_sport_type_tid';
  $handler->display->display_options['arguments']['field_sport_type_tid']['table'] = 'field_data_field_sport_type';
  $handler->display->display_options['arguments']['field_sport_type_tid']['field'] = 'field_sport_type_tid';
  $handler->display->display_options['arguments']['field_sport_type_tid']['default_action'] = 'default';
  $handler->display->display_options['arguments']['field_sport_type_tid']['default_argument_type'] = 'taxonomy_tid';
  $handler->display->display_options['arguments']['field_sport_type_tid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['field_sport_type_tid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['field_sport_type_tid']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['field_sport_type_tid']['specify_validation'] = TRUE;
  $handler->display->display_options['arguments']['field_sport_type_tid']['validate']['type'] = 'taxonomy_term';
  $handler->display->display_options['arguments']['field_sport_type_tid']['validate_options']['vocabularies'] = array(
    'gozulla_sport' => 'gozulla_sport',
  );
  $handler->display->display_options['arguments']['field_sport_type_tid']['validate_options']['type'] = 'convert';
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
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
    'gozullalocation' => 'gozullalocation',
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
  $handler->display->display_options['filters']['circle']['expose']['use_unit'] = 0;
  $handler->display->display_options['filters']['circle']['expose']['use_location'] = 1;
  $handler->display->display_options['filters']['circle']['expose']['use_node'] = 0;
  /* Filter criterion: Content: Deal active  (field_deal_active_) */
  $handler->display->display_options['filters']['field_deal_active__value']['id'] = 'field_deal_active__value';
  $handler->display->display_options['filters']['field_deal_active__value']['table'] = 'field_data_field_deal_active_';
  $handler->display->display_options['filters']['field_deal_active__value']['field'] = 'field_deal_active__value';
  $handler->display->display_options['filters']['field_deal_active__value']['relationship'] = 'reverse_field_gozullalocation_node';
  $handler->display->display_options['filters']['field_deal_active__value']['value'] = array(
    1 => '1',
  );
  $handler->display->display_options['path'] = 'deals/%';
  $handler->display->display_options['menu']['type'] = 'normal';
  $handler->display->display_options['menu']['title'] = 'deals';
  $handler->display->display_options['menu']['description'] = 'find gozulla deals near you';
  $handler->display->display_options['menu']['weight'] = '10';
  $handler->display->display_options['menu']['name'] = 'menu-sport-links';
  $handler->display->display_options['menu']['context'] = 0;

  /* Display: lodging */
  $handler = $view->new_display('page', 'lodging', 'lodging');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'gozulla lodging';
  $handler->display->display_options['display_description'] = 'gozulla lodging directory';
  $handler->display->display_options['defaults']['hide_admin_links'] = FALSE;
  $handler->display->display_options['exposed_block'] = TRUE;
  $handler->display->display_options['defaults']['header'] = FALSE;
  /* Header: common-links */
  $handler->display->display_options['header']['area']['id'] = 'area';
  $handler->display->display_options['header']['area']['table'] = 'views';
  $handler->display->display_options['header']['area']['field'] = 'area';
  $handler->display->display_options['header']['area']['ui_name'] = 'common-links';
  $handler->display->display_options['header']['area']['empty'] = TRUE;
  $handler->display->display_options['header']['area']['content'] = '<div id="common-links-container">
	<span class="common-links"><a id="shops-link" href="/golf" title="locate gozulla shops">shops</a>
		<span class"link-divider">|</span>
	</span> 
	<span class="common-links"><a id="lodging-link" href="/lodging" title="find gozulla lodging">lodging</a>
		<span class"link-divider">|</span> 
		</span> 
	<span class="common-links"><a id="deals-link" href="/deals/golf" title="find gozulla deals">deals</a></span>
</div>';
  $handler->display->display_options['header']['area']['format'] = 'full_html';
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
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
    'gozullalocation' => 'gozullalocation',
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
  $handler->display->display_options['filters']['circle']['expose']['use_unit'] = 0;
  $handler->display->display_options['filters']['circle']['expose']['use_location'] = 1;
  $handler->display->display_options['filters']['circle']['expose']['use_node'] = 0;
  /* Filter criterion: Content: Business type (field_location_type) */
  $handler->display->display_options['filters']['field_location_type_tid']['id'] = 'field_location_type_tid';
  $handler->display->display_options['filters']['field_location_type_tid']['table'] = 'field_data_field_location_type';
  $handler->display->display_options['filters']['field_location_type_tid']['field'] = 'field_location_type_tid';
  $handler->display->display_options['filters']['field_location_type_tid']['value'] = array(
    0 => '10',
  );
  $handler->display->display_options['filters']['field_location_type_tid']['vocabulary'] = 'company_type';
  $handler->display->display_options['path'] = 'lodging';
  $handler->display->display_options['menu']['type'] = 'normal';
  $handler->display->display_options['menu']['title'] = 'golf';
  $handler->display->display_options['menu']['description'] = 'find golf shops near you';
  $handler->display->display_options['menu']['weight'] = '0';
  $handler->display->display_options['menu']['name'] = 'menu-sport-links';
  $handler->display->display_options['menu']['context'] = 0;
  $translatables['gozulla_directory'] = array(
    t('Master'),
    t('go sport'),
    t('more'),
    t('Apply'),
    t('Find Me'),
    t('Sort by'),
    t('Asc'),
    t('Desc'),
    t('Items per page'),
    t('- All -'),
    t('Offset'),
    t('« first'),
    t('‹ previous'),
    t('next ›'),
    t('last »'),
    t('<div id="common-links-container">
	<span class="common-links"><a id="shops-link" href="/" title="locate gozulla shops">shops</a>
		<span class"link-divider">|</span>
	</span> 
	<span class="common-links"><a id="lodging-link" href="/lodging" title="find gozulla lodging">lodging</a>
		<span class"link-divider">|</span> 
		</span> 
	<span class="common-links"><a id="deals-link" href="/deals/" title="find gozulla deals">deals</a></span>
</div>'),
    t('DEAL$'),
    t('.'),
    t(','),
    t('[ edit ]'),
    t('All'),
    t('surf'),
    t('go surf'),
    t('gozulla surf directory'),
    t('<div id="common-links-container">
	<span class="common-links"><a id="shops-link" href="/surf" title="locate gozulla shops">shops</a>
		<span class"link-divider">|</span>
	</span> 
	<span class="common-links"><a id="lodging-link" href="/lodging" title="find gozulla lodging">lodging</a>
		<span class"link-divider">|</span> 
		</span> 
	<span class="common-links"><a id="deals-link" href="/deals/surf" title="find gozulla deals">deals</a></span>
</div>'),
    t('skate'),
    t('go skate'),
    t('gozulla skate directory'),
    t('<div id="common-links-container">
	<span class="common-links"><a id="shops-link" href="/skate" title="locate gozulla shops">shops</a>
		<span class"link-divider">|</span>
	</span> 
	<span class="common-links"><a id="lodging-link" href="/lodging" title="find gozulla lodging">lodging</a>
		<span class"link-divider">|</span> 
		</span> 
	<span class="common-links"><a id="deals-link" href="/deals/skate" title="find gozulla deals">deals</a></span>
</div>'),
    t('geofield map'),
    t('[title] 
  [field_address]'),
    t('~'),
    t('miles'),
    t('Geofield'),
    t('featured shop'),
    t('one hot shop'),
    t('Displays random gozulla location'),
    t('snow'),
    t('go snow'),
    t('gozulla snow directory'),
    t('<div id="common-links-container">
	<span class="common-links"><a id="shops-link" href="/snow" title="locate gozulla shops">shops</a>
		<span class"link-divider">|</span>
	</span> 
	<span class="common-links"><a id="lodging-link" href="/lodging" title="find gozulla lodging">lodging</a>
		<span class"link-divider">|</span> 
		</span> 
	<span class="common-links"><a id="deals-link" href="/deals/snow" title="find gozulla deals">deals</a></span>
</div>'),
    t('bike'),
    t('go bike'),
    t('gozulla bike directory'),
    t('<div id="common-links-container">
	<span class="common-links"><a id="shops-link" href="/bike" title="locate gozulla shops">shops</a>
		<span class"link-divider">|</span>
	</span> 
	<span class="common-links"><a id="lodging-link" href="/lodging" title="find gozulla lodging">lodging</a>
		<span class"link-divider">|</span> 
		</span> 
	<span class="common-links"><a id="deals-link" href="/deals/bike" title="find gozulla deals">deals</a></span>
</div>'),
    t('climb'),
    t('go climb'),
    t('gozulla climb directory'),
    t('<div id="common-links-container">
	<span class="common-links"><a id="shops-link" href="/climb" title="locate gozulla shops">shops</a>
		<span class"link-divider">|</span>
	</span> 
	<span class="common-links"><a id="lodging-link" href="/lodging" title="find gozulla lodging">lodging</a>
		<span class"link-divider">|</span> 
		</span> 
	<span class="common-links"><a id="deals-link" href="/deals/climb" title="find gozulla deals">deals</a></span>
</div>'),
    t('boat'),
    t('go boat'),
    t('gozulla boat directory'),
    t('<div id="common-links-container">
	<span class="common-links"><a id="shops-link" href="/boat" title="locate gozulla shops">shops</a>
		<span class"link-divider">|</span>
	</span> 
	<span class="common-links"><a id="lodging-link" href="/lodging" title="find gozulla lodging">lodging</a>
		<span class"link-divider">|</span> 
		</span> 
	<span class="common-links"><a id="deals-link" href="/deals/boat" title="find gozulla deals">deals</a></span>
</div>'),
    t('golf'),
    t('go golf'),
    t('gozulla golf directory'),
    t('<div id="common-links-container">
	<span class="common-links"><a id="shops-link" href="/golf" title="locate gozulla shops">shops</a>
		<span class"link-divider">|</span>
	</span> 
	<span class="common-links"><a id="lodging-link" href="/lodging" title="find gozulla lodging">lodging</a>
		<span class"link-divider">|</span> 
		</span> 
	<span class="common-links"><a id="deals-link" href="/deals/golf" title="find gozulla deals">deals</a></span>
</div>'),
    t('deals'),
    t('gozulla deals'),
    t('displays gozulla deals by proximity and/or sports'),
    t('<h3>no deals found near your location</h3>

  <div>Try increasing the miles and/or changing the location.</div>
  '),
    t('field_gozulla_location'),
    t('[field_address-premise]'),
    t('&nbsp;'),
    t('[ edit deal ]'),
    t('deals by sport'),
    t('displays gozulla deals by proximity and sport'),
    t('<div id="common-links-container">
	<span class="common-links sport"><a id="shops-link" href="/%1" title="locate gozulla shops">shops</a>
		<span class"link-spander">|</span>
	</span> 
	<span class="common-links lodging">lodging
		<span class"link-spander">|</span> 
		</span> 
	<span class="common-links deal clearfix"><a id="deals-link" href="/deals/%1" title="find gozulla deals">deals</a></span>
</div>'),
    t('Expires: [field_deal_expiration_date]'),
    t('Print Deal'),
    t('lodging'),
    t('gozulla lodging'),
    t('gozulla lodging directory'),
  );
  $export['gozulla_directory'] = $view;

  return $export;
}
