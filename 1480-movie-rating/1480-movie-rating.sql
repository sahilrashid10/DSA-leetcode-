# Write your MySQL query statement below
with t1 as( select user_id, count(*) as num_ratings
from MovieRating 
group by user_id
order by num_ratings desc),
t2 as( select name as results from users
where user_id in (select user_id from t1
where num_ratings = (select max(num_ratings) from t1))
order by name asc limit 1),

t3 as (select movie_id, avg(rating) as avg_rating
from MovieRating where 
datediff('2020-02-29', created_at) between 0 and 28
group by movie_id
order by avg_rating desc),
t4 as(
    select title as results
    from movies where 
    movie_id in (select movie_id from t3
    where avg_rating = (select max(avg_rating) from t3))
    order by title asc limit 1
)

select * from t2
union all
select * from t4


