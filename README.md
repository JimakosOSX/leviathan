# Ansible role to set-up an Ubuntu mail server
Automating the installation of a mail server using Ubuntu 22.04

## Dependencies
Run

`ansible-galaxy collection install geerlingguy.mysql`

Fill `vars/main.yml` with your own credentials.

Fill `test/inventory` with the desired server.

Run `test/test.yml`.

## Tools
Ansible

Postfix, Dovecot, MariaDB, Let's Encrypt, Apache


## Information
Testing this on Debian 11 x64.

Status: Working ✅ 

TODO 📝

1. DKIM intergration
2. Check if let's Encrypt uses the same www_fqdn or simply fqdn.
3. Restore backup (tarball) if present on test folder.
