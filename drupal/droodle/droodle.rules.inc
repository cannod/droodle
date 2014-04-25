<?php

function droodle_rules_action_info() {
  $actions = array(
    // The base-level keys in the array are the machine names for the actions,
    // and by default also the function name for the action callback. Prefix
    // with your module name to avoid name conflicts.

	'droodle_action_create_update_user' => array(
      'label' => t('Create or Update Moodle user'),
      'group' => t('Droodle'),
      // When declaring parameters, site builders will by default get a form to
      // select fitting data. In this case, we require the site builder to
      // select a user object. The 'type' could be any data type known to Rules,
      // which means any entity type known to Entity API or any additional data
      // type declared by hook_rules_data_info – by default including things
      // like 'integer', 'text' and more. See
      'parameter' => array(
        // Each parameter is keyed with an internally used machine name.
        'account' => array(
          'type' => 'user',
          'label' => t('The user to create'),
          // If we were to make changes to the parameter object, whe should set
          // the 'save' property to TRUE. This makes Rules handle the saving in
          // a more optimized way than if each action saved the objects.
          // 'save' => TRUE,
        ),
        'firstname' => array(
          'type' => 'text',
          'label' => t('The users firstname'),
        ),
        'lastname' => array(
          'type' => 'text',
          'label' => t('The users lastname'),
        ),
      ),
    ),
	'droodle_action_delete_user' => array(
      'label' => t('Delete a Moodle user'),
      'group' => t('Droodle'),
      // When declaring parameters, site builders will by default get a form to
      // select fitting data. In this case, we require the site builder to
      // select a user object. The 'type' could be any data type known to Rules,
      // which means any entity type known to Entity API or any additional data
      // type declared by hook_rules_data_info – by default including things
      // like 'integer', 'text' and more. See
      'parameter' => array(
        // Each parameter is keyed with an internally used machine name.
        'account' => array(
          'type' => 'user',
          'label' => t('The user to delete'),
          // If we were to make changes to the parameter object, whe should set
          // the 'save' property to TRUE. This makes Rules handle the saving in
          // a more optimized way than if each action saved the objects.
          // 'save' => TRUE,
        ),
      ),
    ),
	'droodle_action_enrol_user' => array(
      'label' => t('Enrol user into Moodle courses'),
      'group' => t('Droodle'),
      // When declaring parameters, site builders will by default get a form to
      // select fitting data. In this case, we require the site builder to
      // select a user object. The 'type' could be any data type known to Rules,
      // which means any entity type known to Entity API or any additional data
      // type declared by hook_rules_data_info – by default including things
      // like 'integer', 'text' and more. See
      'parameter' => array(
        // Each parameter is keyed with an internally used machine name.
        'account' => array(
          'type' => 'user',
          'label' => t('The user to be enrolled'),
          // If we were to make changes to the parameter object, whe should set
          // the 'save' property to TRUE. This makes Rules handle the saving in
          // a more optimized way than if each action saved the objects.
          // 'save' => TRUE,
        ),
        'course_id' => array(
          'type' => 'text',
          'label' => t('The Moodle course ID number'),
          // If we were to make changes to the parameter object, whe should set
          // the 'save' property to TRUE. This makes Rules handle the saving in
          // a more optimized way than if each action saved the objects.
          // 'save' => TRUE,
        ),
        'time_start' => array(
          'type' => 'date',
          'label' => t('The Enrolment start date'),
          'optional' => TRUE,
          // If we were to make changes to the parameter object, whe should set
          // the 'save' property to TRUE. This makes Rules handle the saving in
          // a more optimized way than if each action saved the objects.
          // 'save' => TRUE,
        ),
        'time_end' => array(
          'type' => 'date',
          'label' => t('The Enrolment end date'),
          'optional' => TRUE,
          // If we were to make changes to the parameter object, whe should set
          // the 'save' property to TRUE. This makes Rules handle the saving in
          // a more optimized way than if each action saved the objects.
          // 'save' => TRUE,
        ),
      ),
    ),
  );

  return $actions;
}

/**
 * The action function for the 'droodle_action_create_update_user'.
 *
 * The $account parameter is the user object sent into this action, selected in
 * the Rules configuration interface.
 * @param <object> $account
 *   The user object to work with. Selected by the site administrator when the
 *   action is configured.
 */
function droodle_action_create_update_user($account, $firstname, $lastname) {

	droodle_create_update_user($account, $firstname, $lastname);
}

/**
 * The action function for the 'droodle_action_create_update_user'.
 *
 * The $account parameter is the user object sent into this action, selected in
 * the Rules configuration interface.
 * @param <object> $account
 *   The user object to work with. Selected by the site administrator when the
 *   action is configured.
 */
function droodle_action_delete_user($account) {

	droodle_delete_user($account);
}


/**
 * The action function for the 'droodle_action_enrol_user'.
 *
 * The $account parameter is the user object sent into this action, selected in
 * the Rules configuration interface.
 * @param <object> $account
 *   The user object to work with. Selected by the site administrator when the
 *   action is configured.
 */
function droodle_action_enrol_user($account, $course_id, $time_start, $time_end) {

  droodle_enrol_user($account, $course_id, $time_start, $time_end);

}