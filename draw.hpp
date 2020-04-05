#include <SFML/Graphics.hpp>
#include <iostream>
#include "forward_decls.hpp"

using namespace sf;
class Utilities
{
public:
  Utilities(Sprite& _background, int _M, int _N, Sprite& _frame) : background(_background), M(_M),N(_N), frame(_frame)
  {
  }
private:
  Sprite background;
  const int M;
  const int N;
  Sprite frame;
  int colorNum = 1;
public:
  void Draw(RenderWindow& window, int field[][10], Sprite &s)
  {
   
    for (int i=0;i<M;i++)
      for (int j=0;j<N;j++)
        {
          if (field[i][j]==0) continue;
          std::cout<<"field[i][j] "<< i << ","<< j <<std::endl;
          s.setTextureRect(IntRect(field[i][j]*18,0,18,18));
          s.setPosition(j*18,i*18);
          s.move(28,31); //offset
          window.draw(s);
        }
    
    for (int i=0;i<4;i++)
      {
        s.setTextureRect(IntRect(colorNum*18,0,18,18));
        s.setPosition(a[i].x*18, a[i].y*18);
        s.move(28,31);
        window.draw(s);
      }
    
    window.draw(frame);
    window.display();
  }

  bool CheckTiles()
  {
 for (int i=0;i<4;i++)
      if (a[i].x<0 || a[i].x>=N || a[i].y>=M) return 0;
      else if (field[a[i].y][a[i].x]) return 0;

   return 1;
  }
};
