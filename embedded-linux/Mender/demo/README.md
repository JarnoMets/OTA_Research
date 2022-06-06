Requirements: Embedded Linux device with internet access.

First and foremost, a Mender account must be created (https://hosted.mender.io/ui/#/signup). Mender offers a 1-year trial period where you can manage and update up to 10 devices. This is sufficient for what I do during the internship.

The next step is to download the Mender Client on your device. I am now doing this on an RPI4B running an embedded Debian.  
On Mender's site you get a prepared package of commands that are simple to execute.
For example:
<span style="color:gray;font-size:50%">JWT_TOKEN="eyJhbGciOiJSUzI1NiIsInR5cCI6IkpXVCJ9.eyJqdGkiOiIyM2U5NGQ5ZC0wOTQ1LTRlODMtYWUwYy1hZjYxZTgwNDIxMmEiLCJzdWIiOiIzNjdmMjQ1NC1hMjEyLTVhMWMtYjhlOC00NjlkMWIzOWE2ZmMiLCJleHAiOjE2NTM0OTYxNjEsImlhdCI6MTY1Mjg5MTM2MSwibWVuZGVyLnRlbmFudCI6IjYyMjliZmY3MTliNmFiMDRkOGFlMGEzZCIsIm1lbmRlci51c2VyIjp0cnVlLCJpc3MiOiJNZW5kZXIgVXNlcnMiLCJzY3AiOiJtZW5kZXIuKiIsIm1lbmRlci5wbGFuIjoiZW50ZXJwcmlzZSIsIm1lbmRlci50cmlhbCI6dHJ1ZSwibWVuZGVyLmFkZG9ucyI6W3sibmFtZSI6ImNvbmZpZ3VyZSIsImVuYWJsZWQiOnRydWV9LHsibmFtZSI6InRyb3VibGVzaG9vdCIsImVuYWJsZWQiOnRydWV9LHsibmFtZSI6Im1vbml0b3IiLCJlbmFibGVkIjp0cnVlfV0sIm5iZiI6MTY1Mjg5MTM2MX0.wpUYN98jPD27X712soe7Srira8Ss0RAwjLYOX3KmURukfMWHM4PWv9vkIyIQwQywRV0uJe1e_PCHlCFUYHjus0ob5n3DE7roxlv3d35L26cPp6pFf85F84k3X9B0KimLaqSGk8gfK7kbaHr0ItKuzROnod41B87jsrbmbfRgiUAqm2aOsI6VRK0d4pkb_lbv2CG91jyJnZLKu6cAdVR6oZ0La4217fWuoTHlQg8iZihBlikLKJxZK5tC--k7d1SC_QHa28GK0Kh3voNFN5XmovHqYxr2HyaX_Hx1gMP83cCo2DLqn3iIdJ0ALZ6e4B4jzk838_0QF--6-Z9SvROxwJ1ghUyuHRHhLSA4juHCU6giPqG-3UQ4jLFZNQqnBcSYOlUg6t3peXb5RLRnjmx1hLZS5eXIlObHQa1ICNDzrxgsZ0-aX22S-BIPiNmZDY6Z7jWKCSwzYYXiKL_RbYlhKAomQ9dpxhClH1g_iGCQPJITwlbDx1RJQTNHG1DO0B8" TENANT_TOKEN="eyJhbGciOiJSUzI1NiIsInR5cCI6IkpXVCJ9.eyJtZW5kZXIudGVuYW50IjoiNjIyOWJmZjcxOWI2YWIwNGQ4YWUwYTNkIiwiaXNzIjoiTWVuZGVyIiwic3ViIjoiNjIyOWJmZjcxOWI2YWIwNGQ4YWUwYTNkIn0.d_WpTLZuLZpSsrAm1LatHdUTo_ZrG7LqXSJGVoZppkLI-A_HV0fP-RqK-z7dy1QKqfp6n74N5F8OM_4yLeGmgyWUJr3AcS8pEUB-_mkc3f1FMVrONj_qvgU6f3-uvYbxpKguY2UiI8g9AmPy95ST-DhldKSLM7PFVll5uVntn2OZhFUL43C3n4dDOPNp_8OKEvXrYcmPjeSvUZ2f6cSXg12_4kpqsEZxs4YovlD_fDw9e67tUoDL5-BHvLNVI6nQVIRUCoJNDwH5QiZzad9KiFUxoWPC-19seXnBcWqgddAHhJoSPQgVSFBtqjbq2vIQQyh1KkGZB3XVHfOeMDltbR5OvzgAqtH00d5AOpWrrqCdxUgYrARWDpFarTNmu2tI174I9GFS9_r_QSwqTd_SeR_CKpF5vXX4tZ0Y1F2MNDd9NOTwRrEWr3f8aYxAwRxevEUJ9V4BYRyu87SCfAGTgHi6wexUyFHXigeZ7JWnjKhKH5xvxoBsli7h4GlYQFhA" wget -O- https://get.mender.io | sudo bash -s -- --demo --commercial --jwt-token $JWT_TOKEN -- --quiet --apparaat-type "raspberrypi4" --tenant-token $TENANT_TOKEN --retry-poll 300 --update-poll 1800 --inventory-poll 28800 --hosted-mender</span>

This installs the entire client and configures the platform, the token, the poll speed etc. It is of course possible to do this step by step or to adjust the settings after installation.  
View on the device:    
![](Assets/Imgs/1.png)  

---

![](Assets/Imgs/2.png)  
After installation, the Mender client will automatically try to connect to the server.
When accepted, it will appear on your dashboard. If you click on this you will get more information about the device, you can start a remote ssh session or perform a software deployment.
![](Assets/Imgs/3.png)  
![](Assets/Imgs/4.png)  