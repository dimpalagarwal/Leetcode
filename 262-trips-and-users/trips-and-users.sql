# Write your MySQL query statement below

select t.request_at as Day, round(sum(case when t.status like 'cancelled%' then 1 else 0 end)/count(*),2) as `Cancellation Rate` from trips t join users c on t.client_id = c.users_id and c.role = 'client' join users d on t.driver_id = d.users_id and d.role = 'driver' where c.banned = 'No' and d.banned = "No" and t.request_at between '2013-10-01' and '2013-10-03' 
group by t.request_at;

-- select t.id, t.client_id, c.banned as client_banned, t.driver_id, d.banned as driver_banned, t.status, t.request_at from trips t join users c on t.client_id = c.users_id and c.role = 'client' join users d on t.driver_id = d.users_id and d.role = 'driver' where c.banned = 'No' and d.banned = 'No';