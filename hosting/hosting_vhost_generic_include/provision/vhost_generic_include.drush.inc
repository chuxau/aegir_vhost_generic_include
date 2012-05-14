<?php
/**
 * @file
 * Implement drush service to amend apache config file
 *
 * a bit of a hack. this active version is for aegir
 * in a ~/.drush context include_once(dirname(__FILE__) . '/../provision.service.inc');
 */

include_once('/var/aegir/.drush/provision/provision.service.inc');

/**
 * Expose the service type this extension defines to provision.
 *
 * @return
 *   An array with the service type the key, and the default implementation the value.
 */
function vhost_generic_include_provision_services() {
  return array('vhost_generic_include' => NULL);
}

/**
 * The subfolder service base class.
 */
class provisionService_vhost_generic_include extends provisionService {
  public $service = 'vhost_generic_include';

  /**
   * Add the subfolder_path property to the site context.
   */
  static function subscribe_site($context) {
    $context->setProperty('vhost_generic_include_content');
  }
}


/*
 * Implementation of hook_provision_apache_vhost_config()
 */
function vhost_generic_include_provision_apache_vhost_config($uri, $data) {
  $lines = array();
  $content = d()->vhost_generic_include_content;

  $lines[] = "## muu";
  if (!empty($content)) {
    // Now add config to the vhost:
    $root = d()->root;
    $lines[] = "$content";
  }

  return implode("\n", $lines);
}
/*
 * Implementation of !FIX ME hook_provision_nginx_vhost_config()
 */
/*
function vhost_generic_include_provision_nginx_vhost_config($uri, $data) {
  $lines = array();
  $content = d()->vhost_generic_include_content;

  if (!empty($content)) {
    // Create the password file.
    $path = _vhost_generic_include_create_file($uri, $data, $server, $require);

    // Now add the file to the vhost:
    $root = d()->root;
    $lines[] = "";
  }

  return implode("\n", $lines);
}
*/
