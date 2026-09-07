# Write your MySQL query statement below
SELECT machine_id , ROUND(AVG(end_time-start_time),3) AS 'processing_time'
FROM
(SELECT 
    machine_id,
    process_id,
    MAX(CASE WHEN activity_type = 'Start' THEN timestamp END) AS 'start_time',
    MAX(CASE WHEN activity_type = 'End' THEN timestamp END) AS 'end_time'
FROM Activity
GROUP BY machine_id,process_id) AS w
GROUP BY machine_id
    