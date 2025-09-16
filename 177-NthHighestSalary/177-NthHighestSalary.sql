-- Last updated: 9/16/2025, 9:53:06 AM
CREATE FUNCTION getNthHighestSalary(N INT) RETURNS INT
BEGIN
SET N = N-1;
  RETURN (
      SELECT DISTINCT(salary) from Employee order by salary DESC
      LIMIT 1 OFFSET N
      
  );
END

#pls upvote if you find solution easy to undestand....!! Thanks..!!!