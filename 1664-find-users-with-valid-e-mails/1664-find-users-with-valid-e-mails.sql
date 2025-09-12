# Write your MySQL query statement below
SELECT * 
FROM Users
WHERE REGEXP_LIKE(mail, '^[a-zA-Z][a-zA-Z0-9._-]*@leetcode\\.com$', 'c');
--  ^ → Start of string.

-- [A-Za-z] → First character must be a letter.

-- [A-Za-z0-9._-]* → After that, you can have zero or more:

-- letters (A–Z, a–z)

-- numbers (0–9)

-- dot (.)

-- underscore (_)

-- dash (-)
-- ✅ This makes up the username part of the email.

-- @leetcode → Must literally have @leetcode.

-- \.com → Must end with .com (dot escaped).

-- $ → End of string.