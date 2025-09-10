# Write your MySQL query statement below


SELECT 
    CASE 
        WHEN id = (SELECT max(id) from seat) AND id & 1 = 1 
            THEN id

        WHEN id & 1 = 1 
            THEN id+1 

        ELSE id-1 
    END as id, student
FROM seat
ORDER BY id ASC