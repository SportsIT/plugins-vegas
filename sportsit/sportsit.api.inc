<?php
/**
 * Sports IT Api for Drupal
 * Implements and integrates sports IT API calls.
 * 
 * @copyright 2012 Triple Smart
 * @author Lucas S. Caro <lucas@triplesmart.com>
 * @license Licensed under the terms of the GNU Lesser General Public License:
 *      http://www.opensource.org/licenses/lgpl-license.php
 * 
 */


defined('SPORTSIT_API_URL') or define('SPORTSIT_API_URL', 'http://test.sports-it.com/beta/api/');

/**
 * Queries sports it facility api
 * 
 * @param array $options
 * @return type 
 */
function sportsit_query($options = array(), $reset = FALSE) {
  static $static_cache = array();
  $hash = _sportsit_hash($options);
  if (!isset($static_cache[$hash]) || $reset) {
    if (!$reset && ($cache = cache_get('sportsit_data.'.$hash)) && !empty($cache)) {
      $static_cache[$hash] = $cache->data;
    }
    else {
      $query_url = SPORTSIT_API_URL . 'event/search';
      $defaults = array(
        'X_SIT_APIKEY' => variable_get('sportsit_api_key', ''),
        'X_SIT_CC' => variable_get('sportsit_company', 'aviator'),
        'facilityID' => variable_get('sportsit_facility_id', ''),

        'start' => '2012-01-01',
        'end' => '2012-02-01',
      );

      $query = array_merge($defaults, $options);

      $query_url_full = url($query_url, array('query' => $query));

      $res = drupal_http_request($query_url_full, array(), 'GET');
      $static_cache[$hash] = $res;
      cache_set('sportsit_data.' . $hash, $res,'cache', CACHE_TEMPORARY);
    }
  }
  return $static_cache[$hash];
}

function _sportsit_hash($array) {
  $hash = md5(serialize($array));
  if($hash == NULL) {
    $hash = '';
  }
  return $hash;
}

function sportsit_format_date($timestamp) {
  return date('Y-m-d', $timestamp);
}
