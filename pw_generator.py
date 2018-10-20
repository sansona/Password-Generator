#!/usr/bin/python3

#------------------------------------------------------------------------------
# simple script to generate secure password from keywords. Useful for those
# who want a password that's not susceptible to dictionary attack, don't trust
# password managers, and/or prefer to memorize several short strings instead
# of a password
#
# python implementation
# Usage: ./pw_generator.py hello entire world
#------------------------------------------------------------------------------

import sys
import hashlib

# settings for each user to better randomize & personalize hash results
PW_len = 16  # recommend 10-20
SALT = 'cumin'  # random word to include in options to randomize hash results
SPEC_CHAR_1 = '!'  # !@#$%^&*()+ are good options
SPEC_CHAR_2 = '@'
char_pos = 7
assert char_pos in range(1, PW_len//2)

if len(sys.argv) == 1:
    print('Usage: ./pw_generator.py [keyword1] [keyword2] [keyword3] ...')
elif len(sys.argv) <= 3:
    print('Minimum 2 keywords')  # just good practice
else:
    args = sys.argv[1:]
    args.sort()
    joined_args = ''.join(args)
    # hash function only takes in byte obj
    byte_args = str.encode(joined_args + SALT)
    hash_obj = hashlib.sha256(byte_args)  # see hashlib docs for alternatives
    hash_res = hash_obj.hexdigest()[:16]

    # subs in special char
    hash_res = hash_res.replace(hash_res[char_pos], SPEC_CHAR_1)
    hash_res = hash_res.replace(hash_res[char_pos*2], SPEC_CHAR_2)

    # capitalizes portion of hash - halves hash, capitalizes first half, rejoin
    h1, h2 = hash_res[:len(hash_res)//2], hash_res[len(hash_res)//2:]
    h1 = h1.upper()
    final_hash = str(h1+h2)
    print(final_hash)
