CREATE DATABASE jdbc;
USE jdbc;
CREATE TABLE users(
    id INT PRIMARY KEY AUTO_INCREMENT,
    name VARCHAR(40),
    password VARCHAR(40),
    email VARCHAR(60),
    birthday DATE
)CHARACTER SET utf8 COLLATE utf8_general_ci;