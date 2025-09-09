# Write your MySQL query statement below
select distinct teacher_id, count(*) as cnt
from (select teacher_id, subject_id
from teacher
group by teacher_id, subject_id) as sub
group by teacher_id