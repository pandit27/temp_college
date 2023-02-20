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