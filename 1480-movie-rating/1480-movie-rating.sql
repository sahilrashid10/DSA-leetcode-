# Write your MySQL query statement below
-- with t1 as( select user_id, count(*) as num_ratings
-- from MovieRating 
-- group by user_id
-- order by num_ratings desc),
-- t2 as( select name as results from users
-- where user_id in (select user_id from t1
-- where num_ratings = (select max(num_ratings) from t1))
-- order by name asc limit 1),

-- t3 as (select movie_id, avg(rating) as avg_rating
-- from MovieRating where 
-- datediff('2020-02-29', created_at) between 0 and 28
-- group by movie_id
-- order by avg_rating desc),
-- t4 as(
--     select title as results
--     from movies where 
--     movie_id in (select movie_id from t3
--     where avg_rating = (select max(avg_rating) from t3))
--     order by title asc limit 1
-- )

-- select * from t2
-- union all
-- select * from t4


with Most_Rated_User as (SELECT u.name as results from users u
join MovieRating r using(user_id) 
group by u.user_id
order by count(r.rating) desc, name asc limit 1
),
Highest_Rated_Movie as (select  title as results from movies
join MovieRating using (movie_id)
where month(created_at) = '02' and year(created_at) = '2020'
group by movie_id
order by avg(rating) desc, title asc 
limit 1)

select * from Most_Rated_User
union all
select * from Highest_Rated_Movie
