# Write your MySQL query statement below

/* Write your PL/SQL query statement below */

SELECT id, "Root" as type
FROM Tree
WHERE p_id IS NULL
UNION
SELECT p_id, "Inner" as type
FROM Tree
WHERE p_id <> (
SELECT id
FROM Tree
WHERE p_id IS NULL
)
UNION
SELECT id, "Leaf" as type
FROM Tree
WHERE id NOT IN (
SELECT p_id
FROM Tree
WHERE p_id IS NOT NULL
) AND p_id IS NOT NULL
;

/*

*/