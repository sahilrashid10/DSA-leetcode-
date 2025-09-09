# Write your MySQL query statement below


SELECT "Low Salary" AS category, count(income) AS accounts_count 
    FROM accounts
where income < 20000


union

SELECT "Average Salary" AS category, count(income) AS accounts_count 
    FROM accounts
where income between 20000 and 50000


union 

SELECT "High Salary" AS category, count(income) AS accounts_count 
    FROM accounts
where income > 50000
