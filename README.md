# Ansible roles to set-up a Linux mail server


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

TODO 📝

1. DKIM intergration
2. Restore backup (tarball) if present on test folder.
3. DMARC intergration 
4. Add Apache installtion (with file placement)
5. Add GitHub CI configuration
