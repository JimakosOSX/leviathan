# Ansible roles to set-up a Linux mail server


## Dependencies

Copy `vars/main.yml.example` to `vars/main.yml` to use your own credentials.

Fill `inventory` with the desired server.

Install geerlinyguy's MySQL role `ansible-galaxy install geerlingguy.mysql`

Run `test.yml`.

If you use ZeroTier, after setting everything up, change your `inventory` to point to the internal one.

## Current Feautures

- Postfix 📤 sending
- Dovecot 📩 receiving + 📬 local mail
- MySQL   🐿️ Keeping e-mail addresses, aliases, domains
- Let's Encrypt 🔐 TLS/SSL free certificate
- OpenDKIM 🗝️ Easy monthly key rotation - just re-run the role
- OpenDMARC 👻 Ignores checks for outgoing e-mails 
- Firewalld 🔥🧱 restricting un-needed network traffic
- Zerotier 🗿 Free VPN tunnel - optional role


## Information
Testing this on Ubuntu 22.04.1 LTS (Digital Ocean Droplet)

TODO 📝

1. Add Apache installation (with file placement)
2. Add GitHub CI configuration


## Notes on DNS Setup
I usually have no problems with the following DNS setup;

- A record from www.FQDN pointing to IP address
- A record from FQDN pointing to IP address
- A record from mail.FQDN pointing to IP address
- TXT record from FQDN with value "v=spf1 a ~all"
- MX record showing mails should be handled by FQDN 
- MX record showing mails for mail.FQDN should be handled by FQDN 
- TXT record from \_dmarc.FQDN with value "v=DMARC1; p=reject; rua=mailto:webadmin@FQDN"
- TXT record based on mail.txt file (check the mail.txt file after running)
- PTR record (Digital Ocean does it automatically if you use FQDN as Droplet name)


## Scores / Improvements
Mail tester shows a 9.5 / 10 score with this configuration 🤩
https://www.mail-tester.com/test-a53q6owhm
