create procedure insert_STUD
	@sexflag int=0, @age int=0, @dept char(8)='MA',@i int=1
	as
	while @i<1000
	begin
		set @age = 20
			
		if @i%4 = 1
			set @age=18
		
		if @i%4 = 2
			set @age = 19

		if @i%2 = 0
			set @sexflag = 0
		else
			set @sexflag = 1


		set @dept = 'MA'
		
		if @i%3 = 0
			set @dept = 'CS'
		if @i%3 = 1 
			set @dept = 'IS'

		insert into STU values(@i, 'Name'+cast(@i as char), @sexflag, @age, @dept)
		set @i=@i+1
	end 

	exec insert_STUD;
	select * from STU where Sage>=20;

	╨▐╕─▒эг║
	create procedure add2_Student
	@sexflag int=0, @age int=0, @dept char(8)='MA',@i int=7000000
	as
	while @i<7000100
	begin

		set @age = 21
		set @sexflag = 0
		set @dept = 'MA'

		insert into Student values(@i, 'add'+cast(@i as char), @sexflag, @age, @dept)
		set @i=@i+1
	end 

	exec add2_Student;
	select * from Student where Sage=21;

-----------------------------------------------------------------------------------------------

create  procedure insert_Course
	@i int = 1
	as
	while @i<1000
		begin
			insert into Course values(@i, 'Course'+ cast(@i as char), @i%5)
			set @i=@i+1
		end


гнгнгнгнгнгнгнгнгнгнгнгнгнгнгнгнгнгнгнгнгнгнгнгнгнгнгнгнгнгнгнгнгнгнгнгнгнгнгнгнгнгнгнгнгнгнгнгн
create procedure insert_SC
	@i int =1, @j int =1
	as

	while @i<6000
    	begin
		set @j=1
		while @j<1000
			begin
				insert into SC values(@i,@j,(@i*@j)%100)
				set @j=@j+1
			end
		set @i=@i+1
	end

-----------------------------------------------------------------------
Data Source=YDXZ-BFF59D120E\SQLEXPRESS;Initial Catalog=S_C;Integrated Security=True

