-- Temporary table vs Table variable
-- temp tb can be pre-compile, faster in long SP
-- Table variable exist only in the same scope as variables
-- In practical - no universal rule try both: small records table variable; large use temp table with indexes



DECLARE @driverID as varchar(50)
set @driverID = 'all'

Declare @DriverID_tb TABLE
(
   DriverID varchar(11)
)

--INSERT INTO @table SELECT * FROM...
--SELECT * INTO #table FROM...
  IF @driverID  = 'all'
    BEGIN
      INSERT INTO @DriverID_tb
	    select DriverID from rfDrivers
    END
  ELSE
     INSERT INTO @DriverID_tb
		  select @driverID


select * from @DriverID_tb

