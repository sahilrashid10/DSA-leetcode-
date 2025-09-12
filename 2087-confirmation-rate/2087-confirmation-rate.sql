# Write your MySQL query statement below
with t as (
    select user_id ,count(*) as cnt from confirmations
    group by user_id
)
select s.user_id, 
if(c.action is NULL, 0, round(sum(if(c.action = 'confirmed', 1, 0))/
(select cnt from t where user_id = s.user_id), 2))
as confirmation_rate  
from signups s
left join confirmations c on s.user_id = c.user_id
group by user_id


