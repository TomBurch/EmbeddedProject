#ifndef PedLight_h
#define PedLight_h

class PedLight {
  private:
    int pinRed;
    int pinGre;

  public:
    void setup(int pinRed, int pinGre);
    void setLights(int stage);
    void setTraffic(bool mode);
    void flashGreen();
	void outState();
};

#endif