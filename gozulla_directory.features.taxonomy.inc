<?php
/**
 * @file
 * gozulla_directory.features.taxonomy.inc
 */

/**
 * Implements hook_taxonomy_default_vocabularies().
 */
function gozulla_directory_taxonomy_default_vocabularies() {
  return array(
    'gozulla_sport' => array(
      'name' => 'gozulla sport',
      'machine_name' => 'gozulla_sport',
      'description' => 'used to determine what to display',
      'hierarchy' => '0',
      'module' => 'taxonomy',
      'weight' => '0',
      'rdf_mapping' => array(
        'rdftype' => array(
          0 => 'skos:ConceptScheme',
        ),
        'name' => array(
          'predicates' => array(
            0 => 'dc:title',
          ),
        ),
        'description' => array(
          'predicates' => array(
            0 => 'rdfs:comment',
          ),
        ),
      ),
    ),
  );
}
