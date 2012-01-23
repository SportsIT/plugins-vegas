<?php
/**
 * Sports IT Integration Module Administration
 * 
 * Administration settings for Sports IT Integration
 *  
 */

/**
 * Administration Form
 * 
 * @return type 
 */
function sportsit_admin_form() {
  $form = array();
  $form['sportsit_api_key'] = array(
    '#type' => 'textfield',
    '#title' => t('Api Key'),
    '#description' => t('Your Sports IT API key.'),
    '#default_value' => variable_get('sportsit_api_key', ''),
  );
  $form['sportsit_company'] = array(
    '#type' => 'textfield',
    '#title' => t('Company'),
    '#description' => t('Write in here the company name you use to log in to sports it.'),
    '#default_value' => variable_get('sportsit_company', ''),
  );
  $form['sportsit_facility_id'] = array(
    '#type' => 'textfield',
    '#title' => t('Facility ID'),
    '#default_value' => variable_get('sportsit_facility_id', ''),
  );
  
            
  return system_settings_form($form);
}

/**
 * Validate Sports IT Credentials before saving changes.
 * 
 */
function sportsit_admin_form_validate($form, &$form_state) {
  $options = array(
        'X_SIT_APIKEY' => $form_state['values']['sportsit_api_key'],
        'X_SIT_CC' => $form_state['values']['sportsit_company'],
        'facilityID' => $form_state['values']['sportsit_facility_id'],

        'start' => '2012-01-01',
        'end' => '2012-01-01',
      );
  $res = sportsit_query($options, TRUE);
  if($res->code != 200) {
    form_set_error('sportsit_api_key', 'Error: ' . $res->status_message);
  }
  else {
    drupal_set_message(t('Sports IT API Key is working.'));
  }
}