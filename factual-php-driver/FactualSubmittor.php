<?php
/**
 * Factual Submittor vars collector
 * @author Tyler
 * @package Factual
 * @license Apache 2.0
 */
 require_once("FactualPost.php");
 class FactualSubmittor extends FactualPost{
	//Required Params
	public $values = array();   //values to be added/updated
		
	/**
	 * Sets Factual ID for entity updates
	 * @return string the Factual ID
	 * 
	 */
	public function setFactualID($var){
		parent::setFactualID($var);
 		$this->setValue("factual_id",$var); //also add this as a value to the post array
 		return $this->factualID;
 	} 		
	
	/**
	 * Gets the object vars required for POST
	 * @return array
	 */
 	protected function getPostVars(){
 		return array_merge(parent::getPostVars(),array("values"));
 	}
 		
 	/**
 	 * Checks whether required params are included before writing
 	 * @return bool
 	 */
 	public function isValid(){
 		if (empty($this->tableName)| empty($this->user)|empty($this->values)){
 			return false;
 		} else {
 			return true;
 		}	
 	}
 	
 	/**
 	 * Adds key/value pairs to object
 	 * @param string key Field/Column name
 	 * @param mixed value Value to add/edit/update
 	 * @return array set values
 	 */
 	public function setValue($key,$value){
 		$this->values[$key] = $value;
 		return $this->values;
 	}
 }
?>
