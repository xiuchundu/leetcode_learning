# 解题思路：通过init()方法初始化墙面--二维数组，对瓷砖覆盖的地方进行赋值。对于lines中的每条线段，判断是否有瓷砖完全覆盖线段。最后进行次数累加。
如何判断瓷砖能否完全覆盖线段？线段可能处于水平、垂直、45度、135度的方向。基于斜率去算比较复杂。可以基于坐标轴x、y的+1来控制。
