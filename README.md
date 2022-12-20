# Ansible roles to set-up a Linux mail server


## Dependencies

Fill `vars/main.yml` with your own credentials.

Fill `test/inventory` with the desired server.

Run `test/test.yml`.

If you want ZeroTier, after setting everything up, change your `test/inventory` address to point to the internal one.

## Current Feautures

Postfix, Dovecot, MySQL, Let's Encrypt, OpenDKIM, Firewalld, Zerotier (optional)


## Information
Testing this on Ubuntu 22.04.1 LTS (Digital Ocean Droplet)

TODO 📝

1. DMARC intergration 
2. Add Apache installtion (with file placement)
3. Add GitHub CI configuration


## Notes on DNS Setup
I usually have no problems with the following DNS setup;

- A record from www.FQDN pointing to IP address
- A record from FQDN pointing to IP address
- A record from mail.FQDN pointing to IP address
- TXT record from FQDN with value "v=spf1 a ~all"
- MX record showing mails should be handled by FQDN 
- MX record showing mails for mail.FQDN should be handled by FQDN 
- TXT record from \_dmarc.FQDN with value "v=DMARC1; p=reject; rua=mailto:webadmin@FQDN"
- TXT record based on mail.txt file (mail selector is used on DKIM so hostname mail._domainkey.FQDN and value based on the txt file should work)
- PTR record (Digital Ocean does it automatically if you use FQDN as Droplet name)
