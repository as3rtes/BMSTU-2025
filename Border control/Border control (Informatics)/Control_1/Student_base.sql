CREATE TABLE students (
    student_id SERIAL PRIMARY KEY,
    full_name TEXT,
    group_number TEXT
);

CREATE TABLE subjects (
    subject_id SERIAL PRIMARY KEY,
    subject_name TEXT
);

CREATE TABLE grades (
    grade_id SERIAL PRIMARY KEY,
    student_id INT REFERENCES students(student_id),
    subject_id INT REFERENCES subjects(subject_id),
    grade INT
);

CREATE TABLE attendance (
    attendance_id SERIAL PRIMARY KEY,
    student_id INT REFERENCES students(student_id),
    date_attended DATE,
    status BOOLEAN
);

CREATE TABLE notes (
    note_id SERIAL PRIMARY KEY,
    student_id INT REFERENCES students(student_id),
    note_text TEXT
);

INSERT INTO students (full_name, group_number) VALUES
('Леонид', '101'),
('Андрей', '101'),
('Артем', '101'),
('Дима', '101'),
('Смирнова', '101'),
('Федоров', '101');

INSERT INTO subjects (subject_name) VALUES
('Математика'),
('Геометрия'),
('Информатика');

INSERT INTO grades (student_id, subject_id, grade) 
VALUES (1,1,5), (1,2,4), (1,3,5),
       (2,1,4), (2,2,4), (2,3,3),
       (3,1,3), (3,2,5), (3,3,4),
       (4,1,5), (4,2,5), (4,3,5),
       (5,1,4), (5,2,4), (5,3,4),
       (6,1,3), (6,2,3), (6,3,4);

INSERT INTO attendance (student_id, date_attended, status) 
VALUES (1,'2025-12-01',true), (1,'2025-12-02',true),
       (2,'2025-12-01',true), (2,'2025-12-02',false),
       (3,'2025-12-01',false), (3,'2025-12-02',true),
       (4,'2025-12-01',true), (4,'2025-12-02',true),
       (5,'2025-12-01',true), (5,'2025-12-02',true),
       (6,'2025-12-01',false), (6,'2025-12-02',true);

INSERT INTO notes (student_id, note_text) VALUES
(1,'Тиктокер и хорошо играет в покер'),
(2,'Командир 34 батальон танковой мотопехотной дивизии'),
(3,'Никогда не готовится к экзаменам (всегда сдает)'),
(4,'Создатель циркулярной бомбы'),
(5,'Хорошо работает в команде'),
(6,'Прогресс по информатике');

CREATE INDEX idx_group ON students(group_number);
CREATE INDEX idx_grades ON grades(student_id);
CREATE INDEX idx_notes ON notes USING gin(to_tsvector('russian', note_text));

CREATE VIEW student_avg AS
SELECT s.student_id, s.full_name, AVG(g.grade) as avg_grade
FROM students s JOIN grades g ON s.student_id = g.student_id
GROUP BY s.student_id, s.full_name;

BEGIN;
INSERT INTO students (full_name, group_number) VALUES ('Новенький', '101');
INSERT INTO grades (student_id, subject_id, grade) 
VALUES (7,1,4), (7,2,5), (7,3,4);
COMMIT;

SELECT * FROM students 
WHERE group_number='101' AND student_id BETWEEN 1 AND 6
ORDER BY student_id
LIMIT 5;

SELECT avg_grade FROM student_avg WHERE student_id=1;

SELECT AVG(grade) FROM grades 
WHERE subject_id=(SELECT subject_id FROM subjects WHERE subject_name='Информатика');

SELECT * FROM notes WHERE note_text LIKE '%Информатика%';

BEGIN;
UPDATE attendance SET status=false 
WHERE student_id=2 AND date_attended='2025-12-01';
COMMIT;
