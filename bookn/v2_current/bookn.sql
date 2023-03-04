CREATE DATABASE IF NOT EXISTS bookn;
SELECT IF(EXISTS(SELECT SCHEMA_NAME FROM INFORMATION_SCHEMA.SCHEMATA WHERE SCHEMA_NAME = 'bookn'), 'Database created.', 'Database creation failed.') AS RESULT;

## TABLES
## Users -> Trips -> Goods -> || Reviews

