Custom Client
===
Kathy Liu and Jonah Winchell

---
Overview
---
This script acts as a very simple client, in the vein of `curl`.    

---
To compile, run:   
`gcc -o client client.c dns.c`   
Run the script with:   
`./client`   

The program will ask for you to input a domain name, enter the name
in this format:   
`www.website.com`   

The client will display the HTTP header of the host's reply.
In addition, the client will print the raw HTML contents of the site,
if present. Most likely you will be given a `301` or `302` error
as our client does not currently support TLS encryption, as needed
with many modern web applications.

---

For questions/concerns/comments, please email `jwinchell@oxy.edu`.
