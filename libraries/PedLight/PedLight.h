#ifndef PedLight_h
#define PedLight_h

class PedLight {
  private:
    int pinRed;
    int pinGre;
	String name;

  public:
    void setup(int pinRed, int pinGre, String name);
    void setLights(int stage);
    void setTraffic(bool mode);
    void flashGreen();
	void outState();
};

#endif

