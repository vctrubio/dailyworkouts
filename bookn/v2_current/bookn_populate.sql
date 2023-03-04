INSERT INTO users (usr_name) VALUES
("ChineseMan"), 
("AmigoMan"), 
("TenMan"), 
("SexbombLad");

INSERT INTO trips (trip_driver_id, trip_client_id, trip_price) VALUES 
(1, NULL, 25), 
(1, 2, 20), 
(1, NULL, NULL), 
(3, 4, 0);

INSERT INTO goods (good_name, good_describe, good_weight) VALUES
('Book', 'A novel by J.K. Rowling', 0.8),
('Laptop', 'Dell XPS 13', 1.2),
('Shoes', 'Running shoes', 0.9),
('Camera', 'Canon EOS 5D Mark IV', 2.1),
('Headphones', 'Bose QuietComfort 35 II', 0.3);

SELECT "Database populated successfully!" As message;