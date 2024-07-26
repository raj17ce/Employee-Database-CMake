-- Populate Department Table
INSERT INTO Department ("departmentName", "baseSalary", "allowance", "deduction") VALUES
('Engineer', 65000, 7000, 3000),
('Finance', 65000, 6000, 2500),
('HR', 55000, 4000, 1500),
('QA', 59000, 4800, 1900);

-- Populate Employee Table
INSERT INTO Employee ("firstName", "middleName", "lastName", "dateOfBirth", "mobileNumber", "email", "address", "gender", "dateOfJoining", "departmentID", "mentorID", "performanceMetric", "bonus") VALUES 
('John', 'Doe', 'Smith', '15-05-1990', 1234567891, 'john.smith@example.com', '123 Main St, City, Country', 'Male', '10-01-2020', 1, NULL, 0.85, 500),
('David', 'Lee', 'Brown', '03-04-1993', 1234509876, 'david.brown@example.com', '345 Oak St, City, Country', 'Male', '12-11-2022', 1, 2, 0.78, 450),
('Daniel', 'Joseph', 'Garcia', '22-06-1989', 1234567892, 'daniel.garcia@example.com', '234 Cedar St, City, Country', 'Male', '30-08-2018', 1, 3, 0.85, 550),
('Ryan', 'Thomas', 'Gonzalez', '08-03-1988', 1234567893, 'ryan.gonzalez@example.com', '567 Birchwood St, City, Country', 'Male', '12-09-2018', 1, 1, 0.87, 500),
('Brandon', 'Michael', 'Lewis', '18-09-1992', 1234567894, 'brandon.lewis@example.com', '567 Redwood St, City, Country', 'Male', '12-02-2018', 1, 2, 0.86, 550),
('Tyler', 'John', 'Hill', '25-08-1993', 1234567895, 'tyler.hill@example.com', '567 Birchwood St, City, Country', 'Male', '12-06-2018', 1, 3, 0.83, 400),
('Matthew', 'David', 'Morris', '08-08-1991', 1234567896, 'matthew.morris@example.com', '567 Cedarwood St, City, Country', 'Male', '15-09-2018', 1, 1, 0.91, 600),
('Jane', 'Doe', 'Smith', '20-08-1992', 9876543211, 'jane.smith@example.com', '456 Elm St, City, Country', 'Female', '20-05-2018', 2, NULL, 0.75, 400),
('Sarah', 'Elizabeth', 'Wilson', '10-07-1995', 9876543212, 'sarah.wilson@example.com', '567 Elm St, City, Country', 'Female', '05-09-2023', 2, 8, 0.88, 600),
('Amanda', 'Nicole', 'Rodriguez', '05-11-1994', 9876543213, 'amanda.rodriguez@example.com', '678 Birch St, City, Country', 'Female', '10-10-2021', 2, 9, 0.77, 400),
('Lauren', 'Ann', 'Perez', '16-07-1991', 9876543214, 'lauren.perez@example.com', '789 Oakwood St, City, Country', 'Female', '25-06-2022', 2, 10, 0.82, 450),
('Melissa', 'Rose', 'King', '02-12-1989', 9876543215, 'melissa.king@example.com', '789 Oakwood St, City, Country', 'Female', '15-07-2021', 2, 9, 0.84, 500),
('Kayla', 'Marie', 'Young', '11-12-1995', 9876543206, 'kayla.young@example.com', '789 Elmwood St, City, Country', 'Female', '15-03-2021', 2, 8, 0.92, 700),
('Nicole', 'Elizabeth', 'Ward', '24-02-1994', 9876543217, 'nicole.ward@example.com', '789 Redwood St, City, Country', 'Female', '12-02-2021', 2, 11, 0.80, 450),
('Michael', 'James', 'Johnson', '12-12-1985', 4567890128, 'michael.johnson@example.com', '789 Oak St, City, Country', 'Male', '05-03-2019', 3, NULL, 0.9, 600),
('Christopher', 'Ray', 'Martinez', '28-02-1991', 4567890129, 'chris.martinez@example.com', '789 Pine St, City, Country', 'Male', '15-03-2020', 3, 15, 0.92, 700),
('James', 'William', 'Lopez', '19-01-1990', 4567890103, 'james.lopez@example.com', '345 Redwood St, City, Country', 'Male', '15-04-2019', 3, 16, 0.89, 600),
('Justin', 'David', 'Sanchez', '01-11-1989', 4567890523, 'justin.sanchez@example.com', '123 Elmwood St, City, Country', 'Male', '30-04-2019', 3, 15, 0.75, 400),
('Andrew', 'Scott', 'Scott', '09-06-1988', 4567890122, 'andrew.scott@example.com', '123 Maplewood St, City, Country', 'Male', '05-11-2019', 3, 17, 0.88, 600),
('Jacob', 'Alexander', 'Nelson', '03-09-1986', 4567895123, 'jacob.nelson@example.com', '123 Oakwood St, City, Country', 'Male', '05-11-2019', 3, 18, 0.85, 550),
('Alexander', 'James', 'Cooper', '06-06-1987', 4567896123, 'alexander.cooper@example.com', '123 Cedarwood St, City, Country', 'Male', '05-03-2019', 3, 17, 0.84, 500),
('Emily', 'Anne', 'Williams', '25-10-1988', 9870723456, 'emily.williams@example.com', '101 Pine St, City, Country', 'Female', '15-02-2021', 4, NULL, 0.82, 550),
('Jessica', 'Marie', 'Taylor', '14-09-1987', 9878123456, 'jessica.taylor@example.com', '908 Maple St, City, Country', 'Female', '25-07-2019', 4, 22, 0.81, 500),
('Ashley', 'Grace', 'Hernandez', '27-08-1986', 9970123456, 'ashley.hernandez@example.com', '234 Elmwood St, City, Country', 'Female', '05-11-2020', 4, 23, 0.80, 550),
('Stephanie', 'Marie', 'Clark', '23-05-1987', 9850123456, 'stephanie.clark@example.com', '345 Cedarwood St, City, Country', 'Female', '05-03-2020', 4, 22, 0.95, 700),
('Rachel', 'Michelle', 'Green', '17-04-1990', 9873123456, 'rachel.green@example.com', '345 Cedarwood St, City, Country', 'Female', '20-08-2020', 4, 24, 0.79, 450),
('Megan', 'Nicole', 'Carter', '19-05-1989', 9870153456, 'megan.carter@example.com', '345 Maplewood St, City, Country', 'Female', '20-07-2020', 4, 23, 0.78, 500),
('Samantha', 'Marie', 'Richardson', '15-10-1989', 9870163456, 'samantha.richardson@example.com', '345 Elmwood St, City, Country', 'Female', '20-04-2020', 4, 25, 0.87, 550);
 
-- Populating Engineer table
INSERT INTO Engineer ("employeeID", "technology") VALUES 
(1, 'Java'),
(2, 'Python'),
(3, 'C++'),
(4, 'JavaScript'),
(5, 'SQL'),
(6, 'HTML/CSS'),
(7, 'Ruby');
 
-- Populating Finance table
INSERT INTO Finance ("employeeID", "accountingTool") VALUES 
(8, 'QuickBooks'),
(9, 'SAP Business One'),
(10, 'Xero'),
(11, 'Tally'),
(12, 'Excel'),
(13, 'SAP ERP'),
(14, 'Oracle Financials');
 
-- Populating HR table
INSERT INTO HR ("employeeID", "hrSpecialization") VALUES 
(15, 'Recruitment'),
(16, 'Training and Development'),
(17, 'Compensation and Benefits'),
(18, 'Employee Relations'),
(19, 'Performance Management'),
(20, 'HRIS Implementation'),
(21, 'Labor Law Compliance');
 
-- Populating QA table
INSERT INTO QA ("employeeID", "testingTool") VALUES 
(22, 'Selenium'),
(23, 'JUnit'),
(24, 'TestNG'),
(25, 'Appium'),
(26, 'JIRA'),
(27, 'Postman'),
(28, 'LoadRunner');
 
-- Populating Manager table
INSERT INTO Manager ("managerID", "departmentID", "teamSize", "yearsOfExperience", "projectTitle", "role") VALUES 
(1, 1, 15, 10, 'Project A', 'Java'),
(5, 1, 18, 12, 'Project E', 'C#'),
(8, 2, 12, 8, 'Project B', 'Python'),
(11, 2, 14, 9, 'Project F', 'JavaScript'),
(15, 3, 20, 15, 'Project C', 'SAP'),
(17, 3, 25, 18, 'Project G', 'Oracle'),
(23, 4, 10, 6, 'Project D', 'HRIS'),
(26, 4, 12, 7, 'Project H', 'Workday');