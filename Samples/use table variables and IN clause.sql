USE [FDMS_32444_2]
GO
/****** Object:  StoredProcedure [dbo].[usp_GetHosEditRecords]    Script Date: 6/18/2014 3:49:01 PM ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
--**************************************************************************************
-- Get Hos Edited records from tblHoursService table
-- Description:
--   Select Hos records that have been edited in recent 8 days based on input date
-- Inputs:
--   EventDate: 
--   DriverID:  ID can be driver ID, or 'all' then return for all drivers
--
-- Date			Programmer		Description
-- --------		--------------	-----------------------------------------------------------
-- 06/12/2014	Chao Wang   	Create usp_GetHosEditRecords stored procedure

ALTER  proc [dbo].[usp_GetHosEditRecords] 

@EventDate as datetime,
@driverID as varchar(50)
AS 

    DECLARE @DriverID_tb TABLE
	(
	   DriverID varchar(11)
	)

	IF @driverID = 'all'
		BEGIN
		  INSERT INTO @DriverID_tb
		    select driverID from rfDrivers
		END
    ELSE
	    INSERT INTO @DriverID_tb
		  select @driverID

	select  ObjId,
			DriverId,
			convert(varchar(8),eventDate,108) as Time,
			StatusTimeStamp,
			timeZone,
			Hosstatus,
			STREET_NAME,
			City,
			State,
			COUNTRY,
			ZIP,
			SupervisorNote,
			CoDriverID,
			AccuTotalMiles,
			ISNULL(VEHICLE_NAME, '') AS VEHICLE_NAME,
			VEHICLE_ID,
			TrailerID,
			ManifestNumb,
			ShipperName,
			Commodity,
			totdrivemiles,
			eventdate,
			Carrier,
			CarrierAddr
	from tblHoursService
	where DriverId in (select * from @DriverID_tb)
		and LastEditTmStamp is not null and LastEditTmStamp between DATEADD(DAY, -8, @EventDate) and @EventDate 
    order by eventDate desc
		