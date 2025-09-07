# Write your MySQL query statement below
select we.id from weather we
join weather w on datediff(we.recorddate, w.recorddate) = 1 
where  we.temperature > w.temperature