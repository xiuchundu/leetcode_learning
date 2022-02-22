# 解题思路：通过init()方法初始化墙面--二维数组tmp[400][400]，对瓷砖覆盖的地方进行赋值。对于lines中的每条线段，判断是否有瓷砖完全覆盖线段。最后进行次数累加。
如何判断瓷砖能否完全覆盖线段？线段可能处于水平、垂直、45度、135度的方向。基于斜率去算比较复杂。可以基于坐标轴x、y的+1来控制。
核心实现为：
int isCover(int index, int[][] lines) {
  sigX = getSig(x1, x2);
  sigY = getSig(y1, y2);
  int len = MaxLen(abs(startRow - endRow), abs(startCol - endCol)) + 1;
  for(int i=0; i<len; i++){
     if (tmp[x1 + i * sigX][y1 + i * sigY] == 0) { // 只要有没覆盖到的，即为不满足
       return 0;
     }
  }

  return 1;
}
