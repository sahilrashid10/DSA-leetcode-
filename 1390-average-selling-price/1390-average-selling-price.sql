# Write your MySQL query statement below
select p.product_id, 
ifnull(round(sum(s.units*p.price)/sum(s.units), 2), 0)
as average_price 
from prices p
left join unitssold s on 
p.product_id = s.product_id and
s.purchase_date between p.start_date and p.end_date 
group by p.product_id
