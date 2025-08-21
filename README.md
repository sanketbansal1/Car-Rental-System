# Car-Rental-System

A system to provide multiple functionalities to different users such as renting and returning cars, adding and updating car details, including automatic fine calculation for late returns or damages, and adding new employees and customers

The following code named “main.cpp”, is an application of problem statement given in the C++ programming assignment using concepts in OOPS.

It uses file handling in C++ for database, with five separate databases in 5 different “.csv” files. “all_customers_data.csv”, “all_employees_data.csv”, “all_managers_data.csv”, “all_cars_data.csv” & “issued_cars_data.csv”.

Two classes are defined “user” & “car”, with three sub-classes of class “user” as “Customer”, “Employee” & “Manager”. Basic functionalities are the same as that defined in the problem statement. To measure user_record, I have used a variable named ‘credit_score’ which is 100 by default. Any user can rent a car until their total_fine which is “late fine + damaged_car_fine” is 40. Per day late fine is 50 units. Always keep the ‘manager1’, to add users or cars into the system.
