CREATE TABLE "Department" (
	"departmentID"	INTEGER NOT NULL UNIQUE,
	"departmentName"	TEXT NOT NULL UNIQUE,
	"baseSalary"	REAL NOT NULL,
	"allowance"	REAL NOT NULL,
	"deduction"	REAL NOT NULL,
	PRIMARY KEY("departmentID" AUTOINCREMENT)
);
 
CREATE TABLE "Employee" (
	"employeeID"	INTEGER NOT NULL UNIQUE,
	"firstName"	TEXT NOT NULL,
	"middleName"	TEXT,
	"lastName"	TEXT NOT NULL,
	"dateOfBirth"	TEXT,
	"mobileNumber"	INTEGER NOT NULL UNIQUE,
	"email"	TEXT NOT NULL UNIQUE,
	"address"	TEXT NOT NULL,
	"gender"	TEXT NOT NULL,
	"dateOfJoining"	TEXT NOT NULL,
	"departmentID"	INTEGER NOT NULL,
	"mentorID"	INTEGER,
	"performanceMetric"	REAL,
	"bonus"	REAL,
	FOREIGN KEY("departmentID") REFERENCES "Department"("departmentID") ON DELETE CASCADE,
	FOREIGN KEY("mentorID") REFERENCES "Employee"("employeeID") ON DELETE SET NULL,
	UNIQUE("employeeID"),
	PRIMARY KEY("employeeID" AUTOINCREMENT)
);
 
CREATE TABLE "Manager" (
	"managerID"	INTEGER NOT NULL,
	"departmentID"	INTEGER NOT NULL,
	"teamSize"	INTEGER NOT NULL,
	"yearsOfExperience"	REAL NOT NULL,
	"projectTitle"	TEXT,
	"role" TEXT,
	PRIMARY KEY("managerID"),
	FOREIGN KEY("managerID") REFERENCES "Employee"("employeeID") ON DELETE CASCADE,
	FOREIGN KEY("departmentID") REFERENCES "Department"("departmentID") ON DELETE CASCADE
);
 
CREATE TABLE "Engineer" (
	"employeeID"	INTEGER NOT NULL,
	"technology"	TEXT NOT NULL,
	FOREIGN KEY("employeeID") REFERENCES "Employee"("employeeID") ON DELETE CASCADE
);
 
CREATE TABLE "QA" (
	"employeeID"	INTEGER NOT NULL,
	"testingTool"	TEXT NOT NULL,
	FOREIGN KEY("employeeID") REFERENCES "Employee"("employeeID") ON DELETE CASCADE
);
 
CREATE TABLE "Finance" (
	"employeeID"	INTEGER NOT NULL,
	"accountingTool" TEXT NOT NULL,
	FOREIGN KEY("employeeID") REFERENCES "Employee"("employeeID") ON DELETE CASCADE
);
 
CREATE TABLE "HR" (
	"employeeID"	INTEGER NOT NULL,
	"hrSpecialization"	TEXT NOT NULL,
	FOREIGN KEY("employeeID") REFERENCES "Employee"("employeeID") ON DELETE CASCADE
);

CREATE VIEW ManagerView
AS
	SELECT Employee.*,Manager.teamSize,Manager.yearsOfExperience,Manager.projectTitle,Manager.role FROM Employee INNER JOIN Manager ON Employee.employeeID = Manager.managerID;

CREATE VIEW SalaryView
AS
	SELECT employeeID, departmentID, performanceMetric, bonus ,baseSalary, allowance, deduction FROM Employee NATURAL JOIN Department;