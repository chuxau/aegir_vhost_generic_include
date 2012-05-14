<?php

/**
 * @file
 * hosting_vhost_generic_include drush context functions 
 *
 */

/**
 * Implementation of hook_hosting_site_context_options().
 */
function hosting_vhost_generic_include_hosting_site_context_options(&$task) {
  if (isset($task->ref->vhost_generic_include_content) && !empty($task->ref->vhost_generic_include_content)) {
    $task->context_options['vhost_generic_include_content'] = $task->ref->vhost_generic_include_content;
  }
  else {
    $task->context_options['vhost_generic_include_content'] = 'null';
  }
}

/**
 * Implementation of hook_drush_context_import().
 */
function hosting_vhost_generic_include_drush_context_import($context, &$node) {
  if ($context->type == 'site') {
    if (isset($context->vhost_generic_include_content) && !empty($context->vhost_generic_include_content)) {
      $node->vhost_generic_include_content = $context->vhost_generic_include_content;
    }
  }

}

