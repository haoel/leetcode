SELECT t.`Request_at` AS Day,
ROUND(COUNT(CASE WHEN t.`Status` = 'cancelled_by_driver' OR t.`Status` = 'cancelled_by_client' THEN 1 END) / COUNT(*), 2) AS "Cancellation Rate"
FROM Trips t 
INNER JOIN Users u 
ON t.Client_Id = u.Users_Id
WHERE u.Banned = 'No'
AND t.Request_at >= '2013-10-01'
AND t.Request_at <= '2013-10-03'
GROUP BY t.Request_at