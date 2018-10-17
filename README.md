# Password-Generator
Simple password generator for those who don't trust password managers and are able to remember several keywords

Features: generates secure password by hashing various keywords with settings user chooses. Password is unique to 
settings/keyword combination, valid for almost all password requirements, and not susceptible to dictionary/brute force attacks.

On first use, initialize the settings to user's own preferences. From there, when need to enter a password, simply generate a 
password using the script, remember those keywords, and generate the password using the memorized (or saved) keywords when needed.

Keywords can either be a sentence, paragraph, or a random string of keywords.

Setup: 
```
~$ chmod 755 pw_generator.py
```

Usage:
```
~$ ./pw_generator.py salt pepper cumin
~$ E!00670!d05a75@a

~$ ./pw_generator.py these are the keywords to my github account -not really
~$ !4AEFF6!0@1!ae@6

~$ ./pw_generator.py As Gregor Samsa awoke one morning from uneasy dreams he found himself transformed in his bed into a monstrous vermin
~$ 5746A9B!3b3830@3
```


