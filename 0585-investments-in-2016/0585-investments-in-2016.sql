# Write your MySQL query statement below


select round(sum(i.tiv_2016), 2) as tiv_2016
from Insurance i
where 
    (i.lat, i.lon) in (
        select lat, lon 
        from Insurance 
        where 
            i.lat = lat and
            i.lon = lon 
        having count(*) = 1
        ) 
    and i.tiv_2015 in (
        select tiv_2015 from insurance
        where i.tiv_2015 = tiv_2015
        having count(*) > 1
    )




