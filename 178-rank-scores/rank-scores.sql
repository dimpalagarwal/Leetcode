# Write your MySQL query statement below

#1st method
-- select s1.score, (
--     select count(distinct s2.score) from Scores s2 where s2.score > s1.score
-- )+1 AS `rank` from Scores s1 order by s1.score desc;

#2nd method
select score, dense_rank() over(order by score desc) as `rank` from Scores;