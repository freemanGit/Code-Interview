-- find out latest event

SELECT
    t.EVENTDATE,
	t.DEG_LATITUDE,
	t.DEG_LONGITUDE,
	t.STREET_NAME,
	t.CITY,
	t.STATE,
	t.ZIP,
	t.VEHICLE_NAME,
	t.STATUS_SHORT,
	v.VIN,
	vlu.VLU_POCSAG as IP
FROM TBLEVENTTRACKING t (nolock)
inner join (select VEHICLE_ID, MAX(eventDate) as eventDate
			from tblEventTracking (nolock)
			where Quality > 0
			group by VEHICLE_ID) s on t.eventDate = s.eventDate and t.VEHICLE_ID = s.VEHICLE_ID
inner join Vehicles v (nolock) on t.VEHICLE_ID = v.VEHICLE_ID and v.INACTIVE_FLAG = 0
left join VLUs vlu (nolock) on v.VLU_ID = vlu.VLU_ID
order by t.eventDate desc


;WITH cte_events AS
(
SELECT 
    t.EVENTDATE,
	t.DEG_LATITUDE,
	t.DEG_LONGITUDE,
	t.STREET_NAME,
	t.CITY,
	t.STATE,
	t.ZIP,
	t.VEHICLE_NAME,
	t.STATUS_SHORT,
	v.VIN,
	vlu.VLU_POCSAG as IP,
	ROW_NUMBER() OVER (PARTITION BY t.VEHICLE_ID ORDER BY t.eventDate DESC) AS rn
FROM TBLEVENTTRACKING t (nolock)
inner join Vehicles v (nolock) on t.VEHICLE_ID = v.VEHICLE_ID and v.INACTIVE_FLAG = 0
left join VLUs vlu (nolock) on v.VLU_ID = vlu.VLU_ID
where t.Quality > 0
)
select *
from  cte_events
where rn = 1
order by eventDate desc