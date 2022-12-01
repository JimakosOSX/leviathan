# Ansible roles to set-up a Linux mail server
Automating the installation of a mail server
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
