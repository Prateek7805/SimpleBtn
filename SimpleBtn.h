#ifndef _SIMPLE_BTN_
	#define SIMPLE_BTN_
	#include <Arduino.h>
	
	
	typedef void (*funcNoParams) (void);
	
	class SimpleBtn {
	  private:
		int _pin;
		const uint8_t PRESS = 1;
		const uint8_t RELEASE = 2;
		bool _pressed = false;
		bool _released = true;

		uint8_t prev = RELEASE;
		uint32_t btn_interval = 100;
		uint32_t t_btn = 0;
		funcNoParams press;
		funcNoParams release;
		
		bool updatePressed(void);
		bool updateReleased(void);
	  public:
	  SimpleBtn(const int);
	  void begin(void);
	  bool isPressed(void);
	  bool isReleased(void);
	  void attachPress(funcNoParams);
	  void attachRelease(funcNoParams);
	  void setTickInterval(uint32_t);
	  void tick(void);
	};


#endif _SIMPLE_BTN_