# Write your MySQL query statement below

select 
round((count(if(first_order = first_delivery, 1, NULL))*100)/count(first_delivery), 2)
as  immediate_percentage 
from (
    # first order table
    select delivery_id,
    customer_id,
    min(order_date) as first_order,
    min(customer_pref_delivery_date) as first_delivery
    from delivery
    group by customer_id) as fo