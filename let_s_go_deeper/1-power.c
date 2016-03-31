int power(int x, int y) {
  long z, a;
  a = x;
  if (y<0||x<0||(a>46340&&y>1)||(x==4&&y>15)||(x==8&&y>10)||(x==16&&y>7)) {
    return -1;}
  if((x==32&&y>6)||(x==64&&y>5)||(x==128&&y>4)||(x==256&&y>3)||(x==512&&y>3)){
    return -1;}
  if((x==1024&&y>3)||(x % 2048 == 0 && y>2) ){ /* handle futher powers */
    return -1;}
  if (y == 0) {
    return 1;}
  if (y == 1) {
    return x;}
  y -= 1;
  z = x * power(x, y);
  if (z > 2147483647) {
    return -1;}
  if (z < 0) {
    return -1;}
  return x * power(x, y); /* recursively call the function */
}
