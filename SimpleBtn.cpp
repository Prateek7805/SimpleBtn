#include "SimpleBtn.h"

	bool SimpleBtn::updatePressed(void){
		if(!digitalRead(_pin) && _pressed){
		  return true;
		}
		if(!digitalRead(_pin) && _released){
		  _pressed = true;
		  _released = false;
		  return true;
		}
		return false;
	  }
	
}

	bool SimpleBtn:updateReleased(void){
		if(digitalRead(_pin) && _released){
		  return true;
		}
		if(digitalRead(_pin) && _pressed){
		  _pressed = false;
		  _released = true;
		  return true;
		}
		return false;
	  }
	  

	  SimpleBtn::SimpleBtn(const int pin){
		_pin = pin;
	  }
	  void SimpleBtn::begin(void){
		pinMode(_pin, INPUT_PULLUP);
	  }
	  
	  bool SimpleBtn::isPressed(void){
		return _pressed;
	  }
	  bool SimpleBtn::isReleased(void){
		return _released;
	  }
	  void SimpleBtn::attachPress(funcNoParams f){
		press = f;
	  }
	  void SimpleBtn::attachRelease(funcNoParams f){
		release = f;
	  }
	  void SimpleBtn::setTickInterval(uint32_t i){
		  btn_interval = i;
	  }
	  void SimpleBtn::tick(void){
		if(millis() - t_btn > btn_interval){
		  t_btn = millis();
		  updatePressed();
		  updateReleased();
		  if(isPressed() && prev == RELEASE){
			prev = PRESS;
			press();
			return;
		  }
		  if(isReleased() && prev == PRESS){
			prev = RELEASE;
			release();
		  }
		}
	  }
