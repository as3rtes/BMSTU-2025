CREATE DATABASE product_inventory;

CREATE TABLE category (
    id INT PRIMARY KEY,
    category_name VARCHAR(255) NOT NULL
);

CREATE TABLE products(
    id INT PRIMARY KEY,
    product_name VARCHAR(255) NOT NULL,
    price DECIMAL(10,2) NOT NULL,
    quantity INT NOT NULL,
    category_id INT,
    FOREIGN KEY (category_id) REFERENCES category(id)
);

CREATE TABLE sales (
    id INT PRIMARY KEY,
    product_id INT NOT NULL,
    sale_date DATE NOT NULL,
    quantity_sold INT NOT NULL,
    FOREIGN KEY (product_id) REFERENCES products(id)
);
