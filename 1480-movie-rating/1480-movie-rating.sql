# Write your MySQL query statement below
with user_ratings as (
    select user_id, count(*) as num_ratings
    from MovieRating
    group by user_id
),
top_user as (
    select u.name as results
    from Users u
    join user_ratings ur on u.user_id = ur.user_id
    where ur.num_ratings = (select max(num_ratings) from user_ratings)
    order by u.name asc
    limit 1
),
movie_avg as (
    select movie_id, avg(rating) as avg_rating
    from MovieRating
    where datediff('2020-02-29', created_at) between 0 and 28
    group by movie_id
),
top_movie as (
    select m.title as results
    from Movies m
    join movie_avg ma on m.movie_id = ma.movie_id
    where ma.avg_rating = (select max(avg_rating) from movie_avg)
    order by m.title asc
    limit 1
)
select * from top_user
union all
select * from top_movie;
