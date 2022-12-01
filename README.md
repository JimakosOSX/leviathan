# Ansible role to set-up an Ubuntu mail server
Automating the installation of a mail server using Ubuntu 22.04

## Dependencies
Run

`ansible-galaxy collection install geerlingguy.mysql`


## Tools
Ansible

Postfix, Dovecot, MariaDB, Let's Encrypt, Apache


## Information
Testing this on Debian 11 x64.

Status: Working ✅ 

TODO 

1. DKIM intergration
2. Check if let's Encrypt uses the same www_fqdn or simply fqdn.
