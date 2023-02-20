-- Priyanshu AD-1274

/*
    Basic SQL commands

    -- to show databases
    show database;

    -- to create a database
    create database nameOfDatabase;

    -- to use a database
    use scheme;

    -- to show tables
    show tables;

    -- to create a table
    create table nameOfTable (column_name1 column_type constraint constname definition, ...);

    -- to describe a table
    describe nameOfTable

    -- to update a table
    update tableName set attribute = ''

    -- where
    where

    -- like
    like

    -- and 
    and

    -- or
    or
*/

-- Now lets create our database scheme and its tables
 create database scheme;

 create table student(rollno char(6), name varchar(20) not null, cname varchar(10), dob date);

  create table society(sid char(6), sname varchar(20) not null, mentorname varchar(20) not null , capacity int unsigned default 50);

  create table enrollment (rollno char (8), sid char(6), dateOfEnrollment date);

  -- now lets enter the elements in the columns of table student
  insert into student (rollno, name, cname, dob) values ('X-1263', 'Nikhil', 'pmcs', '2001-04-02'), ('Z-1601', 'Vipin', 'pmcs', '2001-04-03'), ('AD-1274', 'Priyanshu', 'cs', '2003-04-08'), ('A-1276', 'Ritesh', 'chemistry', '2002-04-05'), ('A-1284', 'Satendar', 'cs', '2002-04-07'), ('B-1230', 'Deepak', 'zoology', '2002-04-03'), ('P-1276', 'Bhoomika', 'pscs', '2002-11-27'), ('B-1290', 'Aman', 'pscs', '2002-04-10'), ('M-1274', 'Meenakshi', 'physics', '2004-01-09');

  -- displaying all the elements of student
  select * from student;

/*
OUTPUT

+---------+-----------+-----------+------------+
| rollno  | name      | cname     | dob        |
+---------+-----------+-----------+------------+
| AD-1224 | Avishkaar | cs        | 2002-04-01 |
| X-1263  | Nikhil    | pmcs      | 2001-04-02 |
| Z-1601  | Vipin     | pmcs      | 2001-04-03 |
| AD-1274 | Priyanshu | cs        | 2003-04-08 |
| A-1276  | Ritesh    | chemistry | 2002-04-05 |
| A-1284  | Satendar  | cs        | 2002-04-07 |
| B-1230  | Deepak    | zoology   | 2002-04-03 |
| P-1276  | Bhoomika  | pscs      | 2002-11-27 |
| B-1290  | Aman      | pscs      | 2002-04-10 |
| M-1274  | Meenakshi | physics   | 2004-01-09 |
+---------+-----------+-----------+------------+
10 rows in set (0.00 sec)
*/

-- now lets enter the elements in the columns of table society
insert into society (sid, sname, mentorname, capacity) values ('01', 'debating', 'Meenakshi', '15'), ('02', 'dancing', 'Priyanka', '20'),  ('03', 'shasakt', 'Ayush', '10'),  ('04', 'eco', 'Mahesh', '25'),  ('05', 'picfie', 'Preeti', '30'),  ('06', 'tech', 'Nishu', '20'),  ('07', 'music', 'Ritesh', '05'),  ('08', 'hacking', 'deepika', '08'),  ('09', 'coding', 'Shubh', '40'),  ('10', 'cricket', 'Chirag', '80');

-- displaying all the elements of student
  select * from society;

  /*
    OUTPUT

    +------+----------+------------+----------+
| sid  | sname    | mentorname | capacity |
+------+----------+------------+----------+
| 01   | debating | Meenakshi  |       15 |
| 02   | dancing  | Priyanka   |       20 |
| 03   | shasakt  | Ayush      |       10 |
| 04   | eco      | Mahesh     |       25 |
| 05   | picfie   | Preeti     |       30 |
| 06   | tech     | Nishu      |       20 |
| 07   | music    | Ritesh     |        5 |
| 08   | hacking  | deepika    |        8 |
| 09   | coding   | Shubh      |       40 |
| 10   | cricket  | Chirag     |       80 |
+------+----------+------------+----------+
10 rows in set (0.00 sec)
  */

  -- now lets enter the elements in the columns of table enrollment
  insert into enrollment (rollno, sid, dateOfEnrollment) values ('AD-1274', '14', '2023-01-15'), ('P-1276', '15', '2023-01-16'), ('AD-1294', '02', '2023-02-15'), ('X-1263', '28', '2023-01-17'), ('Z-1601', '68', '2023-01-17'), ('M-1274', '04', '2023-01-15'), ('A-1284', '14', '2023-01-15'), ('P-1806', '54', '2022-05-19'), ('B-1290', '46', '2023-04-15'), ('B-1230', '94', '2023-08-16');

  -- displaying all the elements of student
  select * from enrollment;

  /*
    OUTPUT

    +---------+------+------------------+
| rollno  | sid  | dateOfEnrollment |
+---------+------+------------------+
| AD-1274 | 14   | 2023-01-15       |
| P-1276  | 15   | 2023-01-16       |
| AD-1294 | 02   | 2023-02-15       |
| X-1263  | 28   | 2023-01-17       |
| Z-1601  | 68   | 2023-01-17       |
| M-1274  | 04   | 2023-01-15       |
| A-1284  | 14   | 2023-01-15       |
| P-1806  | 54   | 2022-05-19       |
| B-1290  | 46   | 2023-04-15       |
| B-1230  | 94   | 2023-08-16       |
+---------+------+------------------+
10 rows in set (0.00 sec)
  */

  /*
    Now lets solve the queries
*/

-- Q1. Retrieve names of student enrolled in any society
select name from student where rollno in (select rollno from enrollme
nt);

/*
OUTPUT

+-----------+
| name      |
+-----------+
| Nikhil    |
| Vipin     |
| Priyanshu |
| Satendar  |
| Deepak    |
| Bhoomika  |
| Aman      |
| Meenakshi |
+-----------+
8 rows in set (0.00 sec)
*/


-- Q2. Retrieve all society names

select sname from society;

/*
OUTPUT

+----------+
| sname    |
+----------+
| debating |
| dancing  |
| shasakt  |
| eco      |
| picfie   |
| tech     |
| music    |
| hacking  |
| coding   |
| cricket  |
+----------+
10 rows in set (0.00 sec)
*/

-- Q3. Retrieve students names starting with letter ‘A’

select * from student where name like ('a%');
/*
OUTPUT

+---------+-----------+-------+------------+
| rollno  | name      | cname | dob        |
+---------+-----------+-------+------------+
| AD-1224 | Avishkaar | cs    | 2002-04-01 |
| B-1290  | Aman      | pscs  | 2002-04-10 |
+---------+-----------+-------+------------+
2 rows in set (0.00 sec)
*/

-- Q4. Retrieve students studying in course ‘computer sc’ or ‘chemistry’

select * from student where cname = 'cs' or cname = 'chemistry';

/*
OUTPUT

+---------+-----------+-----------+------------+
| rollno  | name      | cname     | dob        |
+---------+-----------+-----------+------------+
| AD-1224 | Avishkaar | cs        | 2002-04-01 |
| AD-1274 | Priyanshu | cs        | 2003-04-08 |
| A-1276  | Ritesh    | chemistry | 2002-04-05 |
| A-1284  | Satendar  | cs        | 2002-04-07 |
+---------+-----------+-----------+------------+
4 rows in set (0.00 sec)
*/

-- Q5. Retrieve students whose rollno either starts with ‘X’ or ‘Z’

 select * from student where rollno like ('x%') or rollno like ('z%');

/*
OUTPUT

+--------+--------+-------+------------+
| rollno | name   | cname | dob        |
+--------+--------+-------+------------+
| X-1263 | Nikhil | pmcs  | 2001-04-02 |
| Z-1601 | Vipin  | pmcs  | 2001-04-03 |
+--------+--------+-------+------------+
2 rows in set (0.00 sec)
*/

-- Q6. Find society whose capacity is more than 10

select * from society where capacity > 10;

/*
OUTPUT

+------+----------+------------+----------+
| sid  | sname    | mentorname | capacity |
+------+----------+------------+----------+
| 01   | debating | Meenakshi  |       15 |
| 02   | dancing  | Priyanka   |       20 |
| 04   | eco      | Mahesh     |       25 |
| 05   | picfie   | Preeti     |       30 |
| 06   | tech     | Nishu      |       20 |
| 09   | coding   | Shubh      |       40 |
| 10   | cricket  | Chirag     |       80 |
+------+----------+------------+----------+
7 rows in set (0.00 sec)
*/

-- Q7. Update society table for mentor name for a specific society

 update society set mentorname = 'Nisha' where sname = 'tech';

 /*
OUTPUT

 before updating

 | 06   | tech     | Nishu      |       20 |

 after updating
 | 06   | tech     | Nisha      |       20 |
 */

-- Q9. Increment capacity of each society by 10%

 update society set capacity = capacity + (capacity * 10) / 100;

 /*
OUTPUT

before updating

+------+----------+------------+----------+
| sid  | sname    | mentorname | capacity |
+------+----------+------------+----------+
| 01   | debating | Meenakshi  |       15 |
| 02   | dancing  | Priyanka   |       20 |
| 03   | shasakt  | Ayush      |       10 |
| 04   | eco      | Mahesh     |       25 |
| 05   | picfie   | Preeti     |       30 |
| 06   | tech     | Nishu      |       20 |
| 07   | music    | Ritesh     |        5 |
| 08   | hacking  | deepika    |        8 |
| 09   | coding   | Shubh      |       40 |
| 10   | cricket  | Chirag     |       80 |
+------+----------+------------+----------+

after updating

+------+----------+------------+----------+
| sid  | sname    | mentorname | capacity |
+------+----------+------------+----------+
| 01   | debating | Meenakshi  |       17 |
| 02   | dancing  | Priyanka   |       22 |
| 03   | shasakt  | Ayush      |       11 |
| 04   | eco      | Mahesh     |       28 |
| 05   | picfie   | Preeti     |       33 |
| 06   | tech     | Nisha      |       22 |
| 07   | music    | Ritesh     |        6 |
| 08   | hacking  | deepika    |        9 |
| 09   | coding   | Shubh      |       44 |
| 10   | cricket  | Chirag     |       88 |
+------+----------+------------+----------+
 */

-- Q10. Find the student names who are not enrolled in any society

select name from student where rollno not in (select rollno from enrollment);

/*
OUTPUT

+-----------+
| name      |
+-----------+
| Avishkaar |
| Ritesh    |
+-----------+
*/

--  Q8. Remove details for a student who is not enrolled in any society

delete from student where rollno not in (select rollno from enrollment);

/*
OUTPUT

+---------+-----------+---------+------------+
| rollno  | name      | cname   | dob        |
+---------+-----------+---------+------------+
| X-1263  | Nikhil    | pmcs    | 2001-04-02 |
| Z-1601  | Vipin     | pmcs    | 2001-04-03 |
| AD-1274 | Priyanshu | cs      | 2003-04-08 |
| A-1284  | Satendar  | cs      | 2002-04-07 |
| B-1230  | Deepak    | zoology | 2002-04-03 |
| P-1276  | Bhoomika  | pscs    | 2002-11-27 |
| B-1290  | Aman      | pscs    | 2002-04-10 |
| M-1274  | Meenakshi | physics | 2004-01-09 |
+---------+-----------+---------+------------+
*/

-- Q11. Find total number of students whose age is > 20 years

select name, rollno, cname, dob, curdate(), timestampdiff(year, dob, curdate()) as age from student;

/*
  OUTPUT

  +-----------+---------+---------+------------+------------+------+
| name      | rollno  | cname   | dob        | curdate()  | age  |
+-----------+---------+---------+------------+------------+------+
| Nikhil    | X-1263  | pmcs    | 2001-04-02 | 2023-02-20 |   21 |
| Vipin     | Z-1601  | pmcs    | 2001-04-03 | 2023-02-20 |   21 |
| Priyanshu | AD-1274 | cs      | 2003-04-08 | 2023-02-20 |   19 |
| Satendar  | A-1284  | cs      | 2002-04-07 | 2023-02-20 |   20 |
| Deepak    | B-1230  | zoology | 2002-04-03 | 2023-02-20 |   20 |
| Bhoomika  | P-1276  | pscs    | 2002-11-27 | 2023-02-20 |   20 |
| Aman      | B-1290  | pscs    | 2002-04-10 | 2023-02-20 |   20 |
| Meenakshi | M-1274  | physics | 2004-01-09 | 2023-02-20 |   19 |
+-----------+---------+---------+------------+------------+------+
*/

select * from student where timestampdiff(year, dob, curdate()) > 20;

/*
-- OUTPUT
-- +--------+--------+-------+------------+
-- | rollno | name   | cname | dob        |
-- +--------+--------+-------+------------+
-- | X-1263 | Nikhil | pmcs  | 2001-04-02 |
-- | Z-1601 | Vipin  | pmcs  | 2001-04-03 |
-- +--------+--------+-------+------------+
*/

-- Q12. Find the student names enrolled in atleast two societies

 select * from enrollment;

/*
+---------+------+------------------+
| rollno  | sid  | dateOfEnrollment |
+---------+------+------------------+
| AD-1274 | 06   | 2023-01-15       |
| P-1276  | 07   | 2023-01-16       |
| AD-1294 | 02   | 2023-02-15       |
| X-1263  | 02   | 2023-01-17       |
| Z-1601  | 06   | 2023-01-17       |
| M-1274  | 03   | 2023-01-15       |
| A-1284  | 09   | 2023-01-15       |
| P-1276  | 04   | 2022-05-19       |
| B-1290  | 08   | 2023-04-15       |
| X-1263  | 10   | 2023-08-16       |
+---------+------+------------------+
*/



 select rollno, count(*) as count from enrollment group by rollno having count > 1;

/*
+--------+-------+
| rollno | count |
+--------+-------+
| P-1276 |     2 |
| X-1263 |     2 |
+--------+-------+
*/


select name from student where rollno = 'p-1276' or rollno = 'X-1263';

/*
+----------+
| name     |
+----------+
| Nikhil   |
| Bhoomika |
+----------+
*/

-- Q13. Find society names in which any student is enrolled

select * from society;

/*
+------+----------+------------+----------+
| sid  | sname    | mentorname | capacity |
+------+----------+------------+----------+
| 01   | debating | Meenakshi  |       17 |
| 02   | dancing  | Priyanka   |       22 |
| 03   | shasakt  | Ayush      |       11 |
| 04   | eco      | Mahesh     |       28 |
| 05   | picfie   | Preeti     |       33 |
| 06   | tech     | Nisha      |       22 |
| 07   | music    | Ritesh     |        6 |
| 08   | hacking  | deepika    |        9 |
| 09   | coding   | Shubh      |       44 |
| 10   | cricket  | Chirag     |       88 |
+------+----------+------------+----------+
*/

 select * from student;

 /*
+---------+-----------+---------+------------+
| rollno  | name      | cname   | dob        |
+---------+-----------+---------+------------+
| X-1263  | Nikhil    | pmcs    | 2001-04-02 |
| Z-1601  | Vipin     | pmcs    | 2001-04-03 |
| AD-1274 | Priyanshu | cs      | 2003-04-08 |
| A-1284  | Satendar  | cs      | 2002-04-07 |
| B-1230  | Deepak    | zoology | 2002-04-03 |
| P-1276  | Bhoomika  | pscs    | 2002-11-27 |
| B-1290  | Aman      | pscs    | 2002-04-10 |
| M-1274  | Meenakshi | physics | 2004-01-09 |
+---------+-----------+---------+------------+
*/

 select sname from society where sid in (select sid from enrollment);

 /*
+---------+
| sname   |
+---------+
| dancing |
| shasakt |
| eco     |
| tech    |
| music   |
| hacking |
| coding  |
| cricket |
+---------+
*/

-- Q14. Find names of all students enrolled in any society and society names in which any student is enrolled

 select * from student;

 /*
+---------+-----------+---------+------------+
| rollno  | name      | cname   | dob        |
+---------+-----------+---------+------------+
| X-1263  | Nikhil    | pmcs    | 2001-04-02 |
| Z-1601  | Vipin     | pmcs    | 2001-04-03 |
| AD-1274 | Priyanshu | cs      | 2003-04-08 |
| A-1284  | Satendar  | cs      | 2002-04-07 |
| B-1230  | Deepak    | zoology | 2002-04-03 |
| P-1276  | Bhoomika  | pscs    | 2002-11-27 |
| B-1290  | Aman      | pscs    | 2002-04-10 |
| M-1274  | Meenakshi | physics | 2004-01-09 |
+---------+-----------+---------+------------+
*/

select * from society;

/*
+------+----------+------------+----------+
| sid  | sname    | mentorname | capacity |
+------+----------+------------+----------+
| 01   | debating | Meenakshi  |       17 |
| 02   | dancing  | Priyanka   |       22 |
| 03   | shasakt  | Ayush      |       11 |
| 04   | eco      | Mahesh     |       28 |
| 05   | picfie   | Preeti     |       33 |
| 06   | tech     | Nisha      |       22 |
| 07   | music    | Ritesh     |        6 |
| 08   | hacking  | deepika    |        9 |
| 09   | coding   | Shubh      |       44 |
| 10   | cricket  | Chirag     |       88 |
+------+----------+------------+----------+
*/

 select * from enrollment;

 /*
+---------+------+------------------+
| rollno  | sid  | dateOfEnrollment |
+---------+------+------------------+
| AD-1274 | 06   | 2023-01-15       |
| P-1276  | 07   | 2023-01-16       |
| AD-1294 | 02   | 2023-02-15       |
| X-1263  | 02   | 2023-01-17       |
| Z-1601  | 06   | 2023-01-17       |
| M-1274  | 03   | 2023-01-15       |
| A-1284  | 09   | 2023-01-15       |
| P-1276  | 04   | 2022-05-19       |
| B-1290  | 08   | 2023-04-15       |
| X-1263  | 10   | 2023-08-16       |
+---------+------+------------------+
*/

select name from student where rollno in (select distinct(rollno) from enrollment);

/*
+-----------+
| name      |
+-----------+
| Nikhil    |
| Vipin     |
| Priyanshu |
| Satendar  |
| Bhoomika  |
| Aman      |
| Meenakshi |
+-----------+
*/

select sname from society where sid in (select sid from enrollment);

 /*
+---------+
| sname   |
+---------+
| dancing |
| shasakt |
| eco     |
| tech    |
| music   |
| hacking |
| coding  |
| cricket |
+---------+
*/

-- Q15. Find names of students who are enrolled in all three societies ‘debating’, ‘dancing’ and ‘sashakt’.

-- select s.name from student s join enrollment e on s.name = e.sid where e.sid in ('01', '02', '03') group by s.name having count(distinct e.sid) = 3;


select * from enrollment;

/*
+---------+------+------------------+
| rollno  | sid  | dateOfEnrollment |
+---------+------+------------------+
| AD-1274 | 06   | 2023-01-15       |
| P-1276  | 07   | 2023-01-16       |
| AD-1294 | 02   | 2023-02-15       |
| X-1263  | 02   | 2023-01-17       |
| Z-1601  | 06   | 2023-01-17       |
| M-1274  | 03   | 2023-01-15       |
| A-1284  | 09   | 2023-01-15       |
| P-1276  | 04   | 2022-05-19       |
| B-1290  | 08   | 2023-04-15       |
| X-1263  | 10   | 2023-08-16       |
+---------+------+------------------+
*/

-- insert into enrollment(rollno, sid, dateOfEnrollment) values ('B-1290', '01', '2023-01-17'), ('B-1290', '02', '2023-01-20'), ('B-1290', '03', '2023-01-24');

select * from enrollment;

/*
+---------+------+------------------+
| rollno  | sid  | dateOfEnrollment |
+---------+------+------------------+
| AD-1274 | 06   | 2023-01-15       |
| P-1276  | 07   | 2023-01-16       |
| AD-1294 | 02   | 2023-02-15       |
| X-1263  | 02   | 2023-01-17       |
| Z-1601  | 06   | 2023-01-17       |
| M-1274  | 03   | 2023-01-15       |
| A-1284  | 09   | 2023-01-15       |
| P-1276  | 04   | 2022-05-19       |
| B-1290  | 08   | 2023-04-15       |
| X-1263  | 10   | 2023-08-16       |
| B-1290  | 01   | 2023-01-17       |
| B-1290  | 02   | 2023-01-20       |
| B-1290  | 03   | 2023-01-24       |
+---------+------+------------------+
*/

 select s.name from student s inner join enrollment e on s.rollno = e.rollno inner join society so on e.sid = so.sid where so.sid in ('debating', 'dancing', 'sashakt') group by s.name having count(distinct so.sid) = 3;

 /*
 Empty set
 */

 -- Q16.  Find society names that has ‘abc’ as mentor or ‘abc’ as the name of enrolled student.

 select * from society;

 /*
+------+----------+------------+----------+
| sid  | sname    | mentorname | capacity |
+------+----------+------------+----------+
| 01   | debating | Meenakshi  |       17 |
| 02   | dancing  | Priyanka   |       22 |
| 03   | shasakt  | Ayush      |       11 |
| 04   | eco      | Mahesh     |       28 |
| 05   | picfie   | Preeti     |       33 |
| 06   | tech     | Nisha      |       22 |
| 07   | music    | Ritesh     |        6 |
| 08   | hacking  | deepika    |        9 |
| 09   | coding   | Shubh      |       44 |
| 10   | cricket  | Chirag     |       88 |
+------+----------+------------+----------+
*/

 update society set mentorname = 'Yuabcsh' where mentorname = 'Ayush';

 select * from society;

 /*
+------+----------+------------+----------+
| sid  | sname    | mentorname | capacity |
+------+----------+------------+----------+
| 01   | debating | Meenakshi  |       17 |
| 02   | dancing  | Priyanka   |       22 |
| 03   | shasakt  | Yuabcsh    |       11 |
| 04   | eco      | Mahesh     |       28 |
| 05   | picfie   | Preeti     |       33 |
| 06   | tech     | Nisha      |       22 |
| 07   | music    | Ritesh     |        6 |
| 08   | hacking  | deepika    |        9 |
| 09   | coding   | Shubh      |       44 |
| 10   | cricket  | Chirag     |       88 |
+------+----------+------------+----------+
*/

select distinct s.sid, s.sname from society s left join enrollment e on s.sid = e.sid left join student st on e.rollno = st.rollno where s.mentorname like '%abc%' or st.name = '%abc%';

/*
+------+---------+
| sid  | sname   |
+------+---------+
| 03   | shasakt |
+------+---------+
*/

-- Q17. Find society names whose mentor name is same as that of any enrolled student in it.

insert into enrollment (rollno, sid, dateOfEnrollment) values ('M-1274', '01', '2023-04-06');

 select * from society;

 /*
+------+----------+------------+----------+
| sid  | sname    | mentorname | capacity |
+------+----------+------------+----------+
| 01   | debating | Meenakshi  |       17 |
| 02   | dancing  | Priyanka   |       22 |
| 03   | shasakt  | Yuabcsh    |       11 |
| 04   | eco      | Mahesh     |       28 |
| 05   | picfie   | Preeti     |       33 |
| 06   | tech     | Nisha      |       22 |
| 07   | music    | Ritesh     |        6 |
| 08   | hacking  | deepika    |        9 |
| 09   | coding   | Shubh      |       44 |
| 10   | cricket  | Chirag     |       88 |
+------+----------+------------+----------+
*/

select * from enrollment;

/*
+---------+------+------------------+
| rollno  | sid  | dateOfEnrollment |
+---------+------+------------------+
| AD-1274 | 06   | 2023-01-15       |
| P-1276  | 07   | 2023-01-16       |
| AD-1294 | 02   | 2023-02-15       |
| X-1263  | 02   | 2023-01-17       |
| Z-1601  | 06   | 2023-01-17       |
| M-1274  | 03   | 2023-01-15       |
| A-1284  | 09   | 2023-01-15       |
| P-1276  | 04   | 2022-05-19       |
| B-1290  | 08   | 2023-04-15       |
| X-1263  | 10   | 2023-08-16       |
| B-1290  | 01   | 2023-01-17       |
| B-1290  | 02   | 2023-01-20       |
| B-1290  | 03   | 2023-01-24       |
| M-1274  | 01   | 2023-04-06       |
+---------+------+------------------+
*/
