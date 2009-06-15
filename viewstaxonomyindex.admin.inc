<?php
// $Id$

/**
 * @file
 * Administration of the settings for the views taxonomy index functionality
 */

/**
 * Menu callback: settings form.
 */
function viewstaxonomyindex_admin_settings_form() {
  $form  = array();
  $views = views_get_all_views();

  $options = array();

  foreach ($views as $main_key => $view) {
    $options[$main_key] = array();
    foreach ($view->display as $sub_key => $display) {
      $options[$view->name][$sub_key] = $display->display_title;
    }
    $form['viewstaxonomyindex_views_'. $main_key] = array(
      '#type'          => 'checkboxes',
      '#title'         => t('Apply to @title', array('@title' => $view->name)),
      '#default_value' => variable_get('viewstaxonomyindex_views_'. $main_key, array()),
      '#description'   => t('Choose which views should have a taxonomy index attached to it.'),
      '#options'       => $options[$main_key],
    );
  }

  return system_settings_form($form);
}