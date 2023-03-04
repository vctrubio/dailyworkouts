## NOTE this will destroy your database and create it from scratch.

CREATE DATABASE IF NOT EXISTS bookn;
SELECT IF(EXISTS(SELECT SCHEMA_NAME FROM INFORMATION_SCHEMA.SCHEMATA WHERE SCHEMA_NAME = 'bookn'), 'Database created.', 'Database creation failed.') AS RESULT;
DROP TABLE IF EXISTS users, trips, goods, reviews;

## TABLES
## Users -> Trips -> Goods -> Reviews

#id, name, avgrating, _reviews
CREATE TABLE users 
(
    usr_id      int NOT NULL AUTO_INCREMENT,
    usr_name    varchar(32) NOT NULL,
    PRIMARY KEY (usr_id)
) ENGINE=Maria;
#user has_many trips


#id, date, _userDriver, _userClient, _review, _good, price, completed(success) # (location, KM, comment ect.)
CREATE TABLE trips
(
    trip_id          int NOT NULL AUTO_INCREMENT,
    trip_driver_id   int NOT NULL,
    trip_client_id   int NULL,
    trip_price       int NULL,
    PRIMARY KEY (trip_id),
    FOREIGN KEY (trip_driver_id) REFERENCES users(usr_id)
) ENGINE=Maria;
#trips belongs_to trip_driver_id (user)


#id, name, weight, describe, # catagory
CREATE TABLE goods
(
    good_id         int NOT NULL AUTO_INCREMENT,
    good_name       varchar(32) NOT NULL,
    good_describe   varchar(128) NULL,
    good_weight     int NULL,
    PRIMARY KEY (good_id)
) ENGINE=Maria;
#good belongs_to user, has_many trips TBADDED


#id, rating, comment #=will be used after each trip to enable feedback
CREATE  TABLE reviews
(
    review_id          int NOT NULL AUTO_INCREMENT,
    review_rating      int NOT NULL,
    review_comment     text,
    PRIMARY KEY (review_id)
) ENGINE=Maria;
#to be used discovered 