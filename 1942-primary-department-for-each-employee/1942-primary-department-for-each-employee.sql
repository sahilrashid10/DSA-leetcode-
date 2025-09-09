select 
    employee_id, 
    department_id
from employee 
where primary_flag = 'Y'
group by employee_id

union

select 
    employee_id, 
    department_id
from employee 
group by employee_id
having count(employee_id) = 1


