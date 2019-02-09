#include <iostream>
using namespace std;

void drawTicks(unsigned int ticks, string marker = " ")
{
  //cout << "drawTicks(" << ticks << ", " << marker << ")\n";
  for (unsigned int i = 0; i < ticks; ++i)
  {
    cout << "-";
  }
  cout << ' ' << marker << endl;
}

void drawSubScale(unsigned int ticks)
{
  // cout << "drawSubScale(" << ticks << ")\n";
  if(ticks == 1)
  {
    drawTicks(ticks);
    return;
  }
  drawSubScale(ticks-1);
  drawTicks(ticks);
  drawSubScale(ticks-1);
}

void drawRuler(unsigned int inches, unsigned int ticks)
{
  // cout << "drawRuler(" << inches << ", " << ticks << ")\n";
  for(unsigned int i = 0; i < inches; ++i)
  {
    drawTicks(ticks, to_string(i));
    drawSubScale(ticks-1);
  }
  drawTicks(ticks, to_string(inches));
}

int main()
{
  drawRuler(6, 3);
  return 0;
}
