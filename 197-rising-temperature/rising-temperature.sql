# Write your MySQL query statement below

-- with tempComp as (
--     select id, recordDate as today_date, temperature as today_temp, lag(recordDate) over (order by recordDate) as prev_date, lag(temperature) over (order by id) as prev_day_temp from Weather
-- )select id from tempComp where today_temp > prev_day_temp and datediff(today_date, prev_date) = 1;

select w1.id from weather w1, weather w2 where datediff(w1.recordDate, w2.recordDate) = 1 AND w1.temperature > w2.temperature;