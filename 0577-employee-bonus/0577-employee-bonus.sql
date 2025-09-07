# Write your MySQL query statement below
select e.name, b.bonus from employee e
left join bonus b on e.empid = b.empid and b.bonus < 1000
where b.bonus is not null || e.empid not in (select empid from bonus)
