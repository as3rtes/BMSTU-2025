INSERT INTO category (id, category_name) VALUES
(1, 'Овощи'),
(2, 'Фрукты'),
(3, 'Молочные продукты'),
(4, 'Мясные продукты');

INSERT INTO products (id, product_name, price, quantity, category_id) VALUES
(1, 'Морковь', 45.50, 100, 1),
(2, 'Помидоры', 120.00, 50, 1),
(3, 'Яблоки', 89.90, 120, 2),
(4, 'Бананы', 65.75, 80, 2),
(5, 'Молоко', 75.00, 40, 3),
(6, 'Курица', 320.00, 30, 4);

INSERT INTO sales (id, product_id, sale_date, quantity_sold) VALUES
(1, 1, '2024-01-15', 10),
(2, 3, '2024-01-15', 5),
(3, 5, '2024-01-16', 3),
(4, 2, '2024-01-17', 8),
(5, 6, '2024-01-18', 2);
