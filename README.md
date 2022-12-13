# Ansible roles to set-up a Linux mail server


## Dependencies

Fill `vars/main.yml` with your own credentials.

Fill `test/inventory` with the desired server.

Run `test/test.yml`.

If you want ZeroTier, after running the ansible roles, reload firewalld (`firewall-cmd --reload`) and change your `test/inventory` address to point to the internal one.

## Tools
Ansible

Postfix, Dovecot, MariaDB, Let's Encrypt, Apache


## Information
Testing this on Ubuntu (Always Free tier VM on Oracle Cloud)

TODO 📝

1. DKIM intergration ✅
2. DMARC intergration 
3. Add Apache installtion (with file placement)
4. Add zerotier-one role ✅
5. Add GitHub CI configuration
