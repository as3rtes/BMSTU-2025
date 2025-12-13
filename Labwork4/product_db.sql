CREATE TABLE categories (
    id SERIAL PRIMARY KEY,
    category_name VARCHAR(100) NOT NULL UNIQUE
);


CREATE TABLE products (
    id SERIAL PRIMARY KEY,
    name VARCHAR(200) NOT NULL,
    price DECIMAL(10, 2) NOT NULL,
    quantity INTEGER DEFAULT 0,
    category_id INTEGER REFERENCES categories(id) ON DELETE SET NULL
);

CREATE TABLE sales (
    id SERIAL PRIMARY KEY,
    product_id INTEGER REFERENCES products(id) ON DELETE CASCADE,
    sale_date DATE DEFAULT CURRENT_DATE,
    quantity_sold INTEGER NOT NULL CHECK (quantity_sold > 0)
);


CREATE INDEX idx_categories_name ON categories(category_name);
CREATE INDEX idx_products_name ON products(name);
CREATE INDEX idx_sales_date ON sales(sale_date);



INSERT INTO categories (category_name) VALUES 
('Электроника'),
('Одежда'),
('Продукты питания'),
('Книги');

INSERT INTO products (name, price, quantity, category_id) VALUES
('Ноутбук', 75000.00, 10, 1),
('Футболка', 1500.00, 50, 2),
('Хлеб', 50.00, 100, 3),
('Учебник по SQL', 1200.00, 30, 4),
('Смартфон', 45000.00, 15, 1);