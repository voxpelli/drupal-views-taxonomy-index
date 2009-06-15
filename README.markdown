Drupal module that provides a taxonomy index for Views.

To use with other handlers than taxonomy_term you have to set the property "viewstaxonomyindex_indexable" to tell that you want an index created - the data will then be fetched from either the "validate_argument_vocabulary" option or from a previous vocabulary argument.

You can also set "viewstaxonomyindex_term_name" if you want the term name to be used as the argument instead of the term id.

Example:

    <?php
    function foo_views_plugins() {
      return array(
        'argument validator' => array(
          'foo_taxonomy_term' => array(
            'title'   => t('Taxonomy term (Foo)'),
            'handler' => 'foo_views_plugin_argument_validate_taxonomy_term',
            'path'    => drupal_get_path('module', 'foo') . '/includes',
            'viewstaxonomyindex_indexable' => TRUE,
            'viewstaxonomyindex_term_name' => TRUE,
          ),
        ),
      );
    }