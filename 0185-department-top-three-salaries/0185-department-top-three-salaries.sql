# Write your MySQL query statement below
with ranked as (
    select d.name as Department, e.name as Employee, 
    e.salary as Salary, 
    dense_rank() over (partition by d.id order by e.salary desc)as val
    from employee e
    left join department d on e.departmentId = d.id 
) 
select Department, Employee, Salary
    from ranked 
where val < 4
order by Department,salary

    
