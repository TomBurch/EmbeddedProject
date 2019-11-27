#ifndef NumberDisplay_h
#define NumberDisplay_h

class NumberDisplay
{
  public:
    void setup(int b0, int b1, int b2, int b3, int b4, int b5, int b6, int b7);
    void display(int num);
    void clearDisplay();
  
  private:
    int displayBits[8];
    int length;
};

#endif