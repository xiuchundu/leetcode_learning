1. 解法1：直接使用传染法，访问过的置为'2'
```java
    public int numIslands(char[][] grid) {
        int islandsNum = 0;
        for (int i = 0; i < grid.length; i++) {
            for (int j = 0; j < grid[0].length; j++) {
                if (grid[i][j] == '1') {
                    dfs(grid, i, j);
                    islandsNum++;
                }
            }
        }

        return islandsNum;
    }

    public void dfs(char[][] grid, int x, int y) {
        if (x < 0 || x >= grid.length || y < 0 || y >= grid[0].length || grid[x][y] != '1') {
            return;
        }

        grid[x][y] = '2'; // 一个岛所有的1都变成了-1后，遍历的时候就不会重复遍历了
        dfs(grid, x + 1, y);
        dfs(grid, x - 1, y);
        dfs(grid, x, y + 1);
        dfs(grid, x, y - 1);
    }
```

2. 解法2：直接使用访问标记法，针对地图设置对应的visited[][]。
```java
    public int numIslands(char[][] grid) {
        int islandsNum = 0;
        boolean[][] visited = new boolean[grid.length][grid[0].length];
        for (int i = 0; i < grid.length; i++) {
            for (int j = 0; j < grid[0].length; j++) {
                if (grid[i][j] == '1' && !visited[i][j]) {
                    dfs(visited, grid, i, j);
                    islandsNum++;
                }
            }
        }

        return islandsNum;
    }

    public void dfs(boolean[][] visited, char[][] grid, int x, int y) {
        if (x < 0 || x >= grid.length || y < 0 || y >= grid[0].length || grid[x][y] != '1' || visited[x][y]) {
            return;
        }

        visited[x][y] = true;
        dfs(visited, grid, x + 1, y);
        dfs(visited, grid, x - 1, y);
        dfs(visited, grid, x, y + 1);
        dfs(visited, grid, x, y - 1);
    }
```

两种方法对比起来，第一种更简洁、更高效。
