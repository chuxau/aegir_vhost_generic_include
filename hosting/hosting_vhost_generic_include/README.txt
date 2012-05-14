Aegir HTTP Virtual Server Include 
===============================

Introduction
------------

This is a simple module and drush script for Aegir that allows you to specify 
a block of data to include in the aegir generated config. 

Ends up adding stanzas to the vhost conf something like
<pre>
 <Directory /siteroot>

 "Your string Here"
 </Directory>
</pre>


Installation
------------

The following installation of the code included is being used with Aegir 1.7 
installed from debian packages with drush 4.4. Documentation at 
http://community.aegirproject.org/installing

There are two parts to the code:
- A Drupal module for hostmaster - contained in the /hosting directory. Install
  this like any other Drupal module into you hostmaster site. (ie.
  /var/aegir/hostmaster-6/sites/all/modules.)

- A provision Drush script - contained in the /provision directory. Copy this
  into /var/aegir/.drush/provision/vhost_generic_include.drush.inc on your 
  Aegir master server.

Now just enable the module in the Aegir frontend, and you're ready to go.


Usage
-----

When creating or editing a site, you can optionally add a
a new line of apache config directives (of the sort that appear in Directory
blocks). Leaving this blank will do nothing, but if they are filled in then those 
lines will be inserted.
