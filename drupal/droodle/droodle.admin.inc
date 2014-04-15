<?php

/*
 * @file Admin Settings for Moodle Webservices
 * 
 */


function droodle_admin_settings() {

  $form = array();
  
  $form['droodle_token'] = array(
    '#type' => 'textfield',
    '#default_value' => variable_get('droodle_token', ''),
    '#description' => 'Please Enter your Moodle token.',
    '#title' => 'Token',
    '#required' => TRUE,
  );
  
  $form['droodle_fqdn'] = array(
    '#type' => 'textfield',
    '#default_value' => variable_get('droodle_fqdn', ''),
    '#description' => 'Fully qualified domain name. For example, ("https://moodle.com/").',
    '#title' => 'FQDN',
    '#required' => TRUE,
  );
  
  $form['droodle_service_endpoint'] = array(
    '#type' => 'textfield',
    '#default_value' => variable_get('droodle_service_endpoint', 'webservice/rest/server.php'),
    '#description' => 'Please enter the service endpoint. For example, ("webservice/rest/server.php").',
    '#title' => 'Service Endpoint',
    '#required' => TRUE,
  );
  
  $form['droodle_format'] = array(
    '#type' => 'textfield',
    '#default_value' => variable_get('droodle_format', 'json'),
    '#description' => 'Please enter the required response format. Either, ("json" or "xml").',
    '#title' => 'Respose Format',
    '#required' => TRUE,
  );

  $form['droodle_authtype'] = array(
    '#type' => 'textfield',
    '#default_value' => variable_get('droodle_authtype', 'manual'),
    '#description' => 'Please enter the Moodle user authentication type.',
    '#title' => 'Moodle user auth type',
    '#required' => TRUE,
  );
  
  return system_settings_form($form);
}

